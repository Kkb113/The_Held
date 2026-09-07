#include "Foundation.h"
#include "Modules/ModuleManager.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Engine/PointLight.h"
#include "Engine/SpotLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Sound/SoundWave.h"
#include "Misc/CommandLine.h"
#include "Misc/Paths.h"
#include "Misc/Parse.h"
#include "Misc/FileHelper.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, TheHeld, "TheHeld");
DEFINE_LOG_CATEGORY_STATIC(LogHeld, Log, All);

namespace {
UMaterialInterface* Mat(const TCHAR* Name) {
    return LoadObject<UMaterialInterface>(nullptr, *FString::Printf(TEXT("/Game/Foundation/%s.%s"), Name, Name));
}
UStaticMeshComponent* Part(AActor* Owner, USceneComponent* Parent, const TCHAR* Name, FVector P, FVector Scale, const TCHAR* Material, bool Sphere=false) {
    auto* C = NewObject<UStaticMeshComponent>(Owner, Name);
    C->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, Sphere ? TEXT("/Engine/BasicShapes/Sphere.Sphere") : TEXT("/Engine/BasicShapes/Cube.Cube")));
    C->SetupAttachment(Parent);
    C->SetRelativeLocation(P); C->SetRelativeScale3D(Scale);
    C->SetMaterial(0, Mat(Material)); C->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    C->RegisterComponent();
    return C;
}
AStaticMeshActor* Box(UWorld* W, const TCHAR* Name, FVector P, FVector Size, const TCHAR* Material, bool Collision=true) {
    P.Y=-P.Y; // Backdrop behind the +Y camera; +X reads left to right.
    auto* A = W->SpawnActor<AStaticMeshActor>(P, FRotator::ZeroRotator);
    A->Tags.Add(FName(Name)); // Stable authored identifiers; never persist generated actor names.
    auto* C=A->GetStaticMeshComponent(); C->SetMobility(EComponentMobility::Movable);
    C->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube")));
    C->SetMaterial(0, Mat(Material)); C->SetWorldScale3D(Size/100.f);
    C->SetCollisionEnabled(Collision ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
    return A;
}
void Lamp(UWorld* W, FVector P, FLinearColor Color, float Intensity, float Radius) {
    P.Y=-P.Y;
    auto* L=W->SpawnActor<APointLight>(P, FRotator::ZeroRotator);
    auto* C=L->PointLightComponent.Get(); C->SetMobility(EComponentMobility::Movable);
    C->SetLightColor(Color); C->SetIntensity(Intensity*32.f); C->SetAttenuationRadius(Radius); C->SetCastShadows(false);
}
}

AHeldFoundationCharacter::AHeldFoundationCharacter() {
    PrimaryActorTick.bCanEverTick=true;
    GetCapsuleComponent()->InitCapsuleSize(22,76);
    GetCharacterMovement()->MaxWalkSpeed=210;
    GetCharacterMovement()->MaxStepHeight=22;
    GetCharacterMovement()->bConstrainToPlane=true;
    GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0,1,0));
    GetCharacterMovement()->bSnapToPlaneAtStart=true;
    GetCharacterMovement()->GravityScale=1;
    bUseControllerRotationYaw=false;
}
void AHeldFoundationCharacter::BeginPlay() {
    Super::BeginPlay();
    SetActorLocation(FVector(-720,0,78));
    Figure=NewObject<USceneComponent>(this,TEXT("IvoProxy"));
    Figure->SetupAttachment(GetRootComponent()); Figure->SetRelativeLocation(FVector(0,0,-76)); Figure->RegisterComponent();
    Part(this,Figure,TEXT("Jacket"),{0,0,92},{.29f,.25f,.48f},TEXT("M_AshBlue"));
    Part(this,Figure,TEXT("Collar"),{0,0,117},{.17f,.18f,.06f},TEXT("M_Porcelain"));
    Part(this,Figure,TEXT("Head"),{0,0,135},{.25f,.24f,.30f},TEXT("M_Skin"),true);
    Part(this,Figure,TEXT("Hair"),{-2,0,143},{.25f,.25f,.18f},TEXT("M_Dark"),true);
    LeftLeg=Part(this,Figure,TEXT("LeftLeg"),{0,-8,36},{.115f,.12f,.65f},TEXT("M_Dark"));
    RightLeg=Part(this,Figure,TEXT("RightLeg"),{0,8,36},{.115f,.12f,.65f},TEXT("M_Dark"));
    LeftArm=Part(this,Figure,TEXT("LeftArm"),{0,-19,89},{.095f,.10f,.44f},TEXT("M_AshBlue"));
    RightArm=Part(this,Figure,TEXT("RightArm"),{0,19,89},{.095f,.10f,.44f},TEXT("M_AshBlue"));
    auto* PC=Cast<APlayerController>(GetController());
    if(PC) PC->SetInputMode(FInputModeGameOnly());
    Feedback=TEXT("Follow the passage. Touch the porcelain marker."); FeedbackUntil=8;
}
void AHeldFoundationCharacter::SetupPlayerInputComponent(UInputComponent* Input) {
    Super::SetupPlayerInputComponent(Input);
    auto* E=CastChecked<UEnhancedInputComponent>(Input);
    Mapping=NewObject<UInputMappingContext>(this);
    auto Make=[this](const TCHAR* Name,EInputActionValueType Type) {
        auto* A=NewObject<UInputAction>(this,Name); A->ValueType=Type; A->bTriggerWhenPaused=true; Actions.Add(A); return A;
    };
    auto* MoveAction=Make(TEXT("Move"),EInputActionValueType::Axis1D);
    Mapping->MapKey(MoveAction,EKeys::D); Mapping->MapKey(MoveAction,EKeys::Right);
    for(FKey K : {EKeys::A,EKeys::Left}) { auto& M=Mapping->MapKey(MoveAction,K); M.Modifiers.Add(NewObject<UInputModifierNegate>(Mapping)); }
    auto& Stick=Mapping->MapKey(MoveAction,EKeys::Gamepad_LeftX);
    auto* Dead=NewObject<UInputModifierDeadZone>(Mapping); Dead->LowerThreshold=.18f; Stick.Modifiers.Add(Dead);
    E->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AHeldFoundationCharacter::Move);
    auto Bind=[&](const TCHAR* Name,FKey K,FKey Pad,void(AHeldFoundationCharacter::*Fn)()) {
        auto* A=Make(Name,EInputActionValueType::Boolean); Mapping->MapKey(A,K); Mapping->MapKey(A,Pad);
        E->BindAction(A,ETriggerEvent::Started,this,Fn);
    };
    Bind(TEXT("Contact"),EKeys::E,EKeys::Gamepad_FaceButton_Bottom,&AHeldFoundationCharacter::Contact);
    Bind(TEXT("Pause"),EKeys::Escape,EKeys::Gamepad_Special_Right,&AHeldFoundationCharacter::PauseRoom);
    Bind(TEXT("Restart"),EKeys::R,EKeys::Gamepad_FaceButton_Top,&AHeldFoundationCharacter::RestartRoom);
    Bind(TEXT("Mute"),EKeys::M,EKeys::Gamepad_FaceButton_Left,&AHeldFoundationCharacter::ToggleMute);
    Bind(TEXT("Quit"),EKeys::Q,EKeys::Gamepad_Special_Left,&AHeldFoundationCharacter::QuitRoom);
    auto* Volume=Make(TEXT("Volume"),EInputActionValueType::Axis1D);
    Mapping->MapKey(Volume,EKeys::Equals); Mapping->MapKey(Volume,EKeys::Gamepad_RightShoulder);
    for(FKey K : {EKeys::Hyphen,EKeys::Gamepad_LeftShoulder}) Mapping->MapKey(Volume,K).Modifiers.Add(NewObject<UInputModifierNegate>(Mapping));
    E->BindAction(Volume,ETriggerEvent::Started,this,&AHeldFoundationCharacter::AdjustVolume);
    if(auto* PC=Cast<APlayerController>(GetController())) if(auto* Sub=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer())) Sub->AddMappingContext(Mapping,0);
}
void AHeldFoundationCharacter::Move(const FInputActionValue& V) {
    if(UGameplayStatics::IsGamePaused(this)) return;
    const float X=V.Get<float>(); AddMovementInput(FVector(1,0,0),X);
    if(FMath::Abs(X)>.1f) Facing=FMath::Sign(X);
}
void AHeldFoundationCharacter::Contact() {
    if(UGameplayStatics::IsGamePaused(this)) return;
    if(FMath::Abs(GetActorLocation().X-620)>90) { Feedback=TEXT("Move closer to the porcelain marker."); FeedbackUntil=GetWorld()->GetTimeSeconds()+3; return; }
    bContacted=true;
    Feedback=TEXT("Contact registered. Foundation route complete."); FeedbackUntil=GetWorld()->GetTimeSeconds()+6;
    if(auto* Cue=LoadObject<USoundWave>(nullptr,TEXT("/Game/Foundation/A_Contact.A_Contact"))) UGameplayStatics::PlaySound2D(this,Cue,MasterVolume);
    UE_LOG(LogHeld,Display,TEXT("PH00_CONTACT accepted x=%.2f volume=%.2f"),GetActorLocation().X,MasterVolume);
}
void AHeldFoundationCharacter::PauseRoom() { UGameplayStatics::SetGamePaused(this,!UGameplayStatics::IsGamePaused(this)); }
void AHeldFoundationCharacter::RestartRoom() { UGameplayStatics::SetGamePaused(this,false); UGameplayStatics::OpenLevel(this,FName(TEXT("L_PH00"))); }
void AHeldFoundationCharacter::ToggleMute() { MasterVolume=MasterVolume>0?0:.5f; }
void AHeldFoundationCharacter::AdjustVolume(const FInputActionValue& V) { MasterVolume=FMath::Clamp(MasterVolume+V.Get<float>()*.1f,0.f,1.f); }
void AHeldFoundationCharacter::QuitRoom() { if(UGameplayStatics::IsGamePaused(this)) if(auto* PC=Cast<APlayerController>(GetController())) PC->ConsoleCommand(TEXT("quit")); }
void AHeldFoundationCharacter::Tick(float Dt) {
    Super::Tick(Dt);
    const float Speed=GetVelocity().Size2D(); Gait+=Dt*Speed*.045f;
    float Swing=FMath::Sin(Gait)*FMath::Clamp(Speed/210.f,0.f,1.f)*18;
    if(Figure) { Figure->SetRelativeRotation(FRotator(0,Facing>0?0:180,0)); LeftLeg->SetRelativeRotation(FRotator(Swing,0,0)); RightLeg->SetRelativeRotation(FRotator(-Swing,0,0)); LeftArm->SetRelativeRotation(FRotator(-Swing*.6f,0,0)); RightArm->SetRelativeRotation(FRotator(Swing*.6f,0,0)); }
    if(GetActorLocation().Z < -150) SetActorLocation(FVector(-720,0,78));
}

AHeldFoundationMode::AHeldFoundationMode() {
    DefaultPawnClass=AHeldFoundationCharacter::StaticClass(); HUDClass=AHeldFoundationHUD::StaticClass(); PrimaryActorTick.bCanEverTick=true;
}
void AHeldFoundationMode::BeginPlay() {
    Super::BeginPlay(); UWorld* W=GetWorld();
    bSmoke=FParse::Param(FCommandLine::Get(),TEXT("HeldSmoke"));
    Box(W,TEXT("PH00.Floor"),{0,0,-30},{1900,380,60},TEXT("M_Stone"));
    Box(W,TEXT("PH00.BackWall"),{0,260,250},{1900,40,560},TEXT("M_Stone"));
    Box(W,TEXT("PH00.LeftBound"),{-950,0,160},{30,350,350},TEXT("M_Dark"));
    Box(W,TEXT("PH00.RightBound"),{950,0,160},{30,350,350},TEXT("M_Dark"));
    Box(W,TEXT("PH00.Step"),{-420,0,9},{140,260,18},TEXT("M_Stone"));
    Platform=Box(W,TEXT("PH00.Platform"),{0,0,9},{220,260,18},TEXT("M_Brass"));
    // These are scenic frames, not puzzle machinery or Hold contacts.
    for(int i=-2;i<=2;i++) {
        float X=i*370.f;
        Box(W,*FString::Printf(TEXT("PH00.Column.%d"),i+2),{X,210,250},{28,45,500},TEXT("M_Dark"));
        Box(W,*FString::Printf(TEXT("PH00.Window.%d"),i+2),{X+150,230,330},{110,12,130},TEXT("M_Window"),false);
        Box(W,*FString::Printf(TEXT("PH00.Sill.%d"),i+2),{X+150,195,260},{130,65,10},TEXT("M_Dark"),false);
    }
    for(int i=0;i<19;i++) Box(W,*FString::Printf(TEXT("PH00.Grid.%d"),i),{-900+i*100.f,-125,1},{2,45,1},TEXT("M_Brass"),false);
    Box(W,TEXT("PH00.HighPipe"),{0,160,195},{1800,12,12},TEXT("M_Brass"),false);
    Box(W,TEXT("PH00.Patch"),{-610,231,130},{100,6,130},TEXT("M_AshBlue"),false);
    Box(W,TEXT("PH00.MarkerFrame"),{620,110,103},{48,18,64},TEXT("M_Brass"),false);
    Box(W,TEXT("PH00.Marker"),{620,96,103},{34,8,46},TEXT("M_Porcelain"),false);
    Box(W,TEXT("PH00.MarkerSeam"),{620,90,103},{2,3,28},TEXT("M_Brass"),false);
    Box(W,TEXT("PH00.ForegroundLeft"),{-920,-200,140},{90,70,330},TEXT("M_Dark"),false);
    Box(W,TEXT("PH00.ForegroundRight"),{930,-180,90},{140,85,210},TEXT("M_Dark"),false);
    Box(W,TEXT("PH00.ForegroundLip"),{0,-240,-45},{2100,120,55},TEXT("M_Dark"),false);
    auto* Export=Box(W,TEXT("PH00.BlenderTile"),{380,0,6},{100,100,12},TEXT("M_Stone"));
    if(auto* Mesh=LoadObject<UStaticMesh>(nullptr,TEXT("/Game/Foundation/SM_CalibrationTile.SM_CalibrationTile"))) { Export->GetStaticMeshComponent()->SetStaticMesh(Mesh); Export->SetActorScale3D(FVector(1)); }
    Lamp(W,{-500,-180,300},{.55f,.67f,.72f},18000,1400);
    Lamp(W,{400,-130,320},{.57f,.68f,.72f},16000,1400);
    Lamp(W,{620,30,150},{1.f,.65f,.30f},2400,380);
    auto* Fog=W->SpawnActor<AExponentialHeightFog>(); Fog->GetComponent()->SetFogDensity(.007f); Fog->GetComponent()->SetFogInscatteringColor({.20f,.27f,.29f});
    auto* Post=W->SpawnActor<APostProcessVolume>(); Post->bUnbound=true;
    Post->Settings.bOverride_AutoExposureMethod=true; Post->Settings.AutoExposureMethod=AEM_Manual;
    Post->Settings.bOverride_AutoExposureBias=true; Post->Settings.AutoExposureBias=7.f;
    Post->Settings.bOverride_VignetteIntensity=true; Post->Settings.VignetteIntensity=.25f;
    auto* Cam=W->SpawnActor<ACameraActor>(FVector(0,1750,390),FRotator(-9.8f,-90,0));
    Cam->GetCameraComponent()->SetFieldOfView(58.72f); // 35 degree vertical at 16:9.
    Cam->GetCameraComponent()->SetAspectRatio(16.f/9.f); Cam->GetCameraComponent()->SetConstraintAspectRatio(true);
    if(auto* PC=UGameplayStatics::GetPlayerController(this,0)) PC->SetViewTarget(Cam);
    UE_LOG(LogHeld,Display,TEXT("PH00 build=0.0.1 room ready; proxy=152cm; platform bounded; no Hold/campaign state"));
}
void AHeldFoundationMode::Tick(float Dt) {
    Super::Tick(Dt); Time+=Dt;
    if(Platform) Platform->SetActorLocation(FVector(0,0,9+5*(1-FMath::Cos(Time*.7f))),false);
    if(!bSmoke) return;
    auto* P=Cast<AHeldFoundationCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
    if(!P) return;
    if(Time>2 && SmokeStage==0 && P->GetActorLocation().X<600) P->AddMovementInput(FVector(1,0,0),1);
    if(SmokeStage==0 && (P->GetActorLocation().X>=600 || Time>30)) { P->Contact(); SmokeStage=1; SmokeFinishedAt=Time; UE_LOG(LogHeld,Display,TEXT("PH00_SMOKE x=%.2f z=%.2f contact=%d"),P->GetActorLocation().X,P->GetActorLocation().Z,P->bContacted); }
    if(SmokeStage==1 && Time>SmokeFinishedAt+1) { if(auto* PC=UGameplayStatics::GetPlayerController(this,0)) PC->ConsoleCommand(TEXT("HighResShot 1")); SmokeStage=2; }
    if(SmokeStage==2 && Time>SmokeFinishedAt+3) { FString R=FString::Printf(TEXT("{\"route_contact\":%s,\"x\":%.2f,\"z\":%.2f,\"elapsed_game_seconds\":%.2f}"),P->bContacted?TEXT("true"):TEXT("false"),P->GetActorLocation().X,P->GetActorLocation().Z,Time); FFileHelper::SaveStringToFile(R,*(FPaths::ProjectSavedDir()/TEXT("PH00-smoke.json"))); FPlatformMisc::RequestExit(false); }
}

void AHeldFoundationHUD::DrawHUD() {
    Super::DrawHUD(); auto* P=Cast<AHeldFoundationCharacter>(GetOwningPawn()); if(!Canvas||!P) return;
    const float S=FMath::Clamp(Canvas->SizeY/900.f,.8f,1.3f);
    DrawText(TEXT("THE HELD"),FLinearColor(.82f,.82f,.76f),38,30,nullptr,1.7f*S);
    DrawText(TEXT("PH00  /  FOUNDATION STUDY"),FLinearColor(.5f,.61f,.61f),40,65,nullptr,.85f*S);
    DrawText(TEXT("A/D or Left stick  Move     E / A  Contact     Esc / Menu  Pause"),FLinearColor(.8f,.82f,.79f),40,Canvas->SizeY-50,nullptr,S);
    if(GetWorld()->GetTimeSeconds()<P->FeedbackUntil) DrawText(P->Feedback,FLinearColor(.85f,.73f,.51f),40,Canvas->SizeY-80,nullptr,S);
    if(UGameplayStatics::IsGamePaused(this)) {
        DrawRect(FLinearColor(0.025f,.04f,.045f,.95f),Canvas->SizeX*.25f,Canvas->SizeY*.25f,Canvas->SizeX*.5f,Canvas->SizeY*.5f);
        float X=Canvas->SizeX*.30f,Y=Canvas->SizeY*.32f;
        DrawText(TEXT("PAUSED"),FLinearColor::White,X,Y,nullptr,1.5f*S);
        DrawText(TEXT("Esc / Menu   Resume\nR / Y   Restart room\nM / X   Mute / unmute\n- / + or LB / RB   Master volume\nQ / View   Quit"),FLinearColor(.8f,.82f,.79f),X,Y+50,nullptr,S);
        DrawText(FString::Printf(TEXT("Master volume: %d%%"),FMath::RoundToInt(P->MasterVolume*100)),FLinearColor(.85f,.73f,.51f),X,Y+180,nullptr,S);
    }
}


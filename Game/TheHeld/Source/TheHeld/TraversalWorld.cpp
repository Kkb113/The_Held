#include "Traversal.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/PointLight.h"
#include "Engine/SpotLight.h"
#include "Engine/ExponentialHeightFog.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/Canvas.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

namespace {
UMaterialInterface* Material(const TCHAR* N){return LoadObject<UMaterialInterface>(nullptr,*FString::Printf(TEXT("/Game/Traversal/%s.%s"),N,N));}
UStaticMesh* Shape(const TCHAR* N){return LoadObject<UStaticMesh>(nullptr,*FString::Printf(TEXT("/Engine/BasicShapes/%s.%s"),N,N));}
AStaticMeshActor* Solid(UWorld* W,const TCHAR* ID,FVector P,FVector S,const TCHAR* Mat=TEXT("M_Stone")){
 auto* A=W->SpawnActor<AStaticMeshActor>(P,FRotator::ZeroRotator);A->Tags.Add(FName(ID));
 auto* C=A->GetStaticMeshComponent();C->SetMobility(EComponentMobility::Movable);C->SetStaticMesh(Shape(TEXT("Cube")));C->SetMaterial(0,Material(Mat));C->SetWorldScale3D(S/100);return A;
}
void Decor(UWorld* W,FVector P,FVector S,const TCHAR* Mat,FRotator R=FRotator::ZeroRotator,const TCHAR* Mesh=TEXT("Cube")){
 auto* M=Cast<AHeldTraversalMode>(W->GetAuthGameMode());FName Key(*FString::Printf(TEXT("%s_%s"),Mat,Mesh));
 UInstancedStaticMeshComponent* C=M->Scenery.FindRef(Key);
 if(!C){C=NewObject<UInstancedStaticMeshComponent>(M);C->SetStaticMesh(Shape(Mesh));C->SetMaterial(0,Material(Mat));C->SetCollisionEnabled(ECollisionEnabled::NoCollision);C->SetCastShadow(false);C->RegisterComponent();M->Scenery.Add(Key,C);}
 C->AddInstance(FTransform(R,P,S/100),true);
}
void Pipe(UWorld* W,FVector A,FVector B,float Radius,const TCHAR* Mat=TEXT("M_Brass")){
 FVector D=B-A;Decor(W,(A+B)*.5,FVector(Radius*2,Radius*2,D.Size()),Mat,FRotationMatrix::MakeFromZ(D).Rotator(),TEXT("Cylinder"));
}
void Light(UWorld* W,FVector P,FLinearColor Col,float Strength,float Radius){auto* A=W->SpawnActor<APointLight>(P,FRotator::ZeroRotator);auto* C=A->PointLightComponent.Get();C->SetMobility(EComponentMobility::Movable);C->SetLightColor(Col);C->SetIntensity(Strength);C->SetAttenuationRadius(Radius);C->SetCastShadows(false);}
void Child(AActor* A,FVector P,FVector S,const TCHAR* Mat,const TCHAR* Mesh=TEXT("Cube"),FRotator R=FRotator::ZeroRotator){auto* C=NewObject<UStaticMeshComponent>(A);C->SetupAttachment(A->GetRootComponent());C->SetStaticMesh(Shape(Mesh));C->SetMaterial(0,Material(Mat));C->SetRelativeLocation(P/A->GetActorScale3D());C->SetAbsolute(false,true,true);C->SetWorldScale3D(S/100);C->SetWorldRotation(R);C->SetCollisionEnabled(ECollisionEnabled::NoCollision);C->RegisterComponent();}
}

AHeldTraversalMode::AHeldTraversalMode(){DefaultPawnClass=AHeldTraversalCharacter::StaticClass();PlayerControllerClass=AHeldTraversalController::StaticClass();HUDClass=AHeldTraversalHUD::StaticClass();PrimaryActorTick.bCanEverTick=true;PrimaryActorTick.bTickEvenWhenPaused=true;}
void AHeldTraversalMode::BeginPlay(){
 Super::BeginPlay();SetActorHiddenInGame(false);auto* W=GetWorld();bTest=FParse::Param(FCommandLine::Get(),TEXT("HeldTraversalTest"));bRouteTest=FParse::Param(FCommandLine::Get(),TEXT("HeldRouteTest"));
 auto Floor=[&](float A,float B,float Z){Solid(W,*FString::Printf(TEXT("PH01.Floor.%.0f.%.0f.%.0f"),A,B,Z),{(A+B)/2,0,Z-35},{B-A,350,70});};
 Floor(-600,3700,0);Floor(3700,3880,-180);Floor(3880,4650,0);
 auto* L=Solid(W,TEXT("PH01.Ledge"),{4925,0,52.5},{550,350,105});L->Tags.Add(TEXT("Ledge"));
 for(int i=0;i<4;i++)Floor(5200+i*100,5300+i*100,80-i*20);
 Floor(5600,6330,0);Floor(6330,7100,280);Floor(7100,9000,0);Floor(9000,9500,140);Floor(9500,10900,0);Floor(10900,11500,-230);Floor(11500,14500,0);
 for(int i=0;i<14;i++)Floor(7100+i*50,7150+i*50,260-i*20);
 auto* Ramp=Solid(W,TEXT("PH01.Ramp"),{12570,0,75},{440,350,24});Ramp->SetActorRotation(FRotator(20,0,0));
 Floor(12770,12920,161);for(int i=0;i<8;i++)Floor(12920+i*45,12965+i*45,141-i*20);
 Solid(W,TEXT("PH01.StartBound"),{-600,0,150},{30,350,380});Solid(W,TEXT("PH01.EndBound"),{14500,0,150},{30,350,380});
 auto* Duct=Solid(W,TEXT("PH01.LowPipeClearance"),{2550,0,145},{600,340,80},TEXT("M_PaintedMetal"));Duct->GetStaticMeshComponent()->SetHiddenInGame(true);
 for(float Y:{-120.f,0.f,120.f}){Pipe(W,{2250,Y,145},{2850,Y,145},40,TEXT("M_PaintedMetal"));for(float X:{2270.f,2500.f,2830.f})Pipe(W,{X-4,Y,145},{X+4,Y,145},44,TEXT("M_Brass"));}
 Solid(W,TEXT("PH01.LightOverhang"),{1140,0,225},{390,340,70});
 Solid(W,TEXT("PH01.TrolleyOverhang"),{8530,0,225},{500,340,70});
 // A service ladder is reachable from the lower lane and the upper landing.
 for(float X:{6270.f,6330.f})Pipe(W,{X,-35,0},{X,-35,340},3,TEXT("M_PaintedMetal"));
 for(int i=0;i<13;i++)Pipe(W,{6270,-35,float(i*26)},{6330,-35,float(i*26)},2,TEXT("M_Brass"));
 auto* Chair=Solid(W,TEXT("PH01.LightChair"),{1100,0,50},{65,110,100},TEXT("M_Timber"));Chair->Tags.Add(TEXT("Light"));Chair->Tags.Add(TEXT("Ledge"));Props.Add(Chair);PropStarts.Add(Chair->GetActorLocation());
 auto* Cart=Solid(W,TEXT("PH01.Trolley"),{8500,0,60},{130,145,120},TEXT("M_PaintedMetal"));Cart->Tags.Add(TEXT("Heavy"));Cart->Tags.Add(TEXT("Ledge"));Props.Add(Cart);PropStarts.Add(Cart->GetActorLocation());
 for(auto A:Props){for(float X:{-45.f,45.f})for(float Y:{-68.f,68.f})Child(A,{X,Y,-40},{24,24,14},TEXT("M_Dark"),TEXT("Cylinder"),FRotator(90,0,0));Child(A,{-75,0,38},{8,140,8},TEXT("M_Porcelain"));}
 Ferry=Solid(W,TEXT("PH01.Ferry"),{11000,0,-12},{220,330,24},TEXT("M_PaintedMetal"));
 for(float Y:{-150.f,150.f}){Child(Ferry,{0,Y,30},{220,5,5},TEXT("M_Brass"));Child(Ferry,{-95,Y,10},{5,5,40},TEXT("M_Brass"));Child(Ferry,{95,Y,10},{5,5,40},TEXT("M_Brass"));}
 // Repeated structural kit; scenery is instanced and cannot block the lane.
 for(int Bay=0;Bay<19;Bay++){
  float X=Bay*800.f;
  Decor(W,{X,-520,480},{56,70,1040},TEXT("M_Dark"));Decor(W,{X,-580,780},{780,90,60},TEXT("M_Dark"));
  Decor(W,{X+380,-780,420},{740,50,920},TEXT("M_Backdrop"));
  Decor(W,{X+380,-744,555},{330,12,300},TEXT("M_Glass"));
  for(int j=0;j<4;j++)Decor(W,{X+235+j*97,-730,555},{8,12,310},TEXT("M_Dark"));
  Decor(W,{X+380,-725,555},{340,15,9},TEXT("M_Dark"));
  Pipe(W,{X,-320,370},{X+800,-320,370},8);Pipe(W,{X,-360,402},{X+800,-360,402},3);
  for(int j=0;j<4;j++){float XX=X+j*200;Decor(W,{XX,-325,370},{12,25,28},TEXT("M_Dark"));}
  Decor(W,{X+370,-510,52},{640,100,104},TEXT("M_Stone"));
  // Domestic repairs, tiled skirting and distant service rails establish human scale.
  for(int j=0;j<6;j++)Decor(W,{X+80+j*110,-460,106},{102,15,45},j%3==0?TEXT("M_Tile"):TEXT("M_Stone"));
  Pipe(W,{X,-900,240},{X+800,-900,240},2,TEXT("M_Backdrop"));
  Light(W,{X+340,90,330},{.57f,.68f,.72f},220000,850);
  Light(W,{X+380,-620,680},{.48f,.60f,.68f},180000,1200);
  if(Bay%3==0){Decor(W,{X+150,-170,340},{44,44,12},TEXT("M_Dark"));Decor(W,{X+150,-170,329},{23,23,5},TEXT("M_Warm"));Pipe(W,{X+150,-170,348},{X+150,-170,760},1.5,TEXT("M_Dark"));Light(W,{X+150,-110,280},{1,.70f,.40f},95000,460);}
  // Foreground framing leaves the central traversal silhouette exposed.
  if(Bay%2==0){Decor(W,{X-280,410,680},{70,110,180},TEXT("M_Foreground"));Decor(W,{X-155,390,-85},{340,170,120},TEXT("M_Foreground"));}
  if(Bay>=13&&Bay<=14)Decor(W,{X+190,-110,1.1},{270,130,.6},TEXT("M_Wet"),FRotator::ZeroRotator,TEXT("Sphere"));
  // Original folded cloth export. Distant cloth stays outside all collision queries.
  if(Bay%2==1){auto* A=W->SpawnActor<AStaticMeshActor>(FVector(X+380,-420,330),FRotator::ZeroRotator);auto* C=A->GetStaticMeshComponent();C->SetStaticMesh(LoadObject<UStaticMesh>(nullptr,TEXT("/Game/Traversal/SM_Cloth.SM_Cloth")));C->SetMaterial(0,Material(TEXT("M_Fabric")));C->SetCollisionEnabled(ECollisionEnabled::NoCollision);C->SetCastShadow(false);A->Tags.Add(TEXT("PH01.ScenicCloth"));Pipe(W,{X+190,-420,490},{X+570,-420,490},2,TEXT("M_Dark"));}
 }
 // The start is a modest service threshold, not a new story event.
 Decor(W,{20,-300,145},{135,24,290},TEXT("M_Timber"));Decor(W,{20,-280,155},{100,8,210},TEXT("M_Dark"));
 Decor(W,{115,-265,105},{19,16,36},TEXT("M_Porcelain"));
 Decor(W,{13800,-260,155},{145,20,310},TEXT("M_Timber"));Decor(W,{13800,-245,165},{95,12,235},TEXT("M_Warm"));Light(W,{13800,-120,180},{1,.75f,.5f},100000,500);
 auto* Fog=W->SpawnActor<AExponentialHeightFog>();Fog->GetComponent()->SetFogDensity(.012);Fog->GetComponent()->SetFogInscatteringColor({.12f,.17f,.19f});
 auto* Post=W->SpawnActor<APostProcessVolume>();Post->bUnbound=true;Post->Settings.bOverride_AutoExposureMethod=true;Post->Settings.AutoExposureMethod=AEM_Manual;Post->Settings.bOverride_AutoExposureBias=true;Post->Settings.AutoExposureBias=7;
 Post->Settings.bOverride_VignetteIntensity=true;Post->Settings.VignetteIntensity=.25;
 Camera=W->SpawnActor<ACameraActor>(FVector(150,1500,230),FRotator(-5.3,-90,0));Camera->GetCameraComponent()->SetFieldOfView(58.72);Camera->GetCameraComponent()->SetConstraintAspectRatio(false);
 if(auto* PC=UGameplayStatics::GetPlayerController(this,0))PC->SetViewTarget(Camera);
 UE_LOG(LogTemp,Display,TEXT("PH01 build 0.1.0; 60Hz motor; canonical traversal; no Hold or campaign flags"));
}
void AHeldTraversalMode::FixedWorld(float Dt){WorldClock+=Dt;if(Ferry){float X=11200-200*FMath::Cos(WorldClock*.65f);Ferry->SetActorLocation(FVector(X,0,-12));}}
void AHeldTraversalMode::ResetProps(){for(int i=0;i<Props.Num();i++)Props[i]->SetActorLocation(PropStarts[i]);}
void AHeldTraversalMode::Tick(float Dt){
 Super::Tick(Dt);auto* P=Cast<AHeldTraversalCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));if(!P||!Camera)return;
 float X=P->GetActorLocation().X;float Lead=P->Facing*FMath::Clamp(P->GetVelocity().Size2D()*.36f,0.f,160.f);
 CameraX=FMath::FInterpTo(CameraX,FMath::Clamp(X+Lead,300.f,13700.f),Dt,2.85);
 float Z=P->GetActorLocation().Z+150;if(FMath::Abs(Z-CameraZ)>70)CameraZ=FMath::FInterpTo(CameraZ,Z,Dt,2);
 Camera->SetActorLocation(FVector(CameraX,1500,CameraZ));
 if(auto* PC=UGameplayStatics::GetPlayerController(this,0)){int32 W,H;PC->GetViewportSize(W,H);if(H>0){float Aspect=FMath::Clamp(float(W)/H,1.6f,16.f/9);Camera->GetCameraComponent()->SetFieldOfView(FMath::RadiansToDegrees(2*FMath::Atan(FMath::Tan(FMath::DegreesToRadians(17.5f))*Aspect)));Camera->GetCameraComponent()->SetAspectRatio(Aspect);Camera->GetCameraComponent()->SetConstraintAspectRatio(float(W)/H>1.8f);}}
 if(bTest)RunTest(Dt);
 if(bRouteTest)RunRoute(Dt);
}
void AHeldTraversalHUD::DrawHUD(){
 Super::DrawHUD();auto* P=Cast<AHeldTraversalCharacter>(GetOwningPawn());if(!P||!Canvas)return;
 auto* PC=Cast<AHeldTraversalController>(GetOwningPlayerController());bool Pad=PC&&PC->bPad;float S=FMath::Clamp(Canvas->SizeY/900.f,.8f,1.3f);
 if(UGameplayStatics::IsGamePaused(this)){
  DrawRect(FLinearColor(.018,.025,.028,.96),Canvas->SizeX*.22,Canvas->SizeY*.12,Canvas->SizeX*.56,Canvas->SizeY*.78);
  float X=Canvas->SizeX*.27,Y=Canvas->SizeY*.17;DrawText(TEXT("THE HELD / PAUSED"),FLinearColor(.8,.82,.77),X,Y,nullptr,1.4*S);Y+=50*S;
  TArray<FString> Rows={TEXT("Resume"),TEXT("Retry from safe landing"),FString::Printf(TEXT("Grip assistance: %s"),P->bGripToggle?TEXT("toggle"):TEXT("hold")),FString::Printf(TEXT("Sound: %d%%  (Left/Right adjusts)"),FMath::RoundToInt(P->Volume*100))};
  const TCHAR* Names[]={TEXT("Move left"),TEXT("Move right"),TEXT("Jump / climb"),TEXT("Interact / grip"),TEXT("Crouch / descend")};for(int i=0;i<5;i++)Rows.Add(FString::Printf(TEXT("%s: %s"),Names[i],*P->Keys[i].ToString()));Rows.Add(TEXT("Restore default keys"));Rows.Add(TEXT("Quit"));
  for(int i=0;i<Rows.Num();i++){DrawText((P->MenuRow==i?TEXT(">  "):TEXT("   "))+Rows[i],i==P->MenuRow?FLinearColor(.85,.73,.52):FLinearColor(.65,.70,.69),X,Y+i*28*S,nullptr,S);}
  DrawText(P->RemapRow>=0?TEXT("Press a new keyboard key; Esc cancels."):TEXT("Up/Down select. Enter/A confirm. Esc/Menu resumes."),FLinearColor(.7,.75,.73),X,Canvas->SizeY*.84,nullptr,.8*S);return;
 }
 if(GetWorld()->GetTimeSeconds()<9)DrawText(TEXT("THE HELD   /   SERVICE PASSAGE"),FLinearColor(.67,.73,.72),38,30,nullptr,S);
 FString Help;
 float X=P->GetActorLocation().X;
 if(P->bFinished)Help=P->Hint;
 else if(P->bHang)Help=Pad?TEXT("A  Climb    Stick down  Let go"):TEXT("Jump  Climb    Down  Let go");
 else if(P->bLadder)Help=Pad?TEXT("Stick up/down  Climb"):TEXT("W/S or Up/Down  Climb");
 else if(X>600&&X<1550||X>8100&&X<9050)Help=Pad?TEXT("X  Grip the handle, then move"):TEXT("Interact  Grip the handle, then move");
 else if(X>2050&&X<2950)Help=Pad?TEXT("Stick down  Crouch"):TEXT("Down / Crouch  Keep low beneath the pipe");
 else if(X>3350&&X<4050)Help=Pad?TEXT("A  Jump"):TEXT("Jump  Cross the broken floor");
 else if(X>4400&&X<5200)Help=TEXT("Jump toward the ledge. Jump again to climb.");
 else if(X>5900&&X<6600)Help=Pad?TEXT("X  Take the ladder"):TEXT("Interact  Take the ladder");
 else if(X>10400&&X<11800)Help=TEXT("Watch the carrier. Ride, then jump to the far landing.");
 if(GetWorld()->GetTimeSeconds()<P->HintUntil)Help=P->Hint;
 if(!Help.IsEmpty())DrawText(Help,FLinearColor(.72,.76,.73),38,Canvas->SizeY-55,nullptr,.9*S);
}

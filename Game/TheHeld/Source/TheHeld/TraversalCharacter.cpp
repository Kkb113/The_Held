#include "Traversal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "InputActionValue.h"
#include "InputKeyEventArgs.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
#include "Sound/SoundWave.h"
#include "Misc/ConfigCacheIni.h"

void UHeldLaneMotor::TickComponent(float Dt,ELevelTick Type,FActorComponentTickFunction* Fn) {
 auto* P=Cast<AHeldTraversalCharacter>(CharacterOwner); if(!P) return;
 if(UGameplayStatics::IsGamePaused(this)) return;
 if(Dt>.25f)DroppedSteps++;
 Remainder+=FMath::Min(Dt,.25f);
 int32 N=0;
 while(Remainder+1.e-6f>=1.f/60.f && N++<15) {
  constexpr float Step=1.f/60.f;
  PreviousLocation=P->GetActorLocation();
  if(auto* W=Cast<AHeldTraversalMode>(GetWorld()->GetAuthGameMode())) W->FixedWorld(Step);
  Clock+=Step; P->FixedInput(Step);
  Super::TickComponent(Step,Type,Fn); Remainder-=Step;
 }
 if(Remainder>.25f) { DroppedSteps++; Remainder=0; }
}

bool AHeldTraversalController::InputKey(const FInputKeyEventArgs& P) {
 bPad=P.Key.IsGamepadKey();
 auto* C=Cast<AHeldTraversalCharacter>(GetPawn());
 if(C && P.Event==IE_Pressed && IsPaused()) { C->AcceptKey(P.Key); return true; }
 return Super::InputKey(P);
}

AHeldTraversalCharacter::AHeldTraversalCharacter(const FObjectInitializer& Init)
 :Super(Init.SetDefaultSubobjectClass<UHeldLaneMotor>(ACharacter::CharacterMovementComponentName)) {
 PrimaryActorTick.bCanEverTick=true;
 GetCapsuleComponent()->InitCapsuleSize(22,72.5f);
 auto* M=GetCharacterMovement(); M->MaxWalkSpeed=420; M->MinAnalogWalkSpeed=160;
 M->MaxAcceleration=1400; M->BrakingDecelerationWalking=2000; M->GroundFriction=0; M->BrakingFrictionFactor=0;
 M->GravityScale=1800.f/980.f; M->JumpZVelocity=560; M->MaxStepHeight=25;
 M->SetWalkableFloorAngle(42); M->GetNavAgentPropertiesRef().bCanCrouch=true; M->SetCrouchedHalfHeight(44);
 M->MaxWalkSpeedCrouched=125; M->AirControl=.65; M->bConstrainToPlane=true; M->SetPlaneConstraintNormal(FVector(0,1,0));
 M->bSnapToPlaneAtStart=true; M->bUseFlatBaseForFloorChecks=true; M->MaxSimulationTimeStep=1.f/60; M->MaxSimulationIterations=8;
 bUseControllerRotationYaw=false;
}

void AHeldTraversalCharacter::BeginPlay() {
 Super::BeginPlay(); SetActorLocation(SafePoint);
 Figure=NewObject<USceneComponent>(this,TEXT("IvoArticulatedProxy")); Figure->SetupAttachment(GetRootComponent()); Figure->RegisterComponent();
 const TCHAR* Names[]={TEXT("Jacket"),TEXT("Pelvis"),TEXT("Head"),TEXT("Hair"),TEXT("Collar"),TEXT("UpperArmL"),TEXT("ForearmL"),TEXT("HandL"),TEXT("UpperArmR"),TEXT("ForearmR"),TEXT("HandR"),TEXT("ThighL"),TEXT("ShinL"),TEXT("ShoeL"),TEXT("ThighR"),TEXT("ShinR"),TEXT("ShoeR")};
 for(int i=0;i<17;i++) {
  auto* C=NewObject<UStaticMeshComponent>(this,Names[i]); C->SetupAttachment(Figure);
  C->SetStaticMesh(LoadObject<UStaticMesh>(nullptr,TEXT("/Engine/BasicShapes/Sphere.Sphere")));
  if(i==0)if(auto* Garment=LoadObject<UStaticMesh>(nullptr,TEXT("/Game/Traversal/SM_Jacket.SM_Jacket")))C->SetStaticMesh(Garment);
  const TCHAR* Mat=(i==2||i==6||i==7||i==9||i==10)?TEXT("M_Skin"):(i==0||i==5||i==8)?TEXT("M_AshBlue"):i==4?TEXT("M_Porcelain"):TEXT("M_Dark");
  C->SetMaterial(0,LoadObject<UMaterialInterface>(nullptr,*FString::Printf(TEXT("/Game/Traversal/%s.%s"),Mat,Mat)));
  C->SetCollisionEnabled(ECollisionEnabled::NoCollision); C->SetCastShadow(true); C->RegisterComponent(); Body.Add(C);
 }
 if(auto* PC=Cast<APlayerController>(GetController())) PC->SetInputMode(FInputModeGameOnly());
 Hint=TEXT("Follow the service passage. Each obstacle teaches an ordinary action.");
}

void AHeldTraversalCharacter::SetupPlayerInputComponent(UInputComponent* Input) {
 Super::SetupPlayerInputComponent(Input);
 Keys={EKeys::A,EKeys::D,EKeys::SpaceBar,EKeys::E,EKeys::S};
 for(int i=0;i<Keys.Num();i++) { FString K; if(GConfig->GetString(TEXT("PH01.Input"),*FString::FromInt(i),K,GGameUserSettingsIni)) { FKey F(*K); if(F.IsValid()) Keys[i]=F; } }
 GConfig->GetBool(TEXT("PH01.Input"),TEXT("ToggleGrip"),bGripToggle,GGameUserSettingsIni);
 RebuildBindings();
}

void AHeldTraversalCharacter::RebuildBindings() {
 auto* E=Cast<UEnhancedInputComponent>(InputComponent); auto* PC=Cast<APlayerController>(GetController()); if(!E||!PC) return;
 auto* S=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()); if(!S) return;
 if(Mapping) S->RemoveMappingContext(Mapping); E->ClearActionBindings(); Actions.Empty();
 Mapping=NewObject<UInputMappingContext>(this);
 auto Make=[&](const TCHAR* Name,EInputActionValueType T){auto* A=NewObject<UInputAction>(this,Name); A->ValueType=T; A->bTriggerWhenPaused=true; Actions.Add(A); return A;};
 auto* X=Make(TEXT("TraverseHorizontal"),EInputActionValueType::Axis1D);
 Mapping->MapKey(X,Keys[1]); Mapping->MapKey(X,EKeys::Right);
 for(FKey K:{Keys[0],EKeys::Left}) Mapping->MapKey(X,K).Modifiers.Add(NewObject<UInputModifierNegate>(Mapping));
 Mapping->MapKey(X,EKeys::Gamepad_LeftX).Modifiers.Add(NewObject<UInputModifierDeadZone>(Mapping));
 E->BindAction(X,ETriggerEvent::Triggered,this,&AHeldTraversalCharacter::Move); E->BindAction(X,ETriggerEvent::Completed,this,&AHeldTraversalCharacter::Move);
 auto* Y=Make(TEXT("TraverseVertical"),EInputActionValueType::Axis1D);
 Mapping->MapKey(Y,EKeys::W); Mapping->MapKey(Y,EKeys::Up);
 for(FKey K:{Keys[4],EKeys::Down}) Mapping->MapKey(Y,K).Modifiers.Add(NewObject<UInputModifierNegate>(Mapping));
 Mapping->MapKey(Y,EKeys::Gamepad_LeftY).Modifiers.Add(NewObject<UInputModifierDeadZone>(Mapping));
 E->BindAction(Y,ETriggerEvent::Triggered,this,&AHeldTraversalCharacter::Vertical); E->BindAction(Y,ETriggerEvent::Completed,this,&AHeldTraversalCharacter::Vertical);
 auto* J=Make(TEXT("TraverseJump"),EInputActionValueType::Boolean); Mapping->MapKey(J,Keys[2]); Mapping->MapKey(J,EKeys::Gamepad_FaceButton_Bottom); E->BindAction(J,ETriggerEvent::Started,this,&AHeldTraversalCharacter::JumpPressed);
 auto* I=Make(TEXT("TraverseInteract"),EInputActionValueType::Boolean); Mapping->MapKey(I,Keys[3]); Mapping->MapKey(I,EKeys::Gamepad_FaceButton_Left); E->BindAction(I,ETriggerEvent::Started,this,&AHeldTraversalCharacter::InteractPressed); E->BindAction(I,ETriggerEvent::Completed,this,&AHeldTraversalCharacter::InteractReleased);
 auto* P=Make(TEXT("TraversePause"),EInputActionValueType::Boolean); Mapping->MapKey(P,EKeys::Escape); Mapping->MapKey(P,EKeys::Gamepad_Special_Right); E->BindAction(P,ETriggerEvent::Started,this,&AHeldTraversalCharacter::Pause);
 S->AddMappingContext(Mapping,0);
}

void AHeldTraversalCharacter::Move(const FInputActionValue& V) {Axis=V.Get<float>();}
void AHeldTraversalCharacter::Vertical(const FInputActionValue& V) {UpAxis=V.Get<float>();}
void AHeldTraversalCharacter::JumpPressed() {
 if(UGameplayStatics::IsGamePaused(this)) return;
 if(bHang) {
  FVector End=HangTarget+FVector(Facing*44,0,75),Above=GetActorLocation();Above.Z=End.Z;
  FCollisionQueryParams Q;Q.AddIgnoredActor(this);FHitResult Hit;auto Shape=FCollisionShape::MakeCapsule(22,72.5f);
  if(GetWorld()->SweepSingleByChannel(Hit,GetActorLocation(),Above,FQuat::Identity,ECC_Pawn,Shape,Q)||GetWorld()->SweepSingleByChannel(Hit,Above,End,FQuat::Identity,ECC_Pawn,Shape,Q)) {Hint=TEXT("Not enough clearance. Move the obstruction out from under the beam.");HintUntil=GetWorld()->GetTimeSeconds()+4;return;}
  bHang=false; bClimbing=true; ClimbTime=0; ClimbStart=GetActorLocation(); ClimbEnd=End; Seen.Add(TEXT("LedgeClimb")); return;
 }
 if(bLadder) { bLadder=false; GetCharacterMovement()->SetMovementMode(MOVE_Falling); }
 JumpUntil=Cast<UHeldLaneMotor>(GetCharacterMovement())->Clock+.12;
}
void AHeldTraversalCharacter::InteractPressed() {
 if(UGameplayStatics::IsGamePaused(this)) return;
 if(bHang||bClimbing)return;
 if(Grip) {if(bGripToggle){Grip=nullptr;bInteracting=false;}return;}
 if(bLadder) {bLadder=false;GetCharacterMovement()->SetMovementMode(MOVE_Falling);return;}
 auto* W=Cast<AHeldTraversalMode>(GetWorld()->GetAuthGameMode()); if(!W) return;
 const FVector P=GetActorLocation();
 if(FMath::Abs(P.X-6300)<100 && P.Z<365) {bLadder=true;UnCrouch(); LadderBottom={6300,0,76}; LadderTop={6300,0,356};GetCharacterMovement()->SetMovementMode(MOVE_Flying);SetActorLocation(FVector(6300,0,FMath::Clamp(P.Z,76.,356.)));Seen.Add(TEXT("Ladder"));Cue(TEXT("A_Grip"));return;}
 for(auto Prop:W->Props) if(FMath::Abs(P.X-Prop->GetActorLocation().X)<130 && FMath::Abs(P.Z-Prop->GetActorLocation().Z)<140) {
  Grip=Prop; bInteracting=true; Seen.Add(Prop->ActorHasTag(TEXT("Light"))?TEXT("LightGrip"):TEXT("HeavyPush")); Cue(TEXT("A_Grip"));return;
 }
 Hint=TEXT("The handle must be within reach. Face the object and move closer.");
}
void AHeldTraversalCharacter::InteractReleased() {if(!bGripToggle){bInteracting=false;Grip=nullptr;}}
void AHeldTraversalCharacter::Pause() { Axis=UpAxis=0; JumpUntil=-1; bInteracting=false;Grip=nullptr; UGameplayStatics::SetGamePaused(this,!UGameplayStatics::IsGamePaused(this)); }
void AHeldTraversalCharacter::AcceptKey(FKey Key) {
 if(RemapRow>=0) {
  if(Key!=EKeys::Escape && !Key.IsGamepadKey() && !Key.IsMouseButton()) {
   if(Key==EKeys::W||Key==EKeys::Up||Key==EKeys::Down||Key==EKeys::Left||Key==EKeys::Right||Key==EKeys::Q||Key==EKeys::Tab){Hint=TEXT("Reserved navigation or future Hold key; choose another key.");return;}
   bool Duplicate=false;for(int i=0;i<Keys.Num();i++)if(i!=RemapRow&&Keys[i]==Key)Duplicate=true;
   if(Duplicate){Hint=TEXT("That key is already assigned.");return;}
   Keys[RemapRow]=Key;GConfig->SetString(TEXT("PH01.Input"),*FString::FromInt(RemapRow),*Key.ToString(),GGameUserSettingsIni);GConfig->Flush(false,GGameUserSettingsIni);RebuildBindings();
  } RemapRow=-1;return;
 }
 if(Key==EKeys::Escape||Key==EKeys::Gamepad_Special_Right){Pause();return;}
 if(Key==EKeys::Up||Key==EKeys::Gamepad_DPad_Up){MenuRow=(MenuRow+10)%11;return;}
 if(Key==EKeys::Down||Key==EKeys::Gamepad_DPad_Down){MenuRow=(MenuRow+1)%11;return;}
 if(Key==EKeys::Left||Key==EKeys::Right){Volume=FMath::Clamp(Volume+(Key==EKeys::Right?.1f:-.1f),0.f,1.f);return;}
 if(Key!=EKeys::Enter&&Key!=EKeys::Gamepad_FaceButton_Bottom)return;
 if(MenuRow==0)Pause();
 else if(MenuRow==1){Pause();Retry();}
 else if(MenuRow==2){bGripToggle=!bGripToggle;GConfig->SetBool(TEXT("PH01.Input"),TEXT("ToggleGrip"),bGripToggle,GGameUserSettingsIni);GConfig->Flush(false,GGameUserSettingsIni);}
 else if(MenuRow==3)Volume=Volume>0?0:.5;
 else if(MenuRow>=4&&MenuRow<=8)RemapRow=MenuRow-4;
 else if(MenuRow==9){Keys={EKeys::A,EKeys::D,EKeys::SpaceBar,EKeys::E,EKeys::S};for(int i=0;i<5;i++)GConfig->SetString(TEXT("PH01.Input"),*FString::FromInt(i),*Keys[i].ToString(),GGameUserSettingsIni);GConfig->Flush(false,GGameUserSettingsIni);RebuildBindings();}
 else if(MenuRow==10)Cast<APlayerController>(GetController())->ConsoleCommand(TEXT("quit"));
}
void AHeldTraversalCharacter::Retry() {
 Grip=nullptr;bInteracting=bLadder=bHang=bClimbing=false;Axis=UpAxis=0;JumpUntil=-1;
 GetCharacterMovement()->StopMovementImmediately();GetCharacterMovement()->SetMovementMode(MOVE_Walking);UnCrouch();SetActorLocation(SafePoint);
 Cue(TEXT("A_Grip"),.4);Seen.Add(TEXT("Retry"));
}
void AHeldTraversalCharacter::Cue(const TCHAR* Name,float Gain) {
 if(auto* S=LoadObject<USoundWave>(nullptr,*FString::Printf(TEXT("/Game/Traversal/%s.%s"),Name,Name))) UGameplayStatics::PlaySound2D(this,S,Volume*Gain);
}

void AHeldTraversalCharacter::TryLedge() {
 if(GetCharacterMovement()->Velocity.Z>150 || bIsCrouched)return;
 FVector P=GetActorLocation(); FHitResult Wall,Top;FCollisionQueryParams Q;Q.AddIgnoredActor(this);
 if(!GetWorld()->LineTraceSingleByChannel(Wall,P+FVector(0,0,-20),P+FVector(Facing*58,0,-20),ECC_Visibility,Q))return;
 if(!Wall.GetActor()||!Wall.GetActor()->ActorHasTag(TEXT("Ledge")))return;
 FVector Above=Wall.ImpactPoint+FVector(Facing*12,0,145);
 if(!GetWorld()->LineTraceSingleByChannel(Top,Above,Above-FVector(0,0,150),ECC_Visibility,Q)||Top.ImpactNormal.Z<.75)return;
 if(Top.ImpactPoint.Z-P.Z< -35||Top.ImpactPoint.Z-P.Z>95)return;
 HangTarget=Top.ImpactPoint-FVector(Facing*12,0,0);
 bHang=true;Grip=nullptr;GetCharacterMovement()->StopMovementImmediately();GetCharacterMovement()->SetMovementMode(MOVE_Flying);
 FVector Hang=HangTarget+FVector(-Facing*25,0,-60);Hang.Z=FMath::Max(Hang.Z,74.5);SetActorLocation(Hang);Seen.Add(TEXT("LedgeHang"));Cue(TEXT("A_Grip"));
}

void AHeldTraversalCharacter::FixedInput(float Dt) {
 auto* M=GetCharacterMovement(); const float Now=Cast<UHeldLaneMotor>(M)->Clock;
 if(bClimbing){ClimbTime+=Dt;float A=FMath::Clamp(ClimbTime/.4f,0.f,1.f);FVector Above=ClimbStart;Above.Z=ClimbEnd.Z;FVector T=A<.65f?FMath::Lerp(ClimbStart,Above,A/.65f):FMath::Lerp(Above,ClimbEnd,(A-.65f)/.35f);SetActorLocation(T,false);if(A>=1){bClimbing=false;M->SetMovementMode(MOVE_Walking);}State=TEXT("Climb");return;}
 if(bHang){State=TEXT("LedgeHang");if(UpAxis<-.5){bHang=false;M->SetMovementMode(MOVE_Falling);SetActorLocation(GetActorLocation()-FVector(Facing*10,0,0));}return;}
 if(bLadder){State=TEXT("Ladder");M->Velocity=FVector::ZeroVector;FVector P=GetActorLocation();float Input=UpAxis;if(FMath::Abs(Input)<.1&&JumpUntil>Now)Input=1;P.Z=FMath::Clamp(P.Z+Input*150*Dt,LadderBottom.Z,LadderTop.Z);SetActorLocation(P);if(P.Z>=LadderTop.Z-.1&&Input>0){bLadder=false;SetActorLocation(FVector(6360,0,356));M->SetMovementMode(MOVE_Walking);}if(P.Z<=LadderBottom.Z+.1&&Input<0){bLadder=false;M->SetMovementMode(MOVE_Walking);}return;}
 if(FMath::Abs(Axis)>.1)Facing=FMath::Sign(Axis);
 if(UpAxis<-.3){Crouch();Seen.Add(TEXT("Crouch"));}else UnCrouch();
 const bool Ground=M->IsMovingOnGround();if(Ground)LastGround=Now;
 if(Ground&&!bWasGrounded){LandPulse=1;Cue(TEXT("A_Land"),.6);Seen.Add(TEXT("Land"));}bWasGrounded=Ground;
 if(JumpUntil>=Now && Now-LastGround<=.10 && !bIsCrouched && !Grip){M->Velocity.Z=560;M->SetMovementMode(MOVE_Falling);JumpUntil=-1;LastGround=-1;Seen.Add(TEXT("Jump"));}
 M->MaxWalkSpeed=420;
 if(Grip) {
  Facing=FMath::Sign(Grip->GetActorLocation().X-GetActorLocation().X);
  State=TEXT("GripMove");M->MaxWalkSpeed=Grip->ActorHasTag(TEXT("Light"))?125:85;
  float Min=Grip->ActorHasTag(TEXT("Light"))?900:8300,Max=Grip->ActorHasTag(TEXT("Light"))?1450:8930;
  FVector Old=Grip->GetActorLocation(),Next=Old;Next.X=FMath::Clamp(Next.X+Axis*M->MaxWalkSpeed*Dt,Min,Max);
  Grip->SetActorLocation(Next);float Applied=Next.X-Old.X;
  if(FMath::Abs(Applied)>.001){FVector Before=GetActorLocation();FHitResult H;AddActorWorldOffset(FVector(Applied,0,0),true,&H);if(H.bBlockingHit){Grip->SetActorLocation(Old);SetActorLocation(Before);}}
  M->Velocity.X=0; return;
 }
 State=bIsCrouched?TEXT("Crouched"):Ground?TEXT("Grounded"):TEXT("Airborne");
 AddMovementInput(FVector(1,0,0),Axis);
 if(!Ground)TryLedge();
 if(Ground && GetActorLocation().Z>0 && FMath::Abs(Axis)>.1 && M->Velocity.Size2D()>20){StepPhase+=Dt*M->Velocity.Size2D()/145; if(StepPhase>=1){StepPhase-=1;Cue(TEXT("A_Step"),bIsCrouched?.25:.5);}}
 if(GetActorLocation().Z<-260 || (Ground&&GetActorLocation().Z< -60))Retry();
 if(GetActorLocation().X>13800&&!bFinished){bFinished=true;Hint=TEXT("Passage complete. Explore back, or pause to retry. PH02 Hold is not active.");Cue(TEXT("A_Grip"));Seen.Add(TEXT("RouteComplete"));}
 if(Ground){for(float X:{3200.f,5500.f,7600.f,10000.f,12400.f})if(FMath::Abs(GetActorLocation().X-X)<30)SafePoint=GetActorLocation()+FVector(0,0,2);}
}

void AHeldTraversalCharacter::Tick(float Dt){Super::Tick(Dt);Pose(Dt);}
void AHeldTraversalCharacter::Pose(float Dt) {
 if(Body.Num()!=17)return;
 float Speed=GetCharacterMovement()->Velocity.Size2D();static const float Pi=PI;
 float T=GetWorld()->GetTimeSeconds();float Phase=T*(Speed>180?10:7);float Swing=FMath::Sin(Phase)*FMath::Clamp(Speed/420.f,0.f,1.f);
 float C=bIsCrouched?1:0;LandPulse=FMath::Max(0.f,LandPulse-Dt*5);
 auto* Motor=Cast<UHeldLaneMotor>(GetCharacterMovement());FVector VisualDelta=FVector::ZeroVector;
 if(FVector::DistSquared(Motor->PreviousLocation,GetActorLocation())<10000)VisualDelta=FMath::Lerp(Motor->PreviousLocation,GetActorLocation(),FMath::Clamp(Motor->Remainder*60,0.f,1.f))-GetActorLocation();
 Figure->SetRelativeLocation(VisualDelta+FVector(0,0,-GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));Figure->SetRelativeRotation(FRotator(0,Facing>0?0:180,0));
 auto P=[&](int I,FVector At,FVector Size){Body[I]->SetRelativeLocation(At);Body[I]->SetRelativeScale3D(Size/100);};
 auto Bone=[&](int I,FVector A,FVector B,float R){FVector D=B-A;P(I,(A+B)*.5,FVector(R,R,D.Size()+R*.65));Body[I]->SetRelativeRotation(FRotationMatrix::MakeFromZ(D).Rotator());};
 float Hip=75-C*40-LandPulse*3,Shoulder=119-C*65-LandPulse*3;
 float Lean=C*22+FMath::Clamp(Axis*Speed/70.f,-6.f,6.f);if(Grip)Lean=20;
 P(0,{Lean*.5f,0,(Hip+Shoulder)*.5f},{25,29,Shoulder-Hip+14});P(1,{0,0,Hip},{22,25,24});
 P(2,{Lean+2,0,Shoulder+20},{21,22,27});P(3,{Lean,0,Shoulder+25},{23,24,14});P(4,{Lean,0,Shoulder+2},{15,19,8});
 for(int Side=0;Side<2;Side++){
  float S=Side==0?1:-1,Y=S*9,A=Swing*S;
  FVector Foot(A*27,Y,7),Knee(-A*9+C*25,Y,37-C*6),H(0,Y,Hip);
  if(!GetCharacterMovement()->IsMovingOnGround()){Foot.X=-10-S*8;Foot.Z=22;Knee.X=18;}
  if(bLadder){Foot={15,Y,18+(FMath::Sin(T*7+Side*Pi)+1)*22};Knee={30,Y,50};}
  Bone(11+Side*3,H,Knee,12);Bone(12+Side*3,Knee,Foot,10);P(13+Side*3,Foot+FVector(5,0,0),{22,12,12});
  FVector ShoulderP(Lean,Y*1.8f,Shoulder),Elbow(-A*13,Y*1.9f,Shoulder-23+C*8),Hand(-A*22,Y*1.8f,Shoulder-45+C*12);
  if(Grip){Hand={42,Y*1.7f,95};Elbow={25,Y*2,Shoulder-15};}
  if(bHang||bClimbing){float ContactHeight=HangTarget.Z-(GetActorLocation().Z-GetCapsuleComponent()->GetScaledCapsuleHalfHeight());Hand={25,Y*1.8f,ContactHeight};Elbow={15,Y*2,(Shoulder+ContactHeight)*.5f};}
  if(bLadder){Hand={26,Y*1.8f,125+FMath::Sin(T*7+Side*Pi)*18};Elbow={32,Y*2,110};}
  Bone(5+Side*3,ShoulderP,Elbow,11);Bone(6+Side*3,Elbow,Hand,8);P(7+Side*3,Hand,{9,7,12});
 }
}

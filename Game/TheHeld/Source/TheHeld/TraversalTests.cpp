#include "Traversal.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/PlatformMemory.h"
#include "RenderTimer.h"
#include "DynamicRHI.h"
#include "Components/StaticMeshComponent.h"
#include "Misc/App.h"
#include "InputKeyEventArgs.h"

// Rendered integration fixtures in the real route. Teleports establish each fixture;
// these checks must never be reported as a human or uninterrupted route playthrough.
void AHeldTraversalMode::RunTest(float Dt){
 auto* P=Cast<AHeldTraversalCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));if(!P)return;
 TestClock+=UGameplayStatics::IsGamePaused(this)?FApp::GetDeltaTime():Dt;if(TestStage>0&&Dt>0){FrameTimes.Add(Dt*1000);GameTimes.Add(FPlatformTime::ToMilliseconds(GGameThreadTime));uint32 GPU=RHIGetGPUFrameCycles();if(GPU>0)GPUTimes.Add(FPlatformTime::ToMilliseconds(GPU));}
 auto Next=[&](){TestStage++;TestClock=0;P->Axis=P->UpAxis=0;};
 auto Place=[&](FVector V){P->Grip=nullptr;P->bHang=P->bClimbing=P->bLadder=false;P->GetCharacterMovement()->StopMovementImmediately();P->GetCharacterMovement()->SetMovementMode(MOVE_Walking);P->SetActorLocation(V);};
 static float StartX=0,Peak=0,Offset=0;
 auto Key=[&](FKey K,EInputEvent E){if(auto* PC=Cast<AHeldTraversalController>(P->GetController()))PC->InputKey(FInputKeyEventArgs(nullptr,FInputDeviceId::CreateFromInternalId(0),K,E,E==IE_Released?0.f:1.f,false,FPlatformTime::Cycles64()));};
 switch(TestStage){
 case 0:if(TestClock>2){Place({150,0,76});StartX=150;Next();}break;
 case 1:P->Axis=1;if(TestClock>2){Results.Add(TEXT("acceleration_run"),P->GetActorLocation().X-StartX>690&&P->GetActorLocation().X-StartX<840);Next();Place({1800,0,76});}break;
 case 2:if(TestClock>.15&&TestClock<.20){P->JumpPressed();Peak=0;}Peak=FMath::Max(Peak,float(P->GetActorLocation().Z));if(TestClock>1.6){Results.Add(TEXT("jump_height"),Peak>145&&Peak<170);Results.Add(TEXT("landing"),P->GetCharacterMovement()->IsMovingOnGround());Next();P->Crouch();}break;
 case 3:if(TestClock<.2)P->UpAxis=-1;else if(TestClock<.3)Place({2550,0,46});else P->UpAxis=0;if(TestClock>1){Results.Add(TEXT("blocked_uncrouch"),P->bIsCrouched);if(auto* PC=UGameplayStatics::GetPlayerController(this,0))PC->ConsoleCommand(TEXT("HighResShot 1"));Next();P->UpAxis=-1;}break;
 case 4:P->UpAxis=-1;P->Axis=1;if(TestClock>3.8){P->UpAxis=0;Next();}break;
 case 5:if(TestClock>1){Results.Add(TEXT("clear_uncrouch"),!P->bIsCrouched);Place({4605,0,55});P->Facing=1;P->GetCharacterMovement()->SetMovementMode(MOVE_Falling);Next();}break;
 case 6:if(P->bHang){Results.Add(TEXT("ledge_catch"),true);P->JumpPressed();}if(TestClock>1.5){Results.Add(TEXT("ledge_climb"),P->GetActorLocation().X>4650&&P->GetActorLocation().Z>170);Place({6300,0,76});Next();P->InteractPressed();}break;
 case 7:P->UpAxis=1;if(TestClock>2.2){Results.Add(TEXT("ladder_up"),P->GetActorLocation().Z>340&&!P->bLadder);Next();P->InteractPressed();}break;
 case 8:P->UpAxis=-1;if(TestClock>2.3){Results.Add(TEXT("ladder_down"),P->GetActorLocation().Z<90&&!P->bLadder);Place({985,0,76});Next();P->InteractPressed();StartX=Props[0]->GetActorLocation().X;}break;
 case 9:P->Axis=1;if(TestClock>2){Results.Add(TEXT("light_grip"),Props[0]->GetActorLocation().X>StartX+150);P->InteractReleased();Place({8380,0,76});Next();P->InteractPressed();StartX=Props[1]->GetActorLocation().X;}break;
 case 10:P->Axis=1;if(TestClock>2){Results.Add(TEXT("heavy_push"),Props[1]->GetActorLocation().X>StartX+120&&Props[1]->GetActorLocation().X<StartX+190);P->InteractReleased();Place({Ferry->GetActorLocation().X,0,76});Next();}break;
 case 11:if(TestClock>.5&&TestClock<.6)Offset=P->GetActorLocation().X-Ferry->GetActorLocation().X;if(TestClock>3){Results.Add(TEXT("carrier_ride"),FMath::Abs(P->GetActorLocation().X-Ferry->GetActorLocation().X-Offset)<5&&P->GetActorLocation().Z>65);P->JumpPressed();Next();}break;
 case 12:if(TestClock>.15){Results.Add(TEXT("carrier_departure"),P->GetActorLocation().Z>110&&FMath::Abs(P->GetVelocity().X)<600);Next();P->Retry();}break;
 case 13:if(TestClock>1){Results.Add(TEXT("retry"),FVector::Dist(P->GetActorLocation(),P->SafePoint)<8);Place({2900,0,76});Next();}break;
 case 14:if(TestClock>1){if(auto* PC=UGameplayStatics::GetPlayerController(this,0))PC->ConsoleCommand(TEXT("HighResShot 1"));Next();}break;
 case 15:if(TestClock>2){Next();Place({1800,0,240});P->GetCharacterMovement()->SetMovementMode(MOVE_Falling);Results.Add(TEXT("buffered_landing_jump"),false);}break;
 case 16:if(P->GetActorLocation().Z<125&&P->GetVelocity().Z<0)P->JumpPressed();if(TestClock>.4&&P->GetVelocity().Z>300)Results[TEXT("buffered_landing_jump")]=true;if(TestClock>1.7){Next();Place({3670,0,76});Results.Add(TEXT("coyote_jump"),false);}break;
 case 17:P->Axis=1;if(P->GetCharacterMovement()->IsFalling()&&P->GetActorLocation().X<3740)P->JumpPressed();if(P->GetVelocity().Z>300)Results[TEXT("coyote_jump")]=true;if(TestClock>1.5){Next();Place({7830,0,76});}break;
 case 18:P->Axis=-1;if(TestClock>2.3){Results.Add(TEXT("reverse_stairs"),P->GetActorLocation().X<7100&&P->GetActorLocation().Z>330);Next();Place({12330,0,76});}break;
 case 19:P->Axis=1;if(TestClock>1.4){Results.Add(TEXT("slope_up"),P->GetActorLocation().Z>190);Next();}break;
 case 20:P->Axis=-1;if(TestClock>2){Results.Add(TEXT("slope_down"),P->GetActorLocation().Z<90&&P->GetCharacterMovement()->IsMovingOnGround());Next();StartX=WorldClock;P->Pause();}break;
 case 21:if(TestClock>1){Results.Add(TEXT("pause_freezes_process"),FMath::Abs(WorldClock-StartX)<.0001);P->Pause();Next();}break;
 case 22:if(TestClock>.3){Place({1800,0,76});StartX=1800;Next();Key(P->Keys[1],IE_Pressed);}break;
 case 23:if(TestClock>1){Results.Add(TEXT("enhanced_input_key_path"),P->GetActorLocation().X>StartX+300);Key(P->Keys[1],IE_Released);Next();}break;
 case 24:if(TestClock>.4){Results.Add(TEXT("input_release_stops"),FMath::Abs(P->GetVelocity().X)<1);P->Pause();bool Old=P->bGripToggle;P->MenuRow=2;P->AcceptKey(EKeys::Enter);Results.Add(TEXT("toggle_grip_setting"),P->bGripToggle!=Old);P->AcceptKey(EKeys::Enter);FKey OldKey=P->Keys[2];P->RemapRow=2;P->AcceptKey(EKeys::F9);Results.Add(TEXT("remap_key"),P->Keys[2]==EKeys::F9);P->RemapRow=2;P->AcceptKey(OldKey);P->Pause();Next();Key(EKeys::Gamepad_FaceButton_Bottom,IE_Pressed);}break;
 case 25:if(TestClock>.1){auto* PC=Cast<AHeldTraversalController>(P->GetController());Results.Add(TEXT("synthetic_device_glyph_switch"),PC&&PC->bPad);Key(EKeys::Gamepad_FaceButton_Bottom,IE_Released);Next();}break;
 case 26:if(TestClock>.5){ResetProps();Place({1042.5,0,74.5});P->bHang=true;P->HangTarget={1067.5,0,100};P->Facing=1;P->GetCharacterMovement()->SetMovementMode(MOVE_Flying);P->JumpPressed();Results.Add(TEXT("blocked_climb_clearance"),P->bHang&&!P->bClimbing);P->Retry();Next();}break;
 case 27:if(TestClock>.3){Place({8380,0,76});P->InteractPressed();Next();}break;
 case 28:P->Axis=-1;if(TestClock>.5){Results.Add(TEXT("reverse_grip_contact"),P->Facing>0&&Props[1]->GetActorLocation().X<8490);P->InteractReleased();Next();}break;
 case 29:if(TestClock>.2)FinishTest();break;
 }
}
void AHeldTraversalMode::FinishTest(){
 auto* P=Cast<AHeldTraversalCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));bool Pass=true;FString Json=TEXT("{\n  \"kind\":\"rendered integration fixtures; not physical input or uninterrupted playthrough\",\n  \"checks\":{\n");
 int I=0;for(auto& Pair:Results){Pass&=Pair.Value;Json+=FString::Printf(TEXT("    \"%s\":%s%s\n"),*Pair.Key,Pair.Value?TEXT("true"):TEXT("false"),++I<Results.Num()?TEXT(","):TEXT(""));}
 FrameTimes.Sort();auto Quant=[&](float Q){return FrameTimes.Num()?FrameTimes[FMath::Clamp(int(FrameTimes.Num()*Q),0,FrameTimes.Num()-1)]:0;};
 GameTimes.Sort();GPUTimes.Sort();auto Percent=[](const TArray<float>& Values,float Q){return Values.Num()?Values[FMath::Clamp(int(Values.Num()*Q),0,Values.Num()-1)]:-1.f;};
 Json+=FString::Printf(TEXT("  },\n  \"game_thread_ms_p95\":%.3f,\n  \"game_thread_ms_p99\":%.3f,\n  \"gpu_ms_p95\":%.3f,\n  \"gpu_ms_p99\":%.3f,\n  \"metrics\":{\n"),Percent(GameTimes,.95f),Percent(GameTimes,.99f),Percent(GPUTimes,.95f),Percent(GPUTimes,.99f));
 Json+=FString::Printf(TEXT("  },\n  \"all_checks_pass\":%s,\n  \"render_frame_ms_p95\":%.3f,\n  \"render_frame_ms_p99\":%.3f,\n  \"working_set_bytes\":%llu,\n  \"fixed_step_overflows\":%d\n}\n"),Pass?TEXT("true"):TEXT("false"),Quant(.95),Quant(.99),FPlatformMemory::GetStats().UsedPhysical,Cast<UHeldLaneMotor>(P->GetCharacterMovement())->DroppedSteps);
 FFileHelper::SaveStringToFile(Json,*(FPaths::ProjectSavedDir()/TEXT("PH01-test.json")));FPlatformMisc::RequestExit(false);bTest=false;
}

void AHeldTraversalMode::RunRoute(float Dt){
 auto* P=Cast<AHeldTraversalCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));if(!P)return;
 RouteSeconds+=Dt;RouteFrames++;
 float X=P->GetActorLocation().X;auto* M=P->GetCharacterMovement();
 P->Axis=1;P->UpAxis=0;
 if(P->bHang)P->JumpPressed();
 if(X>970&&X<1510){
  if(Props[0]->GetActorLocation().X<1420){if(!P->Grip)P->InteractPressed();}
  else {P->InteractReleased();if(M->IsMovingOnGround())P->JumpPressed();}
 }
 if(X>2150&&X<2910)P->UpAxis=-1;
 if(X>3635&&X<3690&&M->IsMovingOnGround())P->JumpPressed();
 if(X>4530&&X<4650&&M->IsMovingOnGround())P->JumpPressed();
 if(X>6210&&X<6350&&P->GetActorLocation().Z<350){if(!P->bLadder)P->InteractPressed();P->Axis=0;P->UpAxis=1;}
 if(P->bLadder){P->Axis=0;P->UpAxis=1;}
 if(X>8370&&X<9000){if(Props[1]->GetActorLocation().X<8920){if(!P->Grip)P->InteractPressed();}else{P->InteractReleased();if(M->IsMovingOnGround())P->JumpPressed();}}
 if(X>10820&&X<10900){if(Ferry->GetActorLocation().X>11040)P->Axis=0;else if(M->IsMovingOnGround())P->JumpPressed();}
 if(P->GetMovementBase()&&P->GetMovementBase()->GetOwner()==Ferry){P->Axis=0;if(Ferry->GetActorLocation().X>11300){P->Axis=1;P->JumpPressed();}}
 if(RouteFrames%180==0)UE_LOG(LogTemp,Display,TEXT("PH01_ROUTE t=%.1f x=%.1f z=%.1f state=%s"),RouteSeconds,X,P->GetActorLocation().Z,*P->State);
 if(P->bFinished||RouteSeconds>160){
  FString R=FString::Printf(TEXT("{\"route_completed\":%s,\"seconds\":%.2f,\"x\":%.2f,\"kind\":\"automated forward route using bound-action handlers; no fixture teleport\"}"),P->bFinished?TEXT("true"):TEXT("false"),RouteSeconds,X);
  FFileHelper::SaveStringToFile(R,*(FPaths::ProjectSavedDir()/TEXT("PH01-route.json")));FPlatformMisc::RequestExit(false);bRouteTest=false;
 }
}

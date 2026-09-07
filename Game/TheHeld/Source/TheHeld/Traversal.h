#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerController.h"
#include "Traversal.generated.h"

class UInputMappingContext; class UInputAction; class UStaticMeshComponent; class ACameraActor;
class UInstancedStaticMeshComponent;
struct FInputActionValue;

UCLASS()
class UHeldLaneMotor : public UCharacterMovementComponent {
 GENERATED_BODY()
public:
 virtual void TickComponent(float Dt,ELevelTick TickType,FActorComponentTickFunction* Fn) override;
 float Remainder=0; double Clock=0; int32 DroppedSteps=0;
 FVector PreviousLocation=FVector::ZeroVector;
};

UCLASS()
class AHeldTraversalController : public APlayerController {
 GENERATED_BODY()
public:
 virtual bool InputKey(const FInputKeyEventArgs& Params) override;
 bool bPad=false;
};

UCLASS()
class AHeldTraversalCharacter : public ACharacter {
 GENERATED_BODY()
public:
 AHeldTraversalCharacter(const FObjectInitializer& Init);
 virtual void BeginPlay() override;
 virtual void Tick(float Dt) override;
 virtual void SetupPlayerInputComponent(UInputComponent* Input) override;
 void FixedInput(float Dt);
 void Move(const FInputActionValue& V); void Vertical(const FInputActionValue& V);
 void JumpPressed(); void InteractPressed(); void InteractReleased(); void Pause();
 void RebuildBindings(); void AcceptKey(FKey Key);
 void Retry(); void Cue(const TCHAR* Name,float Gain=1);
 FString State=TEXT("Grounded"),Hint;
 float Axis=0,UpAxis=0,Facing=1,Volume=.5f;
 float HintUntil=0;
 bool bGripToggle=false,bInteracting=false,bWasGrounded=false,bFinished=false;
 int32 MenuRow=0,RemapRow=-1;
 TArray<FKey> Keys; TSet<FString> Seen;
 UPROPERTY() TObjectPtr<AActor> Grip;
 UPROPERTY() TObjectPtr<AActor> Carrier;
 FVector LadderBottom,LadderTop;
 bool bLadder=false,bHang=false,bClimbing=false;
 FVector HangTarget,ClimbStart,ClimbEnd;
 float ClimbTime=0,JumpUntil=-1,LastGround=-1,StepPhase=0,LandPulse=0;
 FVector SafePoint=FVector(150,0,76);
 UPROPERTY() TObjectPtr<USceneComponent> Figure;
 UPROPERTY() TArray<TObjectPtr<UStaticMeshComponent>> Body;
 UPROPERTY() TObjectPtr<UInputMappingContext> Mapping;
 UPROPERTY() TArray<TObjectPtr<UInputAction>> Actions;
private:
 void Pose(float Dt); void TryLedge();
};

UCLASS()
class AHeldTraversalMode : public AGameModeBase {
 GENERATED_BODY()
public:
 AHeldTraversalMode(); virtual void BeginPlay() override; virtual void Tick(float Dt) override;
 void FixedWorld(float Dt); void ResetProps();
 UPROPERTY() TObjectPtr<AActor> Ferry;
 UPROPERTY() TArray<TObjectPtr<AActor>> Props;
 TArray<FVector> PropStarts;
 UPROPERTY() TObjectPtr<ACameraActor> Camera;
 float WorldClock=0,CameraX=150,CameraZ=230;
 bool bTest=false; int32 TestStage=0; float TestClock=0;
 bool bRouteTest=false; float RouteSeconds=0; int32 RouteFrames=0;
 TArray<float> FrameTimes;
 TArray<float> GameTimes,GPUTimes;
 TMap<FString,bool> Results;
 UPROPERTY() TMap<FName,TObjectPtr<UInstancedStaticMeshComponent>> Scenery;
 void RunTest(float Dt); void FinishTest();
 void RunRoute(float Dt);
};

UCLASS()
class AHeldTraversalHUD : public AHUD {
 GENERATED_BODY()
public: virtual void DrawHUD() override;
};

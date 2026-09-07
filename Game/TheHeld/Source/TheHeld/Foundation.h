#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/HUD.h"
#include "Foundation.generated.h"

class UStaticMeshComponent;
class UInputAction;
class UInputMappingContext;
class UMaterialInterface;
struct FInputActionValue;

UCLASS()
class AHeldFoundationCharacter : public ACharacter {
    GENERATED_BODY()
public:
    AHeldFoundationCharacter();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
    virtual void SetupPlayerInputComponent(UInputComponent* Input) override;
    void Move(const FInputActionValue& Value);
    void Contact();
    void PauseRoom();
    void RestartRoom();
    void ToggleMute();
    void QuitRoom();
    void AdjustVolume(const FInputActionValue& Value);
    bool bContacted = false;
    float MasterVolume = 0.5f;
    FString Feedback;
    float FeedbackUntil = 0;
private:
    UPROPERTY() TObjectPtr<UInputMappingContext> Mapping;
    UPROPERTY() TArray<TObjectPtr<UInputAction>> Actions;
    UPROPERTY() TObjectPtr<USceneComponent> Figure;
    UPROPERTY() TObjectPtr<UStaticMeshComponent> LeftLeg;
    UPROPERTY() TObjectPtr<UStaticMeshComponent> RightLeg;
    UPROPERTY() TObjectPtr<UStaticMeshComponent> LeftArm;
    UPROPERTY() TObjectPtr<UStaticMeshComponent> RightArm;
    float Gait = 0;
    float Facing = 1;
};

UCLASS()
class AHeldFoundationMode : public AGameModeBase {
    GENERATED_BODY()
public:
    AHeldFoundationMode();
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaSeconds) override;
private:
    UPROPERTY() TObjectPtr<AActor> Platform;
    float Time = 0;
    bool bSmoke = false;
    int32 SmokeStage = 0;
    float SmokeFinishedAt = 0;
};

UCLASS()
class AHeldFoundationHUD : public AHUD {
    GENERATED_BODY()
public:
    virtual void DrawHUD() override;
};

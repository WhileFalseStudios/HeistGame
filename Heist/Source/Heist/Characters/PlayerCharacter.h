// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "Characters/HeistCharacter.h"
#include "Characters/ActionMode.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HEIST_API APlayerCharacter : public AHeistCharacter
{
	GENERATED_BODY()
	
private:

	void ForwardAxis(float axis);
	void RightAxis(float axis);
	void AttackPressed();
	void AttackReleased();
	void AimPressed();
	void AimReleased();
	void RotatePressed();
	void RotateReleased();
	void FastMovePressed();
	void FastMoveReleased();

	void ActionMode1Pressed();
	void ActionMode2Pressed();
	void ActionMode3Pressed();
	void ActionModeTogglePressed();	

	void CameraUpdate(float deltaTime);
	void UpdatePlayerRotation(float deltaTime);

public:

	APlayerCharacter();
	
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	virtual void OnConstruction(const FTransform& transform) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* CameraSpringArm;

	UFUNCTION(Exec)
	void MaimMe(float dmg);

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void Action_Interact();
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void Action_StealthAttack();
	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void Action_LethalAttack();

	UFUNCTION(BlueprintImplementableEvent, Category = "Interaction")
	void ActionModeChanged(EActionMode newMode);

	virtual FGenericTeamId GetGenericTeamId() const override;

	UPROPERTY(BlueprintReadWrite, Category = "Interaction")
	EActionMode ActionMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float NormalMoveSpeed = 300;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float FastMoveSpeed = 400;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FVector InputDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	float CameraPitch = 60;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	float CameraNormalDistance = 1000;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	float CameraDeadDistance = 400;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	float CameraZoomSpeed = 10;

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	bool bRotatingCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	float CameraRotateSpeed;
};

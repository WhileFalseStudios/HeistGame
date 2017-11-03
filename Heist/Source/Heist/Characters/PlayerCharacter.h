// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "Characters/HeistCharacter.h"
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

	void CameraUpdate();
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

protected:

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

	UPROPERTY(BlueprintReadOnly, Category = "Camera")
	bool bRotatingCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	float CameraRotateSpeed;
};

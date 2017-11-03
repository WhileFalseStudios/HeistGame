// Copyright (c) While False Studios 2017.

#include "PlayerCharacter.h"

#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Kismet/KismetMathLibrary.h"

APlayerCharacter::APlayerCharacter() : Super()
{	
	PrimaryActorTick.bCanEverTick = true;
	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraSpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(CameraSpringArm);
}

void APlayerCharacter::OnConstruction(const FTransform& transform)
{
	Super::OnConstruction(transform);
	CameraSpringArm->SetAbsolute(false, true, false);
	CameraSpringArm->TargetArmLength = CameraNormalDistance;
	CameraSpringArm->SetRelativeRotation(FRotator(-CameraPitch, 0, 0));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CameraUpdate();
	GetCharacterMovement()->MaxWalkSpeed = NormalMoveSpeed;
}

void APlayerCharacter::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	CameraUpdate();
	UpdatePlayerRotation(deltaTime);
}

void APlayerCharacter::CameraUpdate()
{
	if (IsValid(GetController()))
	{
		FRotator controllerRot = GetController()->GetControlRotation();
		controllerRot.Pitch = -CameraPitch;
		controllerRot.Roll = 0;
		CameraSpringArm->SetWorldRotation(controllerRot);
		CameraSpringArm->TargetArmLength = CameraNormalDistance;
	}
}

void APlayerCharacter::UpdatePlayerRotation(float deltaTime)
{
	APlayerController* playerController = Cast<APlayerController>(GetController());

	if (IsValid(playerController) && bRotatingCamera)
	{
		float mX = 0;
		float mY = 0;
		playerController->GetInputMouseDelta(mX, mY);
		AddControllerYawInput(mX * CameraRotateSpeed);
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis("Forward", this, &APlayerCharacter::ForwardAxis);
	InputComponent->BindAxis("Right", this, &APlayerCharacter::RightAxis);

	InputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &APlayerCharacter::AttackPressed);
	InputComponent->BindAction("Attack", EInputEvent::IE_Released, this, &APlayerCharacter::AttackReleased);

	InputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &APlayerCharacter::AimPressed);
	InputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &APlayerCharacter::AimReleased);

	InputComponent->BindAction("RotateCamera", EInputEvent::IE_Pressed, this, &APlayerCharacter::RotatePressed);
	InputComponent->BindAction("RotateCamera", EInputEvent::IE_Released, this, &APlayerCharacter::RotateReleased);

	InputComponent->BindAction("FastMove", EInputEvent::IE_Pressed, this, &APlayerCharacter::FastMovePressed);
	InputComponent->BindAction("FastMove", EInputEvent::IE_Released, this, &APlayerCharacter::FastMoveReleased);
}

void APlayerCharacter::ForwardAxis(float axis)
{
	InputDirection.Y = axis;

	FRotator rot = GetController()->GetControlRotation();
	rot.Pitch = 0;
	rot.Roll = 0;
	FVector forward = UKismetMathLibrary::GetForwardVector(rot);	

	if (axis != 0)
	{
		AddMovementInput(forward, axis);
	}
}

void APlayerCharacter::RightAxis(float axis)
{	
	InputDirection.X = axis;

	FRotator rot = GetController()->GetControlRotation();
	rot.Pitch = 0;
	rot.Roll = 0;
	FVector right = UKismetMathLibrary::GetRightVector(rot);

	if (axis != 0)
	{
		AddMovementInput(right, axis);
	}
}

void APlayerCharacter::AttackPressed()
{
}

void APlayerCharacter::AttackReleased()
{
}

void APlayerCharacter::AimPressed()
{
}

void APlayerCharacter::AimReleased()
{
}

void APlayerCharacter::RotatePressed()
{
	bRotatingCamera = true;
}

void APlayerCharacter::RotateReleased()
{
	bRotatingCamera = false;
}

void APlayerCharacter::FastMovePressed()
{
}

void APlayerCharacter::FastMoveReleased()
{
}

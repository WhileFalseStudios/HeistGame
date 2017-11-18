// Copyright (c) While False Studios 2017.

#include "HeistCharacter.h"
#include "HeistCharacterAIController.h"
#include "AIController.h"


// Sets default values
AHeistCharacter::AHeistCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
}

// Called when the game starts or when spawned
void AHeistCharacter::BeginPlay()
{
	Super::BeginPlay();		
}

void AHeistCharacter::SetupHealth()
{
	Health = MaxHealth;
}

// Called every frame
void AHeistCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AHeistCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (bIsDead)
		return 0.0f;

	Health = FMath::Clamp<int32>(Health - DamageAmount, 0, MaxHealth);
	if (Health == 0)
	{
		Death(DamageCauser, DamageAmount, DamageEvent.DamageTypeClass, FVector(), FVector());
	}

	AHeistCharacterAIController* controller = GetHeistController();
	if (IsValid(controller))
	{
		controller->Notify_CharacterTakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	}

	return DamageAmount;
}

void AHeistCharacter::Death_Implementation(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{
	bIsDead = true;
	AHeistCharacterAIController* controller = GetHeistController();
	if (IsValid(controller))
	{
		controller->Notify_CharacterDeath(killer, killingDamage, killingDamageType, damageOrigin, damageForce);
	}
}

AHeistCharacterAIController* AHeistCharacter::GetHeistController()
{
	return Cast<AHeistCharacterAIController>(GetController());
}

FGenericTeamId AHeistCharacter::GetGenericTeamId() const
{
	AAIController* aiController = Cast<AAIController>(GetController());
	if (IsValid(aiController))
	{
		return aiController->GetGenericTeamId();
	}
	else
	{
		return FGenericTeamId::NoTeam;
	}
}
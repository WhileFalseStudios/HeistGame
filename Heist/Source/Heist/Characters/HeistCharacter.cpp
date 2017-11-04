// Copyright (c) While False Studios 2017.

#include "HeistCharacter.h"
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
	Health = MaxHealth;
}

// Called every frame
void AHeistCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHeistCharacter::Death_Implementation(AActor* killer, float killingDamage, const UDamageType* killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{

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
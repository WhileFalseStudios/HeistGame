// Copyright (c) While False Studios 2017.

#include "Defence.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Defences/DefenceAIController.h"

#include "Heist.h"

// Sets default values
ADefence::ADefence()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ADefence::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}

// Called every frame
void ADefence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADefence::Destroyed_Implementation(AActor* killer, float killingDamage, const UDamageType* killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{
	ADefenceAIController* aiController = Cast<ADefenceAIController>(GetController());
	if (IsValid(aiController))
	{
		aiController->PawnKilled();
	}
}

FGenericTeamId ADefence::GetGenericTeamId() const
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

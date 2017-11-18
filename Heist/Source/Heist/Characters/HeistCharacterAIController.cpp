// Copyright (c) While False Studios 2017.

#include "HeistCharacterAIController.h"
#include "Heist.h"
#include "HeistCharacter.h"
#include "HeistTeamInfo.h"

#include "Perception/AIPerceptionComponent.h"

AHeistCharacterAIController::AHeistCharacterAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
}

void AHeistCharacterAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AHeistCharacterAIController::Notify_CharacterTakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogEnemy, Log, TEXT("Ow!"));
}

void AHeistCharacterAIController::Notify_CharacterDeath(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{
	UE_LOG(LogEnemy, Log, TEXT("Agh!"));
}

AHeistCharacter* AHeistCharacterAIController::GetHeistCharacter()
{
	return Cast<AHeistCharacter>(GetPawn());
}
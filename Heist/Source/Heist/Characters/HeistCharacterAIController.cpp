// Copyright (c) While False Studios 2017.

#include "HeistCharacterAIController.h"
#include "Heist.h"
#include "HeistCharacter.h"
#include "HeistTeamInfo.h"

AHeistCharacterAIController::AHeistCharacterAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
}

void AHeistCharacterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(PerceptionComponent))
	{
		//PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AHeistCharacterAIController::PerceptionUpdated);
		PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AHeistCharacterAIController::ActorPerceptionUpdated);
	}
}

void AHeistCharacterAIController::PerceptionUpdated(TArray<AActor*> updatedActors)
{

}

void AHeistCharacterAIController::ActorPerceptionUpdated(AActor* actor, FAIStimulus stimulus)
{
	if (stimulus.WasSuccessfullySensed())
	{
		if (!SensedEnemies.Contains(actor))
		{
			SensedEnemies.Add(actor);
		}		
	}
	else
	{
		if (SensedEnemies.Contains(actor))
		{
			SensedEnemies.Remove(actor);
		}
	}
}

void AHeistCharacterAIController::Notify_CharacterTakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogEnemy, Log, TEXT("Ow!"));
}

void AHeistCharacterAIController::Notify_CharacterDeath(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{
	UE_LOG(LogEnemy, Log, TEXT("Agh!"));
	PawnKilled();
}

AHeistCharacter* AHeistCharacterAIController::GetHeistCharacter()
{
	return Cast<AHeistCharacter>(GetPawn());
}
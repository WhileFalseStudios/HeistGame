// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "HeistCharacterAIController.generated.h"

/**
 * 
 */
UCLASS()
class HEIST_API AHeistCharacterAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	AHeistCharacterAIController();

	void Notify_CharacterTakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	void Notify_CharacterDeath(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce);

	UFUNCTION()
	void PerceptionUpdated(TArray<AActor*> updatedActors);

	UFUNCTION()
	void ActorPerceptionUpdated(AActor* actor, FAIStimulus stimulus);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "AI|Heist Character")
	class AHeistCharacter* GetHeistCharacter();

	UPROPERTY(BlueprintReadOnly, Category = "AI")
	TArray<AActor*> SensedEnemies;
};

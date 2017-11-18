// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "AI|Heist Character")
	class AHeistCharacter* GetHeistCharacter();
};

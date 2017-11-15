// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "HeistCharacter.generated.h"

UCLASS()
class HEIST_API AHeistCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHeistCharacter();

	UFUNCTION(BlueprintPure, Category = "Health")
	int32 GetHealth() { return Health; }

	UFUNCTION(BlueprintPure, Category = "Health")
	bool GetIsDead() { return bIsDead; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual FGenericTeamId GetGenericTeamId() const override;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int32 Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	int32 MaxHealth;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetupHealth();

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	bool bIsDead;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Death(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce);
};

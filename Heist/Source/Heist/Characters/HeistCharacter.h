// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HeistCharacter.generated.h"

UCLASS()
class HEIST_API AHeistCharacter : public ACharacter
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

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int32 Health;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	bool bIsDead;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Death(AActor* killer, float killingDamage, const UDamageType* killingDamageType, const FVector& damageOrigin, const FVector& damageForce);
};

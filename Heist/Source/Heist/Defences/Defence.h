// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GenericTeamAgentInterface.h"
#include "Defence.generated.h"

UCLASS()
class HEIST_API ADefence : public APawn, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

	/*
	Base class for automated defence objects (cameras, turrets etc.)
	Defences can only see, not hear.
	*/

public:
	// Sets default values for this pawn's properties
	ADefence();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	int32 Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	int32 MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sight")
	float SightRange = 600;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sight")
	float LoseSightRange = 1200;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sight")
	float PeripheralVisionAngle = 90.0f;

	UFUNCTION(BlueprintNativeEvent, Category = "Health")
	void Destroyed(AActor* killer, float killingDamage, const UDamageType* killingDamageType, const FVector& damageOrigin, const FVector& damageForce);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	virtual FGenericTeamId GetGenericTeamId() const override;
};

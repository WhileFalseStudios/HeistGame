// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DefenceAIController.generated.h"

/**
 * 
 */
UCLASS()
class HEIST_API ADefenceAIController : public AAIController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	ADefenceAIController();

	UFUNCTION(BlueprintCallable, Category = "AI|Teams")
	void JoinPlayerTeam();

	UFUNCTION(BlueprintCallable, Category = "AI|Teams")
	void JoinSovietsTeam();

	UFUNCTION(BlueprintCallable, Category = "AI|Health")
	void PawnKilled();

	UPROPERTY(BlueprintReadOnly, Category = "AI|Perception")
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(BlueprintReadOnly, Category = "AI|Network")
	bool bPawnIsDisabled;

	UPROPERTY(BlueprintReadOnly, Category = "AI|Health")
	bool bPawnIsDestroyed;

	void DisablePerception();

	void EnablePerception();

protected:
	virtual void OnConstruction(const FTransform& transform) override;
};

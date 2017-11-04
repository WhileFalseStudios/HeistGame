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

protected:
	virtual void OnConstruction(const FTransform& transform) override;
};

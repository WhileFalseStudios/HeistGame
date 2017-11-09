// Copyright (c) While False Studios 2017.

#include "DefenceAIController.h"
#include "HeistTeamInfo.h"
#include "Heist.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

ADefenceAIController::ADefenceAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	PerceptionComponent->ConfigureSense(*SightConfig);
}

void ADefenceAIController::BeginPlay()
{
	if (IsValid(SightConfig))
	{
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		PerceptionComponent->ConfigureSense(*SightConfig);
	}
}

void ADefenceAIController::JoinPlayerTeam()
{
	SetGenericTeamId(HEIST_TEAM_PLAYER);
}

void ADefenceAIController::JoinSovietsTeam()
{
	SetGenericTeamId(HEIST_TEAM_SOVIETS);
}

void ADefenceAIController::PawnKilled()
{
	SetGenericTeamId(HEIST_TEAM_SOVIETS_UNCONSCIOUS);
	bPawnIsDisabled = true;
	bPawnIsDestroyed = true;
}

void ADefenceAIController::DisablePerception()
{
	PerceptionComponent->SetActive(false);
}

void ADefenceAIController::EnablePerception()
{
	PerceptionComponent->SetActive(true);
}

void ADefenceAIController::OnConstruction(const FTransform& transform)
{
	JoinSovietsTeam();	
}
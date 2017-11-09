// Copyright (c) While False Studios 2017.

#include "Defence.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Defences/DefenceAIController.h"

#include "Networks/NetworkConnectedComponent.h"

#include "Heist.h"

// Sets default values
ADefence::ADefence()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NetworkComponent = CreateDefaultSubobject<UNetworkConnectedComponent>(TEXT("Network Component"));	
}

// Called when the game starts or when spawned
void ADefence::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	NetworkComponent->OnEnabledOverNetwork.AddDynamic(this, &ADefence::OnNetworkEnabled);
	NetworkComponent->OnDisabledOverNetwork.AddDynamic(this, &ADefence::OnNetworkDisabled);
}

void ADefence::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	NetworkComponent->DisconnectFromNetwork(); //So we don't leave null pointers lying around.
	NetworkComponent->OnEnabledOverNetwork.RemoveDynamic(this, &ADefence::OnNetworkEnabled);
	NetworkComponent->OnDisabledOverNetwork.RemoveDynamic(this, &ADefence::OnNetworkDisabled);
}

// Called every frame
void ADefence::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ADefence::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (bIsDestroyed)
		return 0.0f;

	Health = FMath::Clamp<int32>(Health - DamageAmount, 0, MaxHealth);
	if (Health == 0)
	{
		Killed(DamageCauser, DamageAmount, DamageEvent.DamageTypeClass, FVector(), FVector());
	}

	return DamageAmount;
}

void ADefence::Killed_Implementation(AActor* killer, float killingDamage, TSubclassOf<UDamageType> killingDamageType, const FVector& damageOrigin, const FVector& damageForce)
{
	ADefenceAIController* aiController = Cast<ADefenceAIController>(GetController());
	if (IsValid(aiController))
	{
		aiController->PawnKilled();
	}
	bIsDestroyed = true;
	NetworkComponent->DisconnectFromNetwork();
}

FGenericTeamId ADefence::GetGenericTeamId() const
{
	AAIController* aiController = Cast<AAIController>(GetController());
	if (IsValid(aiController))
	{
		return aiController->GetGenericTeamId();
	}
	else
	{
		return FGenericTeamId::NoTeam;
	}
}

void ADefence::OnNetworkEnabled()
{
	ADefenceAIController* aiController = Cast<ADefenceAIController>(GetController());
	if (IsValid(aiController))
	{
		aiController->EnablePerception();
	}
}

void ADefence::OnNetworkDisabled()
{
	ADefenceAIController* aiController = Cast<ADefenceAIController>(GetController());
	if (IsValid(aiController))
	{
		aiController->DisablePerception();
	}
}

bool ADefence::GetEnabledOverNetwork()
{
	return NetworkComponent->bIsNetworkEnabled;
}
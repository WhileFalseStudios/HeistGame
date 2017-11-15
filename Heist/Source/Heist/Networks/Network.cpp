// Copyright (c) While False Studios 2017.

#include "Network.h"
#include "NetworkConnectedComponent.h"
#include "Components/BillboardComponent.h"
#include "ConstructorHelpers.h"

#include "Heist.h"

// Sets default values
ANetwork::ANetwork()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

#if WITH_EDITORONLY_DATA

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinder<UTexture2D> Sprite;
		FConstructorStatics() : Sprite(TEXT("Texture2D'/Game/Heist/Textures/Dev/Network.Network'")) {}
	};

	static FConstructorStatics ConstructorStatics;

	BillboardComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Billboard"), true);
	if (IsValid(BillboardComponent))
	{
		BillboardComponent->Sprite = ConstructorStatics.Sprite.Object;
		BillboardComponent->bIsScreenSizeScaled = true;
	}

#endif
}

// Called when the game starts or when spawned
void ANetwork::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANetwork::ConnectNetworkComponent(UNetworkConnectedComponent* component)
{
	if (IsValid(component))
	{
		if (!ConnectedActors.Contains(component))
		{
			ConnectedActors.Add(component);
			UE_LOG(LogHeistNetworks, Log, TEXT("Added %s to network %s"), *component->NetworkName.ToString(), *NetworkDisplayName);
		}
		else
		{
			UE_LOG(LogHeistNetworks, Warning, TEXT("%s was already added to the network %s"), *component->GetOwner()->GetName(), *NetworkDisplayName);
		}
	}
}

void ANetwork::DisconnectNetworkComponent(UNetworkConnectedComponent * component)
{
	if (IsValid(component))
	{
		if (ConnectedActors.Contains(component))
		{
			ConnectedActors.Remove(component);
		}
		else
		{
			UE_LOG(LogHeistNetworks, Warning, TEXT("%s was not part of network %s. Maybe it was already removed?"), *component->GetOwner()->GetName(), *NetworkDisplayName);
		}
	}
}
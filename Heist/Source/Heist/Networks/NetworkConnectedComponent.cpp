// Copyright (c) While False Studios 2017.

#include "NetworkConnectedComponent.h"

#include "Network.h"


// Sets default values for this component's properties
UNetworkConnectedComponent::UNetworkConnectedComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UNetworkConnectedComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(ConnectedNetwork))
	{
		ConnectedNetwork->ConnectNetworkComponent(this);
		bIsNetworkEnabled = true;
	}
}

void UNetworkConnectedComponent::EnabledOverNetwork()
{
	bIsNetworkEnabled = true;
	OnEnabledOverNetwork.Broadcast();
}

void UNetworkConnectedComponent::DisabledOverNetwork()
{
	bIsNetworkEnabled = false;
	OnDisabledOverNetwork.Broadcast();
}

void UNetworkConnectedComponent::DisconnectFromNetwork()
{
	if (IsValid(ConnectedNetwork))
	{
		ConnectedNetwork->DisconnectNetworkComponent(this);
	}
}

// Called every frame
/*
void UNetworkConnectedComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/

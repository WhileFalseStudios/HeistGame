// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NetworkConnectedComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEnabledOverNetworkSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDisabledOverNetworkSignature);

UCLASS( ClassGroup=(Networks), meta=(BlueprintSpawnableComponent) )
class HEIST_API UNetworkConnectedComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNetworkConnectedComponent();

	/**
	Remove the component from the network. Maybe the owner was destroyed or permemantly deactivated.
	*/
	UFUNCTION(BlueprintCallable, Category = "Networks")
	void DisconnectFromNetwork();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Networks")
	void EnabledOverNetwork();

	UFUNCTION(BlueprintCallable, Category = "Networks")
	void DisabledOverNetwork();

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Networks")
	class ANetwork* ConnectedNetwork;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Networks")
	FName NetworkName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Networks")
	FString NetworkDisplayName; //Doesn't really need to be localised.

	UPROPERTY(BlueprintReadOnly, Category = "Networks")
	bool bIsNetworkEnabled;

	UPROPERTY(BlueprintAssignable, Category = "Networks")
	FEnabledOverNetworkSignature OnEnabledOverNetwork;

	UPROPERTY(BlueprintAssignable, Category = "Networks")
	FDisabledOverNetworkSignature OnDisabledOverNetwork;
};

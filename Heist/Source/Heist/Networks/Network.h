// Copyright (c) While False Studios 2017.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Network.generated.h"

UCLASS(ClassGroup=Networks, hidecategories=(Input))
class HEIST_API ANetwork : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANetwork();

#if WITH_EDITORONLY_DATA

	UPROPERTY()
	UBillboardComponent* BillboardComponent;

#endif

	UFUNCTION(BlueprintCallable, Category = "Networks")
	void ConnectNetworkComponent(class UNetworkConnectedComponent* component);

	void DisconnectNetworkComponent(UNetworkConnectedComponent* component);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Networks")
	FString NetworkDisplayName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, Category = "Networks")
	TSet<UNetworkConnectedComponent*> ConnectedActors;

};

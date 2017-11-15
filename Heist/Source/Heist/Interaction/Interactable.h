#pragma once

#include "Interactable.generated.h"

UINTERFACE(BlueprintType)
class HEIST_API UInteractable : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class HEIST_API IInteractable
{
	GENERATED_IINTERFACE_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void CharacterInteraction(class AHeistCharacter* user);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	bool CanInteract(AHeistCharacter* user);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	FString GetInteractableDisplayName();
};
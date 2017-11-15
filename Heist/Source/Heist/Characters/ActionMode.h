#pragma once

#include "ActionMode.generated.h"

UENUM(BlueprintType)
enum class EActionMode : uint8
{
	Interact,
	StealthAttack,
	LethalAttack,
	MAX
};
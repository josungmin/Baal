#pragma once
#include "CoreMinimal.h"


class IStatFormula
{
public:
	virtual ~IStatFormula() = default;
	virtual float Calculate(float BaseValue, float ModifierValue) const = 0;
};

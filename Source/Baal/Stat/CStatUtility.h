#pragma once
#include "CoreMinimal.h"
#include "Stat/Structures/FModifierCalculator.h"


template<typename TModifier>
float CalculateFinalValue(TSet<TModifier>& Modifiers, float BaseValue)
{
    float FinalValue = BaseValue;
    FModifierCalculator StatFormula;

    // Sort by priority
    Modifiers.Sort([](const TModifier& A, const TModifier& B)
    {
        return A.Priority > B.Priority;
    });

    for (const TModifier& Modifier : Modifiers)
    {
        FinalValue = StatFormula.Calculate(Modifier.CalculationFormula, FinalValue, Modifier.Value);
    }

    return FinalValue;
}
#pragma once
#include "CoreMinimal.h"
#include "Stat/Enums/ECalculationFormulaType.h"
#include "Stat/Interfaces/IStatFormula.h"
#include "Utilities/CLog.h"


class FAddFormula : public IStatFormula
{
public:
	virtual float Calculate(float BaseValue, float ModifierValue) const override
	{
		return BaseValue + ModifierValue;
	}
};


class FPercentAddFormula : public IStatFormula
{
public:
	virtual float Calculate(float BaseValue, float ModifierValue) const override
	{
		return BaseValue + (BaseValue * (ModifierValue / 100.0f));
	}
};


class FPercentMultiFormula : public IStatFormula
{
public:
	virtual float Calculate(float BaseValue, float ModifierValue) const override
	{
		return BaseValue * (1.0f + (ModifierValue / 100.0f));
	}
};


///////////////////////////////////////////////////////////////


class FModifierCalculator
{
public:
	FModifierCalculator()
	{
		Formulas.Add(ECalculationFormulaType::Add, MakeShared<FAddFormula>());
		Formulas.Add(ECalculationFormulaType::PercentAdd, MakeShared<FPercentAddFormula>());
		Formulas.Add(ECalculationFormulaType::PercentMulti, MakeShared<FPercentMultiFormula>());
	}

	float Calculate(ECalculationFormulaType FormulaType, float BaseValue, float ModifierValue) const
	{
		const TSharedPtr<IStatFormula>* Formula = Formulas.Find(FormulaType);
		if (Formula != nullptr && Formula->IsValid())
		{
			return Formula->Get()->Calculate(BaseValue, ModifierValue);
		}

		CLog::LogError("The Formula does not exist");
		return BaseValue;
	}

private:
	TMap<ECalculationFormulaType, TSharedPtr<IStatFormula>> Formulas;
};


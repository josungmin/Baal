#pragma once
#include "CoreMinimal.h"
#include "Stat/Enums/EStat.h"
#include "Stat/Structures/FStatModifier.h"
#include "Stat/Structures/FModifierMarge.h"
#include "Stat/CStatUtility.h"
#include "FStat.generated.h"


USTRUCT(BlueprintType)
struct BAAL_API FStat : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat | Init")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat | Init")
	EStat StatType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat | Init")
	float BaseValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stat | Debug")
	float FinalValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stat | Debug")
	float AttributeBonusValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat | Debug")
	TSet<FStatModifier> StatModifiers;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stat | Debug")
	uint32 bIsChanged : 1;


	void AddModifier(const FStatModifier& Modifier)
	{
		FStatModifier* ExistingModifier = StatModifiers.Find(Modifier);
		if (ExistingModifier != nullptr)
		{
			FModifierMarge ModifierMarge;
			ExistingModifier->Value = ModifierMarge.Marge(ExistingModifier->MargeFormula, ExistingModifier->Value, Modifier.Value);

			bIsChanged = true;
			return;
		}

		StatModifiers.Add(Modifier);
		bIsChanged = true;
		return;
	}


	bool RemoveModifier(FStatModifier Modifier)
	{
		if (!StatModifiers.Contains(Modifier))
		{
			return false;
		}

		StatModifiers.Remove(Modifier);
		bIsChanged = true;

		return true;
	}


	void CalculateModifiers()
	{
		if (!bIsChanged) return;

		FinalValue = BaseValue + AttributeBonusValue;
		FinalValue = ::CalculateFinalValue(StatModifiers, FinalValue);
		bIsChanged = false;
	}
};

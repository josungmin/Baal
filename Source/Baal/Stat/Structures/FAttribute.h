#pragma once
#include "CoreMinimal.h"
#include "Stat/Structures/FStatModifier.h"
#include "Stat/Structures/FModifierMarge.h"
#include "Stat/Structures/FAttributeModifier.h"
#include "Stat/CStatUtility.h"
#include "FAttribute.generated.h"


USTRUCT(BlueprintType)
struct BAAL_API FAttribute : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute | Init")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute | Init")
	EAttribute AttributeType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute | Init")
	float BaseValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute | Init")
	TSet<FStatModifier> AttributeToStatModifier;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attribute | Debug")
	TSet<FAttributeModifier> AttributeModifiers;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attribute | Debug")
	uint32 bIsChanged : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attribute | Debug")
	float FinalValue;


	void AddModifier(FAttributeModifier Modifier)
	{
		FAttributeModifier* ExistingModifier = AttributeModifiers.Find(Modifier);
		if (ExistingModifier != nullptr)
		{
			FModifierMarge ModifierMarge;
			ExistingModifier->Value = ModifierMarge.Marge(ExistingModifier->MargeFormula, ExistingModifier->Value, Modifier.Value);

			bIsChanged = true;
			return;
		}

		AttributeModifiers.Add(Modifier);
		bIsChanged = true;
		return;
	}


	bool RemoveModifier(FAttributeModifier Modifier)
	{
		if (!AttributeModifiers.Contains(Modifier))
		{
			return false;
		}

		AttributeModifiers.Remove(Modifier);
		bIsChanged = true;

		return true;
	}


	void CalculateModifiers()
	{
		if (!bIsChanged) return;

		FinalValue = CalculateFinalValue(AttributeModifiers, BaseValue);
		bIsChanged = false;
	}
};

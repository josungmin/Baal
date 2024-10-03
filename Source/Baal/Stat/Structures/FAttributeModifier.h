#pragma once
#include "CoreMinimal.h"
#include "Stat/Enums/EAttribute.h"
#include "Stat/Enums/EMargeFormulaType.h"
#include "Stat/Enums/ECalculationFormulaType.h"
#include "FAttributeModifier.generated.h"


USTRUCT(BlueprintType)
struct BAAL_API FAttributeModifier
{
	GENERATED_BODY()

	FGuid ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Modifier")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Modifier")
	EAttribute TargetAttribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Modifier")
	ECalculationFormulaType CalculationFormula;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Modifier")
	EMargeFormulaType MargeFormula;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute Modifier")
	float Value;

	FAttributeModifier() : ID(FGuid::NewGuid())
	{

	}

	bool operator==(const FAttributeModifier& Other) const
	{
		return ID == Other.ID;
	}
};

FORCEINLINE uint32 GetTypeHash(const FAttributeModifier& AttributeModifier)
{
	return GetTypeHash(AttributeModifier.ID);
}
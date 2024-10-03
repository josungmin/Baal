#pragma once
#include "CoreMinimal.h"
#include "Stat/Enums/EStat.h"
#include "Stat/Enums/EMargeFormulaType.h"
#include "Stat/Enums/ECalculationFormulaType.h"
#include "FStatModifier.generated.h"


USTRUCT(BlueprintType)
struct BAAL_API FStatModifier
{
	GENERATED_BODY()

	FGuid ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Modifier")
	int32 Priority;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Modifier")
	EStat TargetStat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Modifier")
	ECalculationFormulaType CalculationFormula;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Modifier")
	EMargeFormulaType MargeFormula;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat Modifier")
	float Value;

	FStatModifier() : ID(FGuid::NewGuid())
	{

	}

	bool operator==(const FStatModifier& Other) const
	{
		return ID == Other.ID;
	}
};

FORCEINLINE uint32 GetTypeHash(const FStatModifier& StatModifier)
{
	return GetTypeHash(StatModifier.ID);
}
#pragma once

UENUM(BlueprintType)
enum class ECalculationFormulaType : uint8
{
	Add					UMETA(DisplayName = "Add"),
	PercentAdd			UMETA(DisplayName = "PercentAdd"),
	PercentMulti		UMETA(DisplayName = "PercentMulti"),

	E_MAX,
};

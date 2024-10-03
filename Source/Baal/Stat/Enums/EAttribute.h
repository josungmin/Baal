#pragma once

UENUM(BlueprintType)
enum class EAttribute : uint8
{
	Vitality		UMETA(DisplayName = "Vitality"),
	Vigor			UMETA(DisplayName = "Vigor"),
	Agility			UMETA(DisplayName = "Agility"),
	Fate			UMETA(DisplayName = "Fate"),
	Technique		UMETA(DisplayName = "Technique"),
	Advance			UMETA(DisplayName = "Advance"),

	E_MAX,
};

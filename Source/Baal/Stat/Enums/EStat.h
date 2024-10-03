#pragma once


UENUM(BlueprintType)
enum class EStat : uint8
{
	// Combat
	AttackPower						UMETA(DisplayName = "AttackPower"),
	CriticalDamage					UMETA(DisplayName = "CriticalDamage"),
	CriticalHitRate					UMETA(DisplayName = "CriticalHitRate"),
	CooldownReduction				UMETA(DisplayName = "CooldownReduction"),
	ItemUseSpeed					UMETA(DisplayName = "ItemUseSpeed"),

	// Survivability
	Speed							UMETA(DisplayName = "Speed"),
	Health							UMETA(DisplayName = "Health"),
	HealthRegen						UMETA(DisplayName = "HealthRegen"),
	HealingBoost					UMETA(DisplayName = "HealingBoost"),
	Defense							UMETA(DisplayName = "Defense"),
	StunResistance					UMETA(DisplayName = "StunResistance"),
	BlindResistance					UMETA(DisplayName = "BlindResistance"),

	// Resource 
	Mana							UMETA(DisplayName = "Mana"),
	ManaRegen						UMETA(DisplayName = "ManaRegen"),
	ManaCostReduction				UMETA(DisplayName = "ManaCostReduction"),
	Stamina							UMETA(DisplayName = "Stamina"),
	StaminaRegen					UMETA(DisplayName = "StaminaRegen"),
	StaminaCostReduction			UMETA(DisplayName = "StaminaCostReduction"),
	ItemDropRate					UMETA(DisplayName = "ItemDropRate"),
	GoldGainRate					UMETA(DisplayName = "GoldGainRate"),

	E_MAX,
};

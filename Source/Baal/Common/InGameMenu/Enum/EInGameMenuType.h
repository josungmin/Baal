#pragma once

UENUM(BlueprintType)
enum class EInGameMenuType : uint8
{
	Ability					UMETA(DisplayName = "Ability"),
	EquipmentInventory      UMETA(DisplayName = "EquipmentInventory"),
	ItemInventory			UMETA(DisplayName = "ItemInventory"),
};

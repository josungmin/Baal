#pragma once

UENUM(BlueprintType)
enum class EItemCategory : uint8
{
    Weapon      UMETA(DisplayName = "Weapon"),
    Armor       UMETA(DisplayName = "Armor"),
    Accessory   UMETA(DisplayName = "Accessory"),
    Consumable  UMETA(DisplayName = "Consumable"),
    Quest       UMETA(DisplayName = "Quest"),

    E_MAX,
};

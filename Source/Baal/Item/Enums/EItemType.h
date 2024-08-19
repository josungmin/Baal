#pragma once

UENUM(BlueprintType)
enum class EItemType : uint8
{
    // Weapon
    Sword           UMETA(DisplayName = "Sword"),
    Bow             UMETA(DisplayName = "Bow"),
    Dagger          UMETA(DisplayName = "Dagger"),
    Spear           UMETA(DisplayName = "Spear"),
    Staff           UMETA(DisplayName = "Staff"),

    // Armor
    Helmet          UMETA(DisplayName = "Helmet"),
    Chestplate      UMETA(DisplayName = "Chestplate"),
    Leggings        UMETA(DisplayName = "Leggings"),
    Gloves          UMETA(DisplayName = "Gloves"),
    Boots           UMETA(DisplayName = "Boots"),

    // Accessory
    Necklace        UMETA(DisplayName = "Necklace"),
    Ring            UMETA(DisplayName = "Ring"),
    Earrings        UMETA(DisplayName = "Earrings"),
    Bracelet        UMETA(DisplayName = "Bracelet"),
    Belt            UMETA(DisplayName = "Belt"),

    // Accessory
    Potion          UMETA(DisplayName = "Potion"),
    Elixir          UMETA(DisplayName = "Elixir"),
    Scroll          UMETA(DisplayName = "Scroll"),
    Arrow           UMETA(DisplayName = "Arrow"),

    E_MAX,
};

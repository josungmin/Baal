#pragma once

UENUM(BlueprintType)
enum class EItemGrade : uint8
{
    Common      UMETA(DisplayName = "Common"),      // 회색
    Uncommon    UMETA(DisplayName = "Uncommon"),    // 초록색
    Rare        UMETA(DisplayName = "Rare"),        // 파란색
    Epic        UMETA(DisplayName = "Epic"),        // 보라색
    Legendary   UMETA(DisplayName = "Legendary"),   // 금색
    Myth        UMETA(DisplayName = "Myth"),        // 빨간색

    E_MAX,
};

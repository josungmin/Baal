#pragma once

UENUM(BlueprintType)
enum class EItemGrade : uint8
{
    Common      UMETA(DisplayName = "Common"),      // ȸ��
    Uncommon    UMETA(DisplayName = "Uncommon"),    // �ʷϻ�
    Rare        UMETA(DisplayName = "Rare"),        // �Ķ���
    Epic        UMETA(DisplayName = "Epic"),        // �����
    Legendary   UMETA(DisplayName = "Legendary"),   // �ݻ�
    Myth        UMETA(DisplayName = "Myth"),        // ������

    E_MAX,
};

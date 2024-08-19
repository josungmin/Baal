#include "Core/CGameInstance.h"
#include "Item/Structures/FItemData.h"
#include "Utilities/CLog.h"


void UCGameInstance::Init()
{
    Super::Init();

    if (!ItemDataTable)
    {
        CLog::LogError(TEXT("ItemDataTable is not loaded"));
        return;
    }

    ItemDataMap.Empty();

    for (const auto& Row : ItemDataTable->GetRowMap())
    {
        FItemData* ItemData = (FItemData*)Row.Value;
        if (ItemData)
        {
            ItemDataMap.Add(ItemData->Id, ItemData);
        }
    }
}


FItemData* UCGameInstance::FindItemById(FName Id) const
{
    if (!ItemDataTable)
    {
        CLog::LogError(TEXT("ItemDataTable is not loaded"));
        return nullptr;
    }

    if (FItemData* const* FoundItem = ItemDataMap.Find(Id))
    {
        return *FoundItem;
    }

    return ItemDataMap[Id];
}

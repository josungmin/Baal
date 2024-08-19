#pragma once

#include "CoreMinimal.h"
#include "FInventoryItemData.h"
#include "FInventoryData.generated.h"

/**
 * @ The inventory data for a single inventory
 */
USTRUCT(BlueprintType)
struct BAAL_API FInventoryData
{
	GENERATED_BODY()

	/**
	 * @ Maximum number of slots in the inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 MaxSlotCount;

	/**
	 * @ Current number of active slots in the inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 ActiveSlotCount;

	/**
	 * @ The array of items in the inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventoryItemData> Items;
};

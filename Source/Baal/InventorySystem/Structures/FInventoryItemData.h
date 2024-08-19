#pragma once

#include "CoreMinimal.h"
#include "FInventoryItemData.generated.h"

/**
 * @ The information about a specific inventory item
 */
USTRUCT(BlueprintType)
struct BAAL_API FInventoryItemData
{
	GENERATED_BODY()

	/**
	 * @ The ID of the inventory item
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	FName Id;

	/**
	 * @ The amount of the inventory item
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory|Item")
	int32 Amount;


	FInventoryItemData(FName Id, int32 Amount)
		: Id(Id), Amount(Amount)
	{
		
	}
};

#pragma once

#include "CoreMinimal.h"
#include "Item/Enums/EItemGrade.h"
#include "Item/Enums/EItemCategory.h"
#include "Item/Enums/EItemType.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemCategory ItemCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemGrade ItemGrade;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 MaxStackAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	TObjectPtr<UTexture2D> Icon;
};

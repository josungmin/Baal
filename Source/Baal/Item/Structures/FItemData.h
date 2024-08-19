#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Item/Enums/EItemGrade.h"
#include "Item/Enums/EItemCategory.h"
#include "Item/Enums/EItemType.h"
#include "FItemData.generated.h"


USTRUCT(BlueprintType)
struct BAAL_API FItemData : public FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FText Description;

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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FDataTableRowHandle ItemDataTable;
};

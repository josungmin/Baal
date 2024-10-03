#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structures/FInventoryItemData.h"
#include "CInventoryComponent.generated.h"

class UCGameInstance;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BAAL_API UCInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCInventoryComponent();

protected:
	virtual void BeginPlay() override;

protected:
	/**
	 * @ Maximum number of slots in the inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 MaxSlotCount;

	/**
	 * @ Current number of slots in the inventory
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 FilledSlotCount;

public:
	/**
	 *  Add an item to the inventory
	 * @param Id The ID of the item to add
	 * @param Amount The amount to add
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(FName Id, int Amount);

	/**
	 *  Remove an item from the inventory
	 * @param Id The ID of the item to remove
	 * @param Amount The amount to remove
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(FName Id, int Amount);

	/**
	 *  Remove all the items with the specified ID
	 * @param Id The ID of the item to remove
	 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveAll(FName Id);

	// void MargeItem()
	// void SplitItem()
	// void SortItem()

private:
	/**
	 * @ A reference to the game instance used to reference the item data table
	 */
	UPROPERTY()
	TObjectPtr<UCGameInstance> GameInstance;

	/**
	 * @ The map of all items in the inventory
	 */
	TMap<FName, int32> Items;
};

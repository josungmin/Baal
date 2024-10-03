#include "Inventory/CInventoryComponent.h"
#include "Core/CGameInstance.h"
#include "Item/Structures/FItemData.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/CLog.h"


UCInventoryComponent::UCInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UCInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* CurrentGameInstance = UGameplayStatics::GetGameInstance(GetWorld());
	GameInstance = dynamic_cast<UCGameInstance*>(CurrentGameInstance);
}


void UCInventoryComponent::AddItem(FName Id, int Amount)
{
	// Get Item Data
	if (!GameInstance)
	{
		CLog::LogError(TEXT("GameInstance is not loaded"));
		return;
	}

	FItemData* ItemData = GameInstance->FindItemById(Id);
	if (!ItemData)
	{
		CLog::LogError(FString::Printf(TEXT("Item with ID %s not found"), *Id.ToString()));
		return;
	}

	// Calculate the amount of slots required
	int32 AdditionSlotCount = 0;
	int32 MaxStackAmount = ItemData->MaxStackAmount;

	if (Items.Contains(Id))
	{
		int32 CurrentAmount = Items[Id];
		int32 TotalAmount = CurrentAmount + Amount;

		// Calculate the number of total and current slots
		int32 TotalSlotCount = FMath::CeilToInt((float)TotalAmount / MaxStackAmount);
		int32 CurrentSlotCount = FMath::CeilToInt((float)CurrentAmount / MaxStackAmount);

		// Calculate how many additional slots are needed
		AdditionSlotCount = TotalSlotCount - CurrentSlotCount;
	}
	else
	{
		AdditionSlotCount = FMath::CeilToInt((float)Amount / MaxStackAmount);
	}
	
	// Check if there is enough slots in the inventory
	if (MaxSlotCount < FilledSlotCount + AdditionSlotCount)
	{
		CLog::LogError(TEXT("Not enough inventory slots to add this item."));
		return;
	}

	// Add Item
	if (Items.Contains(Id))
	{
		Items[Id] += Amount;		
	}
	else
	{
		Items.Add(Id, Amount);
	}

	FilledSlotCount += AdditionSlotCount;

	return;
}


void UCInventoryComponent::RemoveItem(FName Id, int Amount)
{
	if (!Items.Contains(Id))
	{
		CLog::LogError(FString::Printf(TEXT("Item with ID %s not found"), *Id.ToString()));
		return;
	}

	if (Items[Id] - Amount < 0)
	{
		CLog::LogError(FString::Printf(TEXT("Not enough of item with ID %s to remove"), *Id.ToString()));
		return;
	}

	if (Items[Id] - Amount == 0)
	{
		RemoveAll(Id);
		return;
	}

	Items[Id] -= Amount;
}


void UCInventoryComponent::RemoveAll(FName Id)
{
	if (!Items.Contains(Id))
	{
		CLog::LogError(FString::Printf(TEXT("Item with ID %s not found"), *Id.ToString()));
		return;
	}

	// Update FilledSlotCount
	FilledSlotCount -= FMath::CeilToInt((float)(Items[Id] / GameInstance->FindItemById(Id)->MaxStackAmount));
	Items.Remove(Id);
}

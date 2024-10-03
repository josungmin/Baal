#include "Inventory/Widget/CInventorySlotGridWidget.h"
#include "Item/Widget/CItemSlotWidget.h"
#include "Components/UniformGridPanel.h"

#include "Utilities/CLog.h"


void UCInventorySlotGridWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SlotCount = Rows * Columns;

	// 슬롯 풀을 미리 할당
	for (int32 i = 0; i < SlotCount; ++i)
	{
		UCItemSlotWidget* ItemSlot = CreateWidget<UCItemSlotWidget>(this, UCItemSlotWidget::StaticClass());
		ItemSlot->InitializeSlot();

		SlotPool.Add(ItemSlot);
	}

	// TODO : Debug code that should be deleted at build time
	if (!SlotGrid)
	{
		CLog::LogError("SlotGrid is not bind");
		return;
	}

	SlotGrid->ClearChildren();
}


void UCInventorySlotGridWidget::UpdateSlotGrid()
{
	if (!SlotGrid)
	{
		CLog::LogError("SlotGrid is not bind");
		return;
	}

	int32 CurrentSlotCount = SlotGrid->GetChildrenCount();
	int32 TargetSlotCount = Rows * Columns;

	// Add slots to grid
	if (CurrentSlotCount < TargetSlotCount)
	{
		// Add slots if slot pool is missing
		ResizeSlotPool(TargetSlotCount - CurrentSlotCount);

		for (int32 i = CurrentSlotCount; i < TargetSlotCount; i++)
		{
			UCItemSlotWidget* ItemSlot = SlotPool.Pop();
			SlotGrid->AddChildToUniformGrid(ItemSlot, i / Columns, i % Columns);
		}
	}

	// Remove slots to grid
	if (CurrentSlotCount > TargetSlotCount)
	{
		for (int32 i = CurrentSlotCount - 1; i >= TargetSlotCount; i--)
		{
			UCItemSlotWidget* ItemSlot = Cast<UCItemSlotWidget>(SlotGrid->GetChildAt(i));
			if (ItemSlot)
			{
				SlotGrid->RemoveChildAt(i);
				ReturnSlotToPool(ItemSlot);
			}
		}
	}
}


void UCInventorySlotGridWidget::ResizeSlotPool(int32 SlotsToAdd)
{
	for (int32 i = 0; i < SlotsToAdd; ++i)
	{
		UCItemSlotWidget* ItemSlot = CreateWidget<UCItemSlotWidget>(this, UCItemSlotWidget::StaticClass());
		ItemSlot->InitializeSlot();

		SlotPool.Add(ItemSlot);
	}
}


void UCInventorySlotGridWidget::ReturnSlotToPool(UCItemSlotWidget* ItemSlot)
{
	if (!ItemSlot)
	{
		return;
	}

	ItemSlot->InitializeSlot();
	SlotPool.Push(ItemSlot);
}


#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInventorySlotGridWidget.generated.h"


UCLASS()
class BAAL_API UCInventorySlotGridWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UUniformGridPanel> SlotGrid;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default"))
	int32 Rows = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default"))
	int32 Columns = 10;

public:
	//void UpdateItemSlots();

private:
	void UpdateSlotGrid();
	void ResizeSlotPool(int32 SlotsToAdd);
	void ReturnSlotToPool(class UCItemSlotWidget* Slot);

private:
	UPROPERTY()
	TArray<TObjectPtr<class UCItemSlotWidget>> SlotPool;

	int32 SlotCount;
};

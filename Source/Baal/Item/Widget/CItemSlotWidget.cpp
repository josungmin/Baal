#include "Item/Widget/CItemSlotWidget.h"
#include "Core/CGameInstance.h"
#include "Components/Button.h"
#include "Components/SizeBox.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Item/Structures/FItemData.h"

#include "Utilities/CLog.h"


void UCItemSlotWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateSlotSizer();
	UpdateItemIcon();
	UpdateEmptyIcon();
	UpdateAmountText();
}


void UCItemSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameInstance = Cast<UCGameInstance>(GetWorld()->GetGameInstance());
	if (!GameInstance)
	{
		CLog::LogError(TEXT("GameInstance is not loaded"));
		return;
	}

	InitializeSlot();

	if (!Button)
	{
		CLog::LogError("Button is not bind");
		return;
	}

	Button->OnClicked.AddDynamic(this, &UCItemSlotWidget::ClickAction);
}


bool UCItemSlotWidget::HasItem()
{
	return !ItemId.IsNone() && 0 < Amount;
}


void UCItemSlotWidget::InitializeSlot()
{
	// Initialize Slot Data
	ItemId = NAME_None;
	Amount = 0;
	ItemIconTexture = nullptr;

	// Update UI
	UpdateItemIcon();
	UpdateEmptyIcon();
	UpdateAmountText();
}


void UCItemSlotWidget::UpdateSlot(const FName& Id, const int32 InAmount)
{
	// Add Optimization Logic
	if (ItemId != Id)
	{
		return;
	}

	if (Amount != InAmount)
	{
		Amount = InAmount;
		UpdateAmountText();
	}

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

	// Set Slot Data
	ItemId = Id;
	Amount = InAmount;
	ItemIconTexture = ItemData->Icon;

	// Update UI
	UpdateItemIcon();
	UpdateEmptyIcon();
	UpdateAmountText();
}


void UCItemSlotWidget::UpdateSlotSizer()
{
	if (!SlotSizer)
	{
		CLog::LogError("SlotSizer is not bind");
		return;
	}

	// Update UI
	SlotSizer->SetWidthOverride(Size.X);
	SlotSizer->SetHeightOverride(Size.Y);
}


void UCItemSlotWidget::UpdateItemIcon()
{
	if (!ItemIconBorder)
	{
		CLog::LogError("ItemIcon is not bind");
		return;
	}

	if (!HasItem())
	{
		ItemIconBorder->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	// Update UI
	ItemIconBorder->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	ItemIconBorder->SetBrushFromTexture(ItemIconTexture);
}


void UCItemSlotWidget::UpdateEmptyIcon()
{
	if (!EmptyIconBorder)
	{
		CLog::LogError("EmptyIcon is not bind");
		return;
	}

	if (HasItem())
	{
		EmptyIconBorder->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	// Update UI
	EmptyIconBorder->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	EmptyIconBorder->SetBrushFromTexture(EmptyIconTexture);

	FLinearColor Color = EmptyIconBorder->GetBrushColor();
	EmptyIconBorder->SetBrushColor(FLinearColor(
		Color.R,
		Color.G, 
		Color.B, 
		EmptyIconOpacity
	));
}


void UCItemSlotWidget::UpdateAmountText()
{
	if (!AmountText)
	{
		CLog::LogError("AmountText is not bind");
		return;
	}

	if (!HasItem() || Amount == 1)
	{
		AmountText->SetVisibility(ESlateVisibility::Collapsed);
		return;
	}

	// Update UI
	AmountText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	AmountText->SetText(FText::AsNumber(Amount));
}


void UCItemSlotWidget::ClickAction()
{
	// More to be added
}
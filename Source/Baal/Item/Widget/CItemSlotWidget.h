#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CItemSlotWidget.generated.h"


UCLASS()
class BAAL_API UCItemSlotWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UButton> Button;

	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class USizeBox> SlotSizer;

	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UBorder> ItemIconBorder;

	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UBorder> EmptyIconBorder;

	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UTextBlock> AmountText;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default"))
	FVector2D Size = FVector2D(100, 100);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default"))
	TObjectPtr<UTexture2D> EmptyIconTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default", ClampMin = "0.0", ClampMax = "1.0"))
	float EmptyIconOpacity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default | Debug"))
	FName ItemId = NAME_None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default | Debug"))
	TObjectPtr<UTexture2D> ItemIconTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (CategoryName = "Default | Debug"))
	int32 Amount = 0;

public:
	bool HasItem();

	void InitializeSlot();
	void UpdateSlot(const FName& Id, const int32 Amount);

private:
	void UpdateSlotSizer();
	void UpdateItemIcon();
	void UpdateEmptyIcon();
	void UpdateAmountText();

private:
	UFUNCTION()
	void ClickAction();

private:
	// Data to be included in the build
	//FName ItemId = NAME_None;
	//int32 Amount = 0;
	// TObjectPtr<UTexture2D> ItemIconTexture;

private:
	UPROPERTY()
	TObjectPtr<class UCGameInstance> GameInstance;
};

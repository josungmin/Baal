#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInGameMenuTabButtonWidget.generated.h"


UCLASS()
class BAAL_API UCInGameMenuTabButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativePreConstruct() override;

protected:
	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly, Category = "TabButton")
	TObjectPtr<class UTextBlock> Label;

	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly, Category = "TabButton")
	TObjectPtr<class UBorder> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialization")
	FText Name = FText::FromString(TEXT("New Tab"));

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialization")
	UTexture2D* IconImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Initialization")
	uint32 IsSelected : 1 = false;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeselected();
};

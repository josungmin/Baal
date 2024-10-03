#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInGameMenuTabWidget.generated.h"

UENUM(BlueprintType)
enum class ETabNavigation : uint8
{
	Select			UMETA(DisplayName = "Select"),
	Next			UMETA(DisplayName = "Next"),
	Previous		UMETA(DisplayName = "Previous"),
};


UCLASS()
class BAAL_API UCInGameMenuTabWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	
protected:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly, Category = "UI")
	TObjectPtr<class UVerticalBox> TabsContainer;

	UPROPERTY(BlueprintReadOnly, Category = "Tabs")
	TArray<TObjectPtr<class UCInGameMenuTabButtonWidget>> Tabs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SelectedIndex = 0;

public:
	UFUNCTION(BlueprintCallable)
	void SwitchTab(ETabNavigation TabNavigation);

	UFUNCTION(BlueprintCallable)
	void UpdateSelectedIndex(ETabNavigation TabNavigation);
};

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CInGameMenuWidget.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class BAAL_API UCInGameMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> UIInputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | Game Input Action")
	UInputAction* UINavigationUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | Game Input Action")
	UInputAction* UINavigationDown;

protected:
	UPROPERTY(meta = (BindWidgetOptional), VisibleAnywhere, BlueprintReadOnly, Category = "TabButton")
	TObjectPtr<class UCInGameMenuTabWidget> InGameMenuTab;

private:
	void NavigateUp();
	void NavigateDown();
};

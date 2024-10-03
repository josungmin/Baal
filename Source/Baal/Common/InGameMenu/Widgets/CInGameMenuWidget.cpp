#include "Common/InGameMenu/Widgets/CInGameMenuWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "Common/InGameMenu/Widgets/CInGameMenuTabWidget.h"

#include "Utilities/CLog.h"

void UCInGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerController* PlayerController = GetOwningPlayer();
	if (!PlayerController)
	{
		CLog::LogError("PlayerController is not valid");
		return;
	}

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
	if (!EnhancedInputComponent)
	{
		CLog::LogError("EnhancedInputComponent is not valid");
		return;
	}

	if (UINavigationUp)
	{
		EnhancedInputComponent->BindAction(UINavigationUp, ETriggerEvent::Triggered, this, &UCInGameMenuWidget::NavigateUp);
	}

	if (UINavigationDown)
	{
		EnhancedInputComponent->BindAction(UINavigationDown, ETriggerEvent::Triggered, this, &UCInGameMenuWidget::NavigateDown);
	}

	// Bind Widget
	if (!InGameMenuTab)
	{
		CLog::LogError("InGameMenuTab is not bind");
		return;
	}
}


void UCInGameMenuWidget::NavigateUp()
{
	InGameMenuTab->SwitchTab(ETabNavigation::Previous);
}


void UCInGameMenuWidget::NavigateDown()
{
	InGameMenuTab->SwitchTab(ETabNavigation::Next);
}

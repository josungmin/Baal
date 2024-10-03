#include "Common/InGameMenu/Widgets/CInGameMenuTabWidget.h"
#include "Common/InGameMenu/Widgets/CInGameMenuTabButtonWidget.h"
#include "Components/VerticalBox.h"

#include "Utilities/CLog.h"


void UCInGameMenuTabWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!TabsContainer)
	{
		CLog::LogError("TabsContainer is not bind");
		return;
	}

	// Initialize the array to store the tab widget
	for (UWidget* Child : TabsContainer->GetAllChildren())
	{
		UCInGameMenuTabButtonWidget* Tab = Cast<UCInGameMenuTabButtonWidget>(Child);
		if (Tab)
		{
			Tabs.Add(Tab);
		}
	}
}


void UCInGameMenuTabWidget::SwitchTab(ETabNavigation TabNavigation)
{
	UpdateSelectedIndex(TabNavigation);

	for (auto Tab : Tabs)
	{
		Tab->OnDeselected();
	}

	Tabs[SelectedIndex]->OnSelected();
}

void UCInGameMenuTabWidget::UpdateSelectedIndex(ETabNavigation TabNavigation)
{
	if (TabNavigation == ETabNavigation::Select)
	{
		return;
	}

	if (TabNavigation == ETabNavigation::Next)
	{
		int32 TabCount = Tabs.Num();

		if (SelectedIndex == TabCount - 1)
		{
			SelectedIndex = 0;
		}
		else
		{
			SelectedIndex += 1;
		}

		return;
	}

	if (TabNavigation == ETabNavigation::Previous)
	{
		int32 TabCount = Tabs.Num();

		if (0 <= SelectedIndex - 1)
		{
			SelectedIndex -= 1;
		}
		else
		{
			SelectedIndex = TabCount - 1;
		}

		return;
	}
}

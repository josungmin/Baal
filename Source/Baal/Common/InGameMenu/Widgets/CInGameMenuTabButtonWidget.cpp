#include "Common/InGameMenu/Widgets/CInGameMenuTabButtonWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Utilities/CLog.h"

void UCInGameMenuTabButtonWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	// Initialize Label UI
	if (!Label)
	{
		CLog::LogError("The label is not bind");
		return;
	}

	Label->SetText(Name);

	// Initialize Icon UI
	if (!Icon)
	{
		CLog::LogError("The Icon is not bind");
		return;
	}

	Icon->SetBrushFromTexture(IconImage);

	if (IsSelected) { OnSelected(); }
	else { OnDeselected(); }
}

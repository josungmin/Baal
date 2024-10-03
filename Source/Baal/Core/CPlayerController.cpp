#include "Core/CPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Core/CCharacter.h"

#include "Utilities/CLog.h"

ACPlayerController::ACPlayerController()
{

}


void ACPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Initialize InputMappingContext
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(Subsystem))
	{
		CLog::LogError("Input Subsystem is not valid");
		return;
	}

	if (!IsValid(GameInputMappingContext))
	{
		CLog::LogError("GameInputMappingContext is not valid");
		return;
	}

	Subsystem->AddMappingContext(GameInputMappingContext, 0);

	if (!IsValid(UIInputMappingContext))
	{
		CLog::LogError("UIInputMappingContext is not valid");
		return;
	}

	Subsystem->AddMappingContext(UIInputMappingContext, 1);


	// Get Controlled Character
	ControlledCharacter = Cast<ACCharacter>(GetPawn());
	if (!ControlledCharacter)
	{
		CLog::LogError("OnPossess :: ACCharacter is not valid");
		return;
	}


	// Create InGameMenu Widget
	if (!IsValid(InGameMenuWidgetClass))
	{
		CLog::LogError("InGameMenuWidgetClass is not valid");
		return;
	}

	InGameMenuWidget = CreateWidget<UUserWidget>(this, InGameMenuWidgetClass);

	if (!IsValid(InGameMenuWidget))
	{
		CLog::LogError("InGameMenuWidget is not valid");
		return;
	}

	InGameMenuWidget->AddToViewport();
	InGameMenuWidget->SetVisibility(ESlateVisibility::Hidden);
}


void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EnhancedInputComponent)
	{
		CLog::LogError("EnhancedInputComponent is not valid");
		return;
	}

	// Game Input Action Bind
	if (JumpAction)
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACPlayerController::StopJump);
	}

	if (MoveAction)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACPlayerController::Move);
	}

	if (LookAction)
	{
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACPlayerController::Look);
	}

	// UI Input Action Bind
	if (ToggleInGameMenuAction)
	{
		EnhancedInputComponent->BindAction(ToggleInGameMenuAction, ETriggerEvent::Triggered, this, &ACPlayerController::ToggleInGameMenu);
	}
}


void ACPlayerController::SetUIInputMode()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->RemoveMappingContext(GameInputMappingContext);
	Subsystem->AddMappingContext(UIInputMappingContext, 1);

	bShowMouseCursor = true;

	FInputModeUIOnly InputMode;
	//SetInputMode(InputMode);
}


void ACPlayerController::SetGameInputMode()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	Subsystem->RemoveMappingContext(UIInputMappingContext);
	Subsystem->AddMappingContext(GameInputMappingContext, 0);

	bShowMouseCursor = false;

	FInputModeGameOnly InputMode;
	//SetInputMode(InputMode);
}


void ACPlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(ControlledCharacter))
	{
		CLog::LogError("Controlled Character is not valid");
		return;
	}

	ControlledCharacter->Move(Value);
}


void ACPlayerController::Look(const FInputActionValue& Value)
{
	if (!IsValid(ControlledCharacter))
	{
		CLog::LogError("Controlled Character is not valid");
		return;
	}

	ControlledCharacter->Look(Value);
}


void ACPlayerController::Jump()
{
	if (!IsValid(ControlledCharacter))
	{
		CLog::LogError("Controlled Character is not valid");
		return;
	}

	ControlledCharacter->Jump();
}


void ACPlayerController::StopJump()
{
	if (!IsValid(ControlledCharacter))
	{
		CLog::LogError("Controlled Character is not valid");
		return;
	}

	ControlledCharacter->StopJumping();
}


void ACPlayerController::ToggleInGameMenu()
{
	CLog::LogDebug("Input ToggleInGameMenu");

	if (!IsValid(InGameMenuWidget))
	{
		CLog::LogError("InGameMenuWidget is not valid");
		return;
	}

	ESlateVisibility Visibility = InGameMenuWidget->GetVisibility();

	if (Visibility == ESlateVisibility::Hidden)
	{
		InGameMenuWidget->SetVisibility(ESlateVisibility::Visible);
		SetUIInputMode();
	}
	else
	{
		InGameMenuWidget->SetVisibility(ESlateVisibility::Hidden);
		SetGameInputMode();
	}
}

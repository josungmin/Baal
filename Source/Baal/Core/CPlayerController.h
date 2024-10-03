#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class ACCharacter;
struct FInputActionValue;

UCLASS()
class BAAL_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> UIInputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | UI Input Action", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> ToggleInGameMenuAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> GameInputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | Game Input Action", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | Game Input Action", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input | Game Input Action", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> InGameMenuWidgetClass;

	UPROPERTY(Transient)
	TObjectPtr<UUserWidget> InGameMenuWidget;

protected:
	// Input Mode
	void SetUIInputMode();
	void SetGameInputMode();

	// Character Input Action
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump();
	void StopJump();

	// UI Input Action
	void ToggleInGameMenu();

private:
	UPROPERTY()
	ACCharacter* ControlledCharacter;
};

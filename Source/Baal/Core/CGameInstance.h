#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CGameInstance.generated.h"

struct FItemData;

UCLASS()
class BAAL_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
public:
	/** 
	*  The item data table containing all item information in the game
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Data")
	UDataTable* ItemDataTable;

public:
	/*
	*  Finds an item in the item data map by its ID
	*  @param Id The unique identifier of the item to find.
	*  @return A pointer to the FItemData structure if the item is found, nullptr otherwise.
	*/
	FItemData* FindItemById(FName Id) const;

private:
	/**
	*  Map to store FText Name to FItemData pointer for fast lookup
	*/
	TMap<FName, FItemData*> ItemDataMap;
};

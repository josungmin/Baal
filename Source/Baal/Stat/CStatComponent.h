#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structures/FAttribute.h"
#include "Structures/FStat.h"
#include "CStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BAAL_API UCStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatComponent();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat | DataTable")
	UDataTable* StatDataTable;

public:
	FStat* FindStat(EStat StatType);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	TOptional<float> GetStatValue(EStat StatType);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	void AddStatModifier(const FStatModifier& StatModifier);

	UFUNCTION(BlueprintCallable, Category = "Stat")
	void RemoveStatModifier(const FStatModifier& StatModifier);

public:
	UFUNCTION()
	void OnAttributeChanged(const FAttribute& Attribute);

protected:
	void LoadDataTable();

private:
	TMap<EStat, FStat> Stats;
};

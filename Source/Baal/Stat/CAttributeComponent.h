#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structures/FAttribute.h"
#include "CAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChanged, const FAttribute&, Attribute);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BAAL_API UCAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCAttributeComponent();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite, Category = "Attribute | Component")
	TObjectPtr<class UCStatComponent> StatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute | DataTable")
	UDataTable* AttributeDataTable;

	UPROPERTY(BlueprintAssignable, Category = "Attribute | Events")
	FOnAttributeChanged OnAttributeChanged;

public:
	FAttribute* FindAttribute(EAttribute AttributeType);

	UFUNCTION(BlueprintCallable, Category = "Attribute")
	TOptional<float> GetAttributeValue(EAttribute AttributeType);

	UFUNCTION(BlueprintCallable, Category = "Attribute")
	void AddAttributeModifier(const FAttributeModifier& AttributeModifier);

	UFUNCTION(BlueprintCallable, Category = "Attribute")
	void RemoveAttributeModifier(const FAttributeModifier& AttributeModifier);

protected:
	void LoadDataTable();

private:
	TMap<EAttribute, FAttribute> Attributes;
};

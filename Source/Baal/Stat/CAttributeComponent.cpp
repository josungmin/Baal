#include "Stat/CAttributeComponent.h"
#include "Stat/CStatComponent.h"
#include "Engine/DataTable.h"
#include "Utilities/CLog.h"


UCAttributeComponent::UCAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	StatComponent = GetOwner()->FindComponentByClass<UCStatComponent>();
	if (!StatComponent)
	{
		CLog::LogError(TEXT("StatComponent not found on the owner."));
	}

	for (const auto& Attribute : Attributes)
	{
		OnAttributeChanged.AddDynamic(StatComponent, &UCStatComponent::OnAttributeChanged);
	}

	LoadDataTable();
}


FAttribute* UCAttributeComponent::FindAttribute(EAttribute AttributeType)
{
	FAttribute* FoundAttribute = Attributes.Find(AttributeType);
	if (!FoundAttribute)
	{
		return nullptr;
	}

	return FoundAttribute;
}


TOptional<float> UCAttributeComponent::GetAttributeValue(EAttribute AttributeType)
{
	FAttribute* Attribute = Attributes.Find(AttributeType);
	if (!Attribute)
	{
		return TOptional<float>();
	}

	Attribute->CalculateModifiers();

	return Attribute->FinalValue;
}


void UCAttributeComponent::AddAttributeModifier(const FAttributeModifier& AttributeModifier)
{
	FAttribute* Attribute = FindAttribute(AttributeModifier.TargetAttribute);
	if (!Attribute)
	{
		CLog::LogError(TEXT("Attribute not found."));
		return;
	}

	Attribute->AddModifier(AttributeModifier);

	OnAttributeChanged.Broadcast(*Attribute);
}


void UCAttributeComponent::RemoveAttributeModifier(const FAttributeModifier& AttributeModifier)
{
	FAttribute* Attribute = FindAttribute(AttributeModifier.TargetAttribute);
	if (!Attribute)
	{
		CLog::LogError(TEXT("Attribute not found."));
		return;
	}

	bool Result = Attribute->RemoveModifier(AttributeModifier);
	if (!Result)
	{
		CLog::LogError(TEXT("Modifier not found."));
		return;
	}

	OnAttributeChanged.Broadcast(*Attribute);
}


void UCAttributeComponent::LoadDataTable()
{
	if (!AttributeDataTable)
	{
		CLog::LogError(TEXT("AttributeDataTable is not set."));
		return;
	}

	static const FString ContextString(TEXT("Attribute Load Context"));
	TArray<FName> RowNames = AttributeDataTable->GetRowNames();
	for (const FName& RowName : RowNames)
	{
		FAttribute* AttributeRow = AttributeDataTable->FindRow<FAttribute>(RowName, ContextString);
		if (AttributeRow)
		{
			Attributes.Add(AttributeRow->AttributeType, *AttributeRow);
		}
	}
}

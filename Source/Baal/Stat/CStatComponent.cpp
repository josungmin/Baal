#include "Stat/CStatComponent.h"



UCStatComponent::UCStatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCStatComponent::BeginPlay()
{
	Super::BeginPlay();

}


FStat* UCStatComponent::FindStat(EStat StatType)
{
	FStat* FoundStat = Stats.Find(StatType);
	if (!FoundStat)
	{
		return nullptr;
	}

	return FoundStat;
}


TOptional<float> UCStatComponent::GetStatValue(EStat StatType)
{
	FStat* FoundStat = Stats.Find(StatType);
	if (!FoundStat)
	{
		return TOptional<float>();
	}

	FoundStat->CalculateModifiers();

	return FoundStat->FinalValue;
}


void UCStatComponent::AddStatModifier(const FStatModifier& StatModifier)
{
	FStat* Stat = FindStat(StatModifier.TargetStat);
	if (!Stat)
	{
		CLog::LogError(TEXT("Stat not found."));
		return;
	}

	Stat->AddModifier(StatModifier);
	return;
}


void UCStatComponent::RemoveStatModifier(const FStatModifier& StatModifier)
{
	FStat* Stat = FindStat(StatModifier.TargetStat);
	if (!Stat)
	{
		CLog::LogError(TEXT("Stat not found."));
		return;
	}

	bool Result = Stat->RemoveModifier(StatModifier);
	if (!Result)
	{
		CLog::LogError(TEXT("Modifier not found."));
		return;
	}
}

void UCStatComponent::OnAttributeChanged(const FAttribute& Attribute)
{
	// To be implemented
	// Attribute가 영향을 주는 Stat의 AttributeBonusValue를 계산
}


void UCStatComponent::LoadDataTable()
{
	if (!StatDataTable)
	{
		CLog::LogError(TEXT("AttributeDataTable is not set."));
		return;
	}

	static const FString ContextString(TEXT("Attribute Load Context"));
	TArray<FName> RowNames = StatDataTable->GetRowNames();
	for (const FName& RowName : RowNames)
	{
		FStat* StatRow = StatDataTable->FindRow<FStat>(RowName, ContextString);
		if (StatRow)
		{
			Stats.Add(StatRow->StatType, *StatRow);
		}
	}
}

#include "Utilities/CLog.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(Baal);

void CLog::Log(const FString& Text, const bool bPrintToScreen)
{
	UE_LOG(Baal, Display, TEXT("%s: %s"), *FString(__FUNCTION__), *Text);

	if (bPrintToScreen)
	{
		LogToScreen(FColor::White, Text);
	}
}


void CLog::LogDebug(const FString& Text, const bool bPrintToScreen)
{
	UE_LOG(Baal, Verbose, TEXT("%s: %s"), *FString(__FUNCTION__), *Text);

	if (bPrintToScreen)
	{
		LogToScreen(FColor::Magenta, Text);
	}
}


void CLog::LogError(const FString& Text, const bool bPrintToScreen)
{
	UE_LOG(Baal, Error, TEXT("%s: %s"), *FString(__FUNCTION__), *Text);

	if (bPrintToScreen)
	{
		LogToScreen(FColor::Red, Text);
	}
}


void CLog::LogWarning(const FString& Text, const bool bPrintToScreen)
{
	UE_LOG(Baal, Warning, TEXT("%s: %s"), *FString(__FUNCTION__), *Text);

	if (bPrintToScreen)
	{
		LogToScreen(FColor::Yellow, Text);
	}
}


void CLog::LogToScreen(const FColor Color, const FString& Text)
{
	if (!GEngine)
	{
		return;
	}

	const FString LogText = "[" + FString(__FUNCTION__) + "] " + Text;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, Color, LogText);
}


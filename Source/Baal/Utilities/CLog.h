#pragma once

#include "CoreMinimal.h"

#define PrintLine() {CLog::Log(__FUNCTION__, __LINE__);}

DECLARE_LOG_CATEGORY_EXTERN(Baal, Log, All);

class BAAL_API CLog
{
public:
	static void Log(const FString& Text, const bool bPrintToScreen = false);
	static void LogDebug(const FString& Text, const bool bPrintToScreen = false);
	static void LogError(const FString& Text, const bool bPrintToScreen = false);
	static void LogWarning(const FString& Text, const bool bPrintToScreen = false);

private:
	static void LogToScreen(const FColor Color, const FString& Text);
};

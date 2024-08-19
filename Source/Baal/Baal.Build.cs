// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Baal : ModuleRules
{
	public Baal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] { "Baal" });

        PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			// Defualt Module
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput" 


		});
	}
}

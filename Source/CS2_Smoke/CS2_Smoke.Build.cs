// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CS2_Smoke : ModuleRules
{
	public CS2_Smoke(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}

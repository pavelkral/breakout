// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ArkanoidUE5Target : TargetRules
{
	public ArkanoidUE5Target( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
          DefaultBuildSettings = BuildSettingsVersion.V5;
          IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
          ExtraModuleNames.AddRange( new string[] { "ArkanoidUE5" } );
	}
}

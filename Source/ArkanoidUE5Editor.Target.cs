// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ArkanoidUE5EditorTarget : TargetRules
{
     public ArkanoidUE5EditorTarget(TargetInfo Target) : base(Target)
     {
          Type = TargetType.Editor;
          DefaultBuildSettings = BuildSettingsVersion.V5;
		  IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
          ExtraModuleNames.Add("ArkanoidUE5");
     }
}

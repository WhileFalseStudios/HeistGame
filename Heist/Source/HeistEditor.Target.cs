// Copyright (c) While False Studios 2017.

using UnrealBuildTool;
using System.Collections.Generic;

public class HeistEditorTarget : TargetRules
{
	public HeistEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Heist" } );
	}
}

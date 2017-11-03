// Copyright (c) While False Studios 2017.

using UnrealBuildTool;
using System.Collections.Generic;

public class HeistTarget : TargetRules
{
	public HeistTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "Heist" } );
	}
}

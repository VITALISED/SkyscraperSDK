#pragma once

struct cGcGalaxyMap
{
	enum MapMode : __int32
	{
		Game = 0x0,
		Intro = 0x1,
		Final = 0x2,
		Tutorial = 0x3,
		Warp = 0x4,
	};

	enum TutorialState : __int32
	{
		HoldBeforFlyHome = 0x0,
		BeginFlyHome = 0x1,
		FlyHome = 0x2,
		HoldHome = 0x3,
		BeginLookAtTarget = 0x4,
		LookingAtTarget = 0x5,
		HoldCamera = 0x6,
		DrawLines = 0x7,
		Hold = 0x8,
		EndLookAtTarget = 0x9,
	};

};
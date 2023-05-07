#pragma once
#include "cGcGalaxyMap.h"

struct cGcHUDManager
{
	typedef cGcGalaxyMap::MapMode eMode;

	enum TransitionDirection : __int32
	{
		In = 0x0,
		Out = 0x1,
	};
};
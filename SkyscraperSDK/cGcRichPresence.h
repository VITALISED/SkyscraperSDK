#pragma once
#include "IStatWatcher.h"

struct __declspec(align(8)) cGcRichPresence : IStatWatcher
{
	bool mbOnPlanet;
	bool mbStormActive;
	bool mbPlayerOutside;
};
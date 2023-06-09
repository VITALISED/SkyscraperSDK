#pragma once
#include "cTkTypes.h"

struct __declspec(align(4)) cGcIdleAnimList
{
	TkID<128> mCurrentIdle;
	TkID<128> maIdles[10];
	int miNumIdles;
	TkID<128> maIdlesShuffled[10];
	int miNumIdlesShuffledRemaining;
	bool mbHasNonEatIdles;
};

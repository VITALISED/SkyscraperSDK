#pragma once
#include "cTkTypes.h"

struct __declspec(align(4)) cGcBeamEffect
{
	cTkSmartResHandle mBeamRes;
	TkHandle mBeamNode;
	TkHandle mBeamLine;
	float mfYFactor;
	float mfTimeLeft;
	int miDamageLevel;
	bool mbActive;
};
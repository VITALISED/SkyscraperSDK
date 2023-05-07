#pragma once
#include "cGcNGui.h"

struct __declspec(align(16)) cGcHUDLayer
{
	cTk2dLayer mLayer;
	cGcHUDLayerData* mpData;
};
#pragma once
#include "Curve.h"
#include "pch.h"

struct __declspec(align(8)) cGcTransition
{
	float mTValue;
	float mTDelta;
	eCurve mCurveFunction;
	std::function<void __cdecl(void)> mOnCompletionFn;
	bool mExtraWaitForTextures;
	bool mRunning;
};

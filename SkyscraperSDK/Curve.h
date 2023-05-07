#pragma once

enum eCurve : __int8
{
	ECurve_Linear = 0x0,
	ECurve_SmoothInOut = 0x1,
	ECurve_FastInSlowOut = 0x2,
	ECurve_BellSquared = 0x3,
	ECurve_Squared = 0x4,
	ECurve_Cubed = 0x5,
	ECurve_Logarithmic = 0x6,
	ECurve_SlowIn = 0x7,
	ECurve_SlowOut = 0x8,
	ECurve_ReallySlowOut = 0x9,
	ECurve_SmootherStep = 0xA,
	ECurve_SmoothFastInSlowOut = 0xB,
	ECurve_SmoothSlowInFastOut = 0xC,
	ECurve_EaseInSine = 0xD,
	ECurve_EaseOutSine = 0xE,
	ECurve_EaseInOutSine = 0xF,
	ECurve_EaseInQuad = 0x10,
	ECurve_EaseOutQuad = 0x11,
	ECurve_EaseInOutQuad = 0x12,
	ECurve_EaseInQuart = 0x13,
	ECurve_EaseOutQuart = 0x14,
	ECurve_EaseInOutQuart = 0x15,
	ECurve_EaseInQuint = 0x16,
	ECurve_EaseOutQuint = 0x17,
	ECurve_EaseInOutQuint = 0x18,
	ECurve_EaseInExpo = 0x19,
	ECurve_EaseOutExpo = 0x1A,
	ECurve_EaseInOutExpo = 0x1B,
	ECurve_EaseInCirc = 0x1C,
	ECurve_EaseOutCirc = 0x1D,
	ECurve_EaseInOutCirc = 0x1E,
	ECurve_EaseInBack = 0x1F,
	ECurve_EaseOutBack = 0x20,
	ECurve_EaseInOutBack = 0x21,
	ECurve_EaseInElastic = 0x22,
	ECurve_EaseOutElastic = 0x23,
	ECurve_EaseInOutElastic = 0x24,
	ECurve_EaseInBounce = 0x25,
	ECurve_EaseOutBounce = 0x26,
	ECurve_EaseInOutBounce = 0x27,
	ECurve_NumTypes = 0x28,
};

struct cTkCurveType
{
	eCurve meCurve;
};
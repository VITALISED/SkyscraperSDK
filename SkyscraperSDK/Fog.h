#pragma once
#include "Planet.h"

struct cGcFogProperties
{
	float mfFogStrength;
	float mfFogMax;
	float mfFogColourStrength;
	float mfFogColourMax;
	float mfHeightFogStrength;
	float mfHeightFogFadeOutStrength;
	float mfHeightFogOffset;
	float mfHeightFogMax;
	float mfFogHeight;
	cGcHeavyAirSetting mHeavyAir;
	float mfCloudRatio;
	float mfFullscreenEffect;
	float mfDepthOfField;
	float mfDepthOfFieldDistance;
	float mfDepthOfFieldFade;
	bool mbIsRaining;
	float mfRainWetness;
};

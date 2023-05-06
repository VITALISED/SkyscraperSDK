#pragma once
#include "cTkTypes.h"

enum eDepthOfFieldSetting : __int32
{
	EDepthOfFieldSetting_Off = 0x0,
	EDepthOfFieldSetting_Mid = 0x1,
	EDepthOfFieldSetting_On = 0x2,
	EDepthOfFieldSetting_Macro = 0x3,
	EDepthOfFieldSetting_NumTypes = 0x4,
};

struct __declspec(align(8)) cGcPhotoModeSettings
{
	float mfFog;
	float mfCloudAmount;
	cTkVector4 mSunDir;
	float mfFoV;
	eDepthOfFieldSetting meDepthOfFieldSetting;
	float mfDepthOfFieldDistance;
	float mfDepthOfFieldDistanceSpace;
	float mfHalfFocalPlaneDepth;
	float mfHalfFocalPlaneDepthSpace;
	float mfDepthOfFieldPhysConvergence;
	float mfDepthOfFieldPhysAperture;
	float mfVignette;
	int miFilter;
	float mfBloom;
};
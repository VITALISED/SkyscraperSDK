#pragma once
#include "cTkTypes.h"
#include "Planet.h"
#include "LightShaft.h"
#include "cTkTimeManager.h"
#include "Fog.h"

struct cGcSky
{
	enum eStormState : __int32
	{
		EStormState_Inactive = 0x0,
		EStormState_Warning = 0x1,
		EStormState_TransitionIn = 0x2,
		EStormState_Active = 0x3,
		EStormState_TransitionOut = 0x4,
		EStormState_NumStates = 0x5,
	};

	enum eFlightFogState : __int32
	{
		EFlightFogState_FadeToFoot = 0x0,
		EFlightFogState_OnFoot = 0x1,
		EFlightFogState_FadeToFlight = 0x2,
		EFlightFogState_InFlight = 0x3,
	};

	enum ePhotoModeSunLock : __int32
	{
		EPhotoModeSunLock_None = 0x0,
		EPhotoModeSunLock_Direction = 0x1,
		EPhotoModeSunLock_TimeOfDay = 0x2,
	};

	cGcWeatherHazardGiftManager mWeatherHazardGiftManager;
	cGcPlanetWeatherColourData mWeatherColours;
	cGcSkyProperties mSkyProperties;
	cGcFogProperties mFogProperties;
	cGcPlanetHeavyAirData mHeavyAirProperties;
	cGcLightShaftProperties mLightShaftProperties;
	cTkTimeManager::UTCFractional mLastWeatherUpdateTime;
	cTkSmartResHandle mCloudMaterial;
	cTkSmartResHandle mRainbowMaterial;
	cTkSmartResHandle mSkyMaterial;
	cTkSmartResHandle mStarsMaterial;
	cTkSmartResHandle mSkyDomeModel;
	cTkSmartResHandle mRainbowPlaneRes;
	TkHandle mSkyNode;
	TkHandle mStarfieldNode;
	TkHandle mRainbowPlaneNode;
	cTkFixedString<32, char> mFormattedTimeOfDay;
	unsigned __int64 mu64SunTimeOffset;
	float mfSolarSunAngle;
	cTkVector3 mSunDirection;
	cTkVector3 mLightDirection;
	cTkVector3 mSunAxis;
	cTkVector3 mRelativeUp;
	float mfAudioLevel;
	float mfWeatherStrength;
	float mfWeatherFilterStrength;
	eWeather meLastKnownWeatherType;
	float mfScreenFilterTimer;
	float mafStormHazardModifiers[5];
	cGcSky::eStormState meStormState;
	float mfForceStormLength;
	unsigned __int64 mu64ForceStormStart;
	cTkTimerTemplate<0> mRainFadeTimer;
	cTkTimerTemplate<0> mWetCaveFadeTimer;
	bool mbIsRaining;
	float mfWetness;
	cTkSmartResHandle mRainCylinderRes;
	TkHandle mRainCyclinderNode;
	TkHandle mRainCyclinderNode2;
	cTkSmoothCD<float> mfWeatherBloomInterpFactorGain;
	cTkSmoothCD<float> mfWeatherBloomInterpFactorThresh;
	float mfWeatherBloomImpulseDelay;
	bool mbIsInFlight;
	cGcSky::eFlightFogState meFlightFogState;
	float mfFlightTimer;
	float mfFlightFogStrength;
	float mfFlightHeightStrength;
	cTkSmoothCD<float> mfStormSpaceStrength;
	float mfSunsetBlend;
	float mfHorizonBlend;
	float mfSunColourBlend;
	float mfSunLightBlend;
	float mfLightColourBlend;
	cGcSky::ePhotoModeSunLock mePhotoModeSunLock;
	cTkVector3 mPhotoModeSunDirection;
	unsigned __int64 mu64SunLockStartTime;
	float mCachedForwardScatter;
	float mCachedBackwardScatter;
	float mHenyeyBalancePoint;
	int muiTemporalCloudStep;
	float mfLightInterpolationTimer;
	unsigned __int64 muiLastWeatherEffectUpdateTime;
	float mfMaxWeatherEffectDuration;
	std::vector<cGcWeatherEffect const*, TkSTLAllocatorShim<cGcWeatherEffect const*> > mapWeatherEffects;
	std::vector<cGcWeatherEffect const*, TkSTLAllocatorShim<cGcWeatherEffect const*> > mapWeatherHazards;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle, 4, -1> > maWeatherEffectResources;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle, 4, -1> > maWeatherHazardResources;
	std::vector<cGcWeatherEffectInstance*, TkSTLAllocatorShim<cGcWeatherEffectInstance*> > maActiveWeatherEffects;
	std::vector<cGcSky::ClusterSpawn, TkSTLAllocatorShim<cGcSky::ClusterSpawn> > maWeatherEffectClusterSpawns;
	std::vector<cGcSky::ClusterSpawn, TkSTLAllocatorShim<cGcSky::ClusterSpawn> > maWeatherHazardClusterSpawns;
	cGcRegionTerrain* mpCurrentPlayerRegion;
	float mfApproxRegionSize;
	std::vector<cGcSky::RegionUpdate, TkSTLAllocatorShim<cGcSky::RegionUpdate> > maUpdateRegions;
	int miFirstUpdateCounter;
	TkID<128> mDebugForceWeatherID;
	TkID<128> mLastDebugForceWeatherID;
	int miDebugForceWeatherCount;
};
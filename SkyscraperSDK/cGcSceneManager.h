#pragma once
#include "cTkTypes.h"

struct __declspec(align(8)) cGcSceneManager
{
	cGcSceneSettings* mpSettings;
	cTkFixedString<256, char> mCurrentScene;
	TkHandle mSceneNode;
	TkHandle mSpawnNode;
	TkHandle mLightNode;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maPlanetSceneNodes;
	cTkSmartResHandle maTrailResources[5];
	cTkSmartResHandle mDefaultTrailRes;
	cTkSmartResHandle maShipFlares[5];
	cTkSmartResHandle mDefaultShipFlareRes;
	cTkSmartResHandle mContrailRes;
	cTkSmartResHandle mMechContrailRes;
	cTkSmartResHandle mMechFoortprintRes;
	cTkSmartResHandle mMissileTrailRes;
	cTkSmartResHandle mAtmosphereGlowRes;
	cTkSmartResHandle mAtmosphereSmokeRes;
	cTkSmartResHandle mLandingSmokeRes;
	cTkSmartResHandle mSpeedCool;
	cTkSmartResHandle mSpeedCoolReverse;
	cTkSmartResHandle mDeathDropRes;
	cTkSmartResHandle mDeathDropSpaceRes;
	cTkSmartResHandle mTeleportEndEffectRes;
	cTkSmartResHandle mTeleportTravelEffectRes;
	cTkSmartResHandle mControllerLeftRes;
	cTkSmartResHandle mControllerRightRes;
	cTkSmartResHandle mLightMaterial;
	bool mbPendingSolarSystemRegenerate;
};
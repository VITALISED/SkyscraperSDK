#pragma once
#include "Procedural.h"

struct cGcGalacticAddressData
{
	int miVoxelX;
	int miVoxelY;
	int miVoxelZ;
	int miSolarSystemIndex;
	int miPlanetIndex;
};

struct cGcUniverseAddressData
{
	int miRealityIndex;
	cGcGalacticAddressData mGalacticAddress;
};

struct __declspec(align(8)) cGcPortalSaveData
{
	cTkSeed mPortalSeed;
	unsigned __int64 mu64LastPortalUA;
	bool mbIsStoryPortal;
};
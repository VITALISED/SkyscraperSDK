#pragma once
#include "cTkTypes.h"
#include "UniverseAddressData.h"
#include "SpaceStation.h"

// FIXME guh

struct cGcLightProperties
{
	cTkColour mSunColour;
	cTkColour mLightColour;
	cTkColour mBounceColour;
};

enum eAsteroidLevel : __int32
{
	EAsteroidLevel_NoRares = 0x0,
	EAsteroidLevel_SomeRares = 0x1,
	EAsteroidLevel_LotsOfRares = 0x2,
	EAsteroidLevel_NumTypes = 0x3,
};

struct cGcSolarSystemTraderSpawnData
{
	int miMaxToSpawn;
	float mfInitialTakeoffDelay;
	cTkVector2 mSequenceTakeoffDelay;
	int miChanceToDelayLaunch;
};

struct __declspec(align(16)) cGcSolarSystemData
{
	cTkSeed mSeed;
	cTkFixedString<128, char> macName;
	cGcSolarSystemClass mClass;
	cGcGalaxyStarTypes mStarType;
	int miPlanets;
	cTkFixedArray<cTkVector3, 8> maPlanetPositions;
	cTkFixedArray<cGcPlanetGenerationInputData, 8> maPlanetGenerationInputs;
	cTkFixedArray<int, 8> maiPlanetOrbits;
	int miPrimePlanets;
	cTkVector3 mSunPosition;
	TkID<128> mAsteroidSubstanceID;
	int miNumTradeRoutes;
	int miNumVisibleTradeRoutes;
	int miMaxNumFreighters;
	bool mbStartWithFreighters;
	cTkVector2 mFreighterTimer;
	cTkVector2 mSpacePirateTimer;
	cTkVector2 mPlanetPirateTimer;
	cTkVector2 mFlybyTimer;
	cTkVector2 mPoliceTimer;
	cGcSpaceStationSpawnData mSpaceStationSpawn;
	cGcSolarSystemTraderSpawnData mTraderSpawnOnOutposts;
	cGcSolarSystemTraderSpawnData mTraderSpawnInStations;
	cTkDynamicArray<cGcSolarSystemLocator> maLocators;
	cTkDynamicArray<cTkClassPointer> maAsteroidGenerators;
	eAsteroidLevel meAsteroidLevel;
	cGcPlanetColourData mColours;
	cGcLightProperties mLight;
	cGcSpaceSkyProperties mSky;
	cGcScreenFilters mScreenFilter;
	cTkFixedString<128, char> macHeavyAir;
	cTkDynamicArray<cGcAISpaceshipPreloadCacheData> maSystemShips;
	cGcAlienRace mInhabitingRace;
	cGcPlanetTradingData mTradingData;
	cGcPlayerConflictData mConflictData;
};

struct cGcAsteroidLayout
{
	std::vector<cTkVector3, TkSTLAllocatorShim<cTkVector3, 16, -1> > mPositions;
	std::vector<cGcAsteroidLayout::Data, TkSTLAllocatorShim<cGcAsteroidLayout::Data, 4, -1> > mData;
};

struct __declspec(align(16)) cGcSolarSystemAsteroidFields
{
	cTkMatrix34 mPlayerSpawnTM;
	cGcSolarSystemAsteroidFields::AsteroidGenerators mAsteroidGenerators;
	cGcAsteroidLayout mAsteroids;
};
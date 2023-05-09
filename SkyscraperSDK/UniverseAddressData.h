#pragma once
#include "Procedural.h"
#include "cGcInWorldUIManager.h"
#include "Marker.h"

enum eCentreJourneyDestination : __int32
{
	ECentreJourneyDestination_Next = 0x0,
	ECentreJourneyDestination_Abandoned = 0x1,
	ECentreJourneyDestination_Vicious = 0x2,
	ECentreJourneyDestination_Lush = 0x3,
	ECentreJourneyDestination_Balanced = 0x4,
	ECentreJourneyDestination_NumTypes = 0x5,
};

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

struct cGcGalacticSolarSystemAddress
{
	cGcGalacticVoxelCoordinate mVoxelCoordinate;
	unsigned __int16 mSolarIndex;
	unsigned __int16 mIteration;
};

struct __declspec(align(8)) cGcWarpJumpTarget
{
	cGcGalacticSolarSystemAddress mTargetSystem;
	cTkVector3 mTargetDirInMap;
	float mfDistanceToTarget;
	int miPortalPlanetIndex;
	bool mbWarpedFromAtlas;
};

struct cGcSpaceshipWarp
{
	typedef cGcInWorldUIManager::cGcScreenProjector::RepositioningState BoostDoubleTap;

	enum eWarpState : __int32
	{
		EWarpState_None = 0x0,
		EWarpState_Charge = 0x1,
		EWarpState_EnterTunnel = 0x2,
		EWarpState_WarpTunnel = 0x3,
		EWarpState_WaitForGeneration = 0x4,
		EWarpState_RespawnPlayer = 0x5,
		EWarpState_ExitTunnel = 0x6,
		EWarpState_WarpSlowdown = 0x7,
		EWarpState_RenderDebug = 0x8,
		EWarpState_NumStates = 0x9,
	};

	enum eWarpEffectType : __int32
	{
		EWT_Normal = 0x0,
		EWT_Teleport = 0x1,
		EWT_ToNextGalaxy = 0x2,
		EWT_BlackHole = 0x3,
		EWT_GalaxyMap = 0x4,
		EWT_Portal = 0x5,
		EWT_PortalStorySpace = 0x6,
		EWT_PortalStoryPlanet = 0x7,
		EWT_PortalCommunity = 0x8,
		EWT_Freighter = 0x9,
		EWT_NexusExit = 0xA,
		EWT_FreighterMegaWarp = 0xB,
		EWT_FakePortalTeleport = 0xC,
		EWT_Num = 0xD,
	};

	struct NexusWarpData
	{
		bool mbValid;
		cGcUniverseAddressData mAddress;
	};

	cGcSpaceshipWarp::eWarpMode meWarpMode;
	__declspec(align(16)) cGcWarpJumpTarget mJumpTarget;
	cGcSolarSystemLocator mLocatorTarget;
	TkAudioObject mAudioObject;
	cGcSpaceshipWarp::eWarpState meWarpState;
	float mfWarpStageTimer;
	float mfWarpTimeTotal;
	ePulseDriveState mePulseDriveState;
	float mfPulseDriveSpeed;
	float mfPulseDriveSpeedAccel;
	float mfPulseDriveTimer;
	float mfPulseDriveFuelTimer;
	float mfPulseDriveDistance;
	float mfPulseDriveDistanceSqToTarget;
	bool mbPulseDriveWanted;
	float mfSpaceFogFadeFactor;
	cGcSpaceshipWarp::BoostDoubleTap mePulseDriveBoostTapState;
	float mfPulseDriveBoostLastTime;
	int miPulseDriveCountdown;
	bool mbHasPulseDriveTrackPos;
	__declspec(align(16)) cGcMarkerPoint mPulseDriveTrackMarker;
	float mfLastPulseDriveFailTime;
	float mfLastThrottleValue;
	cTkMatrix34 mShipTransformAtStart;
	cTkMatrix34 mWarpInDestinationTM;
	cTkMatrix34 mPlayerRelativeToFreighter;
	float mfTunnelAlpha;
	float mfSlowdownTimer;
	cTkSmartResHandle maWarpTunnelRes[13];
	cTkSmartResHandle mPipelineRes;
	int miParticlePipelineStage;
	TkHandle mWarpTunnelNode;
	TkHandle mWarpTunnelLight;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maWarpTunnelMaterials;
	cTkSmartResHandle mWarpExitMaterial;
	float mfWarpShake;
	float mfWarpFov;
	float mfWarpEffectTimeMultiplier;
	float mfDebugRenderOffset;
	float mfDebugRenderAlpha;
	bool mbWarpTunnelHidden;
	bool mbWarpSoundFXActive;
	bool mbPrepared;
	cGcSpaceshipWarp::eWarpEffectType meCurrentWarpEffect;
	cGcTeleportEndpoint mTargetTeleportEndpoint;
	bool mbHasTargetTeleportEndpoint;
	bool mbWarpingWithinSystem;
	bool mbUsedPortal;
	bool mbRequestExitPulse;
	TkHandle mFreighterNode;
	cGcSpaceshipWarp::NexusWarpData mNexusWarpData;
};

enum eFrigateFlybyType
{
	EFrigateFlybyType_SingleShip = 0x0,
	EFrigateFlybyType_AmbientGroup = 0x1,
	EFrigateFlybyType_ScriptedGroup = 0x2,
	EFrigateFlybyType_DeepSpace = 0x3,
	EFrigateFlybyType_DeepSpaceCommon = 0x4,
	EFrigateFlybyType_NumTypes = 0x5,
	EFrigateFlybyType_Unspecified = 0xFFFFFFFF,
};

struct cGcFrigateFlyby
{
	cTkMatrix34 mSpawnMatrix;
	cGcPlayerCommunicatorMessage mCommunicatorMessage;
	TkID<256> mCommunitcatorOSDLocId;
	cTkTextureResource mMarkerIcon;
	__declspec(align(16)) cGcMarkerPoint mMarkerPoint;
	std::vector<enum eFrigateClass, TkSTLAllocatorShim<enum eFrigateClass> > maFrigateClasses;
	eFrigateFlybyType meFlybyType;
	cTkClassPoolHandle mSquadHandle;
	cTkVector3 mPointOfInterest;
	cGcFrigateFlybyTable* mpFlybyTable;
	bool mbCommunicationAllowed;
	bool mbAnythingSpawned;
	bool mbAlignWithSun;
};

enum ePulseEncounterState
{
	EPulseEncounterState_None = 0xFFFFFFFF,
	EPulseEncounterState_Prepare = 0x0,
	EPulseEncounterState_Waiting_To_Start = 0x1,
	EPulseEncounterState_Waiting_To_Exit_Pulse = 0x2,
	EPulseEncounterState_Loading = 0x3,
	EPulseEncounterState_Spawning = 0x4,
	EPulseEncounterState_Active = 0x5,
	EPulseEncounterState_CleanUp = 0x6,
	EPulseEncounterState_NumTypes = 0x7,
};

struct cGcGalaxyVoxelAttributesData
{
	bool mbInsideGoalGap;
	float mfUnitDistanceFromGoalEdge;
	float mfRegionColourValue;
	cTkVector2 mTransitPopulationDistanceRange;
	float mfTransitPopulationPerpDistance;
	int miGuideStarMinimumCount;
	int miGuideStarRenegadeCount;
	int miBlackholeCount;
	int miAtlasStationCount;
	cTkFixedArray<int, 12> maiBlackholeIndices;
	cTkFixedArray<int, 12> maiAtlasStationIndices;
};

enum eGalaxyStarType : __int32
{
	EGalaxyStarType_Yellow = 0x0,
	EGalaxyStarType_Green = 0x1,
	EGalaxyStarType_Blue = 0x2,
	EGalaxyStarType_Red = 0x3,
	EGalaxyStarType_NumTypes = 0x4,
};

struct cGcGalaxyStarTypes
{
	eGalaxyStarType meGalaxyStarType;
};

struct cGcGalaxyStarAnomaly
{
	eGalaxyStarAnomaly meGalaxyStarAnomaly;
};

struct cGcPlanetSize
{
	ePlanetSize mePlanetSize;
};

enum eWealthClass : __int32
{
	EWealthClass_Poor = 0x0,
	EWealthClass_Average = 0x1,
	EWealthClass_Wealthy = 0x2,
	EWealthClass_Pirate = 0x3,
	EWealthClass_NumTypes = 0x4,
};

struct cGcWealthClass
{
	eWealthClass meWealthClass;
};

enum eTradingClass : __int32
{
	ETradingClass_Mining = 0x0,
	ETradingClass_HighTech = 0x1,
	ETradingClass_Trading = 0x2,
	ETradingClass_Manufacturing = 0x3,
	ETradingClass_Fusion = 0x4,
	ETradingClass_Scientific = 0x5,
	ETradingClass_PowerGeneration = 0x6,
	ETradingClass_NumTypes = 0x7,
};

struct cGcTradingClass
{
	eTradingClass meTradingClass;
};

struct cGcPlanetTradingData
{
	cGcWealthClass mWealthClass;
	cGcTradingClass mTradingClass;
};

enum eConflictLevel : __int32
{
	EConflictLevel_Low = 0x0,
	EConflictLevel_Default = 0x1,
	EConflictLevel_High = 0x2,
	EConflictLevel_Pirate = 0x3,
	EConflictLevel_NumTypes = 0x4,
};

struct cGcPlayerConflictData
{
	eConflictLevel meConflictLevel;
};

struct __declspec(align(8)) cGcGalaxyStarAttributesData
{
	cGcGalaxyStarTypes mType;
	cGcGalaxyStarAnomaly mAnomaly;
	int miNumberOfPlanets;
	int miNumberOfPrimePlanets;
	cTkFixedArray<cGcPlanetSize, 16> maPlanetSizes;
	cTkFixedArray<int, 16> maiPlanetParentIndices;
	cTkFixedArray<cTkSeed, 16> maPlanetSeeds;
	cGcPlanetTradingData mTradingData;
	cGcPlayerConflictData mConflictData;
	cGcAlienRace mRace;
	bool mbAbandonedSystem;
	bool mbIsPirateSystem;
	bool mbIsSystemSafe;
};

struct __declspec(align(8)) cGcGalaxyAttributesAtAddress
{
	cGcGalaxyVoxelAttributesData mVoxel;
	cTkColour mVoxelPrimaryColour;
	cTkColour mVoxelSecondaryColour;
	cGcGalaxyStarAttributesData mStar;
	bool mbValid;
};

enum eSolarSystemClass : __int32
{
	ESolarSystemClass_Default = 0x0,
	ESolarSystemClass_Initial = 0x1,
	ESolarSystemClass_Anomaly = 0x2,
	ESolarSystemClass_GameStart = 0x3,
	ESolarSystemClass_NumTypes = 0x4,
};

struct cGcSolarSystemClass
{
	eSolarSystemClass meSolarSystemClass;
};

struct cGcSolarSystemGenerator
{
	struct GenerationData
	{
		const cGcSolarSystem* mpSolarSystem;
		cGcSolarSystemData* mMetaData;
		cGcSolarSystemAsteroidFields* mInfomap;
	};
};


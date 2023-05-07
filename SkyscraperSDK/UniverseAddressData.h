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
#pragma once
#include "INetworkPlayerEventsHandler.h"
#include "UniverseAddressData.h"
#include "AI.h"
#include "cTkTypes.h"
#include "Sentinel.h"
#include "Fiend.h"
#include "pch.h"

enum ePreviousExperienceLocation : __int32
{
	EPreviousExperienceLocation_Invalid = 0x0,
	EPreviousExperienceLocation_Planet = 0x1,
	EPreviousExperienceLocation_Space = 0x2,
	EPreviousExperienceLocation_Freighter = 0x3,
};

struct cGcPlayerExperienceDirector : INetworkPlayerEventsHandler
{
	enum eDebugCameraState : __int32
	{
		EDebugCameraState_Inactive = 0x0,
		EDebugCameraState_Playing = 0x1,
		EDebugCameraState_Paused = 0x2,
	};

	cGcRpcCallBase* RASS;
	std::array<float, 9> mafTimers;
	std::array<float, 9> mafWaitTimes;
	std::array<int, 9> maiRepeatCounters;
	std::array<float, 9> mafTimerAccelerators;
	cGcFrigateFlyby mFrigateFlyby;
	std::vector<cTkSphere, TkSTLAllocatorShim<cTkSphere> > maSpaceInvalidSpawnAreas;
	std::vector<cGcExperienceSpawn, TkSTLAllocatorShim<cGcExperienceSpawn> > maSpawns;
	std::vector<cTkUserIdBase<cTkFixedString<64, char> >, TkSTLAllocatorShim<cTkUserIdBase<cTkFixedString<64, char> >> > maPirateKillers;
	std::vector<Assistance, TkSTLAllocatorShim<Assistance> > maRequestedAssistances;
	bool mbPoliceActive;
	ePoliceEntrance mePoliceArrival;
	float mfPoliceArriveTimer;
	float mfPoliceAttackProbeTimer;
	float mfLastPoliceActiveTime;
	float mfPoliceEscapeTime;
	int mbPoliceHasWantedLevel;
	float mfLastCombatEventTime;
	std::vector<cGcSpawnRequest, TkSTLAllocatorShim<cGcSpawnRequest> > maSpawnRequests;
	eDefenceForceSpawn meDefenseForceSpawn;
	float mfDefenceForceStateStartTime;
	ePirateSpawn mePirateSpawn;
	float mfPirateStateActiveTime;
	cTkVector3 mPirateTargetPos;
	cTkVector3 mPirateTargetDir;
	int miNumActivePirateSpawns;
	cGcChooser<enum ePirateSpawn> maPirateChoosers[4];
	TkHandle mPirateTargetFreighter;
	cTkSeed mPirateSeed;
	cTkAttachmentPtr mpBountyTarget;
	cGcBountySpawnInfo* mpBountyInfo;
	cTkSeed mBountySeed;
	float mfLastSpaceCombatTime;
	float mfLastTraderRequestTime;
	cTkAttachmentPtr mpLastPirateRaidBuildingTarget;
	ePulseEncounterState mePulseEncounterState;
	const cGcPulseEncounterInfo* mpPulseEncounterInfo;
	float mfPulseEncounterActiveTime;
	cTkSmartResHandle mPulseEncounterResource;
	TkAddNodesHandle mPulseEncounterAddNodeHandle;
	TkHandle mPulseEncounterNode;
	TkHandle mPulseEncounterMarkerNode;
	float mfPulseEncounterObjectSpawnScale;
	cGcAIShipSpawn* mpPulseEncounterTraderShipSpawn;
	float mfPulseEncounterOverrideChance;
	TkID<256> mPulseEncounterCustomHailMessage;
	cTkMatrix34 mPulseEncounterSpawnMatrix;
	bool mbPulseEncounterSilentOverride;
	std::pair<TkID<128>, cTkSeed> mPulseEncounterIDSeed;
	float mfPusleEncounterSpawnEffectTimer;
	cTkMatrix34 mPulseEncounterSpawnEffectOriginMatrix;
	ePulseEncounterState meBackgroundSpaceEncounterState;
	const cGcBackgroundSpaceEncounterInfo* mpBackgroundSpaceEncounterInfo;
	cTkSmartResHandle mBackgroundSpaceEncounterResource;
	TkHandle mBackgroundSpaceEncounterNode;
	float mfBackgroundSpaceEncounterActiveTime;
	float mfExtremeWantedEscalator;
	robin_hood::detail::Table<1, 80, cTkAttachmentPtr, cTkAttachmentPtr, robin_hood::hash<cTkAttachmentPtr, void>, std::equal_to<cTkAttachmentPtr>> maRepairTargets;
	cGcSentinelInfo maCombatSquad;
	cGcPlayerExperienceDirector::eCombatSquad meCombatSquad;
	float mfCombatSquadTimer;
	cTkVector3 mCombatBasePos;
	bool mbCombatSquadDeployNotified;
	bool mbInvestigateMessageShown;
	bool mbFinalWaveRewardRequested;
	float mfFireRateModifierScore;
	float mfCrimeBlockedTimer;
	robin_hood::detail::Table<1, 80, cTkAttachmentPtr, TkID<128>, robin_hood::hash<cTkAttachmentPtr, void>, std::equal_to<cTkAttachmentPtr>, -1> maPendingSentinelSummons;
	cGcFiendManagerStandard mFiendManagerPlanet;
	cGcFiendManagerStandard mFiendManagerMission;
	cGcFiendManagerUnderwater mFiendManagerUnderwater;
	cGcFiendManagerStandard mFiendManagerFreighter;
	cGcFiendManagerStandard mFiendManagerSpace;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maSentinelResources;
	cTkSmartResHandle mSentinelCoverRes;
	cTkSmartResHandle mFiendRes;
	cTkSmartResHandle mScuttlerRes;
	cTkSmartResHandle mFloaterRes;
	cTkSmartResHandle mSpaceFloaterRes;
	cTkSmartResHandle mFreighterSlugRes;
	cTkSmartResHandle mMiniDroneRes;
	cTkSmartResHandle mFishFiendBigRes;
	cTkSmartResHandle mFishFiendSmallRes;
	cGcResourceElement mRockCreatureRes;
	cGcResourceElement mGroundWormRes;
	cTkSmartResHandle mGroundWormSpawnerRes;
	std::vector<cGcPlayerExperienceDirector::cGcArchetypeResource, TkSTLAllocatorShim<cGcPlayerExperienceDirector::cGcArchetypeResource> > mArchetypeResources;
	cGcPlayer* mpPlayer;
	cGcExperienceSpawnTable* mpSpawnTable;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maRobots;
	std::vector<cGcPlayerExperienceDirector::TrailerShipData, TkSTLAllocatorShim<cGcPlayerExperienceDirector::TrailerShipData> > maTrailerShips[2];
	cTkClassPoolHandle maTrailerShipSquads[2];
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maTrailerMechs;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maTrailerMechResources;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maTrailerNPCs;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maTrailerNPCResources;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maTrailerNPCBackpackResources;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maTrailerNPCPets;
	std::vector<sOwnedCreatureInfo, TkSTLAllocatorShim<sOwnedCreatureInfo> > maTrailerNPCPetData;
	cTkSmartResHandle mTrailerNPCNavArea;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maTrailerCreatures;
	int miSelectedTrailerCreature;
	cTkPersonalRNG mExperienceRNG;
	bool mDirectorEnabled;
	bool mbAllowPiratesDuringMPMissions;
	bool mbFiendsActive;
	float mfLastActiveFiendCombatTime;
	float mfLastActiveLocalFiendCombatTime;
	bool mbRewardEncounterActive;
	bool mbGroundWormsActive;
	float mfAlienPodAggroFactor;
	cTkSmoothCD<float> mfAlienPodAggroFactorSmoothed;
	float mfLastAlienPodAggroSetTime;
	TkAudioObject mAudioObject;
	int miAmbientSelect;
	float mfAmbientTimer;
	bool mbAllowAmbientFreighters;
	bool mbSpaceBattleRequested;
	bool mbSpaceBattleFlybyRequested;
	bool mbSpaceBattleSunResposition;
	float mfBattleFlyByDelay;
	int miMissionTradersRequested;
	bool mbSpaceBattleActive;
	int miSpaceBattleLevel;
	cTkMatrix34 mSpaceBattleMatrix;
	bool mbSpaceBattlePosGenerated;
	float mfBattleStartTime;
	int miNumSquadsOverride;
	TkID<128> mAttackDefinitionOverride;
	TkID<256> mRewardMessageOverride;
	bool mbPirateAttackSilent;
	float mfPirateAttackDistanceOverride;
	bool mbBlockNextCargoScan;
	float mfLastTraderDialogueStart;
	float mfLastTraderDialogueEnd;
	float mfTraderDialogueWait;
	float mfEndOfSeasonAlertDelay;
	bool mbForceSeasonEnd;
	cTkClassPoolHandle mSpaceBattleFreighterSquad;
	ePirateSpawn meRequestPirateSpawnType;
	ePreviousExperienceLocation mePreviousExperienceLocation;
	cGcVehicleCheckpointManager* mpVehicleRace;
	cTkClassPoolHandle mDebugInputMaskHandle;
	int miDebugDroneStage;
	bool mbDebugFlyby;
	int miRecordNPCWaypoints;
	int miRecordCreatureWaypoints;
	bool mbRecordPlayerRideWaypoints;
	float mfDebugSceneAutoSaveTimer;
	cGcPlayerExperienceDirector::eDebugCameraState meDebugCameraState;
	int miSelectedCamera;
	int miDisableCameraSmoothingFrames;
	bool mbDebugCameraSpin;
	float mfDebugCameraSpinTimer;
	bool mbDebugRepositionPlanets;
	cGcDebugScene* mpDebugScene;
	TkID<128> mDebugSpawnSentinelWave;
	robin_hood::detail::Table<0, 80, unsigned int, std::function<void __cdecl(cGcExperienceDebugTriggerAction const*, bool)>, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>> mDebugTriggers;
	cGcRpcCallBase* WANT;
	cGcRpcCallBase* RPJB;
	cGcRpcCallBase* BGBR;
};
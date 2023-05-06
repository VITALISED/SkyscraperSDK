#pragma once
#include "cGcCreature.h"
#include "Alien.h"

enum ePlayerSquadronSummonState : __int32
{
	EPlayerSquadronSummonState_None = 0x0,
	EPlayerSquadronSummonState_Incoming = 0x1,
	EPlayerSquadronSummonState_Active = 0x2,
	EPlayerSquadronSummonState_Leaving = 0x3,
};

struct cGcShipAISquadronSharedData
{
	bool mbLeaving;
	float mfLastFormationBreakTime;
	int miNumShipsInFormation;
};

struct cGcSquadronPilotInfo
{
	typedef sOwnedCreatureInfo::eLoadState eLoadState;

	enum eShipSpawnState : __int32
	{
		EShipSpawnState_None = 0x0,
		EShipSpawnState_SpawnRequested = 0x1,
		EShipSpawnState_LoadingResources = 0x2,
		EShipSpawnState_AttemptingSpawn = 0x3,
		EShipSpawnState_Spawned = 0x4,
		EShipSpawnState_DespawnRequested = 0x5,
	};

	cGcSquadronPilotInfo::eLoadState mePilotLoadState;
	cGcResourceElement mPilotNPCResource;
	eAlienRace mePilotRace;
	unsigned __int16 muPilotRank;
	cTkFixedString<127, char> msPilotName;
	cTkFixedString<127, char> msPilotNameLoc;
	unsigned __int64 muPilotTraitsSeed;
	cTkModelResourceRenderer mPilotThumbnailRenderer;
	cGcSquadronPilotInfo::eLoadState meSpaceshipLoadState;
	cGcResourceElement mSpaceshipResource;
	cTkModelResourceRenderer mSpaceshipThumbnailRenderer;
	cTkFixedString<127, char> mSpaceshipName;
	cTkAttachmentPtr mpSpaceshipAttachment;
	cGcSquadronPilotInfo::eShipSpawnState meShipSpawnState;
	float mfShipSpawnStateTime;
};

struct __declspec(align(16)) cGcPlayerSquadronOwnership
{
	enum eCombatSummonState : __int32
	{
		OutOfCombat = 0x0,
		InCombat_AutoSummoned = 0x1,
		InCombat_AlreadySummoned = 0x2,
		InCombat_Dismissed = 0x3,
	};

	struct sDismissRequest
	{
		bool mbRequested;
		bool mbWarpOut;
	};

	bool mbIsPrepared;
	cTkPersonalRNG mRNG;
	cTkClassPoolHandle mSquadHandle;
	cGcShipAISquadronSharedData mSquadronSharedBehaviourData;
	ePlayerSquadronSummonState meSquadronSummonState;
	float mfSquadronSummonStateTime;
	cGcSquadronPilotInfo maPilots[4];
	bool mabUnlockedSlots[4];
	cGcPlayerSquadronOwnership::eCombatSummonState meSquadronCombatSummonState;
	TkHandle mThumbnailsGroup;
	cGcPlayerSquadronOwnership::sDismissRequest mDismissRequest;
	bool mbDebugShowMovementTrails;
	bool mbDebugRequestOpenRecruitMenu;
	bool mbDebugRequestOpenPilotsMenu;
	bool mbDebugRequestSummonSquadron;
}; 
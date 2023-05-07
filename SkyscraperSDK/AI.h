#pragma once
#include "cTkTypes.h"
#include "cGcPlayerShip.h"

enum eAIFaction : __int32
{
	EAIFaction_Player = 0x0,
	EAIFaction_Civilian = 0x1,
	EAIFaction_Pirate = 0x2,
	EAIFaction_Police = 0x3,
	EAIFaction_Creature = 0x4,
	EAIFaction_NumTypes = 0x5,
};

enum eAIShipRole : __int32
{
	EAIShipRole_Standard = 0x0,
	EAIShipRole_PlayerSquadron = 0x1,
	EAIShipRole_Freighter = 0x2,
	EAIShipRole_CapitalFreighter = 0x3,
	EAIShipRole_SmallFreighter = 0x4,
	EAIShipRole_TinyFreighter = 0x5,
	EAIShipRole_Frigate = 0x6,
	EAIShipRole_NumTypes = 0x7,
};

enum ePoliceEntrance : __int32
{
	EPoliceEntrance_None = 0x0,
	EPoliceEntrance_Start = 0x1,
	EPoliceEntrance_Probing = 0x2,
	EPoliceEntrance_Incoming = 0x3,
	EPoliceEntrance_Arrived = 0x4,
	EPoliceEntrance_Escalate = 0x5,
	EPoliceEntrance_EscalateProbing = 0x6,
	EPoliceEntrance_EscalateIncoming = 0x7,
	EPoliceEntrance_CargoScanStart = 0x8,
	EPoliceEntrance_CargoScanProbing = 0x9,
	EPoliceEntrance_CargoScanAttemptContact = 0xA,
	EPoliceEntrance_CargoScanInComms = 0xB,
	EPoliceEntrance_CargoScanStartAttack = 0xC,
};

enum eDefenceForceSpawn : __int32
{
	EDefenceForceSpawn_None = 0x0,
	EDefenceForceSpawn_Waiting = 0x1,
	EDefenceForceSpawn_WaitingForFrigateAssignment = 0x2,
	EDefenceForceSpawn_SpawnFrigate = 0x3,
	EDefenceForceSpawn_SpawnDefenders = 0x4,
	EDefenceForceSpawn_Complete = 0x5,
};

enum ePirateSpawn : __int32
{
	EPirateSpawn_None = 0xFFFFFFFF,
	EPirateSpawn_CargoAttackStart = 0x0,
	EPirateSpawn_Probing = 0x1,
	EPirateSpawn_ProbeHail = 0x2,
	EPirateSpawn_ProbeSuccess = 0x3,
	EPirateSpawn_ProbeSuccessSilent = 0x4,
	EPirateSpawn_AttackWarning = 0x5,
	EPirateSpawn_Attacking = 0x6,
	EPirateSpawn_FreighterBattleStart = 0x7,
	EPirateSpawn_BattleMarker = 0x8,
	EPirateSpawn_Battling = 0x9,
	EPirateSpawn_BattleJoined = 0xA,
	EPirateSpawn_BattleEscaped = 0xB,
	EPirateSpawn_BountyStart = 0xC,
	EPirateSpawn_BountyPrepare = 0xD,
	EPirateSpawn_BountyActive = 0xE,
	EPirateSpawn_BountyAttacking = 0xF,
	EPirateSpawn_BountyFleeing = 0x10,
	EPirateSpawn_PlanetaryRaidStart = 0x11,
	EPirateSpawn_PlanetaryRaidApproaching = 0x12,
	EPirateSpawn_PlanetaryRaidAttacking = 0x13,
	EPirateSpawn_PlanetaryRaidFlee = 0x14,
	EPirateSpawn_PlanetaryFlyByStart = 0x15,
	EPirateSpawn_PlanetaryFlyByApproach = 0x16,
	EPirateSpawn_PlanetaryFlyByAttacking = 0x17,
	EPirateSpawn_PlanetaryFlyByFlee = 0x18,
	EPirateSpawn_NumTypes = 0x19,
};

struct __declspec(align(8)) cGcAIShipSpawn
{
	cTkAttachmentPtr mpMainAttachment;
	TkHandle mNode;
	bool mbUsesAISpaceshipComponent;
	eAIFaction meFaction;
	eAIShipRole meRole;
	eShipClass meClass;
	cTkClassPoolHandle mSquad;
};

struct __declspec(align(8)) cGcAIShipSquad
{
	cTkFixedString<256, char> mName;
	cTkClassPoolHandle mHandle;
	cTkRosterPool<cGcAIShipSpawn, 128> maShips;
	bool mbManaged;
	bool mbHasSentEngagedMessage;
};

struct cGcAISpaceshipManager
{
	enum eSortMethod : __int32
	{
		ESortMethod_Type = 0x0,
		ESortMethod_Squad = 0x1,
		ESortMethod_NumTypes = 0x2,
	};

	std::vector<cGcAISpaceshipManager::sFreighterSpawnInProgress, TkSTLAllocatorShim<cGcAISpaceshipManager::sFreighterSpawnInProgress1> > maFreighterSquadsBeingSpawned;
	ePlayerBoostCheck mePlayerBoostState;
	float mfPlayerBoostStateChangeTime;
	std::unordered_map<TkID<128>, cGcShipAICombatDefinition*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcShipAICombatDefinition*>> > mCombatDefinitionMap;
	cGcAISpaceshipManagerData* mpData;
	cGcShipAIAttackDataTable* mpAttackData;
	cTkSeed mSeed;
	robin_hood::detail::Table<1, 80, unsigned int, cGcCachedShipResource*, robin_hood::hash<unsigned int, void>, std::equal_to<unsigned int>> mShipPairCache;
	eAIFaction meBrowseFaction;
	eAIShipRole meBrowseRole;
	cTkClassPoolHandle mDefaultSquad;
	std::vector<cGcAIShipSpawnEvent, TkSTLAllocatorShim<cGcAIShipSpawnEvent> > maSpawnEvents;
	std::vector<cGcAIShipSpawnEvent, TkSTLAllocatorShim<cGcAIShipSpawnEvent> > maChildSpawnEvents;
	bool mbChildSpawnsActive;
	int miNumShipsAttackingPlayer;
	int miNumSquadsAttackingPlayer;
	cTkClassPool<cGcAIShipSquad, 64> maSquads;
	int miSquadCounter;
	cGcAISpaceshipManager::eSortMethod meSortMethod;
	cTkSmartResHandle mFreighterControllerRes;
	cTkPersonalRNG mRNG;
	cGcOutpostComponent* mpSelectedOutpost;
	cGcAISpaceshipComponent* mpSelectedShip;
	bool mbShowShootables;
	bool mbHighlightSelected;
	cTkSmartResHandle mLoot;
	TkHandle mLootRootGroop;
	cTkModelResource mAIHangarResource;
	TkHandle mFrigateBeingSpawned;
	cGcAIShipSpawn* mpFrigateSpawnData;
	cGcRpcCallBase* STSH;
	cGcRpcCallBase* SSSH;
	cGcRpcCallBase* TSSH;
	cGcRpcCallBase* WNSH;
	cGcRpcCallBase* STCC;
	cGcRpcCallBase* PLSS;
};

struct __declspec(align(8)) cGcNPCManager
{
	cGcRpcCallBase* NPIT;
	cGcRpcCallBase* NPRI;
	std::vector<cGcNPCManager::ManagedNPCResource, TkSTLAllocatorShim<cGcNPCManager::ManagedNPCResource> > maNPCResources;
	std::array<cTkSmartResHandle, 5> maHabitationNPCs;
	cTkSmartResHandle mFreighterNPCResource[4];
	cGcCustomisationPresets* mpNPCPresetCustomisations;
	cGcNPCSpawnTable* mpNPCSpawnTable;
	cGcNPCColourTable* mpNPCColourTable;
	cGcNPCPropTable* mpNPCPropTable;
	cGcNPCWordReactionTable* mpNPCWordReactions;
	cGcNPCWordReactionTable* mpTerminalWordReactions;
	cGcNPCInteractionsDataTable* mpNPCInteractionsTable;
	cGcNPCAnimationManager mNPCAnimationManager;
	cTkSmartResHandle mNPCChairResources[2];
	cTkSmartResHandle mNPCPropResources[13];
};

enum exBehaviourFlags : __int32
{
	FBehaviourFlags_DestroyTerrain = 0x1,
	FBehaviourFlags_DestroyAsteroids = 0x2,
	FBehaviourFlags_GatherResources = 0x4,
	FBehaviourFlags_Homing = 0x8,
	FBehaviourFlags_HomingLaser = 0x10,
	FBehaviourFlags_ScareCreatures = 0x20,
	FBehaviourFlags_ExplosionForce = 0x40,
	FBehaviourFlags_None = 0x0,
	FBehaviourFlags_Mask = 0x7F,
};

enum eClass : __int32
{
	EClass_Player = 0x0,
	EClass_PlayerShip = 0x1,
	EClass_Ship = 0x2,
	EClass_Robot = 0x3,
	EClass_NumTypes = 0x4,
};
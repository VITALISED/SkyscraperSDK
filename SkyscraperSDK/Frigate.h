#pragma once
#include "pch.h"
#include "INetworkPlayerEventsHandler.h"
#include "cTkTypes.h"
#include "Inventory.h"
#include "Alien.h"

enum eFrigateClass
{
	EFrigateClass_Combat = 0x0,
	EFrigateClass_Exploration = 0x1,
	EFrigateClass_Mining = 0x2,
	EFrigateClass_Diplomacy = 0x3,
	EFrigateClass_Support = 0x4,
	EFrigateClass_Normandy = 0x5,
	EFrigateClass_DeepSpace = 0x6,
	EFrigateClass_DeepSpaceCommon = 0x7,
	EFrigateClass_NumTypes = 0x8,
	EFrigateClass_Unspecified = 0xFFFFFFFF,
};

enum eExpeditionCategory : __int32
{
	EExpeditionCategory_Combat = 0x0,
	EExpeditionCategory_Exploration = 0x1,
	EExpeditionCategory_Mining = 0x2,
	EExpeditionCategory_Diplomacy = 0x3,
	EExpeditionCategory_Balanced = 0x4,
	EExpeditionCategory_NumTypes = 0x5,
};

struct __declspec(align(8)) cGcPlayerFleetManager : INetworkPlayerEventsHandler
{
	cGcPlayerCommunicatorMessage mDamageCommunicatorMessage;
	cGcPlayerCommunicatorMessage mInterventionCommunicatorMessage;
	std::array<cGcFleetFrigate, 30> maFrigatePool;
	std::array<cGcFleetExpedition, 20> maExpeditionPool;
	std::vector<cTkVector3, TkSTLAllocatorShim<cTkVector3> > maFrigateSpawnLocations;
	std::vector<cGcFleetExpedition, TkSTLAllocatorShim<cGcFleetExpedition> > maAvailableExpeditions;
	std::vector<unsigned __int64, TkSTLAllocatorShim<unsigned __int64> > mau64ExpeditionSeedsSelectedToday;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapFrigates;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapFrigatesWaitingForAIShipSpawn;
	std::vector<cGcFleetExpedition*, TkSTLAllocatorShim<cGcFleetExpedition*> > mapExpeditions;
	std::vector<cGcFleetExpedition*, TkSTLAllocatorShim<cGcFleetExpedition*> > mapActiveExpeditions;
	cGcFrigateOccupationTracker mFrigateOccupationTracker;
	cGcPurchasableFrigateTracker mPurchasableFrigateTracker;
	cTkClassPoolHandle mAIShipSquadHandle;
	cGcFleetFrigate* mpFrigateToRemoveFromFleet;
	cGcFleetExpedition* mpExpeditionToStart;
	unsigned __int64 mu64ExpeditionToStartStartTime;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapFrigatesToDespawn;
	cTkSeed mSeed;
	cTkSeed mLastKnownUASeed;
	unsigned __int64 mu64LastKnownDay;
	cGcFleetExpedition* mpInterventionExpedition;
	TkID<256> mInterventionEventDialog;
	float mfTimeUntilPlayerAlertedToInterventionEvent;
	float mfTimeUntilPlayerAlertedToDamagedFrigates;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > maCachedFrigateInteriorResources;
	cTkClassPoolHandle mInvalidAsteroidArea;
	cTkUserIdBase<cTkFixedString<64, char> > mOwnerId;
	float mfDelayUntilDespawnedFleetRespawns;
	bool mbPlayerAlertedToInterventionEvent;
	bool mbPlayerAlertedToDamagedFrigates;
	bool mbRequestShowInterventionInteraction;
	bool mbShouldAlertPlayerToPurchasableFrigates;
	bool mbPlayerHasSeenTodaysExpeditions;
};


struct cGcFleetFrigate
{
	std::array<cGcFrigateTraitData const*, 5> maTraits;
	std::vector<cGcMaintenanceComponent*, TkSTLAllocatorShim<cGcMaintenanceComponent*> > mapDamagedMaintenanceComponents;
	cTkVector3 mPirateDefenceSpawnPosition;
	unsigned __int64 mu64TimeOfLastIncomeCollection;
	cTkAABB mAABB;
	cTkSeed mSeed;
	cTkSeed mHomeSystemSeed;
	cTkSeed mForcedTraitsSeed;
	cTkFixedString<32, char> mCustomName;
	eFrigateClass meFrigateClass;
	eInventoryClass meInventoryClass;
	eAlienRace meRace;
	TkID<128> mPrimaryTraitOverride;
	float mfTimeUntilSpawnEvent;
	int miTotalNumberOfSuccessfulEvents;
	int miTotalNumberOfFailedEvents;
	int miTotalNumberOfExpeditions;
	int miNumberOfTimesDamaged;
	int maiStats[11];
	cTkBitArray<unsigned __int64> mDamageTaken;
	TkHandle mOnPlanetFalseFrigateNode;
	cGcAIShipSpawn* mpAIShipSpawn;
	const cGcPlayerCommon* mpPirateDefencePlayer;
	cTkAttachmentPtr mLODAttachment;
	cGcFleetExpedition* mpExpedition;
};

struct __declspec(align(8)) cGcFleetExpedition
{
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapAllFrigates;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapActiveFrigates;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapDamagedFrigates;
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapDestroyedFrigates;
	std::vector<cGcExpeditionEventResult, TkSTLAllocatorShim<cGcExpeditionEventResult> > maExpeditionEventResults;
	TkID<128> maPowerups[3];
	cTkSeed mSeed;
	TkID<128> mInterventionEventMissionID;
	unsigned __int64 mu64ExpeditionStartTime;
	unsigned __int64 mu64ExpeditionPauseTime;
	unsigned __int64 mu64TimeOfLastUAChange;
	int miNextEventToTrigger;
	int miChosenNumberOfEvents;
	eExpeditionCategory meExpeditionCategory;
	float mfSpeedMultiplier;
	unsigned __int64 mUA;
	cTkVector3 mSpawnPosition;
	cTkVector3 mTerminalPosition;
	int miNumberOfSuccessfulEventsThisExpedition;
	int miNumberOfFailedEventsThisExpedition;
	bool mbWaitingForCommunicatorResponse;
	bool mbLoadedEventResults;
	bool mbHaveGivenRewards;
};

struct __declspec(align(8)) cGcFrigateOccupationTracker
{
	std::vector<cGcFleetFrigate*, TkSTLAllocatorShim<cGcFleetFrigate*> > mapOccupiedFrigates;
	std::vector<cTkUserIdBase<cTkFixedString<64, char> >, TkSTLAllocatorShim<cTkUserIdBase<cTkFixedString<64, char> >> > maOccupyingPlayerIds;
	const cGcPlayerFleetManager* mFleetManager;
	int miOccupationCounter;
};

struct cGcPurchasableFrigateTracker
{
	TkHandle mContact;
	const cGcPlayerFleetManager* mOwner;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maUnavailableFrigates;
};

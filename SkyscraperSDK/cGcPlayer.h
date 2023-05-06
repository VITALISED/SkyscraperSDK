#pragma once
#include "IStatWatcher.h"
#include "Inventory.h"
#include "Procedural.h"
#include "Vehicle.h"
#include "UniverseAddressData.h"

enum eHand
{
	EHand_Right = 0x0,
	EHand_Left = 0x1,
	EHand_NumTypes = 0x2,
	EHand_Unspecified = 0xFFFFFFFF,
};

enum eScanEffectType : __int32
{
	EScanEffectType_Building = 0x0,
	EScanEffectType_TargetShip = 0x1,
	EScanEffectType_Creature = 0x2,
	EScanEffectType_Ground = 0x3,
	EScanEffectType_Objects = 0x4,
	EScanEffectType_NumTypes = 0x5,
};

struct cGcScanEffectData
{
	TkID<128> mId;
	eScanEffectType meScanEffectType;
	cTkColour mColour;
	float mfBasecolourIntensity;
	float mfScanlinesSeparation;
	float mfFresnelIntensity;
	float mfGlowIntensity;
	float mfWaveOffset;
	bool mbWaveActive;
	bool mbFixedUpAxis;
	bool mbTransparent;
	bool mbModelFade;
	float mfFadeInTime;
	float mfFadeOutTime;
};


enum ePlayerFinalisePurchaseState : __int32
{
	EPlayerFinalisePurchaseState_None = 0x0,
	EPlayerFinalisePurchaseState_SpawnNewShip = 0x1,
};

enum eLastKnownPlayerState : __int32
{
	ELastKnownPlayerState_OnFoot = 0x0,
	ELastKnownPlayerState_InShip = 0x1,
	ELastKnownPlayerState_InStation = 0x2,
	ELastKnownPlayerState_AboardFleet = 0x3,
	ELastKnownPlayerState_InNexus = 0x4,
	ELastKnownPlayerState_AbandonedFreighter = 0x5,
	ELastKnownPlayerState_InShipLanded = 0x6,
	ELastKnownPlayerState_NumTypes = 0x7,
};

struct cGcPlayerRespawn
{
	enum RespawnReason : __int32
	{
		FreshStart = 0x0,
		LoadSave = 0x1,
		LoadToLocation = 0x2,
		RestorePreviousSave = 0x3,
		DeathInSpace = 0x4,
		DeathOnPlanet = 0x5,
		DeathInOrbit = 0x6,
		DeathOnAbandonedFreighter = 0x7,
		WarpInShip = 0x8,
		Teleport = 0x9,
		Portal = 0xA,
		UpgradeSaveAfterPatch = 0xB,
		SwitchAmbientPlanet = 0xC,
		BaseViewerMode = 0xD,
		WarpInFreighter = 0xE,
		JoinMultiplayer = 0xF,
	};
};

struct cGcPlayerSpawnStateData
{
	cTkVector4 mPlayerPositionInSystem;
	cTkVector4 mPlayerTransformAt;
	cTkVector4 mPlayerDeathRespawnPositionInSystem;
	cTkVector4 mPlayerDeathRespawnTransformAt;
	cTkVector4 mShipPositionInSystem;
	cTkVector4 mShipTransformAt;
	eLastKnownPlayerState meLastKnownPlayerState;
	cTkVector4 mFreighterPositionInSystem;
	cTkVector4 mFreighterTransformAt;
	cTkVector4 mFreighterTransformUp;
	cTkVector4 mAbandonedFreighterPositionInSystem;
	cTkVector4 mAbandonedFreighterTransformAt;
	cTkVector4 mAbandonedFreighterTransformUp;
};

struct cGcPlayer
{
	enum eRocketBootsDoubleTapState : __int32
	{
		None = 0x0,
		WaitingForRelease = 0x1,
		WaitingForSecondTap = 0x2,
		SingleTap = 0x3,
		DoubleTap = 0x4,
	};

	//???
	//typedef cGcPlayer::eRocketBootsDoubleTapState cGcApplicationLocalLoadState::SaveRestoreMode;

};

struct cGcPlayerState
{
	struct __declspec(align(8)) ItemEvent
	{
		TkID<128> mId;
		float mfTime;
	};

	cTkFixedString<256, char> mNameWithTitle;
	sPlayerTitleStatWatcher mTitleStatWatcher;
	unsigned __int64 mu64ChangeRevision;
	cGcUniverseAddressData mGameStartLocation1;
	cGcUniverseAddressData mGameStartLocation2;
	cGcUniverseAddressData mLocation;
	cGcUniverseAddressData mPrevLocation;
	int miShield;
	int miHealth;
	int miShipHealth;
	unsigned int muUnits;
	unsigned int muNanites;
	unsigned int muSpecials;
	std::array<float, 6> mafRestoreHazardTimers;
	int miRestoreShield;
	int miRestoreHealth;
	int miRestoreShipShield;
	int miRestoreShipHealth;
	int miRestoreEnergy;
	cGcExactResource mWeaponResource;
	cTkFixedArray<cGcInventoryStore, 28> mInventories;
	std::vector<cGcInventoryStore, TkSTLAllocatorShim<cGcInventoryStore, 8, -1> > mShelvedInventories;
	cTkFixedArray<cGcInventoryStore, 7> mVehicleInventories;
	cTkFixedArray<cGcInventoryStore, 7> mVehicleTechInventories;
	cTkFixedArray<cGcVehicleLocation, 7> mVehicleLocations;
	eVehicleType mePrimaryVehicle;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventories;
	std::vector<cGcInventoryStore, TkSTLAllocatorShim<cGcInventoryStore, 8, -1> > mShelvedShipInventories;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesCargo;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesTechOnly;
	cTkFixedArray<cGcResourceElement, 12> mShipResources;
	int miPrimaryShip;
	std::vector<cGcRepairTechData, TkSTLAllocatorShim<cGcRepairTechData, 8, -1> > mRepairTechBuffer;
	std::vector<cTkVector3, TkSTLAllocatorShim<cTkVector3, 16, -1> > maSurveyedEventPositions;
	cGcPlayerLogBook mPlayerLog;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mSeenBaseBuildingObjects;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>, 8, -1> > mKnownTechnologies;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>, 8, -1> > mKnownProducts;
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>, 8, -1> > mKnownRefinerRecipes;
	std::vector<cGcWordGroupKnowledge, TkSTLAllocatorShim<cGcWordGroupKnowledge, 8, -1> > mKnownWordGroups;
	unsigned __int64 mu64TotalPlayTime;
	unsigned __int64 mu64TimeAlive;
	float mfTimeAccumulator;
	unsigned __int64 mu64HazardTimeAlive;
	float mfHazardTimeAccumulator;
	float mfLastInventoryStoreTime;
	float mfLastInventoryFailTime;
	int miProcTechIndex;
	cTkFixedArray<cGcSavedInteractionRaceData, 131> maSavedInteractionIndicies;
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>> > maInteractionLookupTable;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultSuitLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultWeaponLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultShipLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mGraveInventory;
	cGcUniverseAddressData mGraveLocation;
	cTkMatrix34 mGraveMatrix;
	bool mbSpawnGrave;
	bool mbSpaceGrave;
	bool mbPendingBootSpawnGrave;
	std::vector<cGcUniverseAddressData, TkSTLAllocatorShim<cGcUniverseAddressData> > mAtlasStationLocations;
	cTkLinearHashTable<unsigned __int64, TkID<256>, cTkLinearHashTableHash<unsigned __int64> > maInteractionDialogMap;
	bool mbFirstAtlasStationDiscovered;
	bool mbUsesThirdPersonCharacterCam;
	cTkVector4 mInitialSpawnPosition;
	cTkVector4 mInitialShipPosition;
	int miProgressionLevel;
	unsigned __int64 mActiveBattleUA;
	cGcPlayerState::ItemEvent mLastBuiltProduct;
	cGcPlayerState::ItemEvent mLastBuiltTech;
	cGcPlayerState::ItemEvent mLastRepairedTech;
	int miSlots;
	int miLevel;
	int miMaxTechValue;
	int miMaxTechs;
	bool mbFillAllSlots;
	bool mbWarpFromBlackHole;
	bool mbRevealBlackHoles;
	bool mbWarpFromRelicGate;
	bool mbWarpFromFreighterMegaWarp;
	bool mbUseSmallerBlackholeJumps;
	bool mbIsDataNew;
	std::vector<cGcSavedEntitlement, TkSTLAllocatorShim<cGcSavedEntitlement, 1, -1> > maUsedEntitlements;
	unsigned __int64 mu64LastSpaceBattleTime;
	int miLastSpaceBattleWarps;
	unsigned __int64 mu64LastMiniStationTime;
	int miLastMiniStationWarps;
	unsigned __int64 mMiniStationLocation;
	cTkVector3 mAnomalyPositionOverride;
	cGcPhotoModeSettings mPhotoModeSettings;
	std::vector<cGcTeleportEndpoint, TkSTLAllocatorShim<cGcTeleportEndpoint, 16, -1> > maTeleportEndpoints;
	cGcPlayerNPCWorkers mPlayerNPCWorkers;
	cGcInteractionData mHoloExplorerInteraction;
	cGcInteractionData mHoloScepticInteraction;
	cGcInteractionData mHoloNooneInteraction;
	cGcInteractionData mNetworkPlayerInteraction;
	cTkVector4 mStartGameShipPosition;
	bool mbShipNeedsTerrainPositioning;
	cTkFixedString<32, char> mCustomWeaponName;
	cTkFixedString<32, char> maCustomShipNames[12];
	cTkFixedString<32, char> maCustomVehicleNames[7];
	std::vector<cGcPortalSaveData, TkSTLAllocatorShim<cGcPortalSaveData, 8, -1> > maLastPortal;
	cGcPortalSaveData mLastPortal;
	int miKnownPortalRunes;
	bool mbOnOtherSideOfPortal;
	cGcTeleportEndpoint mOtherSideOfPortalReturnBase;
	cTkPhysRelVec3 mPortalMarkerPosition;
	unsigned __int64 mu64LastUABeforePortalWarp;
	unsigned __int64 mu64ActiveStoryPortalSeed;
	std::pair<TkID<128>, cTkSeed> mPreviousMission;
	std::pair<TkID<128>, cTkSeed> mCurrentMission;
	eWeaponMode meStartingPrimaryWeapon;
	eWeaponMode meStartingSecondaryWeapon;
	float mfVRCameraOffset;
	bool mbThirdPersonShipCam;
	bool mbThirdPersonVehicleCam;
	bool mbNextLoadSpawnsWithFreshStart;
	bool mbInitialised;
	bool mbVehicleAIControlEnabled;
	bool mbHasAccessToNexus;
	cGcUniverseAddressData mNexusUniverseLocation;
	cTkMatrix34 mNexusSavedMatrix;
	std::array<cGcResourceCustomisation, 23> mCustomisationData;
	std::array<cGcResourceCustomisation, 3> mOutfits;
	cTkFixedArray<cGcStoryPageSeenDataArray, 8> maSeenStoriesData;
	TkID<128> mJetpackEffect;
	cGcPlayerBanner mPlayerBanner;
	cGcSeasonState mSeasonState;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedSpecials;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedSeasonRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedTwitchRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedPlatformRewards;
	TkID<128> mPendingRewardId;
	bool mbHasPendingRewardFromSeason;
	bool mbHasPendingRewardFromTwitch;
	bool mbHasPendingRewardFromPlatform;
	ePlayerFinalisePurchaseState meFinalisePurchaseState;
	cGcSettlementState maSettlementStates[100];
	int miSettlementStateRingBufferIndex;
	cTkFixedString<128, char> macSaveName;
	cTkFixedString<128, char> macSaveSummary;
	const cGcRewardDeath* mpDeathReward;
	cGcCustomisationDescriptorGroups* mpCharacterCustomisationDescriptorGroups;
	cGcCustomisationTextureOptions* mpCharacterCustomisationTextureOptions;
	cGcCustomisationPresets* mpCharacterCustomisationPresets;
	cGcCustomisationColourPalettes* mpCustomisationColourPalettes;
	cGcCustomisationBannerGroup* mpCustomisationBannerData;
	cGcCustomisationThrusterEffects* mpCustomisationThrusterData;
	cGcCustomisationShipBobbleHeads* mpCustomisationShipBobbleHeads;
};

struct sPlayerTitleStatWatcher : IStatWatcher
{
	std::unordered_map<TkID<128>, cGcPlayerTitle const*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcPlayerTitle const*>, 8, -1> > mStatIdMap;
};

struct cGcPlayerLogBook
{
	std::vector<LogBookMessage, TkSTLAllocatorShim<LogBookMessage> > mPlayerLogs;
};

struct cGcInteractionData
{
	unsigned __int64 mu64GalacticAddress;
	unsigned __int64 mu64Value;
	cTkVector4 mPosition;
};

struct cGcSavedInteractionRaceData
{
	cTkFixedArray<int, 8> maiSavedRaceIndicies;
	cTkFixedArray<bool, 8> mabHasLoopedIndicies;
};

struct cGcPlayerBanner
{
	unsigned __int8 miIconIndex;
	unsigned __int8 miMainColourIndex;
	unsigned __int8 miBackgroundColourIndex;
	eInventoryClass meShipClass;
	TkID<128> mTitleId;
};
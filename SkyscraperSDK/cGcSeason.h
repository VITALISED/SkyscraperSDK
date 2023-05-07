#pragma once
#include "pch.h"
#include "cTkTypes.h"
#include "cGcApplication.h"
#include "Alien.h"

enum eSeasonSaveStateOnDeath
{
	ESeasonSaveStateOnDeath_Standard = 0x0,
	ESeasonSaveStateOnDeath_ResetAndQuit = 0x1,
	ESeasonSaveStateOnDeath_ResetPosSaveAndQuit = 0x2,
	ESeasonSaveStateOnDeath_SaveAndQuit = 0x3,
	ESeasonSaveStateOnDeath_NumTypes = 0x4,
	ESeasonSaveStateOnDeath_Unspecified = 0xFFFFFFFF,
};

struct cGcSeasonSaveStateOnDeath
{
	eSeasonSaveStateOnDeath meSeasonSaveStateOnDeath;
};

struct __declspec(align(4)) cGcSeasonalData
{
	cGcSeasonalGameModeData mData;
	cGcSeasonalGameModeData mLatestSeasonServerData;
	int miCachedServerSeasonId;
	unsigned __int64 mu64CachedServerSeasonStartTime;
	unsigned __int64 mu64CachedServerSeasonEndTime;
	unsigned __int64 mu64CachedServerSeasonDataHash;
	int miCachedServerNextSeasonId;
	unsigned __int64 mu64CachedServerNextSeasonStartTime;
	std::vector<std::pair<void(__cdecl*)(void*), void*>, TkSTLAllocatorShim<std::pair<void(__cdecl*)(void*), void*> > > mDataDownloadedCallbacks;
	bool mbWaitingForDataToDownload;
	bool mbDataDownloadFailed;
	bool mbDataAvailable;
	bool mbDataLocked;
	bool mbServerDataAvailable;
};

struct __declspec(align(8)) cGcSeasonalGameModeData
{
	int miSeasonId;
	unsigned __int64 mu64StartTimeUTC;
	unsigned __int64 mu64EndTimeUTC;
	unsigned __int64 mu64Hash;
	cTkFixedString<32, char> macTitle;
	cTkFixedString<32, char> macSubtitle;
	cTkFixedString<32, char> macDescription;
	TkID<256> mFinalStageTitle;
	TkID<256> mMilestoneWithStageLocId;
	cGcGameMode mGameMode;
	cGcDifficultyPresetType mDifficultySettingPreset;
	cGcDifficultySettingsData mDifficultyMinimums;
	cTkFixedString<32, char> macSeasonalUAOverride;
	unsigned __int64 mu64UAOverrideValue;
	TkID<128> mFinalReward;
	TkID<128> mFinalRewardSwitchAlt;
	TkID<256> mFinalCantRewardMessage;
	cTkFixedString<512, char> macFinalRewardDescription;
	cTkTextureResource mMainIcon;
	int miSeasonNumber;
	int miRemixNumber;
	int miDisplayNumber;
	TkID<256> mSeasonName;
	TkID<256> mSeasonNameUpper;
	TkID<256> mMainMissionTitle;
	TkID<256> mMainMissionMessage;
	bool mbDoCommunityMissionTextSubstitutions;
	bool mbDefaultToPvPOff;
	bool mbMustCraftInBases;
	cTkDynamicArray<TkID<128> > maAdditionalTradeProducts;
	cTkDynamicArray<TkID<128> > maNeverTradeProducts;
	int miStartingSuitSlots;
	int miStartingSuitTechSlots;
	int miStartingSuitCargoSlots;
	cTkSeed mWeaponSeed;
	cTkSeed mShipSeed;
	cGcSpaceshipClasses mShipType;
	bool mbStartWithFreighter;
	cTkFixedString<128, char> macFreighterBaseOverrideFilename;
	cGcAlienRace mFreighterRace;
	bool mbStartAboardFreighter;
	bool mbForceStartSystemTernary;
	bool mbForceStartSystemAbandoned;
	cTkDynamicArray<cGcBuildingClassification> maValidSpawnBuildings;
	cGcInventoryLayout mWeaponInventoryLayout;
	cGcInventoryLayout mShipInventoryLayout;
	cGcInventoryLayout mShipTechInventoryLayout;
	bool mbUseDefaultAppearance;
	cGcInventoryContainer mInventory;
	cGcInventoryContainer mInventory_TechOnly;
	cGcInventoryContainer mInventory_Cargo;
	cGcInventoryContainer mShipInventory;
	cGcInventoryContainer mWeaponInventory;
	bool mbUseRandomPet;
	cTkDynamicArray<cGcSeasonPetConstraints> maRandomPetConstraints;
	cTkFixedArray<cGcPetData, 18> maSpecificPets;
	cTkDynamicArray<cGcSandwormTimerAndFrequencyOverride> maSandwormOverrides;
	bool mbSandwormGlobalOverride;
	float mfSandwormGlobalOverrideTimer;
	float mfSandwormGlobalOverrideSpawnChance;
	bool mbStartNextToShip;
	float mfDistanceFromShipAtStartOfGame;
	bool mbShipStartsDamaged;
	bool mbAllowMissionDetailMessages;
	bool mbUseStartPlanetObjectListOverrides;
	TkID<128> mStartPlanetRareSubstanceOverride;
	bool mbTrashInventoryOnGalaxyTravel;
	int miFreighterBattleEarlyWarpsOverride;
	bool mbForceDeepSpaceAmbientFrigatesOnInfested;
	int miTechCostMultiplier;
	cTkDynamicArray<TkID<128> > maNeverLearnableTech;
	cTkDynamicArray<TkID<128> > maForgottenProducts;
	bool mbIncreaseXClassTechOddsWithCommTier;
	float mfAbandonedFreighterHazardProtectionMul;
	float mfHazardProtectionDrainMultiplier;
	float mfEnergyDrainMultiplier;
	int miQuestSubstanceReducer;
	cTkDynamicArray<cGcSeasonalStage> maStages;
	cGcScanEventTable mScanEventTable;
	bool mbResetSaveOnDeath;
	cTkDynamicArray<cGcPersistedStatData> maStatsToPersistOnReset;
	bool mbCompatibleWithState;
	bool mbHasBeenConverted;
	cTkDynamicArray<cGcTechnology> maTechnologyTable;
	cTkDynamicArray<cGcProductData> maProductTable;
	cTkDynamicArray<cGcRealitySubstanceData> maSubstanceTable;
	cGcTradeData mSeasonalUAStationTradeData;
	bool mbUseSeasonalUAStationTradeData;
};

struct cGcSeasonState
{
	struct sPinnedMilestone
	{
		int miStageIndex;
		int miMilestoneIndex;
	};

	struct sPendingMilestoneReward
	{
		int miStageIndex;
		int miMilestoneIndex;
	};

	std::vector<cGcSeasonState::sSeasonalStageProgress, TkSTLAllocatorShim<cGcSeasonState::sSeasonalStageProgress> > maStageProgress;
	cGcSeasonState::sPinnedMilestone mPinnedMilestone;
	cGcSeasonState::sPendingMilestoneReward mPendingMilestoneReward;
	std::vector<unsigned __int64, TkSTLAllocatorShim<unsigned __int64> > maRendezvousUAs;
	std::vector<cGcSeasonState::sSeasonInitialBuilding, TkSTLAllocatorShim<cGcSeasonState::sSeasonInitialBuilding> > maInitialBuildings;
	robin_hood::detail::Table<1, 80, unsigned __int64, std::vector<cGcSeasonState::sBuildingPreventionArea, TkSTLAllocatorShim<cGcSeasonState::sBuildingPreventionArea> >, robin_hood::hash<unsigned __int64, void>, std::equal_to<unsigned __int64>> mBuildingPreventionAreas;
	cGcSeasonSaveStateOnDeath mStateOnDeath;
	std::vector<cGcTechnology, TkSTLAllocatorShim<cGcTechnology> > maReplacedTechnologies;
	std::vector<cGcProductData, TkSTLAllocatorShim<cGcProductData> > maReplacedProducts;
	std::vector<cGcRealitySubstanceData, TkSTLAllocatorShim<cGcRealitySubstanceData> > maReplacedSubstances;
	bool mbWantToUpdateRewardAvailability;
	bool mbHasCollectedFinalReward;
	bool mbFinalRewardFitsInInventory;
};
#pragma once

enum eDifficultyPresetType : __int32
{
	EDifficultyPresetType_Invalid = 0x0,
	EDifficultyPresetType_Custom = 0x1,
	EDifficultyPresetType_Normal = 0x2,
	EDifficultyPresetType_Creative = 0x3,
	EDifficultyPresetType_Relaxed = 0x4,
	EDifficultyPresetType_Survival = 0x5,
	EDifficultyPresetType_Permadeath = 0x6,
	EDifficultyPresetType_NumTypes = 0x7,
};

enum eDeathConsequencesDifficulty : __int32
{
	EDeathConsequencesDifficulty_None = 0x0,
	EDeathConsequencesDifficulty_ItemGrave = 0x1,
	EDeathConsequencesDifficulty_DestroyItems = 0x2,
	EDeathConsequencesDifficulty_DestroySave = 0x3,
	EDeathConsequencesDifficulty_NumTypes = 0x4,
};

struct cGcDeathConsequencesDifficultyOption
{
	eDeathConsequencesDifficulty meDeathConsequencesDifficulty;
};

enum eDamageGivenDifficulty : __int32
{
	EDamageGivenDifficulty_High = 0x0,
	EDamageGivenDifficulty_Normal = 0x1,
	EDamageGivenDifficulty_Low = 0x2,
	EDamageGivenDifficulty_NumTypes = 0x3,
};

struct cGcDamageGivenDifficultyOption
{
	eDamageGivenDifficulty meDamageGivenDifficulty;
};

enum eActiveSurvivalBarsDifficulty : __int32
{
	EActiveSurvivalBarsDifficulty_None = 0x0,
	EActiveSurvivalBarsDifficulty_HealthOnly = 0x1,
	EActiveSurvivalBarsDifficulty_HealthAndHazard = 0x2,
	EActiveSurvivalBarsDifficulty_All = 0x3,
	EActiveSurvivalBarsDifficulty_NumTypes = 0x4,
};

struct cGcActiveSurvivalBarsDifficultyOption
{
	eActiveSurvivalBarsDifficulty meActiveSurvivalBarsDifficulty;
};

enum eHazardDrainDifficulty : __int32
{
	EHazardDrainDifficulty_Slow = 0x0,
	EHazardDrainDifficulty_Normal = 0x1,
	EHazardDrainDifficulty_Fast = 0x2,
	EHazardDrainDifficulty_NumTypes = 0x3,
};

struct cGcHazardDrainDifficultyOption
{
	eHazardDrainDifficulty meHazardDrainDifficulty;
};

enum eEnergyDrainDifficulty : __int32
{
	EEnergyDrainDifficulty_Slow = 0x0,
	EEnergyDrainDifficulty_Normal = 0x1,
	EEnergyDrainDifficulty_Fast = 0x2,
	EEnergyDrainDifficulty_NumTypes = 0x3,
};


struct cGcEnergyDrainDifficultyOption
{
	eEnergyDrainDifficulty meEnergyDrainDifficulty;
};

enum eSubstanceCollectionDifficulty : __int32
{
	ESubstanceCollectionDifficulty_High = 0x0,
	ESubstanceCollectionDifficulty_Normal = 0x1,
	ESubstanceCollectionDifficulty_Low = 0x2,
	ESubstanceCollectionDifficulty_NumTypes = 0x3,
};

struct cGcSubstanceCollectionDifficultyOption
{
	eSubstanceCollectionDifficulty meSubstanceCollectionDifficulty;
};

enum eInventoryStackLimitsDifficulty : __int32
{
	EInventoryStackLimitsDifficulty_High = 0x0,
	EInventoryStackLimitsDifficulty_Normal = 0x1,
	EInventoryStackLimitsDifficulty_Low = 0x2,
	EInventoryStackLimitsDifficulty_NumTypes = 0x3,
};

struct cGcInventoryStackLimitsDifficultyOption
{
	eInventoryStackLimitsDifficulty meInventoryStackLimitsDifficulty;
};

enum eChargingRequirementsDifficulty : __int32
{
	EChargingRequirementsDifficulty_None = 0x0,
	EChargingRequirementsDifficulty_Low = 0x1,
	EChargingRequirementsDifficulty_Normal = 0x2,
	EChargingRequirementsDifficulty_High = 0x3,
	EChargingRequirementsDifficulty_NumTypes = 0x4,
};

struct cGcChargingRequirementsDifficultyOption
{
	eChargingRequirementsDifficulty meChargingRequirementsDifficulty;
};

enum eFuelUseDifficulty : __int32
{
	EFuelUseDifficulty_Free = 0x0,
	EFuelUseDifficulty_Cheap = 0x1,
	EFuelUseDifficulty_Normal = 0x2,
	EFuelUseDifficulty_Expensive = 0x3,
	EFuelUseDifficulty_NumTypes = 0x4,
};

struct cGcFuelUseDifficultyOption
{
	eFuelUseDifficulty meFuelUseDifficulty;
};

enum eLaunchFuelCostDifficulty : __int32
{
	ELaunchFuelCostDifficulty_Free = 0x0,
	ELaunchFuelCostDifficulty_Low = 0x1,
	ELaunchFuelCostDifficulty_Normal = 0x2,
	ELaunchFuelCostDifficulty_High = 0x3,
	ELaunchFuelCostDifficulty_NumTypes = 0x4,
};

struct cGcLaunchFuelCostDifficultyOption
{
	eLaunchFuelCostDifficulty meLaunchFuelCostDifficulty;
};

enum eCurrencyCostDifficulty : __int32
{
	ECurrencyCostDifficulty_Free = 0x0,
	ECurrencyCostDifficulty_Cheap = 0x1,
	ECurrencyCostDifficulty_Normal = 0x2,
	ECurrencyCostDifficulty_Expensive = 0x3,
	ECurrencyCostDifficulty_NumTypes = 0x4,
};

struct cGcCurrencyCostDifficultyOption
{
	eCurrencyCostDifficulty meCurrencyCostDifficulty;
};

enum eItemShopAvailabilityDifficulty : __int32
{
	EItemShopAvailabilityDifficulty_High = 0x0,
	EItemShopAvailabilityDifficulty_Normal = 0x1,
	EItemShopAvailabilityDifficulty_Low = 0x2,
	EItemShopAvailabilityDifficulty_NumTypes = 0x3,
};

struct cGcItemShopAvailabilityDifficultyOption
{
	eItemShopAvailabilityDifficulty meItemShopAvailabilityDifficulty;
};

enum eScannerRechargeDifficulty : __int32
{
	EScannerRechargeDifficulty_VeryFast = 0x0,
	EScannerRechargeDifficulty_Fast = 0x1,
	EScannerRechargeDifficulty_Normal = 0x2,
	EScannerRechargeDifficulty_Slow = 0x3,
	EScannerRechargeDifficulty_NumTypes = 0x4,
};

struct cGcScannerRechargeDifficultyOption
{
	eScannerRechargeDifficulty meScannerRechargeDifficulty;
};

enum eReputationGainDifficulty : __int32
{
	EReputationGainDifficulty_VeryFast = 0x0,
	EReputationGainDifficulty_Fast = 0x1,
	EReputationGainDifficulty_Normal = 0x2,
	EReputationGainDifficulty_Slow = 0x3,
	EReputationGainDifficulty_NumTypes = 0x4,
};

struct cGcReputationGainDifficultyOption
{
	eReputationGainDifficulty meReputationGainDifficulty;
};

enum eCreatureHostilityDifficulty : __int32
{
	ECreatureHostilityDifficulty_NeverAttack = 0x0,
	ECreatureHostilityDifficulty_AttackIfProvoked = 0x1,
	ECreatureHostilityDifficulty_FullEcosystem = 0x2,
	ECreatureHostilityDifficulty_NumTypes = 0x3,
};

struct cGcCreatureHostilityDifficultyOption
{
	eCreatureHostilityDifficulty meCreatureHostilityDifficulty;
};

enum eCombatTimerDifficultyOption : __int32
{
	ECombatTimerDifficultyOption_Off = 0x0,
	ECombatTimerDifficultyOption_Slow = 0x1,
	ECombatTimerDifficultyOption_Normal = 0x2,
	ECombatTimerDifficultyOption_Fast = 0x3,
	ECombatTimerDifficultyOption_NumTypes = 0x4,
};

struct cGcCombatTimerDifficultyOption
{
	eCombatTimerDifficultyOption meCombatTimerDifficultyOption;
};

enum eSprintingCostDifficulty : __int32
{
	ESprintingCostDifficulty_Free = 0x0,
	ESprintingCostDifficulty_Low = 0x1,
	ESprintingCostDifficulty_Full = 0x2,
	ESprintingCostDifficulty_NumTypes = 0x3,
};

struct cGcSprintingCostDifficultyOption
{
	eSprintingCostDifficulty meSprintingCostDifficulty;
};

enum eBreakTechOnDamageProbability : __int32
{
	EBreakTechOnDamageProbability_None = 0x0,
	EBreakTechOnDamageProbability_Low = 0x1,
	EBreakTechOnDamageProbability_High = 0x2,
	EBreakTechOnDamageProbability_NumTypes = 0x3,
};

struct cGcBreakTechOnDamageDifficultyOption
{
	eBreakTechOnDamageProbability meBreakTechOnDamageProbability;
};

struct cGcDifficultyPresetType
{
	eDifficultyPresetType meDifficultyPresetType;
};

struct cGcDifficultyStateData
{
	cGcDifficultyPresetType mPreset;
	cGcDifficultyPresetType mEasiestUsedPreset;
	cGcDifficultyPresetType mHardestUsedPreset;
	cGcDifficultySettingsData mSettings;
};

struct cGcDifficultySettingsData
{
	bool mbSettingsLocked;
	bool mbInventoriesAlwaysInRange;
	bool mbAllSlotsUnlocked;
	bool mbWarpDriveRequirements;
	bool mbCraftingIsFree;
	bool mbTutorialEnabled;
	bool mbStartWithAllItemsKnown;
	bool mbBaseAutoPower;
	cGcDeathConsequencesDifficultyOption mDeathConsequences;
	cGcDamageReceivedDifficultyOption mDamageReceived;
	cGcDamageGivenDifficultyOption mDamageGiven;
	cGcActiveSurvivalBarsDifficultyOption mActiveSurvivalBars;
	cGcHazardDrainDifficultyOption mHazardDrain;
	cGcEnergyDrainDifficultyOption mEnergyDrain;
	cGcSubstanceCollectionDifficultyOption mSubstanceCollection;
	cGcInventoryStackLimitsDifficultyOption mInventoryStackLimits;
	cGcChargingRequirementsDifficultyOption mChargingRequirements;
	cGcFuelUseDifficultyOption mFuelUse;
	cGcLaunchFuelCostDifficultyOption mLaunchFuelCost;
	cGcCurrencyCostDifficultyOption mCurrencyCost;
	cGcItemShopAvailabilityDifficultyOption mItemShopAvailability;
	cGcScannerRechargeDifficultyOption mScannerRecharge;
	cGcReputationGainDifficultyOption mReputationGain;
	cGcCreatureHostilityDifficultyOption mCreatureHostility;
	cGcCombatTimerDifficultyOption mSpaceCombatTimers;
	cGcCombatTimerDifficultyOption mGroundCombatTimers;
	cGcSprintingCostDifficultyOption mSprintingCost;
	cGcBreakTechOnDamageDifficultyOption mBreakTechOnDamage;
};

struct __declspec(align(4)) cGcDifficultySettings
{
	cGcDifficultyStateData mDifficultyStateData;
	bool mbDifficultySettingsDirty;
	bool mbDebugRequestOpenFrontEndMenu;
};
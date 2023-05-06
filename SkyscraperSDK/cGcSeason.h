#pragma once
#include "pch.h"
#include "cTkTypes.h"

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
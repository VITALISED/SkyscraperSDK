#pragma once
#include "pch.h"
#include "cTkTypes.h"
#include "IDiscoveryManagerEventHandler.h"
#include "INetworkPlayerEventsHandler.h"
#include "UniverseAddressData.h"
#include "cGcPlayer.h"

struct cGcMPMissionSelectionHelper
{
	std::vector<cGcMPMissionSelectionHelper::sGcOfferedMPMission, TkSTLAllocatorShim<cGcMPMissionSelectionHelper::sGcOfferedMPMission, 8, -1> > maAvailableMissions;
	cGcRpcCallBase* MPMO;
	cGcRpcCallBase* MPMR;
	cGcRpcCallBase* MPML;
	cGcRpcCallBase* MPRS;
	cGcRpcCallBase* MPMB;
};

struct cGcMPMissionTracker : INetworkPlayerEventsHandler, IDiscoveryManagerEventHandler
{
	typedef cGcPlayer::eRocketBootsDoubleTapState InventoryChoice;

	cGcMPMissionSelectionHelper mMissionSelectionHelper;
	std::vector<cGcMPMissionTracker::sGcSyncedMPMissionPlayerData, TkSTLAllocatorShim<cGcMPMissionTracker::sGcSyncedMPMissionPlayerData> > maPlayerData;
	TkID<128> mMissionId;
	cTkSeed mMissionSeed;
	bool mbMissionRewardsQuicksilver;
	bool mbMissionIsWeekendEvent;
	cGcUniverseAddressData mPreMissionUA;
	unsigned __int64 mNexusExitUA;
	InventoryChoice meInventoryBeingCounted;
	int miElementBeingCounted;
	int miElementRunningTotal;
	float mfTimeUntilNextSync;
	unsigned __int64 mSyncedDiscoveryPlanet;
	cGcDiscoveryData mSyncedPlanetDiscoveryData;
	cGcDiscoverySearch* mpDiscoverySearch;
	std::vector<enum eDiscoveryType, TkSTLAllocatorShim<enum eDiscoveryType> > maeDiscoveryTypesToRefresh;
	bool mbWantToSyncWhenInventoryIsCounted;
	cGcRpcCallBase* SMPM;
	cGcRpcCallBase* SMPS;
	cGcRpcCallBase* SMPD;
	cGcRpcCallBase* REMO;
	cGcRpcCallBase* OMMS;
	cGcRpcCallBase* PLLM;
};
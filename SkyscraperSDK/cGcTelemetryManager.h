#pragma once
#include "IStatVariantWatcher.h"
#include "pch.h"
#include "cTkTypes.h"

struct cGcTelemetryManager : IStatVariantWatcher
{
	robin_hood::detail::Table<1, 80, TkID<128>, cGcStatDefinition const*, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mStatDefinitionLookup;
	robin_hood::detail::Table<1, 80, TkID<128>, Stat, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mStats;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mStatChangesSinceLastSave;
	robin_hood::detail::Table<1, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mMissionStagesCached;
	robin_hood::detail::Table<1, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mLevelledStatStagesCached;
	robin_hood::detail::Table<1, 80, TkID<128>, int, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mStatStagesCached;
	cGcStatsManager* mpStatsManager;
	cGcGameAnalytics* mpGameAnalytics;
	float mfUpdateTimer;
	int miPlayerCount;
	int miMaxFullPlayerCount;
	int miMaxOrbPlayerCount;
	bool mbFullMultiplayer;
	unsigned __int64 muPlayTime;
};

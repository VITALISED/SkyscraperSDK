#pragma once
#include "pch.h"
#include "cTkTypes.h"
#include "IStatWatcher.h"

struct cGcStatsManager
{
	cGcRpcCallBase* RSRI;
	cGcRpcCallBase* RSRF;
	cGcStatDefinitionTable* mpStatDefinitionsTable;
	cGcStatGroupTable* mpStatGroupsTable;
	cGcLeveledStatTable* mpLeveledStatTable;
	cGcJourneyMilestoneTable* mpJourneyMilestoneTable;
	robin_hood::detail::Table<1, 80, TkID<128>, cGcStatDefinition*, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mStatDefinitionLookup;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mStatChangesThisFrame;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mStatChangesSinceLastSave;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mLevelledStatChangesSinceLastSave;
	std::vector<StatListener, TkSTLAllocatorShim<StatListener> > mStatListeners;
	std::vector<int, TkSTLAllocatorShim<int> > mActiveListenerIndicies;
	cTkSmartResHandle mStatLevelIcons[11];
	robin_hood::detail::Table<1, 80, TkID<128>, std::vector<IStatWatcher*, TkSTLAllocatorShim<IStatWatcher*> >*, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mStatWatchers;
	std::vector<IStatWatcher*, TkSTLAllocatorShim<IStatWatcher*> > mVariantStatWatchers;
};
#pragma once
#include "pch.h"
#include "cTkTypes.h"

struct __declspec(align(8)) cGcUserSeenItemsState
{
	robin_hood::detail::Table<1, 80, TkID<256>, void, robin_hood::hash<TkID<256>, void>, std::equal_to<TkID<256> >> mSeenWikiTopics;
	robin_hood::detail::Table<1, 80, TkID<256>, void, robin_hood::hash<TkID<256>, void>, std::equal_to<TkID<256> >> mUnlockedWikiTopics;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mSeenSubstances;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mSeenTechnologies;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mSeenProducts;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mUnlockedTitles;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mUnlockedSpecials;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mUnlockedSeasonRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mUnlockedTwitchRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mUnlockedPlatformRewards;
	std::vector<std::pair<void(__cdecl*)(void*), void*>, TkSTLAllocatorShim<std::pair<void(__cdecl*)(void*), void*>> > mDataLoadedCallbacks;
	bool mbOutdated;
	bool mbLoaded;
};
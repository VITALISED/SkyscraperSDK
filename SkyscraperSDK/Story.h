#pragma once
#include "cTkTypes.h"

struct cGcStoryPageSeenDataArray
{
	cTkDynamicArray<cGcStoryPageSeenData> maPagesData;
};

struct cGcStoriesPageData
{
	int miCurrentCategory;
	int miCurrentTopicPage;
	int miCurrentStoryPage;
	int miCurrentStoryPageSection;
	std::vector<cTkFixedString<8192, char>, TkSTLAllocatorShim<cTkFixedString<8192, char> > > maCurentPageSecionsText;
	float mfTimeSinceLastTransition;
	cTkFixedArray<cTkDynamicArray<cGcStoriesPageData::sGcUnlockedStoryInfo>, 8> maiUnlockedStoryIndex;
	cTkFixedArray<int, 8> maiCategoryUnseenCount;
	TextScrollBarState mTextScrollBarState;
};

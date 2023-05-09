#pragma once
#include "cTkTypes.h"
#include "Procedural.h"
#include "UnorderedMapHashes.h"
#include "Mission.h"

enum eInventoryStackSizeGroup : __int32
{
	EInventoryStackSizeGroup_Default = 0x0,
	EInventoryStackSizeGroup_Personal = 0x1,
	EInventoryStackSizeGroup_PersonalCargo = 0x2,
	EInventoryStackSizeGroup_Ship = 0x3,
	EInventoryStackSizeGroup_ShipCargo = 0x4,
	EInventoryStackSizeGroup_Freighter = 0x5,
	EInventoryStackSizeGroup_FreighterCargo = 0x6,
	EInventoryStackSizeGroup_Vehicle = 0x7,
	EInventoryStackSizeGroup_Chest = 0x8,
	EInventoryStackSizeGroup_BaseCapsule = 0x9,
	EInventoryStackSizeGroup_MaintenanceObject = 0xA,
	EInventoryStackSizeGroup_UIPopup = 0xB,
	EInventoryStackSizeGroup_NumTypes = 0xC,
};

enum eInventoryClass : __int32
{
	EInventoryClass_C = 0x0,
	EInventoryClass_B = 0x1,
	EInventoryClass_A = 0x2,
	EInventoryClass_S = 0x3,
	EInventoryClass_NumTypes = 0x4,
};

struct cGcInventoryClass
{
	eInventoryClass meInventoryClass;
};

struct cGcInventoryStackSizeGroup
{
	eInventoryStackSizeGroup meInventoryStackSizeGroup;
};

struct cGcInventoryContainer
{
	cTkDynamicArray<cGcInventoryElement> maSlots;
	cTkDynamicArray<cGcInventoryIndex> maValidSlotIndices;
	cGcInventoryClass mClass;
	cGcInventoryStackSizeGroup mStackSizeGroup;
	cTkDynamicArray<cGcInventoryBaseStatEntry> maBaseStatValues;
	cTkDynamicArray<cGcInventorySpecialSlot> maSpecialSlots;
	int miWidth;
	int miHeight;
	bool mbIsCool;
	cTkFixedString<256, char> macName;
	int miVersion;
};

struct cGcInventoryStore
{
	cTkBitArray<unsigned __int64, 16> mxValidSlots[16];
	__int16 miWidth;
	__int16 miHeight;
	__int16 miCapacity;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mStore;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mStoreHistory;
	std::vector<cGcInventorySpecialSlot, TkSTLAllocatorShim<cGcInventorySpecialSlot> > maSpecialSlots;
	std::vector<cGcInventoryBaseStatEntry, TkSTLAllocatorShim<cGcInventoryBaseStatEntry> > maBaseStats;
	cGcInventoryLayout mLayoutDescriptor;
	bool mbAutoMaxEnabled;
	bool mbIsCool;
	eInventoryStackSizeGroup meStackSizeGroup;
	cGcInventoryClass mClass;
	cTkFixedString<256, char> mInventoryName;
	std::unordered_map<TkID<256>, int, TkIDUnorderedMap::Hash256, std::equal_to<TkID<256> >, TkSTLAllocatorShim<std::pair<TkID<256> const, int>> > mTechGroupCounts;
};

struct cGcInventoryStoreBalance
{
	int miPlayerPersonalInventoryTechWidth;
	int miPlayerPersonalInventoryTechHeight;
	int miPlayerPersonalInventoryCargoWidth;
	int miPlayerPersonalInventoryCargoHeight;
	float mfDeconstructRefundPercentage;
};

enum eInventoryType
{
	EInventoryType_Substance = 0x0,
	EInventoryType_Technology = 0x1,
	EInventoryType_Product = 0x2,
	EInventoryType_NumTypes = 0x3,
	EInventoryType_Unspecified = 0xFFFFFFFF,
};

struct cGcInventoryType
{
	eInventoryType meInventoryType;
};

struct cGcInventoryIndex
{
	int miX;
	int miY;
};

const struct cGcInventoryElement
{
	cGcInventoryType mType;
	TkID<128> mId;
	int miAmount;
	int miMaxAmount;
	float mfDamageFactor;
	bool mbFullyInstalled;
	cGcInventoryIndex mIndex;
};

const struct cGcSlotIcon
{
	cTkSmartResHandle mIcon;
	eIconStyle meIconStyle;
	cGcInventoryElement mItem;
};

struct __declspec(align(8)) cGcCraftingTreePageData
{
	eFrontendPage meReturnPage;
	cGcInventoryType mType;
	TkID<128> mId;
	InventoryChoice meInventory;
	cGcInventoryIndex mInventoryIndex;
	cGcInventoryElement mHighlightElement;
	bool mbNeedsRefresh;
};

struct __declspec(align(8)) InventoryTransferData
{
	std::vector<InventoryData, TkSTLAllocatorShim<InventoryData> > maLeft;
	int miCurrentLeft;
	std::vector<InventoryData, TkSTLAllocatorShim<InventoryData> > maRight;
	int miCurrentRight;
};

enum eWikiPageType : __int32
{
	EWikiPageType_Wiki = 0x0,
	EWikiPageType_Catalogue = 0x1,
	EWikiPageType_MaterialsAndItemsCatalogue = 0x2,
	EWikiPageType_CraftingAndTechnologyCatalogue = 0x3,
	EWikiPageType_BuildablesCatalogue = 0x4,
	EWikiPageType_Stories = 0x5,
	EWikiPageType_RecipesCatalogue = 0x6,
	EWikiPageType_Wonders = 0x7,
	EWikiPageType_NumTypes = 0x8,
};

enum eInventoryFilter : __int32
{
	EInventoryFilter_All = 0x0,
	EInventoryFilter_Substance = 0x1,
	EInventoryFilter_HighValue = 0x2,
	EInventoryFilter_Consumable = 0x3,
	EInventoryFilter_Deployable = 0x4,
	EInventoryFilter_NumTypes = 0x5,
};

struct __declspec(align(16)) cGcInventorySlotAction
{
	enum Style
	{
		InventoryHint = 0x0,
		NewSuitPulse = 0x1,
		NewSuitReveal = 0x2,
		Repair = 0x3,
		Charge = 0x4,
		InstallTech = 0x5,
		BuildProduct = 0x6,
		NumStyles = 0x7,
	};

	InventoryChoice meInventory;
	cGcInventoryIndex mInventoryIndex;
	cGcNGuiLayer* mpSlot;
	bool mbActive;
	bool mbCanAutoScrollToBottom;
	bool mbOffScreen;
	float mfStartTime;
	cGcInventorySlotAction::Style meStyle;
	cGcNGuiLayer mActionSlot;
	cGcInventorySlotActionData* mpActionData;
};

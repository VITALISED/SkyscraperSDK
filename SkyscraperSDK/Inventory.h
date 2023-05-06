#pragma once
#include "cTkTypes.h"
#include "Naming.h"
#include "UnorderedMapHashes.h"

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

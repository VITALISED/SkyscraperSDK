#pragma once
#include "cTkTypes.h"
#include "Discovery.h"

enum eSettlementJudgementType : __int32
{
	ESettlementJudgementType_None = 0x0,
	ESettlementJudgementType_StrangerVisit = 0x1,
	ESettlementJudgementType_Policy = 0x2,
	ESettlementJudgementType_NewBuilding = 0x3,
	ESettlementJudgementType_BuildingChoice = 0x4,
	ESettlementJudgementType_Conflict = 0x5,
	ESettlementJudgementType_Request = 0x6,
	ESettlementJudgementType_NumTypes = 0x7,
};

struct cGcSettlementJudgementType
{
	eSettlementJudgementType meSettlementJudgementType;
};

struct __declspec(align(8)) cGcSettlementProductionSlotData
{
	TkID<128> mElementId;
	unsigned __int64 mu64LastChangeTimestamp;
	int miAmount;
};

struct __declspec(align(16)) cGcSettlementState
{
	cTkFixedString<64, char> macUniqueId;
	unsigned __int64 mu64UniverseAddress;
	cTkVector3 mPosition;
	unsigned __int64 mu64SeedValue;
	cTkFixedArray<int, 48> maiBuildingStates;
	cTkFixedArray<unsigned __int64, 48> mau64LastBuildingUpgradesTimestamps;
	cTkFixedString<64, char> macName;
	cGcDiscoveryOwner mOwner;
	cGcSettlementJudgementType mPendingJudgementType;
	TkID<128> mPendingCustomJudgementID;
	cTkFixedArray<int, 7> maiStats;
	cTkDynamicArray<TkID<128> > maPerks;
	unsigned __int64 mu64LastJudgementTime;
	unsigned __int64 mu64LastUpkeepDebtCheckTime;
	unsigned __int64 mu64LastDebtChangeTime;
	unsigned __int64 mu64LastAlertChangeTime;
	cTkFixedString<64, char> macDbResourceId;
	unsigned __int64 mu64DbTimestamp;
	int miDbVersion;
	cTkFixedArray<cGcSettlementProductionSlotData, 2> maProductionState;
	bool mbIsReported;
	int miNextBuildingUpgradeIndex;
	cGcBuildingClassification mNextBuildingUpgradeClass;
	unsigned __int64 mu64NextBuildingUpgradeSeedValue;
};

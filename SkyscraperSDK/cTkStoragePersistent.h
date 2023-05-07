#pragma once
#include "cTkTypes.h"
#include "pch.h"
#include "cGcTerrainEditBlockBuffer.h"
#include "Trade.h"

struct GcGameStatePersistence
{
	struct SpecificSave
	{
		enum Type : __int32
		{
			Current = 0x0,
			Previous = 0x1,
			Max = 0x2,
			CauseAuto = 0x41,
			CausePlayer = 0x50,
			CauseAutoMicro = 0x4D,
			CauseDifficulty = 0x44,
			CauseDebugTools = 0x50,
		};
	};

	enum eSaveVersion
	{
		ESaveVersion_Unknown = 0x0,
		ESaveVersion_RC1 = 0x1001,
		ESaveVersion_Patch1 = 0x1002,
		ESaveVersion_Update1 = 0x1003,
		ESaveVersion_Update1_1 = 0x1004,
		ESaveVersion_Update1_2 = 0x1005,
		ESaveVersion_Update1_3 = 0x1006,
		ESaveVersion_Update1_33 = 0x1007,
		ESaveVersion_Update1_35 = 0x1008,
		ESaveVersion_Update1_39 = 0x1009,
		ESaveVersion_Update1_4Internal = 0x1010,
		ESaveVersion_Update1_4 = 0x1011,
		ESaveVersion_Update1_5 = 0x1012,
		ESaveVersion_Update1_51 = 0x1013,
		ESaveVersion_Update1_62 = 0x1014,
		ESaveVersion_Update1_8 = 0x1015,
		ESaveVersion_Update1_81 = 0x1016,
		ESaveVersion_Update1_82 = 0x1017,
		ESaveVersion_Update1_83 = 0x1018,
		ESaveVersion_Update1_84 = 0x1019,
		ESaveVersion_Update1_85 = 0x101A,
		ESaveVersion_Update1_86 = 0x101B,
		ESaveVersion_Update1_87 = 0x101C,
		ESaveVersion_Update1_88 = 0x101D,
		ESaveVersion_Update1_89 = 0x101E,
		ESaveVersion_Update1_90 = 0x101F,
		ESaveVersion_Update1_91 = 0x1020,
		ESaveVersion_Update3_30 = 0x1021,
		ESaveVersion_Update3_32 = 0x1022,
		ESaveVersion_Update3_34 = 0x1023,
		ESaveVersion_Update3_35 = 0x1024,
		ESaveVersion_Update3_36 = 0x1025,
		ESaveVersion_Update3_52 = 0x1026,
		ESaveVersion_Update3_53 = 0x1027,
		ESaveVersion_Update3_80 = 0x1028,
		ESaveVersion_Update3_81 = 0x1029,
		ESaveVersion_Update3_85 = 0x102A,
		ESaveVersion_Update3_94 = 0x102B,
		ESaveVersion_Update4_00 = 0x102C,
		ESaveVersion_Update4_04 = 0x102D,
		ESaveVersion_Update4_05 = 0x102E,
		ESaveVersion_Update4_09 = 0x102F,
		ESaveVersion_GameModeMask = 0xE00,
		ESaveVersion_GameModeShift = 0x9,
		ESaveVersion_SeasonNumberMask = 0xFFFF0000,
		ESaveVersion_SeasonNumberShift = 0x10,
	};

};



struct cTkStoragePersistent
{
	struct LowSpaceWarningData
	{
		unsigned __int64 mu64RequestedMB;
		unsigned __int64 mu64RemainingMB;
		cTkFixedString<32, char> mDrive;
	};
};

struct __declspec(align(8)) cGcPersistentInteractionBuffer : cGcNetworkSynchronisedBuffer
{
	int miLastBufferIndex;
	unsigned __int64 muCurrentAddress;
	eInteractionBufferType meType;
	cTkDynamicArray<cGcInteractionData> maBufferData;
	int miCurrentPos;
	cTkVector3MetaKD<int, -1> mSavedInteractionsDB;
	nanoflann::KDTreeSingleIndexAdaptor<nanoflann::L2_Simple_Adaptor<float, cTkVector3MetaKD<int, -1>, float>, cTkVector3MetaKD<int, -1>, 3, unsigned __int64> mTree;
	int miNGuiOffset;
	int miGetCalls;
	int miSaveCalls;
	long double mfGetTime;
	long double mfSaveTime;
	float mfTimeSinceLastSavedInteraction;
	float mfFurthestPointDistance;
	cTkVector3 mFurthestPoint;
	void* mMutex;
	bool mbDebugPositions;
	bool mbPersistenceActive;
	bool mbTreeHasData;
	bool mbTreeNeedsRebuild;
};

template <class T>
struct __declspec(align(8)) cGcVariablePersistentInteractionBuffer/*<cGcMaintenanceContainer>*/ : cGcPersistentInteractionBuffer
{
	std::vector<T, TkSTLAllocatorShim<T> > mVariableData;
	const int mkiSyncMessageMaxSize;
};

struct cGcMaintenanceBuffer : cGcVariablePersistentInteractionBuffer<cGcMaintenanceContainer> {};

struct sVisitedSystem
{
	cGcGalacticVoxelCoordinate mVoxel;
	__int16 miSystemIndex;
	unsigned __int16 miPlanetsVisited;
};

struct cGcVisitedSystemsBuffer
{
	cTkFixedArray<sVisitedSystem, 512> mVisitedSystems;
	int miCurrentPosition;
	int miVisitedSystemsCount;
};

struct __declspec(align(16)) cGcPersistentInteractionsManager
{
	bool mbRenderLocalInteractions;
	cGcBaseBuildingGlobalBuffer mBaseBuildingBuffer;
	std::vector<cGcPlayerBasePersistentBuffer, TkSTLAllocatorShim<cGcPlayerBasePersistentBuffer> > maPersistentBaseBuffers;
	cGcPersistentInteractionBuffer mDistressSignalBuffer;
	cGcPersistentInteractionBuffer mCrateBuffer;
	cGcPersistentInteractionBuffer mDestructableBuffer;
	cGcPersistentInteractionBuffer mCostBuffer;
	cGcPersistentInteractionBuffer mBuildingBuffer;
	cGcPersistentInteractionBuffer mCreatureBuffer;
	cGcPersistentInteractionBuffer mPersonalBuffer;
	cGcPersistentInteractionBuffer mFireteamSyncBuffer;
	cGcTerrainEditsPersistentBuffer mTerrainEditBuffer;
	cGcTradingSupplyBuffer mTradingSupplyBuffer;
	cGcMaintenanceBuffer mMaintenanceBuffer;
	cGcMaintenanceBuffer mPersonalMaintenanceBuffer;
	cGcVisitedSystemsBuffer mVisitedSystemsBuffer;
};
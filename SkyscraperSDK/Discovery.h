#pragma once
#include "cTkTypes.h"
#include "cGcAsyncLoadOps.h"
#include "IDiscoveryManagerEventHandler.h"

enum eGalaxyStarAnomaly : __int32
{
	EGalaxyStarAnomaly_None = 0x0,
	EGalaxyStarAnomaly_AtlasStation = 0x1,
	EGalaxyStarAnomaly_AtlasStationFinal = 0x2,
	EGalaxyStarAnomaly_BlackHole = 0x3,
	EGalaxyStarAnomaly_MiniStation = 0x4,
	EGalaxyStarAnomaly_NumTypes = 0x5,
};

enum eRegionKnowledgeInterest : __int32
{
	ERegionKnowledgeInterest_NothingInteresting = 0x0,
	ERegionKnowledgeInterest_DeadEnd = 0x1,
	ERegionKnowledgeInterest_Shelter = 0x2,
	ERegionKnowledgeInterest_WaterEdge = 0x3,
	ERegionKnowledgeInterest_WaterInlet = 0x4,
	ERegionKnowledgeInterest_WaterShore = 0x5,
	ERegionKnowledgeInterest_Forest = 0x6,
	ERegionKnowledgeInterest_Meadow = 0x7,
	ERegionKnowledgeInterest_MeadowEdge = 0x8,
	ERegionKnowledgeInterest_Clearing = 0x9,
	ERegionKnowledgeInterest_Building = 0xA,
	ERegionKnowledgeInterest_PlayerBase = 0xB,
	ERegionKnowledgeInterest_Settlement = 0xC,
	ERegionKnowledgeInterest_Spaceship = 0xD,
	ERegionKnowledgeInterest_Impassable = 0xE,
	ERegionKnowledgeInterest_Count = 0xF,
};

enum eWonderType : __int32
{
	EWonderType_Treasure = 0x0,
	EWonderType_WeirdBasePart = 0x1,
	EWonderType_Planet = 0x2,
	EWonderType_Creature = 0x3,
	EWonderType_Flora = 0x4,
	EWonderType_Mineral = 0x5,
	EWonderType_Custom = 0x6,
	EWonderType_NumTypes = 0x7,
};

enum eDiscoveryType : __int32
{
	EDiscoveryType_Unknown = 0x0,
	EDiscoveryType_SolarSystem = 0x1,
	EDiscoveryType_Planet = 0x2,
	EDiscoveryType_Animal = 0x3,
	EDiscoveryType_Flora = 0x4,
	EDiscoveryType_Mineral = 0x5,
	EDiscoveryType_Sector = 0x6,
	EDiscoveryType_Building = 0x7,
	EDiscoveryType_Interactable = 0x8,
	EDiscoveryType_Sentinel = 0x9,
	EDiscoveryType_Starship = 0xA,
	EDiscoveryType_Artifact = 0xB,
	EDiscoveryType_Mystery = 0xC,
	EDiscoveryType_Treasure = 0xD,
	EDiscoveryType_Control = 0xE,
	EDiscoveryType_HarvestPlant = 0xF,
	EDiscoveryType_FriendlyDrone = 0x10,
	EDiscoveryType_NumTypes = 0x11,
};

enum eBuildingClass : __int32
{
	EBuildingClass_None = 0x0,
	EBuildingClass_TerrainResource = 0x1,
	EBuildingClass_Shelter = 0x2,
	EBuildingClass_Abandoned = 0x3,
	EBuildingClass_Terminal = 0x4,
	EBuildingClass_Shop = 0x5,
	EBuildingClass_Outpost = 0x6,
	EBuildingClass_Waypoint = 0x7,
	EBuildingClass_Beacon = 0x8,
	EBuildingClass_RadioTower = 0x9,
	EBuildingClass_Observatory = 0xA,
	EBuildingClass_Depot = 0xB,
	EBuildingClass_Factory = 0xC,
	EBuildingClass_Harvester = 0xD,
	EBuildingClass_Plaque = 0xE,
	EBuildingClass_Monolith = 0xF,
	EBuildingClass_Portal = 0x10,
	EBuildingClass_Ruin = 0x11,
	EBuildingClass_Debris = 0x12,
	EBuildingClass_DamagedMachine = 0x13,
	EBuildingClass_DistressSignal = 0x14,
	EBuildingClass_LandingPad = 0x15,
	EBuildingClass_Base = 0x16,
	EBuildingClass_MissionTower = 0x17,
	EBuildingClass_CrashedFreighter = 0x18,
	EBuildingClass_GraveInCave = 0x19,
	EBuildingClass_StoryGlitch = 0x1A,
	EBuildingClass_TreasureRuins = 0x1B,
	EBuildingClass_GameStartSpawn = 0x1C,
	EBuildingClass_WaterCrashedFreighter = 0x1D,
	EBuildingClass_WaterTreasureRuins = 0x1E,
	EBuildingClass_WaterAbandoned = 0x1F,
	EBuildingClass_WaterDistressSignal = 0x20,
	EBuildingClass_NPCDistressSignal = 0x21,
	EBuildingClass_NPCDebris = 0x22,
	EBuildingClass_LargeBuilding = 0x23,
	EBuildingClass_Settlement_Hub = 0x24,
	EBuildingClass_Settlement_LandingZone = 0x25,
	EBuildingClass_Settlement_Bar = 0x26,
	EBuildingClass_Settlement_Tower = 0x27,
	EBuildingClass_Settlement_Market = 0x28,
	EBuildingClass_Settlement_Small = 0x29,
	EBuildingClass_Settlement_SmallIndustrial = 0x2A,
	EBuildingClass_Settlement_Medium = 0x2B,
	EBuildingClass_Settlement_Large = 0x2C,
	EBuildingClass_Settlement_Monument = 0x2D,
	EBuildingClass_Settlement_SheriffsOffice = 0x2E,
	EBuildingClass_Settlement_Double = 0x2F,
	EBuildingClass_Settlement_Farm = 0x30,
	EBuildingClass_Settlement_Factory = 0x31,
	EBuildingClass_Settlement_Clump = 0x32,
	EBuildingClass_DroneHive = 0x33,
	EBuildingClass_NumTypes = 0x34,
};

struct cGcDiscoveryOwner
{
	cTkFixedString<64, char> macLocalID;
	cTkFixedString<64, char> macOnlineID;
	cTkFixedString<64, char> macUsername;
	cTkFixedString<64, char> macPlatform;
	int miTimestamp;
};

struct cGcBuildingClassification
{
	eBuildingClass meBuildingClass;
};

struct cGcDiscoveryManager
{
	cGcRpcCallBase* NDMP;
	cGcDiscoveryManager::Data* mpData;
	cTkStackVector<IDiscoveryManagerEventHandler*> mCachedHandlers;
};

struct __declspec(align(4)) cGcWonderRecord
{
	cTkFixedArray<unsigned __int64, 2> mau64GenerationID;
	float mfWonderStatValue;
	bool mbSeenInFrontend;
};

struct cGcWonderData
{
	typedef cGcPlayerEmoteProp::eState eLoadState;

	struct sDiscoveryData
	{
		cGcDiscoverySearch* mpSearchTask;
		cGcDiscoveryData mData;
		unsigned __int64 mUniverseAddress;
		unsigned __int64 muSeed;
		unsigned __int64 muFilenameHash;
		cTkFixedString<127, char> macName;
		cTkFixedString<64, char> macDiscovererName;
		cTkFixedString<3, char> mDiscovererPlatform;
		int miTimeDiscovered;
	};

	struct sPlanetData
	{
		cTkFixedString<127, char> macName;
		cGcPlanetGenerationWonderQuery mQueryResult;
	};

	struct __declspec(align(16)) sModelResData
	{
		cTkSmartResHandle mModelResource;
		cGcProceduralTextureManager::TaskContext* mpTC;
		bool mbFurAllowed;
		TkID<256> mResDescriptorHint;
		TkID<256> mResDescriptorFilter;
		float mfScale;
		cTkVector3 mvModelOffset;
		float mfFurScaler;
		eModelViews meModelView;
	};

	struct sCreatureData
	{
		cGcCreatureInfo mCreatureInfo;
	};

	eWonderType meWonderType;
	int miWonderCategory;
	cGcWonderRecord mRecord;
	cGcWonderData::eLoadState meLoadState;
	cGcWonderRecordCustomData mCustomData;
	cGcWonderData::sDiscoveryData mDiscoveryData;
	cGcWonderData::sPlanetData mPlanetData;
	cGcWonderData::sModelResData mModelResData;
	cGcWonderData::sCreatureData mCreatureData;
};

struct cGcWonderType
{
	eWonderType meWonderType;
};

struct cGcWonderRecordCustomData
{
	cTkFixedString<64, char> macCustomName;
	cGcWonderType mActualType;
};

struct cGcWonderManager : IDiscoveryManagerEventHandler
{
	struct sWonderData
	{
		cGcWonderData maPlanets[11];
		cGcWonderData maCreatures[15];
		cGcWonderData maFlora[8];
		cGcWonderData maMinerals[8];
		cGcWonderData maTreasures[13];
		cGcWonderData maWeirdBaseParts[11];
		cGcWonderData maCustom[12];
	};

	struct sRenderData
	{
		eWonderType meActiveWonderRenderType;
		TkHandle mThumbnailsGroup;
		cTkModelResourceRenderer maThumbnailRenderers[15];
	};

	struct sDiscoveryParseData
	{
		int miNextSystemIndex;
		int miNextPlanetIndex;
		const cGcDiscoveryExport* mpDiscoveryExport;
	};

	cGcWonderManager::sWonderData mWonderData;
	cGcWonderManager::sRenderData mRenderData;
	cGcWonderManager::sDiscoveryParseData mDiscoveryParseData;
};

struct __declspec(align(8)) cGcDiscoveryPayload : AutoPooled<19>
{
	unsigned int kuSignificantElements;
	std::array<unsigned __int64, 5> mau64Storage;
	unsigned int muNumElements;
};

struct __declspec(align(8)) cGcPlayerDiscoveryHelper
{
	int miDiscoveredCreatures;
	int miTotalDiscoverableCreatures;
	const int kiNotifyIfDiscoveredLessThan;
	std::forward_list<cGcPlayerDiscoveryHelper::DiscoveryHelperEvent> maEvents;
	cGcDiscoverySearch* mDiscoverySearch;
	cTkSeed mCreatureSeed;
	bool mPendingDiscoveryNew;
};

struct DiscoveryResolver
{
	struct __declspec(align(4)) NameAndOwnerResult
	{
		DiscoveryResolver::NameAndOwnerResult::NameResultDetail meNameResultDetail;
		cTkFixedString<127, char> mDisplayName;
		cTkFixedString<127, char> mLocalisedDisplayName;
		DiscoveryResolver::NameAndOwnerResult::OwnershipResult meOwnershipResult;
		cGcDiscoveryOwner mOwnership;
		bool mbOwnedByCurrentPlayer;
	};

	struct __declspec(align(4)) DiscoveryInfo
	{
		cTkFixedString<128, char> msTitle;
		DiscoveryResolver::NameAndOwnerResult mNameAndOwner;
		std::vector<DiscoveryResolver::DiscoveryInfo::DiscoveryInfoValue, TkSTLAllocatorShim<DiscoveryResolver::DiscoveryInfo::DiscoveryInfoValue> > mValues;
		eDiscoveryType meDiscoveryType;
		int miWorth;
		cTkModelResourceRenderer* mpThumbnail;
		float mfDisplayTime;
		float mfDisplayTimer;
		float mfAnimateInTime;
		bool mbNewDiscovery;
		bool mbWeird;
	};
};
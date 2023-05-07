#pragma once
#include "Procedural.h"
#include "UniverseAddressData.h"

enum eBasePartAudioLocation : __int32
{
	EBasePartAudioLocation_None = 0x0,
	EBasePartAudioLocation_Freighter_SpaceWalk = 0x1,
	EBasePartAudioLocation_Freighter_BioRoom = 0x2,
	EBasePartAudioLocation_Freighter_TechRoom = 0x3,
	EBasePartAudioLocation_Freighter_IndustrialRoom = 0x4,
	EBasePartAudioLocation_NumTypes = 0x5,
};


enum eBaseSharingMode : __int32
{
	EBaseSharingMode_Undecided = 0x0,
	EBaseSharingMode_On = 0x1,
	EBaseSharingMode_Off = 0x2,
	EBaseSharingMode_NumTypes = 0x3,
};

struct BaseIndex
{
	unsigned __int16 mValue;
};

struct cGcPlayerNPCWorkers
{
	struct WorkerStationInfo
	{
		bool mbWorkerHired;
		BaseIndex muWorkerIndex;
		cGcResourceElement mWorkerResourceData;
		cTkSeed mNPCInteractionSeed;
	};

	cGcPlayerNPCWorkers::WorkerStationInfo maWorkerStations[5];
};

enum eTeleporterType : __int32
{
	ETeleporterType_Base = 0x0,
	ETeleporterType_Spacestation = 0x1,
	ETeleporterType_Atlas = 0x2,
	ETeleporterType_PlanetAwayFromShip = 0x3,
	ETeleporterType_ExternalBase = 0x4,
	ETeleporterType_EmergencyGalaxyFix = 0x5,
	ETeleporterType_OnNexus = 0x6,
	ETeleporterType_SpacestationFixPosition = 0x7,
	ETeleporterType_Settlement = 0x8,
	ETeleporterType_Freighter = 0x9,
	ETeleporterType_Frigate = 0xA,
	ETeleporterType_NumTypes = 0xB,
};

struct __declspec(align(16)) cGcTeleportEndpoint
{
	cGcUniverseAddressData mUniverseAddress;
	cTkVector3 mPosition;
	cTkVector3 mFacing;
	eTeleporterType meTeleporterType;
	cTkFixedString<64, char> macName;
	bool mbCalcWarpOffset;
	bool mbIsFeatured;
};

struct cGcBaseBuildingPersistentBuffer : cGcNetworkSynchronisedBuffer
{
	std::vector<cGcBaseBuildingPersistentBuffer::BaseBuildingPersistentData, TkSTLAllocatorShim<cGcBaseBuildingPersistentBuffer::BaseBuildingPersistentData> > maBaseBuildingObjects;
	robin_hood::detail::Table<1, 80, unsigned __int64, std::vector<unsigned short, TkSTLAllocatorShim<unsigned short> >, robin_hood::hash<unsigned __int64, void>, std::equal_to<unsigned __int64>> maCurrentPlanetObjects;
	unsigned __int64 muCurrentAddress;
	bool mbDebugPositions;
	cTkUserIdBase<cTkFixedString<64, char> > mNetworkOwnerId;
	unsigned int miBufferIndex;
};

struct cGcBaseBuildingGlobalBuffer
{
	cGcBaseBuildingPersistentBuffer mPersistentBuffers[32];
};

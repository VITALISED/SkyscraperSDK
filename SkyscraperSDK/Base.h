#pragma once
#include "Procedural.h"
#include "UniverseAddressData.h"

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
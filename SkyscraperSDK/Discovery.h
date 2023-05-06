#pragma once
#include "cTkTypes.h"

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
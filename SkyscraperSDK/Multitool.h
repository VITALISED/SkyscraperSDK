#pragma once
#include "Procedural.h"
#include "pch.h"
#include "Inventory.h"
#include "cTkModelResourceRenderer.h"

enum eWeaponMode : __int32
{
	EWeaponMode_Bolt = 0x0,
	EWeaponMode_Shotgun = 0x1,
	EWeaponMode_Burst = 0x2,
	EWeaponMode_Rail = 0x3,
	EWeaponMode_Cannon = 0x4,
	EWeaponMode_Laser = 0x5,
	EWeaponMode_Grenade = 0x6,
	EWeaponMode_MineGrenade = 0x7,
	EWeaponMode_Scope = 0x8,
	EWeaponMode_FrontShield = 0x9,
	EWeaponMode_Melee = 0xA,
	EWeaponMode_TerrainEdit = 0xB,
	EWeaponMode_SunLaser = 0xC,
	EWeaponMode_Spawner = 0xD,
	EWeaponMode_SpawnerAlt = 0xE,
	EWeaponMode_SoulLaser = 0xF,
	EWeaponMode_Flamethrower = 0x10,
	EWeaponMode_StunGrenade = 0x11,
	EWeaponMode_Stealth = 0x12,
	EWeaponMode_NumTypes = 0x13,
};

enum ePalette : __int32
{
	EPalette_Grass = 0x0,
	EPalette_Plant = 0x1,
	EPalette_Leaf = 0x2,
	EPalette_Wood = 0x3,
	EPalette_Rock = 0x4,
	EPalette_Stone = 0x5,
	EPalette_Crystal = 0x6,
	EPalette_Sand = 0x7,
	EPalette_Dirt = 0x8,
	EPalette_Metal = 0x9,
	EPalette_Paint = 0xA,
	EPalette_Plastic = 0xB,
	EPalette_Fur = 0xC,
	EPalette_Scale = 0xD,
	EPalette_Feather = 0xE,
	EPalette_Water = 0xF,
	EPalette_Cloud = 0x10,
	EPalette_Sky = 0x11,
	EPalette_Space = 0x12,
	EPalette_Underbelly = 0x13,
	EPalette_Undercoat = 0x14,
	EPalette_Snow = 0x15,
	EPalette_SkyHorizon = 0x16,
	EPalette_SkyFog = 0x17,
	EPalette_SkyHeightFog = 0x18,
	EPalette_SkySunset = 0x19,
	EPalette_SkyNight = 0x1A,
	EPalette_WaterNear = 0x1B,
	EPalette_SpaceCloud = 0x1C,
	EPalette_SpaceBottom = 0x1D,
	EPalette_SpaceSolar = 0x1E,
	EPalette_SpaceLight = 0x1F,
	EPalette_Warrior = 0x20,
	EPalette_Scientific = 0x21,
	EPalette_Trader = 0x22,
	EPalette_WarriorAlt = 0x23,
	EPalette_ScientificAlt = 0x24,
	EPalette_TraderAlt = 0x25,
	EPalette_RockSaturated = 0x26,
	EPalette_RockLight = 0x27,
	EPalette_RockDark = 0x28,
	EPalette_PlanetRing = 0x29,
	EPalette_Custom_Head = 0x2A,
	EPalette_Custom_Torso = 0x2B,
	EPalette_Custom_Chest_Armour = 0x2C,
	EPalette_Custom_Backpack = 0x2D,
	EPalette_Custom_Arms = 0x2E,
	EPalette_Custom_Hands = 0x2F,
	EPalette_Custom_Legs = 0x30,
	EPalette_Custom_Feet = 0x31,
	EPalette_Cave = 0x32,
	EPalette_GrassAlt = 0x33,
	EPalette_BioShip_Body = 0x34,
	EPalette_BioShip_Underbelly = 0x35,
	EPalette_BioShip_Cockpit = 0x36,
	EPalette_SailShip_Sails = 0x37,
	EPalette_Freighter = 0x38,
	EPalette_FreighterPaint = 0x39,
	EPalette_NumTypes = 0x3A,
};

enum eColourAlt : __int32
{
	EColourAlt_Primary = 0x0,
	EColourAlt_Alternative1 = 0x1,
	EColourAlt_Alternative2 = 0x2,
	EColourAlt_Alternative3 = 0x3,
	EColourAlt_Alternative4 = 0x4,
	EColourAlt_Unique = 0x5,
	EColourAlt_MatchGround = 0x6,
	EColourAlt_None = 0x7,
	EColourAlt_NumTypes = 0x8,
};

struct __declspec(align(4)) cGcPlayerMultitoolOwnership
{
	struct sMultitoolInfo
	{
		cGcInventoryStore mInventory;
		cTkSmartResHandle mResource;
		cTkFixedString<32, char> mCustomName;
		eWeaponMode mePrimaryMode;
		eWeaponMode meSecondaryMode;
		bool mbIsLarge;
		bool mbUseLegacyColours;
		cTkSeed mSeed;
	};

	cGcPlayerMultitoolOwnership::sMultitoolInfo maMultitools[6];
	cTkModelResourceRenderer maThumbnailRenderers[6];
	TkHandle mThumbnailsGroup;
	int miPrimaryToolIndex;
	int miRequestedMultitoolIndex;
	bool mbReadyWeapon;
};
#pragma once

enum eCustomisationDataType : __int32
{
	ECustomisationDataType_Player = 0x0,
	ECustomisationDataType_Vehicle = 0x1,
	ECustomisationDataType_Weapon = 0x2,
	ECustomisationDataType_Ship_01 = 0x3,
	ECustomisationDataType_Ship_02 = 0x4,
	ECustomisationDataType_Ship_03 = 0x5,
	ECustomisationDataType_Ship_04 = 0x6,
	ECustomisationDataType_Ship_05 = 0x7,
	ECustomisationDataType_Ship_06 = 0x8,
	ECustomisationDataType_Vehicle_Bike = 0x9,
	ECustomisationDataType_Vehicle_Truck = 0xA,
	ECustomisationDataType_Vehicle_WheeledBike = 0xB,
	ECustomisationDataType_Vehicle_Hovercraft = 0xC,
	ECustomisationDataType_Vehicle_Submarine = 0xD,
	ECustomisationDataType_Vehicle_Mech = 0xE,
	ECustomisationDataType_Freighter = 0xF,
	ECustomisationDataType_Pet = 0x10,
	ECustomisationDataType_Ship_07 = 0x11,
	ECustomisationDataType_Ship_08 = 0x12,
	ECustomisationDataType_Ship_09 = 0x13,
	ECustomisationDataType_Ship_10 = 0x14,
	ECustomisationDataType_Ship_11 = 0x15,
	ECustomisationDataType_Ship_12 = 0x16,
	ECustomisationDataType_NumTypes = 0x17,
};

struct cGcCustomisationComponentData
{
	eCustomisationDataType meCustomisationDataType;
};
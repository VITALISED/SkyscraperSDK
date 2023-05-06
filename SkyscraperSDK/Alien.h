#pragma once
#include "cTkTypes.h"

enum eAlienRace
{
	EAlienRace_Traders = 0x0,
	EAlienRace_Warriors = 0x1,
	EAlienRace_Explorers = 0x2,
	EAlienRace_Robots = 0x3,
	EAlienRace_Atlas = 0x4,
	EAlienRace_Diplomats = 0x5,
	EAlienRace_Exotics = 0x6,
	EAlienRace_None = 0x7,
	EAlienRace_NumTypes = 0x8,
	EAlienRace_Unspecified = 0xFFFFFFFF,
};

enum eCommunicatorType : __int32
{
	ECommunicatorType_HoloExplorer = 0x0,
	ECommunicatorType_HoloSceptic = 0x1,
	ECommunicatorType_HoloNoone = 0x2,
	ECommunicatorType_Generic = 0x3,
	ECommunicatorType_PlayerFreighterCaptain = 0x4,
	ECommunicatorType_Polo = 0x5,
	ECommunicatorType_Nada = 0x6,
	ECommunicatorType_QuicksilverBot = 0x7,
	ECommunicatorType_PlayerSettlementResident = 0x8,
	ECommunicatorType_CargoScanDrone = 0x9,
	ECommunicatorType_Tethys = 0xA,
	ECommunicatorType_NumTypes = 0xB,
};

struct cGcAlienRace
{
	eAlienRace meAlienRace;
};

struct cGcPlayerCommunicatorMessage
{
	TkID<256> mDialog;
	bool mbShowHologram;
	eCommunicatorType meCommunicatorType;
	cGcAlienRace mRaceOverride;
	TkID<256> mShipHUDOverride;
};
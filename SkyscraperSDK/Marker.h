#pragma once
#include "cGcFrontendPage.h"
#include "cTkTypes.h"
#include "Discovery.h"
#include "cGcNetwork.h"

struct cGcMarkerPoint
{
	typedef cGcFrontendPage::ButtonIcon::Size eDisplay;

	enum eType : __int32
	{
		EMarkerType_Default = 0x0,
		EMarkerType_PlanetPoleNorth = 0x1,
		EMarkerType_PlanetPoleSouth = 0x2,
		EMarkerType_BaseBuildingMarkerBeacon = 0x3,
		EMarkerType_TerrainResource = 0x4,
		EMarkerType_Object = 0x5,
		EMarkerType_Tagged = 0x6,
		EMarkerType_Unknown = 0x7,
		EMarkerType_Ship = 0x8,
		EMarkerType_Freighter = 0x9,
		EMarkerType_NetworkPlayerFireTeamFreighter = 0xA,
		EMarkerType_FreighterBase = 0xB,
		EMarkerType_PlayerFreighter = 0xC,
		EMarkerType_PlayerSettlement = 0xD,
		EMarkerType_DamagedFrigate = 0xE,
		EMarkerType_Bounty = 0xF,
		EMarkerType_PlanetRaid = 0x10,
		EMarkerType_Battle = 0x11,
		EMarkerType_SpaceSignal = 0x12,
		EMarkerType_BlackHole = 0x13,
		EMarkerType_SpaceAnomalySignal = 0x14,
		EMarkerType_SpaceAtlasSignal = 0x15,
		EMarkerType_GenericIcon = 0x16,
		EMarkerType_NetworkPlayerFireTeam = 0x17,
		EMarkerType_NetworkPlayerFireTeamShip = 0x18,
		EMarkerType_NetworkPlayer = 0x19,
		EMarkerType_NetworkPlayerShip = 0x1A,
		EMarkerType_NetworkPlayerVehicle = 0x1B,
		EMarkerType_Monument = 0x1C,
		EMarkerType_PlayerBase = 0x1D,
		EMarkerType_EditingBase = 0x1E,
		EMarkerType_MessageBeacon = 0x1F,
		EMarkerType_ExternalBase = 0x20,
		EMarkerType_PlanetBaseTerminal = 0x21,
		EMarkerType_Vehicle = 0x22,
		EMarkerType_VehicleCheckpoint = 0x23,
		EMarkerType_VehicleGarage = 0x24,
		EMarkerType_Pet = 0x25,
		EMarkerType_DeathPoint = 0x26,
		EMarkerType_Signal = 0x27,
		EMarkerType_Portal = 0x28,
		EMarkerType_PurchasableFrigate = 0x29,
		EMarkerType_Expedition = 0x2A,
		EMarkerType_Building = 0x2B,
		EMarkerType_ActiveNetworkMarker = 0x2C,
		EMarkerType_CustomMarker = 0x2D,
		EMarkerType_PlacedMarker = 0x2E,
		EMarkerType_Nexus = 0x2F,
		EMarkerType_PowerHotspot = 0x30,
		EMarkerType_MineralHotspot = 0x31,
		EMarkerType_GasHotspot = 0x32,
		EMarkerType_NPC = 0x33,
		EMarkerType_SettlementNPC = 0x34,
		EMarkerType_CreatureCurious = 0x35,
		EMarkerType_CreatureAction = 0x36,
		EMarkerType_CreatureTame = 0x37,
		EMarkerType_CreatureDanger = 0x38,
		EMarkerType_CreatureFiend = 0x39,
		EMarkerType_CreatureMilk = 0x3A,
		EMarkerType_FuelAsteroid = 0x3B,
		EMarkerType_PulseEncounter = 0x3C,
		EMarkerType_FrigateFlyby = 0x3D,
		EMarkerType_ShipExperienceSpawn = 0x3E,
		EMarkerType_FriendlyDrone = 0x3F,
		EMarkerType_NumTypes = 0x40,
	};

	cTkPhysRelVec3 mPosition;
	cTkVector3 mCenterOffset;
	float mfTopOffset;
	cGcMarkerPoint::eType meType;
	float mfBoundingRadius;
	cTkFixedString<64, char> mCustomName;
	cTkFixedString<128, char> mCustomSubtitle;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> maCustomIcons[3];
	TkHandle mNode;
	TkHandle mModelNode;
	TkHandle mEntranceNode;
	eBuildingClass meBuildingClass;
	cGcBuilding* mpBuilding;
	cGcLootComponent* mpLootComponent;
	cGcScannableComponent* mpScannableComponent;
	cGcMarkerComponent* mpMarkerComponent;
	cTkUserIdBase<cTkFixedString<64, char> > mNetworkPlayerId;
	int miPlayerIndex;
	eScannableType meScannableType;
	cTkPhysRelVec3 mInteractPosition;
	cTkAttachmentPtr mpInteractPhysics;
	TkHandle mInteractLocator;
	cTkUserIdBase<cTkFixedString<64, char> > mRemotePlayerID;
	cGcMarkerPoint::eType meRemoteType;
	float mfRemoteStartTime;
	cGcNetworkConstants::OnlinePlatformType mePlatform;
	float mfStartTime;
	float mfActiveTime;
	bool mbPerpetual;
	bool mbFollowNode;
	bool mbAlwaysAdd;
	bool mbMarkedPrimary;
	bool mbPulseDriveTarget;
	bool mbNeedsToBeSurveyed;
	bool mbWaitingForNode;
	cTkColour mOverwriteColour;
	bool mbTimedEvent;
	bool mbActive;
	bool mbCanDisplay;
	std::pair<TkID<128>, cTkSeed> mMission;
	TkID<256> mSequence;
	cGcMarkerPoint::eDisplay meDisplay;
	bool mbLockedOn;
	float mfScreenOffsetY;
	eOverrideInteriorExteriorMarker meInsideOrOutsideOverride;
	bool mbUseInteractPosition;
};

enum eScannableType : __int32
{
	EScannableType_Binoculars = 0x0,
	EScannableType_BinocularsHotspots = 0x1,
	EScannableType_Scanner = 0x2,
	EScannableType_Marker = 0x3,
	EScannableType_None = 0x4,
	EScannableType_NumTypes = 0x5,
};

enum eOverrideInteriorExteriorMarker : __int32
{
	EOverrideInteriorExteriorMarker_No = 0x0,
	EOverrideInteriorExteriorMarker_Interior = 0x1,
	EOverrideInteriorExteriorMarker_Exterior = 0x2,
	EOverrideInteriorExteriorMarker_NumTypes = 0x3,
};

struct cGcMarkerList
{
	std::vector<cGcMarkerPoint, TkSTLAllocatorShim<cGcMarkerPoint> > maMarkerObjects;
};

struct __declspec(align(8)) cGcMarkerRenderData
{
	cTkColour mFillColour;
	cTkColour mBackgroundColour;
	float mfAmount;
	float mfInnerRadius;
	float mfOuterRadius;
};

#pragma once
#include "cTkTypes.h"
#include "cGcPlayerShip.h"

enum eVehicleType : __int32
{
	EVehicleType_Buggy = 0x0,
	EVehicleType_Bike = 0x1,
	EVehicleType_Truck = 0x2,
	EVehicleType_WheeledBike = 0x3,
	EVehicleType_Hovercraft = 0x4,
	EVehicleType_Submarine = 0x5,
	EVehicleType_Mech = 0x6,
	EVehicleType_NumTypes = 0x7,
};

struct cGcVehicleLocation
{
	unsigned __int64 mLocation;
	cTkVector4 mPosition;
	cTkVector4 mDirection;
};

struct __declspec(align(16)) VehicleInstance
{
	cGcProceduralTextureManager::TaskContext* mpTC;
	cTkSmartResHandle mPlayerVehicleResHandle;
	TkHandle mPlayerVehicleNode;
	cGcVehicleComponent* mpPlayerVehicleComponent;
	bool mbInSummoningRange;
	cTkMatrix34 mSpawnMatrix;
	bool mbSpawnPending;
	bool mbFancySpawn;
};


struct  __declspec(align(16)) cGcPlayerVehicleOwnership
{
	typedef cGcPlayerShipOwnership::eMeshRefreshState eMeshRefreshState;

	std::unordered_map<int, std::function<void __cdecl(enum eVehicleType, cTkMatrix34 const&)>> mNewVehicleSpawnCallbacks;
	TkHandle mGroupRootNode;
	VehicleInstance maVehicles[7];
	eVehicleType meRequestVehicle;
	cTkMatrix34 mRequestedVehicleMatrix;
	cGcPlacementArc mPlacementArc;
	eVehicleType meShowPreview;
	cGcScanEffectData mPreviewScanData;
	cTkColour mPreviewColour;
	float mfPreviewFirstActiveTime;
	float mfPreviewLastActiveTime;
	TkHandle mPreviewNode;
	bool mbClearPreview;
	bool mbShowRocketPreview;
	bool mbShouldRefreshMesh;
	cGcPlayerVehicleOwnership::eMeshRefreshState mMeshRefreshState;
	cTkSmartResHandle mRefreshSwapRes;
};
#pragma once
#include "Procedural.h"
#include "cTkTypes.h"
#include "Customisation.h"
#include "cTkModelResourceRenderer.h"
#include "Raycast.h"

enum eShipClass : __int32
{
	EShipClass_Freighter = 0x0,
	EShipClass_Dropship = 0x1,
	EShipClass_Fighter = 0x2,
	EShipClass_Scientific = 0x3,
	EShipClass_Shuttle = 0x4,
	EShipClass_PlayerFreighter = 0x5,
	EShipClass_Royal = 0x6,
	EShipClass_Alien = 0x7,
	EShipClass_Sail = 0x8,
	// sentinel ship for 4.20 is probably EShipClass_Salvage
	EShipClass_NumTypes = 0x9,
};

enum ePulseDriveState : __int32
{
	EPulseDriveState_None = 0x0,
	EPulseDriveState_Charge = 0x1,
	EPulseDriveState_Jumping = 0x2,
	EPulseDriveState_CrashStop = 0x3,
	EPulseDriveState_Cooldown = 0x4,
};

struct cGcSpaceshipClasses
{
	eShipClass meShipClass;
};

struct __declspec(align(4)) cGcPlayerShipOwnership
{
	struct sGcShipData
	{
		cTkSeed mPlayerShipSeed;
		cTkSmartResHandle mPlayerShipResHandle;
		TkHandle mPlayerShipNode;
		cTkAttachmentPtr mpPlayerShipAttachment;
		int mFreighterDockIndex;
		cGcCustomisationComponentData mShipCustomisationData;
	};

	enum eMeshRefreshState : __int32
	{
		ReadyForRefresh = 0x0,
		Generating = 0x1,
		SwapMesh = 0x2,
	};

	std::unordered_map<int, std::function<void __cdecl(cTkMatrix34 const&)>> mNewSpaceshipSpawnCallbacks;
	TkHandle mGroupRootNode;
	cGcPlayerShipOwnership::sGcShipData mShips[12];
	cTkMatrix34 mPlayerShipTMWhenLastDestroyed;
	cTkMatrix34 mNewShipDelayedSpawnMatrix;
	const cGcSpaceshipComponentData* mpPrimaryShipComponentData;
	int miCachedShipComponentDataIndex;
	cTkModelResourceRenderer maThumbnailRenderers[12];
	cGcPlacementArc mPlacementArc;
	cTkVector2 mInitialPlacementDirection;
	float mfPlacementRotation;
	bool mbUseOffHandForPlacementRotation;
	std::vector<cGcPlayerShipOwnership::RetiredShipRecord, TkSTLAllocatorShim<cGcPlayerShipOwnership::RetiredShipRecord> > mRetiredShips;
	bool mbShowShipPreview;
	int miShipToPreview;
	int miCurrentPreviewShip;
	TkHandle mPreviewShipNode;
	cTkPhysRelMat34 mLastKnownPreviewMatrix;
	cTkPhysRelMat34 mLastGoodPreviewMatrix;
	bool mbLastGoodPreviewMatrixValid;
	cGcScanEffectData mShipPreviewScanData;
	float mfShipPreviewFirstActiveTime;
	float mfShipPreviewLastActiveTime;
	cTkVector3 mShipPreviewScale;
	cTkColour mShipPreviewColour;
	bool mbShouldRefreshMesh;
	cGcPlayerShipOwnership::eMeshRefreshState mMeshRefreshState;
	cTkSmartResHandle mRefreshSwapRes;
	bool mbNextSummonIsFree;
};
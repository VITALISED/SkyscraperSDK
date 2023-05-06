#pragma once
#include "Procedural.h"
#include "cTkTypes.h"
#include "Customisation.h"
#include "cTkModelResourceRenderer.h"
#include "Raycast.h"

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
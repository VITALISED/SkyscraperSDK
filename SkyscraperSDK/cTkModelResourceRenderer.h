#pragma once
#include "cTkTypes.h"
#include "Procedural.h"

enum EModelResourceRendererViewMode : __int32
{
	EModelResourceRendererViewMode_RotateX = 0x1,
	EModelResourceRendererViewMode_RotateY = 0x2,
	EModelResourceRendererViewMode_RotateZ = 0x4,
	EModelResourceRendererViewMode_RotateXYZ = 0x7,
};

/* 933 */
enum EModelResourceRendererSyncStage : __int32
{
	EModelResourceRendererSyncStage_None = 0x0,
	EModelResourceRendererSyncStage_RequestLoad = 0x1,
	EModelResourceRendererSyncStage_WaitForHighestMips = 0x2,
	EModelResourceRendererSyncStage_WaitForGeometryAndMaterials = 0x3,
	EModelResourceRendererSyncStage_LoadResources = 0x4,
	EModelResourceRendererSyncStage_RequestRenderToTexture = 0x5,
	EModelResourceRendererSyncStage_RenderToTexture = 0x6,
	EModelResourceRendererSyncStage_GetNodeBoundingBox = 0x7,
	EModelResourceRendererSyncStage_UpdateCamera = 0x8,
	EModelResourceRendererSyncStage_RenderToTextureDone = 0x9,
	EModelResourceRendererSyncStage_RenderToTextureFailed = 0xA,
	EModelResourceRendererSyncStage_RemoveNode = 0xB,
};

struct cTkModelResource
{
	cTkFixedString<128, char> macFilename;
	cTkSmartResHandle mResHandle;
};

struct __declspec(align(16)) cTkModelResourceRenderer
{
	int miShowLod;
	void(__fastcall* mAllowedComponentsCallback)();
	void(__fastcall* mAttachmentPrepareCallback)(cTkAttachment*);
	cTkSmartResHandle mResHandle;
	cTkSmartResHandle mViewPipelineRes;
	int mViewPipelineNumStages;
	int maClearModesStages[5];
	cTkSmartResHandle mPostProcessMaterial;
	TkHandle mIconGroup;
	TkHandle mNodeToRender;
	bool mbNodeIsExternal;
	bool mbForceChildNodesVisible;
	cTkSmartResHandle mRenderTargetTextureRes;
	cTkSmartResHandle mBackgroundImageTextureRes;
	cTkSmartResHandle mThumbnailBackgroundImageGUITextureRes;
	cTkSmartResHandle mThumbnailBackgroundImageHUDTextureRes;
	float mfModelScale;
	cTkVector3 mvModelOffset;
	cTkSeed mPetBoneScaleSeed;
	float mfPetBabify;
	float mfFurScaler;
	bool mbFurAllowed;
	cTkMatrix34 mModelMatrix;
	cTkMatrix34 mCameraMatrix;
	cTkPhysRelMat34 mRenderMatrix;
	cTkPhysRelMat34 mPrevRenderMatrix;
	float mfLightRotate;
	float mfLightPitch;
	float mfParallaxOffsetX;
	float mfParallaxOffsetY;
	EModelResourceRendererViewMode mViewMode;
	EModelResourceRendererSyncStage meSyncStage;
	cTkModelRendererData* mpData;
	cTkAABB mSpawnCachedLocalAABBMeshCulled;
	cTkAABB mSceneResourceAABB;
	bool mbReflectionsEnabled;
	bool mbHasRendered;
	bool mbRenderOnlyOnce;
	bool mbNodeHasImpostors;
	bool mbDisableLightingOverride;
	float mfTransitionTime;
	std::vector<cTkFixedString<128, char>, TkSTLAllocatorShim<cTkFixedString<128, char>> > mNodeNameActivationList;
	std::vector<cTkFixedString<128, char>, TkSTLAllocatorShim<cTkFixedString<128, char>> > mNodeNameDeactivationList;
	std::vector<int, TkSTLAllocatorShim<int> > mNodeTypeDeactivationList;
	cTkFixedString<128, char> mName_dbg;
};
#pragma once
#include "cTkTypes.h"
#include "Procedural.h"

enum eModelViews : __int32
{
	EModelViews_Suit = 0x0,
	EModelViews_Weapon = 0x1,
	EModelViews_Ship = 0x2,
	EModelViews_Vehicle = 0x3,
	EModelViews_DiscoveryMain = 0x4,
	EModelViews_DiscoveryThumbnail = 0x5,
	EModelViews_WonderThumbnail = 0x6,
	EModelViews_WonderThumbnailCreatureSmall = 0x7,
	EModelViews_WonderThumbnailCreatureMed = 0x8,
	EModelViews_WonderThumbnailCreatureLarge = 0x9,
	EModelViews_WonderThumbnailFloraSmall = 0xA,
	EModelViews_WonderThumbnailFloraLarge = 0xB,
	EModelViews_WonderThumbnailMineralSmall = 0xC,
	EModelViews_WonderThumbnailMineralLarge = 0xD,
	EModelViews_ToolboxMain = 0xE,
	EModelViews_ToolboxThumbnail = 0xF,
	EModelViews_TradeSuit = 0x10,
	EModelViews_TradeShip = 0x11,
	EModelViews_TradeCompareShips = 0x12,
	EModelViews_TradeCompareWeapons = 0x13,
	EModelViews_HUDThumbnail = 0x14,
	EModelViews_Interaction = 0x15,
	EModelViews_Freighter = 0x16,
	EModelViews_TradeFreighter = 0x17,
	EModelViews_TradeChest = 0x18,
	EModelViews_TradeCapsule = 0x19,
	EModelViews_TradeFrigate = 0x1A,
	EModelViews_TerrainBall = 0x1B,
	EModelViews_FreighterChest = 0x1C,
	EModelViews_Submarine = 0x1D,
	EModelViews_TradeCooker = 0x1E,
	EModelViews_SuitRefiner = 0x1F,
	EModelViews_FreighterRepair = 0x20,
	EModelViews_DiscoveryPlanetaryMapping = 0x21,
	EModelViews_Mech = 0x22,
	EModelViews_PetThumbnail = 0x23,
	EModelViews_PetThumbnailUI = 0x24,
	EModelViews_PetLarge = 0x25,
	EModelViews_SquadronPilotLarge = 0x26,
	EModelViews_SquadronPilotThumbnail = 0x27,
	EModelViews_SquadronSpaceshipThumbnail = 0x28,
	EModelViews_NumTypes = 0x29,
};

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
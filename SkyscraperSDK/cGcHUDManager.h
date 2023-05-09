#pragma once
#include "cGcGalaxyMap.h"
#include "Audio.h"
#include "cTkTypes.h"
#include "cGcNGui.h"
#include "Inventory.h"
#include "Discovery.h"
#include "cTkModelResourceRenderer.h"
#include "Marker.h"

struct __declspec(align(16)) cGcHUDManager
{
	typedef cGcGalaxyMap::MapMode eMode;

	enum TransitionDirection : __int32
	{
		In = 0x0,
		Out = 0x1,
	};

	cGcRpcCallBase* PAMU;
	cGcHUDManagerData* mpData;
	cGcScannerIcons* mpScannerIcons;
	TkAudioObject mAudioObject;
	cGcHUDManager::eMode meHUDMode;
	cGcTransition mSolidOverlayTransition;
	cTkColour mSolidOverlayColour;
	cGcHUDManager::TransitionDirection mSolidOverlayTransitionDirection;
	cGcPlayerHUD mPlayerHUD;
	cGcShipHUD mShipHUD;
	cGcPlayerNotifications mPlayerNotifications;
	cGcPhotoManager mPhotoManager;
	cGcQuickMenu mQuickMenu;
	cGcInventoryStore mChargingInventory;
	float mfCinematicTimer;
	float mfCinematicBarsAnimTime;
	cGcNGuiLayer mCinematicBars;
	cGcNGuiLayer mOSDMessageLayer;
	cGcNGuiLayer* mpDiscoveryTitleLayer;
	cTkVector2 mDiscoveryTitleLayerPos;
	cTkClassPoolHandle mFramerateScreen;
	cGcNGuiTextSpecial* mpSkipMsgText;
	cGcNGuiLayer* mpSkipMsgBar;
	float mfSkipMsgAlpha;
	float mfSkipMsgHoldT;
	std::vector<OSDMessage, TkSTLAllocatorShim<OSDMessage> > mOSDMessages;
	std::vector<cGcHUDManager::QueuedMessage, TkSTLAllocatorShim<cGcHUDManager::QueuedMessage> > mOSDMessageThumbnailRenderQueue;
	OSDMessageEffectReward mOSDMessageRewardEffect;
	cGcNGui mEffectLayer;
	std::vector<cGcHUDManager::CollectedResource, TkSTLAllocatorShim<cGcHUDManager::CollectedResource> > mCollectedResources;
	std::vector<MissionMessage, TkSTLAllocatorShim<MissionMessage> > mMissionMessages;
	std::vector<MissionDetailMessage, TkSTLAllocatorShim<MissionDetailMessage> > mMissionDetailMessages;
	StatsMessages mStatsMessages;
	std::array<cTkModelResourceRenderer, 2> mModelResourceRenderers;
	std::array<bool, 2> mModelResourceRendererUsage;
	__declspec(align(8)) DiscoveryResolver::DiscoveryInfo mDiscoveryDisplayInfo;
	bool mbIntroPausedToStart;
	bool mbIntroRequestStart;
	eHUDStartup meIntroStage;
	float mfIntroTimer;
	bool mbIntroStageFirstTime;
	cGcMarkerRenderData mIntroButtonData;
	bool mbIntroPlayingHoldAudio;
	int miIntroPauseFrames;
	float mfStatsMessageDelayTimer;
	bool mbSuppressMarkersAfterNextWarp;
	bool mbHasMissionDetailMessagesOnScreen;
	float mfLastDetailMessageTime;
	float mfLastDetailMessageDismissTime;
	bool mbCreatureMessageRequested;
	bool mbForcedAtlasPath;
	cGcHUDScreensPool mHUDScreensPool;
	bool mbHUDScreensPoolCtr;
	bool mbReloadRequest;
	std::vector<cGcInteractionComponent*, TkSTLAllocatorShim<cGcInteractionComponent*> > maInteractionOffScreenRenderers;
};
#pragma once
#include "cTkTypes.h"
#include "cGcAsyncLoadOps.h"
#include "cGcPlayer.h"
#include "cGcNGui.h"
#include "cGcApplicationTitleScreen.h"
#include "cGcApplicationUGCBaseViewer.h"

enum ePS4FixedFPS : __int32
{
	EPS4FixedFPS_Invalid = 0x0,
	EPS4FixedFPS_False = 0x1,
	EPS4FixedFPS_True = 0x2,
	EPS4FixedFPS_NumTypes = 0x3,
};

enum ePresetGameMode : __int32
{
	EPresetGameMode_Unspecified = 0x0,
	EPresetGameMode_Normal = 0x1,
	EPresetGameMode_Creative = 0x2,
	EPresetGameMode_Survival = 0x3,
	EPresetGameMode_Ambient = 0x4,
	EPresetGameMode_Permadeath = 0x5,
	EPresetGameMode_Seasonal = 0x6,
	EPresetGameMode_NumTypes = 0x7,
};

enum eBootLoadDelay : __int32
{
	EBootLoadDelay_LoadAll = 0x0,
	EBootLoadDelay_WaitForPlanet = 0x1,
	EBootLoadDelay_WaitForNothing = 0x2,
	EBootLoadDelay_NumTypes = 0x3,
};

enum eLifeSetting : __int32
{
	ELifeSetting_Dead = 0x0,
	ELifeSetting_Low = 0x1,
	ELifeSetting_Mid = 0x2,
	ELifeSetting_Full = 0x3,
	ELifeSetting_NumTypes = 0x4,
};

enum eGameStateMode : __int32
{
	EGameStateMode_LoadPreset = 0x0,
	EGameStateMode_UserStorage = 0x1,
	EGameStateMode_FreshStart = 0x2,
	EGameStateMode_NumTypes = 0x3,
};

enum eSolarSystemBoot : __int32
{
	ESolarSystemBoot_FromSettings = 0x0,
	ESolarSystemBoot_Generate = 0x1,
	ESolarSystemBoot_NumTypes = 0x2,
};

enum eBootMode : __int32
{
	EBootMode_MinimalSolarSystem = 0x0,
	EBootMode_SolarSystem = 0x1,
	EBootMode_GalaxyMap = 0x2,
	EBootMode_SmokeTest = 0x3,
	EBootMode_SmokeTestGalaxyMap = 0x4,
	EBootMode_Scratchpad = 0x5,
	EBootMode_UnitTest = 0x6,
	EBootMode_NumTypes = 0x7,
};

enum ePlayerSpawnLocationOverride : __int32
{
	EPlayerSpawnLocationOverride_None = 0x0,
	EPlayerSpawnLocationOverride_FromSettings = 0x1,
	EPlayerSpawnLocationOverride_Space = 0x2,
	EPlayerSpawnLocationOverride_SpaceStation = 0x3,
	EPlayerSpawnLocationOverride_RandomPlanet = 0x4,
	EPlayerSpawnLocationOverride_GameStartPlanet = 0x5,
	EPlayerSpawnLocationOverride_SpecificLocation = 0x6,
	EPlayerSpawnLocationOverride_NumTypes = 0x7,
};

struct cGcGameConfigCache
{
	eBootLoadDelay meBootLoadDelay;
	bool mbSkipIntro;
	bool mbSkipPlanetDiscoverOnBoot;
	ePresetGameMode meNewSaveGameMode;
	int miForceSaveSlot;
	bool mbForceLatestSaveSlot;
	bool mbSpawnPirates;
	bool mbSpawnRobots;
	bool mbSpawnShips;
	bool mbSpawnPulseEncounters;
	eLifeSetting meForceCreatureLifeLevelTo;
	bool mbForceCreatureLifeLevel;
	eGameStateMode meGameStateMode;
	eSolarSystemBoot meSolarSystemBoot;
	eBootMode meBootMode;
	ePlayerSpawnLocationOverride mePlayerLocationOverride;
	unsigned __int64 mMultiplayerUAOverride;
	unsigned __int64 mUDAOverride[2];
	unsigned __int64 mUAOverride;
};

struct cGcApplicationState : cTkFSMState
{
	cTkPhysRelMat34 mStereoCameraMatrices[2];
	cTkPhysRelMat34 mStereoPrevCameraMatrices[2];
	cTkSmartResHandle mShadowsPipelineRes;
	cTkSmartResHandle mShadowsTextureRes;
	cTkMatrix44 mStereoViewMatrices[2];
	cTkMatrix44 maMainProjMatrixHmd[2];
	cTkMatrix44 maMainViewMatrixHmd[2];
	cTkMatrix44 maMainPrevProjMatrixHmd[2];
	cTkMatrix44 maMainPrevViewMatrixHmd[2];
	EgRenderQueueHandle mMainRenderHandle;
	cTkMatrix44 mMainProjMatrix;
	cTkMatrix44 mMainViewMatrix;
	cTkMatrix44 mMainPrevProjMatrix;
	cTkMatrix44 mMainPrevViewMatrix;
	cTkPhysRelMat34 mPrevCameraMatrix;
	cTkPhysRelMat34 mCameraMatrix;
};

struct cGcApplicationBootState : cGcApplicationState {};

struct __declspec(align(16)) cGcApplicationBaseLoadingState : cGcApplicationState
{
	float mfDistractionFXAlphaOverride;
	bool mbShowDistractionFX;
	cTkTimerTemplate<0> mLoadingBackgroundFadeInTimer;
	cTkSmartResHandle mLoadingScreenBackgroundRes;
	bool mbTextureIsReady;
};

struct __declspec(align(8)) cGcApplicationGlobalLoadState : cGcApplicationBaseLoadingState
{
	cGcAsyncLoadOps mAsyncLoadOps;
	GlobalLoadPhase::Enum mPhase;
};

struct __declspec(align(16)) cGcApplicationLocalLoadState : cGcApplicationBaseLoadingState
{
	cGcPlayerRespawn::RespawnReason meLoadReason;
	bool mColdBoot;
	bool mbWarpingToNewGalaxy;
	bool mbWarpingUsingGalaxyMap;
	bool mbForceRespawnAsFreshStart;
	cGcApplicationLocalLoadState::SaveRestoreMode meSaveRestoreMode;
	LocalLoadPhase::Enum mPhase;
	int mPrelaunchCountdown;
	int mRepeatingPhaseCounter;
	Engine::cEgShaderCompilationState* mpShaderCompilationState;
	unsigned __int64 mLoadTimerStartSystemTime;
	cTkMatrix34 mSavedCameraMatrix;
	cTkPhysRelMat34 mLastFrameCameraMatrix;
	cTkVector3 mRenderOffset;
	float mfLastFrameFov;
	float mfSavedFoV;
	float mfSavedFoVAdj;
	float mfSavedFoVAdjDist;
	float mfShaderLoadDisplayMsg;
};

struct __declspec(align(4)) cGcUserdataPrimaryPlanetChange
{
	ApplicationStateEvents::Enum mCheck;
	int mNewPrimaryPlanetIndex;
	bool mImmediate;
};

struct cGcApplicationSimulationState : cGcApplicationState
{
	cTkStopwatch mSimThreadTimer;
	cTkStopwatch mSimUpdateTimer;
	cTkStopwatch mSyncPointTimer;
	float mfLastSimThreadTimeCPU;
	float mfLastSimUpdateTimeCPU;
	float mfLastSyncPointTimeCPU;
	cTkMatrix34 mMeasurementAnchorTM;
	cTkMatrix44 mDebugProjMatrix;
	cTkMatrix44 mDebugViewMatrix;
	cTkVector3 mvDebugRenderOffset;
	bool mbFirstRender;
	void* mRenderMutex;
	std::atomic<bool> mbRunUpdateThread;
	std::atomic<bool> mbExitUpdateThread;
	std::atomic<bool> mbUpdateThreadActive;
	unsigned int mThreadId;
	bool mbUpdateThreadCreated;
	bool mbUpdate;
	bool mbRender;
	float mfFoVAdjust;
	float mfFovSpringSpeed;
	float mfFoV;
	float mfPrevFoV;
	float mfFoVFixedDist;
	float mfTimestep;
	__declspec(align(16)) cTk2dText mFramerateText;
	cTk2dTextPreset mTextPreset;
	cTkFixedString<128, wchar_t> macFramerateTextBuffer;
	cGcUserdataPrimaryPlanetChange mChangePlanetData;
	int miPrepareToPauseFrame;
	bool mChangePlanetRequested;
	bool mbDoMeasurement;
	bool mbPrepareToPause;
	bool mbFirstBootPrepare;
	float mfResetVRCameraTimer;
	cTkSmartResHandle mCloudsPipelineRes;
	cTkFixedString<32, wchar_t> mFramerateString;
	void* mThreadSyncStartedEvent;
	void* mCullingStartedEvent;
};

struct  cGcApplicationShutdownState : cGcApplicationState {};

struct __declspec(align(16)) cGcApplicationGalacticMapState : cGcApplicationState
{
	bool mabMoveActive[2];
	cTkMatrix34 maMoveOrigin[2];
	bool mbRequestNextGalaxy;
	bool mbMultiplayer;
};

struct cGcApplicationSmokeTestState : cGcApplicationSimulationState
{
	cTkPhysRelMat34 mTransformForMovement;
	cTkPhysRelMat34 mTransformForLookAt;
	int miCurrentPlanet;
	int miNumPlanetsVisited;
	bool mbSpaceTravel;
	float mfSpaceTravelTimer;
	cTkSmoothCD<float> mfHeightSpring;
	bool mbHeightSpringSet;
	float mfInitialPauseLeft;
	float mfSmokeTestFlashTimeLeft;
	float mfGifTimeBetweenKeyframesLeft;
	int miFrames;
	float mfRightSunPosRandom;
	float mfUpSunPosRandom;
	float mfAtSunPosRandom;
	float mfPlanetFlightTimer;
	float mfPlanetFlightTimeoutTimer;
	cTkColour mFlashColour;
	float mfFullScreenFlashTimer;
	bool mbRenderFullScreenFlash;
	bool mbFinished;
	bool mbIsCompleted;
	bool mbIsExiting;
	cGcSmokeTestScenario* mpSmokeTestScenario;
	cGcSmokeTestScenario* mpSmokeTestCycleScenario;
	std::vector<float, TkSTLAllocatorShim<float, 4, -1> > mafLowMemoryWatermarks;
};

struct cGcApplicationAmbientGameState : cGcApplicationSimulationState {};

struct __declspec(align(16)) cGcApplicationDeathState : cGcApplicationState
{
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPipelineResource;
	std::vector<bool, TkSTLAllocatorShim<bool> > maPreviousPipelineStageState;
	cTkFixedString<512, char> mDeathQuote;
	cTkFixedString<512, char> mDeathAuthor;
	int miDeathQuoteIndex;
	cTkVector3 mDeathPosition;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mTrashedItems;
	cGcNGui mGUI;
	float mfQuoteAlpha;
	cGcApplicationDeathState::Phase mePhase;
	float mfTimeDeadTotal;
	float mfTimeToSpendDead;
	float mfTimeToWaitForQuote;
	float mfTimeToSpendGeneratingSpawnLocation;
	float mfRegenDistractionAlpha;
	bool mbDeleteManualSave;
	bool mbPlayerWasInShipWhenKilled;
	bool mbPlayerWasInVehicleWhenKilled;
	bool mbPlayerWasInsidePlanetRangeWhenKilled;
	bool mbPlayerWasLandedWhenKilled;
	bool mbPlayerCrashingOnPlanetFromShip;
	bool mbPlayerWasInAbandonedFreighter;
	bool mbFirstUpdate;
};

struct cGcApplicationScratchpadState : cGcApplicationState
{
	std::unique_ptr<cGcApplicationScratchpadState::CustomData> mCustomData;
	std::unique_ptr<cGcApplicationScratchpadState::StateData> mStateData;
};

struct ITkUserServiceNotifications
{
	ITkUserServiceNotifications_vtbl* __vftable /*VFT*/;
};

struct cTkCSMutex
{
	_RTL_CRITICAL_SECTION mMutex;
};

struct cGcApplication : cTkFSM
{
	cGcApplication::Data* mpData;
	unsigned int muPlayerSaveSlot;
	ePresetGameMode meGameMode;
	ePresetGameMode meSeasonalGameMode;
	bool mbSavingEnabled;
	bool mbFullyBooted;
	cGcGameConfigCache mGameConfigCache;
	cTkStopwatch mRenderTimer;
	long double mLastRenderTimeMS;
	long double mfStartTime;
	int miLoadBalancingTimeout;
	cGcApplicationBootState mApplicationBootState;
	cGcApplicationCoreServicesState mApplicationCoreServicesState;
	cGcApplicationGlobalLoadState mApplicationGlobalLoadState;
	cGcApplicationLocalLoadState mApplicationLocalLoadState;
	cGcApplicationSimulationState mApplicationSimulationState;
	cGcApplicationShutdownState mApplicationShutdownState;
	cGcApplicationGalacticMapState mApplicationGalacticMapState;
	cGcApplicationSmokeTestState mApplicationSmokeTestState;
	cGcApplicationAmbientGameState mApplicationAmbientGameState;
	cGcApplicationDeathState mApplicationDeathState;
	cGcApplicationScratchpadState mApplicationScratchpadState;
	cGcApplicationGameModeSelectorState mApplicationGameModeSelectorState;
	cGcApplicationTitleScreenState mApplicationTitleScreenState;
	cGcApplicationUGCBaseViewerState mApplicationUGCBaseViewerState;
	float mfResetVRCameraTimer;
	bool mbPaused;
	bool mbTkPaused;
	bool mbStepOneFrame;
	bool mbMultiplayerActive;
	bool mbWindowFocused;
	bool mbHasFocus;
	bool mbQuitRequested;
	bool mResumeFromSuspendSave;
	std::vector<cTkFixedString<128, char>, TkSTLAllocatorShim<cTkFixedString<128, char>> > mAssertMessage;
	cTkCSMutex mAssertMessageLock;
};

struct cTkTextureResource
{
	cTkFixedString<128, char> macFilename;
	cTkSmartResHandle mResHandle;
};

enum eInteractionBufferType : __int32
{
	EInteractionBufferType_Distress_Signal = 0x0,
	EInteractionBufferType_Crate = 0x1,
	EInteractionBufferType_Destructable = 0x2,
	EInteractionBufferType_Terrain = 0x3,
	EInteractionBufferType_Cost = 0x4,
	EInteractionBufferType_Building = 0x5,
	EInteractionBufferType_Creature = 0x6,
	EInteractionBufferType_Maintenance = 0x7,
	EInteractionBufferType_Personal = 0x8,
	EInteractionBufferType_Personal_Maintenance = 0x9,
	EInteractionBufferType_FireteamSync = 0xA,
	EInteractionBufferType_NumTypes = 0xB,
};

struct cGcGameMode
{
	ePresetGameMode mePresetGameMode;
};

#pragma once
#include "cTkTypes.h"
#include "cGcPlayer.h"
#include "cGcBlockedUser.h"

enum eTemperatureUnit : __int32
{
	ETemperatureUnit_Invalid = 0x0,
	ETemperatureUnit_C = 0x1,
	ETemperatureUnit_F = 0x2,
	ETemperatureUnit_K = 0x3,
	ETemperatureUnit_NumTypes = 0x4,
};

enum eMovementMode : __int32
{
	EMovementMode_Teleporter = 0x0,
	EMovementMode_Smooth = 0x1,
	EMovementMode_NumTypes = 0x2,
};

enum eMovementDirection : __int32
{
	EMovementDirection_WorldRelative = 0x0,
	EMovementDirection_BodyRelative = 0x1,
	EMovementDirection_HeadRelative = 0x2,
	EMovementDirection_NotSet = 0x3,
	EMovementDirection_NumTypes = 0x4,
};

struct cGcMovementDirection
{
	eMovementDirection meMovementDirection;
};

enum eTurnMode : __int32
{
	ETurnMode_Smooth = 0x0,
	ETurnMode_Snap = 0x1,
	ETurnMode_NumTypes = 0x2,
};

enum eUIColourScheme : __int32
{
	EUIColourScheme_Default = 0x0,
	EUIColourScheme_Protanopia = 0x1,
	EUIColourScheme_Deuteranopia = 0x2,
	EUIColourScheme_Tritanopia = 0x3,
	EUIColourScheme_NumTypes = 0x4,
};

enum eSpaceCombatFollowMode : __int32
{
	ESpaceCombatFollowMode_Disabled = 0x0,
	ESpaceCombatFollowMode_Hold = 0x1,
	ESpaceCombatFollowMode_Toggle = 0x2,
	ESpaceCombatFollowMode_NumTypes = 0x3,
};

enum exEyeTrackingFlags : __int32
{
	FEyeTrackingFlags_BaseBuilding = 0x1,
	FEyeTrackingFlags_WristMenus = 0x2,
	FEyeTrackingFlags_LookVector = 0x4,
	FEyeTrackingFlags_BinocScanner = 0x8,
	FEyeTrackingFlags_None = 0x0,
	FEyeTrackingFlags_Mask = 0xF,
};

enum eActiveModeOnFoot : __int32
{
	EActiveModeOnFoot_None = 0x0,
	EActiveModeOnFoot_ScopeOnly = 0x1,
	EActiveModeOnFoot_ScopeOrFiring = 0x2,
	EActiveModeOnFoot_Always = 0x3,
	EActiveModeOnFoot_NumTypes = 0x4,
};

enum eActiveModeWhenBuilding : __int32
{
	EActiveModeWhenBuilding_None = 0x0,
	EActiveModeWhenBuilding_BuildPlacementOnly = 0x1,
	EActiveModeWhenBuilding_SelectionModeOnly = 0x2,
	EActiveModeWhenBuilding_Always = 0x3,
	EActiveModeWhenBuilding_NumTypes = 0x4,
};

enum eEnableGyroInBuildingFreeCam : __int32
{
	EEnableGyroInBuildingFreeCam_Never = 0x0,
	EEnableGyroInBuildingFreeCam_MatchActiveModeWhenBuilding = 0x1,
	EEnableGyroInBuildingFreeCam_Always = 0x2,
	EEnableGyroInBuildingFreeCam_NumTypes = 0x3,
};

enum eActiveModeInExocraft : __int32
{
	EActiveModeInExocraft_None = 0x0,
	EActiveModeInExocraft_Firing = 0x1,
	EActiveModeInExocraft_Always = 0x2,
	EActiveModeInExocraft_NumTypes = 0x3,
};

enum eLookStickEnabled : __int32
{
	ELookStickEnabled_None = 0x0,
	ELookStickEnabled_Disabled = 0x1,
	ELookStickEnabled_Enabled = 0x2,
	ELookStickEnabled_NumTypes = 0x3,
};

enum eCursorLookStickEnabled : __int32
{
	ECursorLookStickEnabled_None = 0x0,
	ECursorLookStickEnabled_Disabled = 0x1,
	ECursorLookStickEnabled_NumTypes = 0x2,
};

enum eHandedness : __int32
{
	EHandedness_Left = 0x0,
	EHandedness_Right = 0x1,
	EHandedness_NumTypes = 0x2,
};

enum eGyroRotationSpace : __int32
{
	EGyroRotationSpace_Local = 0x0,
	EGyroRotationSpace_Player = 0x1,
	EGyroRotationSpace_NumTypes = 0x2,
};

enum eGyroRotationSpaceHandheld : __int32
{
	EGyroRotationSpaceHandheld_Local = 0x0,
	EGyroRotationSpaceHandheld_Player = 0x1,
	EGyroRotationSpaceHandheld_NumTypes = 0x2,
};

enum eYawAxisDirection : __int32
{
	EYawAxisDirection_Disabled = 0x0,
	EYawAxisDirection_Standard = 0x1,
	EYawAxisDirection_Inverted = 0x2,
	EYawAxisDirection_NumTypes = 0x3,
};

enum eRollAxisDirection : __int32
{
	ERollAxisDirection_Disabled = 0x0,
	ERollAxisDirection_Standard = 0x1,
	ERollAxisDirection_Inverted = 0x2,
	ERollAxisDirection_NumTypes = 0x3,
};

enum ePitchAxisDirection : __int32
{
	EPitchAxisDirection_Disabled = 0x0,
	EPitchAxisDirection_Standard = 0x1,
	EPitchAxisDirection_Inverted = 0x2,
	EPitchAxisDirection_NumTypes = 0x3,
};

struct __declspec(align(4)) cGcGyroSettingsData
{
	bool mbGyroEnabled;
	bool mbGyroEnabledHandheld;
	eActiveModeOnFoot meActiveModeOnFoot;
	bool mbAllowWhenRidingCreatures;
	eActiveModeWhenBuilding meActiveModeWhenBuilding;
	eEnableGyroInBuildingFreeCam meEnableGyroInBuildingFreeCam;
	eActiveModeInExocraft meActiveModeInExocraft;
	eLookStickEnabled meLookStickEnabled;
	bool mbGyroCursorEnabled;
	float mfCursorSensitivityX;
	float mfCursorSensitivityY;
	float mfCursorTighteningThreshold;
	eCursorLookStickEnabled meCursorLookStickEnabled;
	eHandedness meHandedness;
	float mfSensitivityX;
	float mfSensitivityY;
	float mfSteadying;
	float mfAcceleration;
	bool mbEnableAdvancedOptions;
	float mfScopeMultiplier;
	float mfAimingMultiplier;
	float mfExocraftMultiplier;
	float mfBuildingMultiplier;
	bool mbZoomScalesSensitivity;
	eGyroRotationSpace meGyroRotationSpace;
	eGyroRotationSpaceHandheld meGyroRotationSpaceHandheld;
	eYawAxisDirection meYawAxisDirection;
	eRollAxisDirection meRollAxisDirection;
	ePitchAxisDirection mePitchAxisDirection;
	float mfSmoothingThreshold;
	float mfSmoothingWindow;
	float mfTighteningThreshold;
	float mfDeadzone;
	bool mbFilterControllerVibrations;
};

enum eLanguage : __int32
{
	ELanguage_Default = 0x0,
	ELanguage_English = 0x1,
	ELanguage_USEnglish = 0x2,
	ELanguage_French = 0x3,
	ELanguage_Italian = 0x4,
	ELanguage_German = 0x5,
	ELanguage_Spanish = 0x6,
	ELanguage_Russian = 0x7,
	ELanguage_Polish = 0x8,
	ELanguage_Dutch = 0x9,
	ELanguage_Portuguese = 0xA,
	ELanguage_LatinAmericanSpanish = 0xB,
	ELanguage_BrazilianPortuguese = 0xC,
	ELanguage_Japanese = 0xD,
	ELanguage_TraditionalChinese = 0xE,
	ELanguage_SimplifiedChinese = 0xF,
	ELanguage_TencentChinese = 0x10,
	ELanguage_Korean = 0x11,
	ELanguage_NumTypes = 0x12,
};

struct cTkLanguages
{
	eLanguage meLanguage;
};

enum eHighResVRUI : __int32
{
	EHighResVRUI_High = 0x0,
	EHighResVRUI_Low = 0x1,
	EHighResVRUI_NumTypes = 0x2,
};

struct cGcInWorldUIScreenData
{
	float mfScreenScale;
	cTkVector3 mScreenOffset;
	cTkVector4 mScreenRotation;
};

struct cGcUserSettingsData
{
	bool mbInvertLookControls;
	bool mbInvertFlightControls;
	bool mbInvertVRInWorldFlightControls;
	bool mbVRVehiclesUseWorldControls;
	bool mbHUDHidden;
	bool mbVibration;
	int miScreenBrightness;
	int miMusicVolume;
	int miSfxVolume;
	int miLookSensitivityMode1;
	int miLookSensitivityMode2;
	int miFlightSensitivityMode1;
	int miFlightSensitivityMode2;
	int miCursorSensitivityMode1;
	int miCursorSensitivityMode2;
	int miMouseSpringSmoothing;
	cGcBlockListPersistence mBlockList;
	int miMotionBlurAmount;
	int miFilter;
	bool mbDamageNumbers;
	ePS4FixedFPS mePS4FixedFPS;
	float mfPS4FOVFoot;
	float mfPS4FOVShip;
	bool mbXboxOneXHighResolutionMode;
	bool mbPS4VignetteAndScanlines;
	eBaseSharingMode meBaseSharingMode;
	cTkDynamicArray<TkID<128> > maSeenSubstances;
	cTkDynamicArray<TkID<128> > maSeenTechnologies;
	cTkDynamicArray<TkID<128> > maSeenProducts;
	cTkDynamicArray<TkID<256> > maSeenWikiTopics;
	cTkDynamicArray<TkID<256> > maUnlockedWikiTopics;
	cTkDynamicArray<TkID<128> > maUnlockedTitles;
	cTkDynamicArray<TkID<128> > maUnlockedSpecials;
	cTkDynamicArray<TkID<128> > maUnlockedSeasonRewards;
	cTkDynamicArray<TkID<128> > maUnlockedTwitchRewards;
	cTkDynamicArray<TkID<128> > maUnlockedPlatformRewards;
	bool mbVoiceChat;
	bool mbMultiplayer;
	bool mbInstantUIInputs;
	bool mbInstantUIDelete;
	bool mbSpeechToText;
	bool mbTranslate;
	bool mbCrossPlatform;
	eTemperatureUnit meTemperatureUnit;
	bool mbUseOldMouseFlight;
	int miLastSeenCommunityMission;
	int miLastSeenCommunityMissionTier;
	eMovementMode meMovementMode;
	cGcMovementDirection mMovementDirectionPad;
	cGcMovementDirection mMovementDirectionHands;
	bool mbEnableControllerCursorInVR;
	eTurnMode meTurnMode;
	float mfVRVignetteStrength;
	bool mbUseShipAutoControlVignette;
	float mfHUDZoom;
	float mfFrontendZoom;
	bool mbUseAutoTorch;
	eUIColourScheme meUIColourScheme;
	bool mbEnableModdingConsole;
	bool mbHeadBob;
	bool mbVRHeadBob;
	bool mbVRShowBody;
	bool mbUseCharacterHeightForCamera;
	bool mbBaseComplexityLimitsEnabled;
	bool mbEnableLargeLobbies;
	int miFireteamSessionCount;
	int miHeadsetVibrationStrength;
	int miVibrationStrength;
	int miCamerShakeStrength;
	int miTriggerFeedbackStrength;
	eSpaceCombatFollowMode meSpaceCombatFollowMode;
	cTkDynamicArray<cTkFixedString<128, char> > maacUpgradedUsers;
	bool mbAllowWhiteScreenTransitions;
	bool mbAccessibleText;
	bool mbAutoScanDiscoveries;
	bool mbSprintScanSwap;
	bool mbPlaceJumpSwap;
	exEyeTrackingFlags mexEyeTrackingFlags;
	cGcGyroSettingsData mGyroSettings;
	cTkLanguages mLanguage;
	bool mbAutoRotateThirdPersonPlayerCamera;
	cGcHand mDominantHand;
	float mfHazardEffectsStrength;
	bool mbQuickMenuBuildMenuSwap;
	eHighResVRUI meHighResVRUI;
	float mfPlayerHUDVROffset;
	float mfShipHUDVROffset;
	cGcInWorldUIScreenData mQuickMenuLauncherScreenData;
	cGcInWorldUIScreenData mVehicleWristMenuScreenData;
	cGcInWorldUIScreenData mWeaponMenuScreenData;
	cGcInWorldUIScreenData mLargeWeaponMenuScreenData;
};

struct __declspec(align(16)) cGcUserSettings
{
	enum eLoadState : __int32
	{
		Unloaded = 0x0,
		EaryBootLoadComplete = 0x1,
		FullLoadComplete = 0x2,
	};

	enum Sensitivity : __int32
	{
		Flight = 0x0,
		View = 0x1,
		Cursor = 0x2,
	};

	cGcUserSettingsData mSettingsData;
	cGcGyroSettingsData mGyroSettingsDataHandheldProxy;
	cGcBlockList mBlockList;
	cGcUserSettings::eLoadState meLoadState;
	bool mbPendingWrite;
	bool mbWriteThreadCreated;
	unsigned int mWriteThreadId;
	unsigned __int64 mu64LastContentHash1;
	unsigned __int64 mu64LastContentHash2;
	bool mbContentHashesValid;
	robin_hood::detail::Table<0, 80, cTkFixedString<128, char>, void, robin_hood::hash<cTkFixedString<128, char>, void>, std::equal_to<cTkFixedString<128, char> > > mUpgradedUsers;
};
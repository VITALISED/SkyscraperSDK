#pragma once
#include "cGcNGui.h"
#include "cGcApplication.h"
#include "cTkTypes.h"
#include "cTkStoragePersistent.h"
#include "Difficulty.h"

struct cGcApplicationGameModeSelectorState : cGcApplicationState
{
	enum DisplayState : __int32
	{
		EHostJoinSelection = 0x0,
		ESlotSelection = 0x1,
		EModeSelection = 0x2,
		ECustomDifficulty = 0x3,
		EDeletionWarning = 0x4,
		EMultiplayerFriends = 0x5,
		EManageCloudSaves = 0x6,
		EOptions = 0x7,
		ECredits = 0x8,
		ERemapControls = 0x9,
		EManageMods = 0xA,
		EManageModsSaves = 0xB,
	};

	enum MultiplayerState : __int32
	{
		ENone = 0x0,
		EFriendLobby = 0x1,
		ERandom = 0x2,
	};

	enum CloudSaveUpdateState : __int32
	{
		eShowingInfo = 0x0,
		eUploadingData = 0x1,
		eDownloadingData = 0x2,
		eConfirmOverwriting = 0x3,
		eShowingResult = 0x4,
	};

	cGcNGuiLayer* mpSelectorUIRoot;
	cGcNGuiLayer* mpDeletionWarningUIRoot;
	cGcNGuiLayer* mpSlotUIRoot;
	cGcNGuiLayer* mpModeUIRoot;
	cGcNGuiLayer* mpMultiplayerUIRoot;
	cGcNGuiLayer* mpCloudSavesUIRoot;
	cGcNGuiLayer* mpStartUIRoot;
	cGcNGuiLayer* mpVRModeButton;
	cGcNGuiLayer* mpPCOSK;
	cGcNGuiLayer* mpError;
	cGcNGuiLayer* mpPatchNotesBox;
	cGcNGuiLayer* mpOKCancelDialog;
	cGcNGuiLayer* mpModManagerUIRoot;
	cGcNGuiLayer* mpModSaveManagerUIRoot;
	std::vector<bool, TkSTLAllocatorShim<bool> > mCustomSavesDeletionSelectionState;
	cGcNGuiLayer* mpCustomDifficultyUIRoot;
	cGcNGuiLayer* mpOptionsUIRoot;
	cGcNGuiLayer* mpCreditsUIRoot;
	cGcNGuiLayer* mpRemapControlsUIRoot;
	cGcNGuiTextSpecial* mpStatusText;
	float mfStatusTextClearCountdown;
	float mfSlotWidth;
	cGcNGuiLayer* mpHoverLayer;
	cTkSmartResHandle mIconWarning;
	cGcApplicationGameModeSelectorState::WarningDlgComponents mWarningDlgComponents;
	cGcAsyncLoadOps mAsyncLoadOps;
	cGcLayerInteractControl* mpLayerInteractControl;
	cTkNGuiInput mSelectorGuiInput;
	ModeSelectorPhase::Enum mPhase;
	float mfAppearFade;
	float mfTimeFx;
	float mfNotifyTimer;
	unsigned int muSelectedPlayerSlot;
	bool mbSelectedEmptySlot;
	ePresetGameMode meSelectedGameMode;
	unsigned int muOccupiedSlots;
	eDifficultyPresetType meSelectedDifficultyPreset;
	cGcDifficultySettingsData mSelectedDifficultySettings;
	int miPrepareCount;
	bool mbDownloadedSeasonalData_REMOVEME;
	bool mbModeUISetupRequired;
	bool mbCenterCursor;
	ePresetGameMode mUGCBaseModeToLoad;
	bool mbLoadDirectlyToBase;
	int miSyncStateTimeout;
	bool mbCompletedBefore;
	float mfCursorSizeNormalised;
	bool mbCursorHoverActive;
	cTkFixedString<128, char> msMPHostName;
	cTkFixedString<256, char> msMPOtherPlayers;
	cTkFixedString<64, char> msMPGameMode;
	bool mbSkippedStartScreen;
	bool mbShowingOKCancelDialog;
	std::function<void __cdecl(bool, bool)> mOnCancelDialogClosedCallbackFn;
	bool mbVRModeSelected;
	float mfAutoJoinDelay;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPipelineResource;
	std::vector<bool, TkSTLAllocatorShim<bool> > maPreviousPipelineStageState;
	std::vector<GcGameStatePersistence::StorageSlotInformation, TkSTLAllocatorShim<GcGameStatePersistence::StorageSlotInformation> > mSlotSaveStates;
	ScrollBarState mSaveSlotsScrollBarState;
	int miSlotsScrollStartIndex;
	std::vector<cGcModManager::ModInfo, TkSTLAllocatorShim<cGcModManager::ModInfo> > mLoadedModsInfo;
	cTkStoragePersistent::LowSpaceWarningData mLowSpaceWarningData;
	float mfLowSpaceSkipDelay;
	bool mbFirstBoot;
	char* mpSaveDirectory;
	bool mbWaitingOnConsoleOSK;
	bool mbCanUploadCloudSave;
	bool mbCanDownloadCloudSave;
	bool mbCloudSaveResult;
	float mfCloudResultTimer;
	cGcApplicationGameModeSelectorState::DisplayState meScreenToReturnToFromOptionsScreen;
	cGcApplicationGameModeSelectorState::CloudSaveUpdateState meCloudSaveUpdateState;

	//what
	template <class T, int size>
	struct EnumIconResources
	{
		cTkSmartResHandle mResources[Y]
	};

	struct WarningDlgComponents
	{
		cGcNGuiLayer* mpRootLayer;
		cGcNGuiLayer* mpMidSec;
		cGcNGuiLayer* mpLowSec;
		cGcNGuiTextSpecial* mpTitle;
		cGcNGuiTextSpecial* mpHelpContinue;
		cGcNGuiTextSpecial* mpHelpCancel;
		cGcNGuiGraphic* mpIcon;
		cGcNGuiLayer* mpIconFx;
	};

	struct __declspec(align(4)) State
	{
		cGcApplicationGameModeSelectorState::DisplayState mDisplayState;
		cGcApplicationGameModeSelectorState::MultiplayerState mMultplayerState;
		int miChosenIndex;
		int miFriendsPage;
		int miModsPage;
		int miModsSavesManagerPage;
		float mfConfirmationValue;
		bool mbWaitingOnInputGap;
		bool mbPlayingHoldAudio;
	};

	struct SlotComponents
	{
		cGcNGuiLayer* mpSlot;
		cGcNGuiLayer* mpChoiceRoot;
		cGcNGuiGraphic* mpIcon;
		cGcNGuiTextSpecial* mpModeTitle;
		cGcNGuiTextSpecial* mpSubtitle;
		cGcNGuiGraphic* mpBackground;
		cGcNGuiGraphic* mpBackgroundDesaturated;
		cGcNGuiGraphic* mpBackgroundLocked;
		cGcNGuiLayer* mpHighlightLayer;
		cGcNGuiLayer* mpSeasonLayer;
		cGcNGuiTextSpecial* mpSeasonHeaderText;
		cGcNGuiTextSpecial* mpSeasonTimeText;
		cGcNGuiGraphic* mpSeasonTimeBackground;
		cGcNGuiGraphic* mpSeasonTimeLowBackground;
		cGcNGuiTextSpecial* mpSeasonDescText;
		cGcNGuiTextSpecial* mpSeasonTitleText;
		cGcNGuiText* mpSlotTitle;
		cGcNGuiLayer* mpTwoLineSlot;
		cGcNGuiText* mpTwoLineSlotTitle;
		cGcNGuiText* mpSlotSummary;
		cGcNGuiText* mpGameModeFinger;
		cGcNGuiLayer* mpLayerSaveContainer;
		cGcNGuiLayer* mpLayerSaveBlank;
		cGcNGuiLayer* mpLayerSaveOK;
		cGcNGuiTextSpecial* mpSaveTimeText;
		cGcNGuiLayer* mpLayerPlayContainer;
		cGcNGuiLayer* mpLayerPlayBlank;
		cGcNGuiLayer* mpLayerPlayOK;
		cGcNGuiTextSpecial* mpPlayTimeText;
		cGcNGuiLayer* mpDisabled;
		cTkSmoothCD<float> mfHighlightAlpha;
	};

	cGcApplicationGameModeSelectorState::State mState;
	std::array<cGcApplicationGameModeSelectorState::SlotComponents, 5> mSaveSlotComponents;
	std::array<cGcApplicationGameModeSelectorState::SlotComponents, 7> mModeSlotComponents;
	cGcApplicationGameModeSelectorState::EnumIconResources<enum ePresetGameMode, 7> mSmallGameModeIcons;
	cGcApplicationGameModeSelectorState::EnumIconResources<enum eModeSelectPreset, 7> mModeSelectPresetIcons;
	cGcApplicationGameModeSelectorState::EnumIconResources<enum eModeSelectPreset, 7> mModeSelectPresetBackgrounds;
	cGcApplicationGameModeSelectorState::EnumIconResources<enum eModeSelectPreset, 7> mModeSelectPresetDesaturatedBackgrounds;
};
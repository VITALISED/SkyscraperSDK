#pragma once
#include "cTkTypes.h"
#include "cGcApplication.h"
#include "cGcNGui.h"
#include "Audio.h"
#include "cGcApplicationGameModeSelector.h"

struct cGcApplicationUGCBaseViewerState : cGcApplicationState
{
	cGcNGuiLayer* mpNextPageLayer;
	cGcNGuiLayer* mpPreviousPageLayer;
	cGcNGuiLayer* mpSelectorUIRoot;
	cGcNGuiLayer* mpWarningUIRoot;
	cGcNGuiLayer* mpBackButton;
	cGcNGuiLayer* mpSteamButton;
	cGcNGuiLayer* mpDotsLayer;
	cGcNGuiTextSpecial* mpStatusText;
	float mfStatusTextClearCountdown;
	float mfSlotWidth;
	cGcNGuiLayer* mpHoverLayer;
	cGcAsyncLoadOps mAsyncLoadOps;
	cGcLayerInteractControl* mpLayerInteractControl;
	cTkNGuiInput mSelectorGuiInput;
	bool mbDebounceInitialInput;
	UGCBaseViewerSelectorPhase::Enum mPhase;
	float mfAppearFade;
	float mfTimeFx;
	int miPrepareCount;
	bool mbCenterCursor;
	unsigned int miLastUGCSubscriptionsCount;
	unsigned int miUGCPage;
	std::vector<unsigned int, TkSTLAllocatorShim<unsigned int, 4, -1> > mUGCSubscriptionIdLookups;

	struct IconResources
	{
		cTkSmartResHandle mIconNormal;
		cTkSmartResHandle mIconSurvival;
		cTkSmartResHandle mIconCreative;
		cTkSmartResHandle mIconWarning;
		cTkSmartResHandle mIconPermadeath;
	};

	struct __declspec(align(8)) SlotComponents
	{
		cGcNGuiLayer* mpSlot;
		cGcNGuiLayer* mpChoiceRoot;
		cGcNGuiTextSpecial* mpTitle;
		cGcNGuiTextSpecial* mpUserName;
		cGcNGuiText* mpDesc;
		cGcNGuiTextSpecial* mpDesc2;
		cGcNGuiGraphic* mpModeIcon;
		cGcNGuiGraphic* mpScreenshotImage;
		cGcNGuiLayer* mpStarsContainer;
		cGcNGuiGraphic* mpStarsIcons[5];
		cGcNGuiLayer* mpExtraContainer;
		cGcNGuiGraphic* mpExtraIcon;
		ePresetGameMode meMode;
		cTkSmartResHandle mpTextureResourceHandle;
		cEgTextureResource* mpTexResource;
		bool mbEmptySlot;
		cTkFixedString<256, char> mPreviewImageName;
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

	struct SlotSaveDataState
	{
		int miTimestamp;
	};

	typedef cGcApplicationGameModeSelectorState::DisplayState DisplayState;

	struct __declspec(align(4)) State
	{
		TkAudioObject mAudioObject;
		DisplayState mDisplayState;
		int miChosenIndex;
		float mfConfirmationValue;
		bool mbWaitingOnInputGap;
		bool mbPlayingHoldAudio;
	};

	cGcApplicationUGCBaseViewerState::IconResources mIconResources;
	std::array<cGcApplicationUGCBaseViewerState::SlotComponents, 5> mSlotComponents;
	cGcApplicationUGCBaseViewerState::WarningDlgComponents mWarningDlgComponents;
	std::array<cGcApplicationUGCBaseViewerState::SlotSaveDataState, 3> mSlotSaveStates;
	cGcApplicationUGCBaseViewerState::State mState;
};
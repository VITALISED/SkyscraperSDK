#pragma once
#include "cGcApplication.h"
#include "Audio.h"
#include "cGcNGui.h"

struct cGcApplicationTitleScreenState::State
{
	TkAudioObject mAudioObject;
};

struct cGcApplicationTitleScreenState : cGcApplicationState, ITkUserServiceNotifications
{
	cGcNGuiLayer* mpTitleUIRoot;
	cGcNGuiLayer* mpUserDetails;
	cGcNGuiTextSpecial* mpPlayerName;
	cGcNGuiGraphic* mpPlayerIcon;
	cTkSmartResHandle mhPlayerIconTexture;
	TitleScreenPhase::Enum mPhase;
	cTkNGuiInput mTitleGuiInput;
	float mfAppearFade;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPipelineResource;
	std::vector<bool, TkSTLAllocatorShim<bool> > maPreviousPipelineStageState;

	struct State
	{
		TkAudioObject mAudioObject;
	};

	cGcApplicationTitleScreenState::State mState;
};

#pragma once
#include "Alien.h"
#include "cGcFrontendManager.h"

struct cGcPlayerCommunicatorMessage
{
	TkID<256> mDialog;
	bool mbShowHologram;
	eCommunicatorType meCommunicatorType;
	cGcAlienRace mRaceOverride;
	TkID<256> mShipHUDOverride;
};

struct cGcPlayerCommunicator
{
	typedef cGcFrontendManager::eState eState;

	struct cGcPlayerCommunicatorSignal
	{
		cGcPlayerCommunicatorMessage mMessage;
		std::pair<TkID<128>, cTkSeed> mIDSeed;
		cTkAttachment* mpAttachment;
	};

	cGcPlayerCommunicator::cGcPlayerCommunicatorSignal mSignal;
	TkHandle mActiveNode;
	cGcInteractionComponent* mpActiveInteraction;
	cGcNPCComponent* mpActiveNPC;
	cGcPlayerCommunicator::eState meState;
	float mfActiveTime;
	bool mbAutoOpen;
	cGcPlayerCommunicatorMessage mDebugMessage;
	cGcPlayerCommunicator::cGcPlayerCommunicatorSignal mTakeOffCommunicatorSignal;
};
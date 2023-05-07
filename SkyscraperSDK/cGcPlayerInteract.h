#pragma once
#include "cTkTypes.h"
#include "cGcScanner.h"
#include "Raycast.h"

enum ePlayerInteraction
{
	EPlayerInteraction_None = 0xFFFFFFFF,
	EPlayerInteraction_HoldButton = 0x0,
	EPlayerInteraction_Shoot = 0x1,
	EPlayerInteraction_Tap = 0x2,
	EPlayerInteraction_NumTypes = 0x3,
};

enum ePlayerInteractIcon : __int32
{
	EPlayerInteractIcon_Hold = 0x0,
	EPlayerInteractIcon_Mine = 0x1,
	EPlayerInteractIcon_Shoot = 0x2,
	EPlayerInteractIcon_Deconstruct = 0x3,
	EPlayerInteractIcon_Armour = 0x4,
	EPlayerInteractIcon_NumTypes = 0x5,
};

struct cGcTargetHelper
{
	struct __declspec(align(4))InteractLabelMarker
	{
		cTkRigidBodyPtr mpBody;
		cGcCreatureComponent* mpCreature;
		TkHandle mLocator;
		bool mbTerrainResource;
	};

	ePlayerInteraction meTargetType;
	cTkAttachmentPtr mpCurrentTarget;
	cGcTargetHelper::InteractLabelMarker mCurrentTargetHelper;
	float mfFocusTargetTimer;
	bool mbValidInteraction;
	bool mbTargetInfoDynamic;
	ePlayerInteractIcon meIconType;
	cTkFixedString<127, char> mTargetName;
	cTkFixedString<256, char> mTargetSubtitle;
	cTkColour mTargetSubtitleColour;
	cTkFixedString<256, char> mTargetSubtitle2;
	cTkColour mTargetSubtitle2Colour;
	cTkPhysRelVec3 mLabelWorldPos;
	cTkVector4 mLabelScreenPos;
	cGcSimpleScanEffect mHighlight;
	cGcScanEffectData mHighlightData;
	TkHandle mHandInteractLight;
	float mfHandInteractLightIntensity;
	cTkSmoothCD<float> mHandInteractLightActiveFactor;
	float mfHandInteractLightActiveTarget;
	cTkVector4 mLabelScreenPosLeft;
	cTkVector4 mLabelScreenPosRight;
	cTkRaycastJob mRaycastJob;
};

struct cGcPlayerInteract
{
	enum eHoldMode : __int32
	{
		EHoldMode_None = 0x0,
		EHoldMode_DisplayInteraction = 0x1,
		EHoldMode_Interacting = 0x2,
		EHoldMode_Interacted = 0x3,
		EHoldMode_Deleting = 0x4,
	};

	enum eShootMode : __int32
	{
		EShootMode_None = 0x0,
		EShootMode_Display = 0x1,
	};

	enum eTapMode : __int32
	{
		ETapMode_None = 0x0,
		ETapMode_Tapping = 0x1,
		ETapMode_Done = 0x2,
	};

	cGcPlayer* mpPlayer;
	cGcNGui mHoldGui;
	cGcTargetHelper mHoldHelper;
	cTkAttachmentPtr mpHoldTarget;
	cTkAttachmentPtr mpInteraction;
	TkHandle mHoldModel;
	TkHandle mHoldMasterModel;
	cGcPlayerInteract::eHoldMode meHoldMode;
	float mfHoldTimer;
	float mfErrorTimer;
	__declspec(align(16)) cGcMarkerRenderData mRenderData;
	cTkSmoothCD<float> mfHoldAlpha;
	cTkVector3 mNetworkLockPosition;
	bool mNetworkLockRequested;
	bool mbCanPickupHoldTarget;
	int meHoldInteractButton;
	cTkPhysRelVec3 mHandHoldStartPos;
	cTkVector3 mHandHoldDirOffset;
	bool mbHandHoldActive;
	bool mbHoldComplete;
	float mfLastGrabbableTargetTime;
	cGcSimpleScanEffect mDeconstructEffect;
	cGcNGui mShootGui;
	cGcTargetHelper mShootHelper;
	cTkRigidBodyPtr mpShootTarget;
	cGcPlayerInteract::eShootMode meShootMode;
	float mfShootHealth;
	cTkSmoothCD<float> mfShootAlpha;
	cGcTargetHelper mTapHelper;
	cGcPlayerInteract::eTapMode meTapMode;
	bool mbTapUp;
	TkAudioObject mAudioObject;
	bool mbHideOnRender;
	bool mbAllowedToInteractBasedOnVehicle;
	TkHandle mViewTarget;
	cTkRaycastJob mViewTargetRaycast;
};
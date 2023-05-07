#pragma once
#include "Weapon.h"
#include "cGcBeamEffect.h"

//FIXME types are all over the place

enum eEditPlaneState : __int32
{
	EEditPlaneState_Disabled = 0x0,
	EEditPlaneState_LockedOnPlane = 0x1,
	EEditPlaneState_LockedInFrontOfPlane = 0x2,
};

enum eTerrainEditShape : __int32
{
	ETerrainEditShape_Sphere = 0x0,
	ETerrainEditShape_Cube = 0x1,
	ETerrainEditShape_Num = 0x2,
};

struct cGcTerrainEditorBeam
{
	enum eEditMode
	{
		EEditMode_SubtractiveMode = 0x0,
		EEditMode_AdditiveMode = 0x1,
		EEditMode_FlatteningMode = 0x2,
		EEditMode_UndoMode = 0x3,
		EEditMode_NumTypes = 0x4,
	};

	cGcWeapon* mpOwnerWeapon;
	cTkSmartResHandle mHologramResources[3];
	TkHandle mHologramNodes[3];
	cGcScanEffectComponent* mpHologramEffects[3];
	cTkSmartResHandle mPlaneHologramResource;
	TkHandle mPlaneHologramNode;
	int miCurrentHologramIndex;
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mPlaneMaterial;
	cTkSmartResHandle mMuzzleEffectResources[4];
	float mfHologramLastInactiveTime;
	float mfHologramLastActiveTime;
	cGcScanEffectData mEditScanData;
	cGcBeamEffect mBeam;
	cGcBeamEffect mBeamCore;
	EffectInstance mTerrainEditorEffectHandle;
	EffectInstance mImpactEffectHandle;
	TkHandle mMuzzleEffects[4];
	cTkVector3 mLastEditAddLocation;
	bool mbLastEditWasAdd;
	bool mbActive;
	bool mbPrepared;
	TkAudioObject mAudioObject;
	float mfFiringTime;
	float mfLastFireTime;
	float mfLastEditTime;
	cTkPlane mEditPlane;
	eEditPlaneState meEditPlaneState;
	int miCurrentSizeIndex;
	eTerrainEditShape meCurrentShape;
	cTkVector3 mCurrentEditPosition;
	cTkVector3 mLastEditPosition;
	cTkVector3 mLastApplyPosition;
	bool mbRaycastHit;
	bool mbRaycastHitTerrain;
	bool mbPositionOverlapsObject;
	float mfPositionRaycastOffset;
	float mfCurrentEditPositionDistance;
	cGcTerrainEditorBeam::eEditMode meEditMode;
	float mfModeSwitchTime;
	bool mbInterpolationTrailLost;
	bool mbDisableLastEditHologram;
	bool mbShowNotificationMessage;
	float mfLastSizeChangeTime;
	TkHandle mLight;
};
#pragma once
#include "Raycast.h"
#include "cTkTypes.h"

struct __declspec(align(4)) cGcPersonalTeleporter
{
	enum eTeleporterState : __int32
	{
		ETeleporterState_Ready = 0x0,
		ETeleporterState_Charging = 0x1,
		ETeleporterState_Charged = 0x2,
		ETeleporterState_Teleporting = 0x3,
		ETeleporterState_Canceling = 0x4,
	};

	cGcPlacementArc mPlacementArc;
	TkHandle mEndEffectNode;
	TkHandle mEndEffectDirection;
	TkHandle mTravelEffect;
	TkHandle mTravelEffectActive;
	TkHandle mTravelEffectBlocked;
	TkHandle mTravelEffectBehind;
	TkHandle mTravelEffectComplete;
	TkHandle mEndEffectActive;
	TkHandle mEndEffectBlocked;
	cTkPhysRelVec3 mInitialPosition;
	cTkVector2 mInitialTargetDirection;
	cTkVector2 mTargetDirection;
	cGcPersonalTeleporter::eTeleporterState meState;
	float mfMovementTime;
	float mfChargeTime;
	float mfFadeTime;
	float mfTeleportTime;
	float mfLastSnapTurnImpulse;
	bool mbWantsTeleport;
	bool mbValidLastFrame;
	bool mbTeleported;
	bool mbAdjustFacing;
	bool mbDrawArc;
	bool mbOffHandSetsDirection;
};

#pragma once
#include "Projectle.h"
#include "cGcBeamEffect.h"
#include "cGcFullscreenEffectManager.h"

struct __cppobj cGcLaserBeam
{
	const cGcLaserBeamData* mpData;
	cGcProjectileData mDamageData;
	cGcOwnerConcept* mpOwnerConcept;
	TkID<128> mDebugTag;
	TkAudioObject mAudioObject;
	cGcBeamEffect mBeam;
	cGcBeamEffect mBeamCore;
	bool mbActive;
	bool mbDeferred;
	bool mbDeferredCheck;
	cTkRigidBodyPtr mpHitBody;
	cTkPhysRelVec3 mHitPoint;
	cTkVector3 mHitNormal;
	int miHitMaterial;
	cTkPhysRelVec3 mStartPoint;
	cTkPhysRelVec3 mEndPoint;
	float mfMiningTime;
	cTkRigidBodyPtr mpMiningBody;
	float mfStartTime;
	float mfLastHitTime;
	float mfLastFireTime;
	bool mbFiredThisFrame;
	int miDamageLevel;
	float mfLeechValue;
	TkHandle mLight;
	EffectInstance mLaserMuzzleFlashEffectHandle;
	EffectInstance mLaserImpactEffectHandle;
	TkID<128> mLaserImpactEffect;
	float mfLaserImpactSize;
	float mfMiningSpeedMultiplier;
	float mfMiningRadiusMultiplier;
	cTkColour mColour;
	float mfDebrisTime;
	float mfWidthBoost;
	bool mbHeatBoostNumbers;
	bool mbTracerMode;
	std::vector<cGcImpactCombatEffectData, TkSTLAllocatorShim<cGcImpactCombatEffectData> > maCombatEffects;
	std::vector<cGcCombatEffectDamageMultiplier, TkSTLAllocatorShim<cGcCombatEffectDamageMultiplier> > maCombatEffectsDmgMultipliers;
};
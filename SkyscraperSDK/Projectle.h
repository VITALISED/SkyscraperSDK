#pragma once
#include "cTkTypes.h"
#include "Audio.h"
#include "cGcApplication.h"
#include "AI.h"

enum eDamageType : __int32
{
	EDamageType_Gun = 0x0,
	EDamageType_Laser = 0x1,
	EDamageType_Shotgun = 0x2,
	EDamageType_Burst = 0x3,
	EDamageType_Rail = 0x4,
	EDamageType_Cannon = 0x5,
	EDamageType_Explosion = 0x6,
	EDamageType_Melee = 0x7,
	EDamageType_ShipGun = 0x8,
	EDamageType_ShipLaser = 0x9,
	EDamageType_ShipShotgun = 0xA,
	EDamageType_ShipMinigun = 0xB,
	EDamageType_ShipRockets = 0xC,
	EDamageType_ShipPlasma = 0xD,
	EDamageType_VehicleGun = 0xE,
	EDamageType_VehicleLaser = 0xF,
	EDamageType_SentinelLaser = 0x10,
	EDamageType_PlayerDamage = 0x11,
	EDamageType_PlayerWeapons = 0x12,
	EDamageType_ShipWeapons = 0x13,
	EDamageType_VehicleWeapons = 0x14,
	EDamageType_CombatEffects = 0x15,
	EDamageType_Fiend = 0x16,
	EDamageType_NumTypes = 0x17,
};

struct cGcProjectileData
{
	TkID<128> mId;
	cGcResourceElement mModel;
	cGcAudioWwiseEvents mFireAudioEvent;
	cGcAudioWwiseEvents mChargedFireAudioEvent;
	cGcAudioWwiseEvents mOverheatAudioEvent;
	float mfScale;
	bool mbIsAutonomous;
	bool mbApplyCombatLevelMultipliers;
	float mfRadius;
	float mfCapsuleHeight;
	float mfDefaultSpeed;
	float mfGravity;
	float mfLife;
	float mfOffset;
	float mfRagdollPush;
	float mfPhysicsPush;
	float mfDroneImpulse;
	int miDefaultDamage;
	float mfExtraPlayerDamage;
	cGcDamageType mDamageType;
	int miDefaultBounces;
	float mfBounceMaxSpeed;
	float mfBounceDamping;
	float mfBounceFinalStopTime;
	bool mbHitOnBounce;
	TkID<128> mPlayerDamage;
	float mfCriticalHitModifier;
	float mfPiercingDamagePercentage;
	bool mbUseCustomBulletData;
	cGcProjectileLineData mCustomBulletData;
	bool mbUseDamageNumberData;
	float mfDamageImpactMergeTime;
	float mfDamageImpactTimeBetweenNumbers;
	float mfDamageImpactMinDistance;
	cTkColour mColour;
	bool mbOverrideLightColour;
	cTkColour mLightColour;
	exBehaviourFlags mexBehaviourFlags;
	eClass meClass;
	TkID<128> mDefaultImpact;
	TkID<128> mCriticalImpact;
	cTkDynamicArray<cGcProjectileImpactData> maImpacts;
	cTkVector3 mImpactOffset;
	cTkDynamicArray<cGcImpactCombatEffectData> maCombatEffectsOnImpact;
};

struct cGcProjectile
{
	cGcProjectileData* mpData;
	TkHandle mNode;
	TkAudioObject mAudioObject;
	float mfRemainingLife;
	float mfEffectiveLife;
	cTkVector3 mDir;
	cTkPhysRelVec3 mPos;
	cTkPhysRelVec3 mStartPos;
	cTkVector3 mVelocity;
	cTkVector3 mColour;
	cGcOwnerConcept* mpOwnerConcept;
	cTkAttachmentPtr mOwnerAttachment;
	cTkRigidBodyPtr mpTarget;
	int miIgnoreCollision;
	int miBounceCount;
	int miTotalBounces;
	int miDamage;
	eDamageType meDamageType;
	bool mbTracking;
	float mfSpeed;
	float mfExplosionRadius;
	float mfScale;
	bool mbHoming;
	bool mbHomingLaser;
	bool mbCrit;
	std::vector<cGcImpactCombatEffectData, TkSTLAllocatorShim<cGcImpactCombatEffectData> > maCombatEffects;
	std::vector<cGcCombatEffectDamageMultiplier, TkSTLAllocatorShim<cGcCombatEffectDamageMultiplier> > maCombatEffectsDmgMultipliers;
	float mfLeechValue;
	TkHandle mBeamLine;
};

struct __declspec(align(16)) cGcProjectileManager
{
	struct MiningTracker
	{
		int miMinedCount;
		float mfLastMinedTime;
	};

	cGcRpcCallBase* SHOH;
	cGcRpcCallBase* ROSH;
	cGcRpcCallBase* BLOB;
	cGcRpcCallBase* SSNH;
	cGcProjectileDataTable* mpDataTable;
	cGcEffectList<cGcProjectile, 4096> mProjectiles;
	bool mbContructed;
	bool mbPrepared;
	cTkSmartResHandle mDefaultBlobRes;
	cGcProjectileManager::MiningTracker maiMiningCount[3];
	std::array<TkAudioObject, 32> mProjectileAudioObjectArray;
	unsigned int mProjectileAudioIndex;
	std::unordered_map<TkID<128>, cGcProjectileData*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcProjectileData*>> > mProjectileIDMap;
	std::unordered_map<TkID<128>, cGcLaserBeamData*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcLaserBeamData*>> > mLaserIDMap;
	std::vector<cTkSmartResHandle, TkSTLAllocatorShim<cTkSmartResHandle> > mLoadedResources;
	cGcProjectileImpact mLastPlayerImpact;
	std::vector<cGcProjectileManager::cGcResourceBlob, TkSTLAllocatorShim<cGcProjectileManager::cGcResourceBlob> > maResourceBlobs;
	cTkVector3 mLastEditPos;
	float mfLastEditRadius;
};

enum eCombatEffectType : __int32
{
	ECombatEffectType_None = 0x0,
	ECombatEffectType_Fire = 0x1,
	ECombatEffectType_Stun = 0x2,
	ECombatEffectType_Slow = 0x3,
	ECombatEffectType_NumTypes = 0x4,
};

struct cGcOwnerConcept : cTkMetaMessageSink<cTkAttachmentPtr> {};

const struct __declspec(align(16)) cGcProjectileImpact
{
	cTkMatrix34 mMatrix;
	cTkVector3 mDirection;
	cTkRigidBodyPtr mpImpactBody;
	int miImpactMaterial;
	cGcOwnerConcept* mpOwnerConcept;
	cTkAttachmentPtr mOwnerAttachment;
	float mfTime;
	int miDamage;
	eDamageType meDamageType;
	eCombatEffectType meCombatEffectType;
	float mfExplosionRadius;
	float mfLeechValue;
	TkID<128> mProjectileID;
	TkID<128> mPlayerDamage;
	cGcProjectileImpact::InstantKill meInstantKill;
	bool mbCrit;
	bool mbLaserBoost;
	bool mbIsPiercingImpact;
	bool mbRemoteMessage;
	std::vector<cGcImpactCombatEffectData, TkSTLAllocatorShim<cGcImpactCombatEffectData> > maCombatEffects;
	std::vector<cGcCombatEffectDamageMultiplier, TkSTLAllocatorShim<cGcCombatEffectDamageMultiplier> > maDamageMultipliers;
};

struct cGcProjectileLineData
{
	float mfBulletLength;
	float mfBulletGlowWidthTime;
	float mfBulletGlowWidthMax;
	float mfBulletGlowWidthMin;
	cTkCurveType mBulletGlowWidthCurve;
	float mfBulletScaler;
	float mfBulletScalerMinDist;
	float mfBulletScalerMaxDist;
	float mfBulletMinScaleDistance;
	float mfBulletMaxScaleDistance;
};

struct cGcDamageType
{
	eDamageType meDamageType;
};
#pragma once
#include "cTkTypes.h"
#include "cGcFullscreenEffectManager.h"
#include "Projectle.h"

struct cGcPlayerAimTarget
{
	cTkPhysRelVec3 mPoint;
	cTkVector3 mNormal;
	int miMaterial;
	cTkRigidBodyPtr mpBody;
	cTkAttachmentPtr mpAttachment;
};

struct __declspec(align(16)) cGcPlayerAim
{
	cGcPlayer* mpPlayer;
	cGcPlayerAimTarget mLookTarget;
	cGcPlayerAimTarget mShootTarget;
	cTkAttachmentPtr mpAutoAimTarget;
	cTkPhysRelVec3 mAutoAimIntercept;
	cTkVector3 mAutoAimPos;
	float mfAutoAimWeight;
};

struct cGcWeapon
{
	cGcWeapon_vtbl* __vftable /*VFT*/;
};

enum eRemoteWeaponType : __int32
{
	ERemoteWeaponType_Laser = 0x0,
	ERemoteWeaponType_VehicleLaser = 0x1,
	ERemoteWeaponType_AIMechLaser = 0x2,
	ERemoteWeaponType_ShipLaser = 0x3,
	ERemoteWeaponType_ShipLaser2 = 0x4,
	ERemoteWeaponType_RailLaser = 0x5,
	ERemoteWeaponType_NumLasers = 0x6,
	ERemoteWeaponType_BoltCaster = 0x7,
	ERemoteWeaponType_Shotgun = 0x8,
	ERemoteWeaponType_Cannon = 0x9,
	ERemoteWeaponType_Burst = 0xA,
	ERemoteWeaponType_MineGrenade = 0xB,
	ERemoteWeaponType_BounceGrenade = 0xC,
	ERemoteWeaponType_StunGrenade = 0xD,
	ERemoteWeaponType_VehicleCanon = 0xE,
	ERemoteWeaponType_AIMechCanon = 0xF,
	ERemoteWeaponType_ShipPhoton = 0x10,
	ERemoteWeaponType_ShipShotgun = 0x11,
	ERemoteWeaponType_ShipMinigun = 0x12,
	ERemoteWeaponType_ShipPlasma = 0x13,
	ERemoteWeaponType_ShipRocket = 0x14,
	ERemoteWeaponType_None = 0x15,
	ERemoteWeaponType_NumTypes = 0x16,
};

struct __declspec(align(8)) cGcMuzzleFlash
{
	cTkSmartResHandle mResource;
	TkHandle mNode;
	cTkAttachmentPtr mpAttachment;
	TkID<128> mActiveParticlesEffect;
	EffectInstance mParticlesEffectHandle;
	eRemoteWeaponType meRemoteWeaponType;
};
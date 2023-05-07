#pragma once
#include "pch.h"
#include "cTkTypes.h"

struct __declspec(align(8)) cGcFiendManagerBase
{
	cGcFiendManagerBase_vtbl* __vftable /*VFT*/;
	std::vector<cGcFiendSpawnRequest, TkSTLAllocatorShim<cGcFiendSpawnRequest> > maSpawnRequests;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > mapAttachments;
	std::vector<cGcVirtualisedCreature, TkSTLAllocatorShim<cGcVirtualisedCreature> > maVirtualisedCreatures;
	bool mbWantsToClear;
};

struct cGcFiendManagerStandard
{
	enum eManagerLocation : __int32
	{
		EManagerLocation_Planet = 0x0,
		EManagerLocation_Mission = 0x1,
		EManagerLocation_Freighter = 0x2,
		EManagerLocation_Space = 0x3,
	};
};

struct __declspec(align(16)) cGcFiendManagerStandard : cGcFiendManagerBase
{
	float mfSpawnTimer;
	float mfSpawnTimeRemaining;
	float mfActiveTimeRemaining;
	unsigned int miMaxFiendstoSpawn;
	unsigned int miOverrideFiendHealth;
	TkID<128> mOverrideFiendDamage;
	float mfSpawnDistanceMultiplier;
	float mfSpeedMultiplier;
	float mfOverrideFiendScale;
	float mfAggroLevel;
	bool mbCanSpawn;
	cTkVector3 mvLastCrimePosition;
	cGcFiendManagerStandard::eManagerLocation meLocation;
};

struct cGcFiendManagerUnderwater : cGcFiendManagerBase {};
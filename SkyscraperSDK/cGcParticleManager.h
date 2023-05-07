#pragma once
#include "cTkTypes.h"
#include "UnorderedMapHashes.h"
#include "Explosion.h"

enum eHeavyAirType : __int32
{
	EHeavyAir_None = 0x0,
	EHeavyAir_Planet = 0x1,
	EHeavyAir_Cave = 0x2,
	EHeavyAir_Underwater = 0x3,
	EHeavyAir_Space = 0x4,
	EHeavyAir_AbandonedFreighter = 0x5,
	EHeavyAir_SpaceStorm = 0x6,
};

struct __declspec(align(16)) cGcParticleManager
{
	struct __declspec(align(16)) cGcHeavyAir
	{
		cTkSmartResHandle mResource;
		TkHandle mRootNode;
		eHeavyAirType meType;
		cTkColour lColour1;
		cTkColour lColour2;
		std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > mChildNodes;
	};

	std::vector<cGcExplosionDataTable*, TkSTLAllocatorShim<cGcExplosionDataTable*> > mapEffectDataTables;
	std::unordered_map<TkID<128>, cGcExplosionData*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcExplosionData*>> > maEffectLookup;
	std::unordered_map<TkID<128>, cGcAreaDamageData*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcAreaDamageData*>> > maAreaDamageLookup;
	cTkSmartResHandle mSpeedLineRes;
	cTkSmartResHandle mLinesRes;
	TkHandle mParticleGroupNode;
	TkHandle mSpeedLinesNode;
	TkHandle mLinesNode;
	cGcEffectList<cGcExplosion, 512> mEffects;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maEffectsToDestroyOnCompletion;
	cGcParticleManager::cGcHeavyAir mActiveHeavyAir;
	TkID<128> mRequestDebugViewEffect;
	TkID<128> mRequestDebugEditEffect;
	bool mbParticleDebugRender;
	bool mbHeavyAirChangeRequested;
	float mfHeavyAirFade;
	eHeavyAirType meRequestedHeavyAirType;
	cTkSeed mSeed;
	std::vector<cGcParticleManager::EffectHistory, TkSTLAllocatorShim<cGcParticleManager::EffectHistory> > maEffectHistory;
};
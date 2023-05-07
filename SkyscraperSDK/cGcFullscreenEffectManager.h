#pragma once
#include "cTkTypes.h"
#include "Planet.h"
#include "Explosion.h"

struct cGcFullscreenEffectManager
{
	cTkSmartResHandle mDebugMaterial;
	cTkSmartResHandle mPostProcessMaterial;
	cTkSmartResHandle mLensFlareMaterial;
	cTkSmartResHandle mDepthOfFieldMaterial;
	cTkSmartResHandle mUIMaterial;
	int mDepthOfFieldNewBokehStage;
	int mDepthOfFieldBokehStage;
	int mDepthOfFieldBlurStage;
	int mCloudsStage;
	int maSSR_Stages[6];
	cTkSmartResHandle maLUTTextureResHandle[82];
	eScreenFilter maeActiveFilters[4];
	float mafFilterStrengths[4];
	float mafFilterDistances[4];
	float mafHdrAdjusts[4];
	cGcScreenFilterTable* mpFilterTable;
};

struct EffectInstance
{
	TkHandle mNodeHandle;
	cGcExplosion* mpExplosion;
	const cGcExplosionData* mpExplosionData;
};

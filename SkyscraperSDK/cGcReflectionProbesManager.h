#pragma once
#include "cTkTypes.h"

struct cGcReflectionProbesManager
{
	byte mePhase[1];
	int maProbeSamplersIndices[8];
	int miProbeIndex;
	int miProbeRenderIndex;
	int miTileIndex;
	TkHandle mParentNode;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maProbeNodesAll;
	TkHandle maProbeNodes[8];
	cTkSmartResHandle maProbeCubemapRes[8];
	cTkSmartResHandle mProbeCubemapFlat;
	cTkSmartResHandle mProbeCubemapTile;
	cTkSmartResHandle mProbeSceneRes;
	cTkSmartResHandle mProbeMaterialRes;
	cTkSmartResHandle mSSRShaderRes;
	cTkSmartResHandle mSSRMaterialRes;
	cTkSmartResHandle mPostProcessShaderRes;
	cTkSmartResHandle mProbePipelineTileRes;
	cTkSmartResHandle mProbePipelineBlurRes;
	cTkSmartResHandle mProbePipelineCubeRes;
};
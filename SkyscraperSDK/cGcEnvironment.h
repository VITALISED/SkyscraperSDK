#pragma once
#include "Planet.h"
#include "cTkTypes.h"
#include "cGcAsyncLoadOps.h"
#include "cGcReflectionProbesManager.h"
#include "Raycast.h"
#include "cGcSky.h"

struct cGcEnvironment
{
	enum eShadowState : __int32
	{
		EShadowState_Space = 0x0,
		EShadowState_Ship = 0x1,
		EShadowState_Surface = 0x2,
	};

	TkIterationState<1> mTextureCreationIterationState;
	cTkSmartResHandle mWaterReflectionTextureRes;
	cTkSmartResHandle mWaterReflectionPipelineRes;
	cTkSmartResHandle mDualPMapPipelineRes;
	cTkSmartResHandle mMainPipeline;
	cTkSmartResHandle mCausticDisplacementTex;
	cTkSmartResHandle mCausticMapTex;
	cTkSmartResHandle mUberShader;
	cTkSmartResHandle mLightShader;
	cTkSmartResHandle mWaterShader;
	cTkSmartResHandle mSkyShader;
	cTkSmartResHandle mTerrainShader;
	cTkSmartResHandle mIBLShader;
	cTkSmartResHandle mParticleShader;
	cTkSmartResHandle mPStreamShader;
	cTkSmartResHandle mShaderMillParticleShader;
	cTkSmartResHandle mShaderMillUberShader;
	cTkSmartResHandle mUIScreenShader;
	cTkSmartResHandle mDualPMapResFront;
	cTkSmartResHandle mDualPMapResBack;
	cTkSmartResHandle mIBLMapResFront;
	cTkSmartResHandle mIBLMapResBack;
	cTkSmartResHandle mIBLMapIndoorResFront;
	cTkSmartResHandle mIBLMapIndoorResBack;
	cTkSmartResHandle mTerrainColourRes;
	cTkSmartResHandle mIBLPipelineRes;
	cTkSmartResHandle mDepthOfFieldMat;
	cTkSmartResHandle mIBLMaterial;
	bool mbIsUsingDynamicDualPmap;
	cGcSky mSky;
	bool mbCloudsEnabled;
	int miCloudsIndex;
	int miCloudsBlurIndex;
	int miCloudsCopyIndex;
	int miParticleIndex;
	int miReflectionWaterFromAboveIndex;
	int miReflectionWaterFromBelowIndex;
	int miMainWaterFromAboveIndex;
	int miMainWaterFromBelowIndex;
	int miDepthReprojectWFAIndex;
	int miDepthReprojectIndex;
	int miVolumetricsIndex;
	int miNumDualPMips;
	float mfShadowLength;
	cTkVector4 mShadowSplit;
	float mfShadowLengthTarget;
	float mfShadowSplit1Target;
	float mfShadowSplit2Target;
	cGcEnvironment::eShadowState meShadowState;
	cGcPlayerEnvironment mPlayerEnvironment;
	cGcPlayerEnvironment mPlayerEnvironmentPreviousFrame;
	cTkRaycastJob mGeometryProbeJob;
	float mfMinPixelCullForShadows;
	cTkVector3 mLightingOriginPosition;
	cGcReflectionProbesManager mReflectionProbesManager;
	cTkFixedString<32, char> mEnvSnapshotPrefix;
	bool mbDoEnvSnapshot;
	bool mbMakeItRain;
	float mfStepSize;
	float mfMaxSteps;
	float mfThickness;
	bool mbEnableScreenSpaceShadow;
	cGcTempPortalRenderData mPortalRenderData;
};

struct cGcPlayerEnvironment
{
	struct SpaceState
	{
		float mfNearestPolice;
		float mfNearestPirate;
		float mfNearestFreighter;
		bool mbPoliceActive;
		bool mbPiratesActive;
		bool mbFreightersActive;
		bool mbFreightersBeingAttacked;
	};

	cTkMatrix34 mPlayerTM;
	cTkVector3 mUp;
	unsigned __int64 mu64UA;
	int miNearestPlanetIndex;
	float mfDistanceFromPlanet;
	float mfNearestPlanetSealevel;
	cTkVector3 mNearestPlanetPos;
	int miNearestPlanetCreatureRoles;
	eGalaxyStarAnomaly meStarAnomaly;
	float mfDistanceFromAnomaly;
	bool mbInsidePlanetAtmosphere;
	eBiome meBiome;
	eBiomeSubType meBiomeSubType;
	bool mbIsRaining;
	float mfStormLevel;
	eWeather meWeather;
	float mfTimeOfDay;
	float mfLightFactor;
	float mfNightFactor;
	bool mbIsNight;
	float mfLightShaftFactor;
	EnvironmentLocation::Enum meLocation;
	float mfTimeInLocation;
	bool mbUndergroundIsCave;
	EnvironmentLocation::Enum meCameraLocation;
	float mfTimeInCameraLocation;
	EnvironmentLocation::Enum meCameraLocationStable;
	TkHandle mInsideBuildingNode;
	eRegionKnowledgeInterest meInterest;
	float mfTimeInInterest;
	EnvironmentLocation::Enum meLocationStable;
	eRegionKnowledgeInterest meInterestStable;
	bool mbInAsteroidFieldStable;
	EnvironmentLocation::Enum meVehicleLocation;
	eBuildingClass meNearestBuildingClass;
	float mfNearestBuildingDistance;
	bool mbNearestBuildingValid;
	eBasePartAudioLocation meBasePartAudioLocation;
	bool mbPilotingShip;
	bool mbPilotingVehicle;
	bool mbFullControlOfShip;
	bool mbIsWarping;
	bool mbIsWanted;
	bool mbSpaceCombatActive;
	float mfSpaceCombatActiveTime;
	bool mbIsInPlayerFreighter;
	bool mbIsInFreighterBase;
	bool mbForceFreighterShipHidingUpdate;
	cTkUserIdBase<cTkFixedString<64, char> > mOccupiedFreighterOwner;
	bool mbBlockedFromCraftingBySeasonalBaseRequirements;
	bool mPlanetRegionQueryValid;
	cTkRegionHeightResult mPlanetRegionQuery;
	float mPlanetRegionQueryDistance;
	float mfUnderwaterDepth;
	float mfExteriorExposure;
	float mfTemperature;
	float mfTemperatureSmoothed;
	float mfTemperatureExternal;
	float mfToxicity;
	float mfToxicitySmoothed;
	float mfToxicityExternal;
	float mfRadiation;
	float mfRadiationSmoothed;
	float mfRadiationExternal;
	float mfLifeSupportDrain;
	float mafHazardFactors[6];
	float mafTargetHazardFactors[6];
	float mafNormalisedHazardFactors[6];
	eHazardValue mePrimaryHazardControl;
	float maObscuredAroundNear[2];
	float maObscuredAroundNearSlow[2];
	float maObscuredAroundFar[2];
	float maObscuredAroundFarSlow[2];
	float maObscuredOverhead[2];
	float maObscuredTowardsSun[2];
	float mfGlassSurfacesNearby;
	float mfNearestSurface;
	float mfNearestSurfaceOverhead;
	eCollisionGroup meCollisionGroupOverhead;
	eCollisionGroup meCollisionGroupDirectUnder;
	float mfDistanceDirectUnder;
	eCollisionGroup meCollisionGroupDirectUnderNA;
	float mfDistanceDirectUnderNA;
	float maGroundCoverage[2];
	float mfIndoorLightingFactor;
	float mfIndoorLightingFactorRate;
	float mfIndoorLightTransitionFactor;
	bool mbFlyingTowardsPlanet;
	int miFlyingTowardsPlanetIndex;
	bool mbSpaceStateValid;
	cGcPlayerEnvironment::SpaceState mSpaceState;
	cTkStackVector<cGcPlayerEnvironment::ActiveTriggerVolume> mCurrentlyActiveTriggers;
	bool mbInteriorTriggerTypeActive;
	bool mbCoveredExteriorTriggerTypeActive;
	bool mbInsideHazardProtectionVolume;
	bool mbInsideHazardProtectionColdVolume;
	bool mbInsideSpaceStorm;
	float mfTemperatureSpringRate;
	float mfToxicitySpringRate;
	float mfRadiationSpringRate;
	float maObscuredAroundNearRate[2];
	float maObscuredAroundNearRateSlow[2];
	float maObscuredAroundFarRate[2];
	float maObscuredAroundFarRateSlow[2];
	float maObscuredOverheadRate[2];
	float maObscuredTowardsSunRate[2];
	float maGroundCoverageRate[2];
	float mfNearestSurfaceRate;
	float mfNearestSurfaceOverheadRate;
	float mfGlassSurfacesNearbyRate;
	bool mbInAsteroidField;
	float mfAsteroidFieldStateTime;
};

struct cGcTempPortalRenderData
{
	cTkSmartResHandle mPipeline;
	cTkSmartResHandle maRenderTextures[2];
};

struct cGcEnvironmentSpawnData
{
	cTkDynamicArray<cGcCreatureSpawnData> maCreatures;
	cTkDynamicArray<cGcObjectSpawnData> maDistantObjects;
	cTkDynamicArray<cGcObjectSpawnData> maLandmarks;
	cTkDynamicArray<cGcObjectSpawnData> maObjects;
	cTkDynamicArray<cGcObjectSpawnData> maDetailObjects;
	cTkDynamicArray<cGcSelectableObjectSpawnList> maSelectableObjects;
};
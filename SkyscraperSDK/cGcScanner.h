#pragma once
#include "cTkTypes.h"
#include "cGcPlayer.h"
#include "Marker.h"
#include "cGcBinoculars.h"
// FIXME
// scanner structs are all over the place

struct __declspec(align(16)) cGcSimpleScanEffect
{
	typedef cGcPlayerEmoteProp::eState eState;

	cGcScanEffectData* mpSourceData;
	cGcScanEffectData mData;
	cTkSmoothCD<float> mScanPower;
	TkHandle mScanNode;
	cTkColour mColour;
	bool mbColourOverride;
	cGcSimpleScanEffect::eState meState;
};

template <int pool_shit>
struct cGcSimpleScanEffectPool/*<3>*/
{
	struct Data
	{
		cGcSimpleScanEffect mEffect;
		cGcScanEffectData mData;
	};

	cTkClassPool<cGcSimpleScanEffectPool<pool_shit>::Data, pool_shit> maPool;
};

struct cGcScanner
{
	struct SortableScanData
	{
		float mfSortValue;
		TkHandle mNodeHandle;
		float mfDotToNode;
		float mfDistance;
	};

	struct ScannerRoutineInfo
	{
		std::vector<cTkPhysRelVec3, TkSTLAllocatorShim<cTkPhysRelVec3> > maRoutineCreaturePositions;
		std::vector<float, TkSTLAllocatorShim<float> > maRoutineCreatureTimes;
	};

	TkAudioObject mScannerAudioObject;
	cTkSmartResHandle mResLineMaterial;
	cTkSmartResHandle mResLightMaterial;
	float mfScannerCharge;
	unsigned int miScannerUIDCounter;
	float mfScanStartTime;
	cTkVector3 mScanCentre;
	float mfScanProgression;
	float mfScanLiveBlendValue;
	float mfScanTime;
	float mfScanDisplayedTime;
	bool mbPlayedScanAudio;
	cTkMatrix34 mScanBase;
	cTkAABB mScanAABB;
	bool mbScanLive;
	const cGcScanData* mpData;
	bool mbSubstanceScanLive;
	bool mbSubstanceScanDisplay;
	float mfSubstanceScanTime;
	float mfSubstanceDisplayValue;
	int miHoveredBuilding;
	float mfHoveredBuildingTime;
	std::vector<cGcBuilding*, TkSTLAllocatorShim<cGcBuilding*> > mHoveredObjects;
	std::vector<cGcBuilding*, TkSTLAllocatorShim<cGcBuilding*> > mScannedBuildings;
	__declspec(align(16)) cGcMarkerPoint mCurrentObjectHighlight;
	std::array<cGcScanner::SortableScanData, 180> mTemporarySortableScanDataArray;
	cGcScannedNodesList mScannedNodesList;
	std::vector<cGcScanner::TerrainResourcePosition, TkSTLAllocatorShim<cGcScanner::TerrainResourcePosition> > mScannableTerrainResources;
	cTkStackVector<cGcScanner::FuelAsteroidInfo> mScannableFuelAsteroids;
	float mfRangeMultiplier;
	bool mbIsZooming;
	cGcMarkerList* mpMarkerList;
	cGcScanner::ScannerRoutineInfo mScannerRoutineInfo;
	std::vector<cGcScanner::ScannerCreatureInfo, TkSTLAllocatorShim<cGcScanner::ScannerCreatureInfo> > maCreatureInfo;
	__declspec(align(16)) cGcBinoculars mBinoculars;
	cGcSimpleScanEffect mBinocularScan;
	unsigned __int64 mCurrentPlanetUA;
};

struct __declspec(align(8)) ScanInfo
{
	TkHandle mModelNode;
	cTkAttachmentPtr mpAttachment;
	cTkRigidBodyPtr mpBody;
	bool mbUnknown;
	bool mbAlwaysKnown;
};

struct __declspec(align(16)) cGcScanManager
{
	cGcScanner mScanner;
	cGcMarkerList mMarkerList;
	cGcScanEventManager* mpScanEventManager;
	std::vector<cGcMarkerPoint, TkSTLAllocatorShim<cGcMarkerPoint, 16, -1> > maFilteredMarkers;
	std::vector<enum cGcMarkerPoint::eType, TkSTLAllocatorShim<enum cGcMarkerPoint::eType, 4, -1> > maMarkedPrimaryMarkerTypes;
	cGcCameraAerialViewData* mpRequestArielCamData;
	bool mbRequestArielHasPosition;
	cTkVector3 mRequestArielPosition;
	bool mbSuppressMarkers;
};

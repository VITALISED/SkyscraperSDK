#pragma once
#include "cTkTypes.h"
#include "cGcNGui.h"
#include "Discovery.h"
#include "Raycast.h"
#include "cGcScanner.h"
#include "cGcRegionHotspots.h"

struct __declspec(align(4)) cGcBinoculars
{
	enum eTargetScan : __int32
	{
		ETargetScan_None = 0x0,
		ETargetScan_Scanning = 0x1,
		ETargetScan_Displayed = 0x2,
	};

	enum eMode : __int32
	{
		EMode_ScanMode = 0x0,
		EMode_MissionSurvey = 0x1,
		EMode_PowerHotspots = 0x2,
		EMode_MineralHotspots = 0x3,
		EMode_GasHotspots = 0x4,
		EMode_NumModes = 0x5,
	};

	struct sMissionSurvey
	{
		TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mIcon;
		cTkAttachmentPtr mpClosestScannable;
		cTkAttachmentPtr mpScannableTarget;
		unsigned __int64 mLastUpdateTime;
		float mfCurrentDistance;
		bool mbLookingForScannable;
		bool mbHasCloseUnsurveyedScanEvent;
		bool mbClosestEventIsOffWorld;
		TkID<128> mCurrentMissionID;
	};

	struct ScopeNodes
	{
		TkHandle mMainNode;
		TkHandle mScopeNode;
	};

	cTkSmartResHandle mScannerScopeRes;
	cTkSmartResHandle mScannerScopeSurveyRes;
	TkHandle mScanNodeGroup;
	cGcBinoculars::ScopeNodes mScannerScopeNodes;
	cGcBinoculars::ScopeNodes mSurveyScopeNodes;
	float mfCrosshairDistanceSmoothed;
	bool mbPlayerOnPlanet;
	float mfScanProgress;
	float mfStatusDotsProgress;
	float mfSonarProgress;
	float mfGrowTime;
	std::vector<cGcNGuiText*, TkSTLAllocatorShim<cGcNGuiText*> > mapGrowTexts;
	DiscoveryResolver::DiscoveryInfo mCurrentDiscoveryInfo;
	bool mbCurrentDiscoveryUnknown;
	cTkUserIdBase<cTkFixedString<64, char> > mMPMissionPlayerWhoScanned;
	float mfDampenedDistanceValue;
	float mfDiscoveryWindowActiveTime;
	float mfDiscoveryWindowDeactivateTime;
	cGcBinoculars::eTargetScan meTargetMode;
	unsigned __int64 mCurrentPlanet;
	cTkRaycastJob mRaycastJob;
	cGcSimpleScanEffectPool<3> mHighlightEffects;
	cTkClassPoolHandle mInfoPanelScreen;
	ScanInfo mMarkerInfo;
	ScanInfo mTargetInfo;
	bool mbTargetingWasHeld;
	cTkVector2 mTargetScreenPos;
	cTkSmoothCD<float> mfTargetScreenHeight;
	float mfTargetStartTime;
	cTkPhysRelVec3 mTargetSmoothedCentre;
	cTkVector3 mTargetSmoothedCentreVel;
	bool mbTargetDiscovered;
	cTkMatrix34 mSmoothScopeMatrix;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maFadingMarkers;
	TkHandle mMarkerModel;
	cGcBinoculars::eMode meMode;
	float mfBinocsLastUsedTime;
	float mfAtmosphereEntryErrorTimer;
	TkAudioObject mAudioObject;
	cGcBinoculars::sMissionSurvey mMissionSurvey;
	cGcNGui* mpBinocularInfoGui;
	cGcNGui* mpBinocularMarkerGui;
	cGcNGui* mpDiscoveryGui;
	cGcNGuiLayer* mpCentreLayer;
	cGcNGuiLayer* mpModesLayer;
	cGcNGuiLayer* mpModesSmallLayer;
	cGcRegionHotspots::eHotspotCategory meCurrentHotspotCategory;
	bool mbCurrentHotspotDiscovered;
};
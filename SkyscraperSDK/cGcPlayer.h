#pragma once
#include "IStatWatcher.h"
#include "Inventory.h"
#include "Procedural.h"
#include "Vehicle.h"
#include "UniverseAddressData.h"
#include "Multitool.h"
#include "Base.h"
#include "PhotoMode.h"
#include "cGcSeason.h"
#include "Story.h"
#include "Settlement.h"
#include "Sentinel.h"
#include "cGcPlayerCommunicator.h"
#include "cGcPersonalTeleporter.h"
#include "cGcPlayerStick.h"
#include "cGcGrabbableComponent.h"
#include "Emote.h"

enum eCharacterPhysicsDisabledReasons : __int32
{
	ECharacterPhysicsDisabledReason_None = 0x0,
	ECharacterPhysicsDisabledReason_MovementDisabled = 0x1,
	ECharacterPhysicsDisabledReason_Sitting = 0x2,
	ECharacterPhysicsDisabledReason_Riding = 0x4,
	ECharacterPhysicsDisabledReason_ClimbingLadder = 0x8,
	ECharacterPhysicsDisabledReason_NavFallback = 0x10,
	ECharacterPhysicsDisabledReason_Replicated = 0x20,
	ECharacterPhysicsDisabledReason_Any = 0x3F,
};

enum eHand
{
	EHand_Right = 0x0,
	EHand_Left = 0x1,
	EHand_NumTypes = 0x2,
	EHand_Unspecified = 0xFFFFFFFF,
};

enum eScanEffectType : __int32
{
	EScanEffectType_Building = 0x0,
	EScanEffectType_TargetShip = 0x1,
	EScanEffectType_Creature = 0x2,
	EScanEffectType_Ground = 0x3,
	EScanEffectType_Objects = 0x4,
	EScanEffectType_NumTypes = 0x5,
};

struct cGcScanEffectData
{
	TkID<128> mId;
	eScanEffectType meScanEffectType;
	cTkColour mColour;
	float mfBasecolourIntensity;
	float mfScanlinesSeparation;
	float mfFresnelIntensity;
	float mfGlowIntensity;
	float mfWaveOffset;
	bool mbWaveActive;
	bool mbFixedUpAxis;
	bool mbTransparent;
	bool mbModelFade;
	float mfFadeInTime;
	float mfFadeOutTime;
};


enum ePlayerFinalisePurchaseState : __int32
{
	EPlayerFinalisePurchaseState_None = 0x0,
	EPlayerFinalisePurchaseState_SpawnNewShip = 0x1,
};

enum eLastKnownPlayerState : __int32
{
	ELastKnownPlayerState_OnFoot = 0x0,
	ELastKnownPlayerState_InShip = 0x1,
	ELastKnownPlayerState_InStation = 0x2,
	ELastKnownPlayerState_AboardFleet = 0x3,
	ELastKnownPlayerState_InNexus = 0x4,
	ELastKnownPlayerState_AbandonedFreighter = 0x5,
	ELastKnownPlayerState_InShipLanded = 0x6,
	ELastKnownPlayerState_NumTypes = 0x7,
};

struct cGcPlayerRespawn
{
	enum RespawnReason : __int32
	{
		FreshStart = 0x0,
		LoadSave = 0x1,
		LoadToLocation = 0x2,
		RestorePreviousSave = 0x3,
		DeathInSpace = 0x4,
		DeathOnPlanet = 0x5,
		DeathInOrbit = 0x6,
		DeathOnAbandonedFreighter = 0x7,
		WarpInShip = 0x8,
		Teleport = 0x9,
		Portal = 0xA,
		UpgradeSaveAfterPatch = 0xB,
		SwitchAmbientPlanet = 0xC,
		BaseViewerMode = 0xD,
		WarpInFreighter = 0xE,
		JoinMultiplayer = 0xF,
	};
};

struct cGcPlayerSpawnStateData
{
	cTkVector4 mPlayerPositionInSystem;
	cTkVector4 mPlayerTransformAt;
	cTkVector4 mPlayerDeathRespawnPositionInSystem;
	cTkVector4 mPlayerDeathRespawnTransformAt;
	cTkVector4 mShipPositionInSystem;
	cTkVector4 mShipTransformAt;
	eLastKnownPlayerState meLastKnownPlayerState;
	cTkVector4 mFreighterPositionInSystem;
	cTkVector4 mFreighterTransformAt;
	cTkVector4 mFreighterTransformUp;
	cTkVector4 mAbandonedFreighterPositionInSystem;
	cTkVector4 mAbandonedFreighterTransformAt;
	cTkVector4 mAbandonedFreighterTransformUp;
};

struct cGcPlayer : cGcPlayerCommon
{
	typedef cGcPlayerEmoteProp::eState eRocketBootsState;

	enum eStaminaState : __int32
	{
		EStamina_Available = 0x0,
		EStamina_Recovering = 0x1,
	};

	enum eRocketBootsDoubleTapState : __int32
	{
		None = 0x0,
		WaitingForRelease = 0x1,
		WaitingForSecondTap = 0x2,
		SingleTap = 0x3,
		DoubleTap = 0x4,
	};

	struct __declspec(align(8)) FootstepOnDistanceTravel
	{
		cTkPhysRelVec3 mLastUsedPosition;
		float mfTriggerDistance;
		float mfTriggerDistanceSqr;
		bool mbValidDistance;
		bool mbValidPosition;
	};

	enum eCharacterMode : __int32
	{
		ECharacterMode_FirstPerson = 0x0,
		ECharacterMode_ThirdPerson = 0x1,
	};

	struct cGcSummonPetData
	{
		int miIndex;
		float mfAdultScale;
		float mfGrowthProgress;
		cTkMatrix34 mSpawnMat;
		eCreatureType meCreatureType;
		cTkSeed mBoneScaleSeed;
		bool mbHasFur;
		cTkSmartResHandle mPetResource;
	};

	cTkRigidBody* lpGrabbedBody;
	cGcPlayerThirdPerson* mpThirdPerson;
	cGcCameraBehaviourFirstPerson* mpCamera;
	cGcPlayerController* mpController;
	cTkHavokCharacterController* mpPhysicsController;
	cTkAttachmentPtr mpExternalControlAttachment;
	eCharacterPhysicsDisabledReasons muGravityDisabledReasons;
	eCharacterPhysicsDisabledReasons muCollisionDisabledReasons;
	cTkAttachmentPtr mpGrabbedBy;
	float mfLastGrabbedTime;
	float mfGrabEscapeTimer;
	cGcPlayerEffectsComponent* mpEffectsComponent;
	cGcPlayerFullBodyIKComponent* mpIkComponent;
	cTkPhysRelMat34 mGraphicsMatrix;
	cTkVector3 mPosition;
	std::vector<cGcPlayerImpact, TkSTLAllocatorShim<cGcPlayerImpact> > maProjectileImpacts;
	TkHandle mEquipmentNode;
	cTkSmartResHandle mPlayerResource;
	std::unordered_map<TkID<128>, cTkSmartResHandle, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cTkSmartResHandle>, 8, -1> > mCreatureFoodResources;
	float mfThrowFoodCooldown;
	TkAudioObject mAudioObject;
	cGcPlayerWeapon mWeapon;
	float mfRecoilSpeed;
	float mfRecoilAmount;
	float mfDamagePerSecondRate;
	cGcWarpJumpTarget mPlayerWarpJumpTarget;
	cGcTeleportEndpoint mPlayerTeleportEndpoint;
	cGcPlayer::WarpTargetMode meWarpTargetMode;
	cTkBitArray<unsigned int, 1> mxMapRequests;
	cTkBitArray<unsigned int, 1> mPostWarpRequests;
	cTkPhysRelMat34 mHandMatrix[2];
	cTkPhysRelMat34 mPreviousHandMatrix[2];
	cTkMatrix34 mLastHandMatrixOffset[2];
	cTkPhysRelMat34 mSmoothHandMatrix[2];
	cTkMatrix34 mFingerFromHandOffset[2];
	bool mbHandMatrixValid[2];
	bool mbReleaseGrabbable[2];
	cTkPhysRelVec3 mSwimHandPos[2];
	cTkVector3 mSwimAccumulator[2];
	bool mbSwimHandPosActive[2];
	bool mbHandTrackingMotionEnabled;
	__declspec(align(16)) cGcPersonalTeleporter mTeleporter;
	bool mbSpawned;
	bool mbLanded;
	bool mbRunning;
	float mfHardLandTimer;
	bool mbIsAutoWalking;
	bool mbWeaponSuppressed;
	cTkVector3 mCurrentMoveForce;
	cGcPlayerAim mAiming;
	cGcPlayerStick mStick;
	float mfLastHitTime;
	cTkAttachmentPtr mpLastHitOwner;
	TkID<128> mLastHitDamageId;
	float mfLastWoundTime;
	cTkVector3 mLastHitDir;
	cTkPhysRelVec3 mLastPosition;
	float mfLastDamageTime;
	float mfWoundDamageAccumulator;
	TkID<128> mLastDamageId;
	cTkVector3 mfPullCamToward;
	float mfCamPullStrength;
	float mfCamPullDecay;
	bool mbCamHorizontalOnly;
	float mYawPull;
	cTkVector3 mFacingDir;
	float mfLastFacingImpulse;
	float mfPitch;
	float mfCreatureRideYaw;
	bool mbTurning;
	bool mbMoving;
	eCreatureRideState meCreatureRideState;
	cTkPhysRelVec3 mSmoothedPos;
	std::array<cTkVector3, 4> mLastVelocities;
	bool mbFoot;
	float mfBobAmount;
	int miGroundMat;
	bool mbJetpackIgnite;
	bool mbJetpackStart;
	float mfJetpackTimer;
	float mfJetpackTank;
	eFreeJetpackSurface mbFreeJetpack;
	float mfJetpackUpForce;
	float mfJetpackForce;
	float mfJetpackIgnitionForce;
	float mfJetpackUpBoost;
	float mfJetpackForwardBoost;
	float mfJetpackIgnitionBoost;
	float mfJetpackFreeDuration;
	float mfJetpackBoostTimer;
	bool mbJetpackBoostOverride;
	bool mbJetpackHeld;
	float mfRequiredJetpackRefillLevel;
	float mfFreeSprintTimer;
	float mfFreeSprintDuration;
	bool mbSprintIsFree;
	float mfAirTimer;
	float mfJetpackLandedTime;
	cTkClassPoolHandle mJetpackShake;
	cTkClassPoolHandle mRocketBootsShake;
	cTkClassPoolHandle mRunShake;
	cTkClassPoolHandle mWarpTransitionShake;
	float mfActionTimer;
	bool mbActionRequiresButtonUp;
	bool mbJumpRequiresButtonUp;
	bool mbInteractBlockingAction;
	bool mbPreviouslyCouldNotFire;
	bool mbAltStarted;
	cGcPlayerHazard mHazard;
	cGcPlayerInteract mInteract;
	cGcPlayerRespawn mRespawn;
	cGcPlayerLadderClimb mLadderClimb;
	cGcCharacterSit mCharacterSit;
	cTkTimerTemplate<0> mUnderwaterTimer;
	float mfRandomUnderwaterValue;
	cGcPlayer::eStaminaState meStaminaState;
	float mfStamina;
	float mfTurnAccelerator;
	bool mbIsTransitioning;
	cTkAttachment* mpAttachment;
	cTkSmartResHandle mAnimHeadSceneRes;
	TkHandle mAnimHeadSceneNode;
	cTkAnimationComponent* mpAnimHeadAnimation;
	cTkAnimLayerHandle mHeadAnimLayer;
	cTkMatrix34 mAnimHeadBaseTrans;
	cTkMatrix34 mHeadMatrixWhenMovementStarted;
	float mfExertion;
	float mfExertionRate;
	float mfDampShoes;
	float mfHitReactFadeSpeed;
	cTkVector2 mHitReactDir;
	byte mePlayerMode[4];
	bool mbIsDying;
	bool mbModRandomiseWeapon;
	cTkFixedString<128, char> mbModResetWithSeed;
	float mfShieldChargeAccumulator;
	float mfShipShieldRechargeAccumulator;
	float mfLaunchThrustersAccumulator;
	float mfEnergyAccumulator;
	float mfEnergyPainTime;
	float mfLastScanTime;
	float mfLastShipScanTime;
	bool mbAimToggleActive;
	bool mbAimHeld;
	bool mbAimBeingHeld;
	bool mbHasFired;
	bool mbTorchActive;
	bool mbToggleTorch;
	bool mbTorchLightNeeded;
	TkHandle mTorchNode;
	cTkSmoothCD<cTkVector3> mvTorchDir;
	TkHandle mAmbientLightNode;
	cTkPhysRelVec3 mLookAtPoint;
	bool mbForceLookAt;
	float mfLookAtTimeLeft;
	float mfLookAtTime;
	float mTimeLastUsedJetpack;
	float mfTimeInMeleeBoost;
	bool mbMeleeBoostActive;
	float mfTimeOnGround;
	float mfTimeRocketBootsActive;
	float mfRocketBootsBoostStrength;
	float mfRocketBootsHeightAdjust;
	float mfRocketBootsHeightAdjustVel;
	cGcPlayer::eRocketBootsState meRocketBootsState;
	float mfRocketBootsDoubleTapTimer;
	cGcPlayer::eRocketBootsDoubleTapState meRocketBootsDoubleTapState;
	TkAudioID mCurrentSwimAudioEvent;
	TkID<128> mDebugDamageType;
	TkHandle mDeathDropNode;
	std::deque<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maFriendlyCreatures;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maPredatorsAttacking;
	float mfTimeSicePredatorAttacked;
	__declspec(align(16)) cGcPlayer::FootstepOnDistanceTravel mLadderFootsteps;
	float mfDisabledTimer;
	float mfTimeUntilBodyRealignment;
	unsigned __int8 muiCheckFallenThroughFloorCounter;
	cGcPlayerCommunicator mCommunicator;
	int meSavedFilter;
	int meRequestedFilter;
	cGcPlayer::eCharacterMode meCharacterMode;
	cGcPlayer::eCharacterMode meRequestedCharacterMode;
	std::vector<std::pair<TkID<128>, enum cGcPlayer::eCharacterMode>, TkSTLAllocatorShim<std::pair<TkID<128>, enum cGcPlayer::eCharacterMode>> > maCharacterModeOverrides;
	CharacterSlopeState mCurrentSlopeState;
	float mfTimeInCurrentSlopeState;
	cTkMatrix34 maRealignmentTransform[2];
	cTkMatrix34 maLastControllerTransform[2];
	cTkSmoothCD<float> maHandControllersFade[2];
	TkHandle maHandControllers[2];
	TkHandle maHandCollisionNodes[2];
	cTkMatrix34 maGrabChangedMatrix[2];
	cTkMatrix34 maLastGoodGrabTransform[2];
	sGrabbedObjectInfo maPreviousGrabbable[2];
	float mafGrabTimer[2];
	bool mabClenchingFist[2];
	sGrabbedObjectInfo maCurrentGrabbable[2];
	unsigned __int64 mauPointingStartTime[2];
	unsigned __int64 mauPointingEndTime[2];
	cTkVector3 mPlayerShift;
	cTkVector3 mFrameShift;
	bool mbPendingFrameShift;
	eAlienRace meRace;
	bool mbHeadAnimationInProgress;
	eEmoteState meEmoteState;
	cGcPlayerEmoteProp mEmoteProp;
	bool mbIsTargetingUnscannedPlanet;
	cTkPhysRelMat34 mmCurrentTargetPlacement;
	float mfShipRadiusCached;
	float mfFreighterMegaWarpTimer;
	unsigned __int64 mu64LastAutoSaveTimeStamp;
	cGcPlayer::cGcSummonPetData mSummonPetData;
	bool mbShowOneContact;
	int miContactToShow;
	int miNumContactsToShow;
};

struct cGcPlayerState
{
	typedef cGcPlayer::eRocketBootsDoubleTapState WarpTargetMode;

	struct __declspec(align(8)) ItemEvent
	{
		TkID<128> mId;
		float mfTime;
	};

	cTkFixedString<256, char> mNameWithTitle;
	sPlayerTitleStatWatcher mTitleStatWatcher;
	unsigned __int64 mu64ChangeRevision;
	cGcUniverseAddressData mGameStartLocation1;
	cGcUniverseAddressData mGameStartLocation2;
	cGcUniverseAddressData mLocation;
	cGcUniverseAddressData mPrevLocation;
	int miShield;
	int miHealth;
	int miShipHealth;
	unsigned int muUnits;
	unsigned int muNanites;
	unsigned int muSpecials;
	std::array<float, 6> mafRestoreHazardTimers;
	int miRestoreShield;
	int miRestoreHealth;
	int miRestoreShipShield;
	int miRestoreShipHealth;
	int miRestoreEnergy;
	cGcExactResource mWeaponResource;
	cTkFixedArray<cGcInventoryStore, 28> mInventories;
	std::vector<cGcInventoryStore, TkSTLAllocatorShim<cGcInventoryStore> > mShelvedInventories;
	cTkFixedArray<cGcInventoryStore, 7> mVehicleInventories;
	cTkFixedArray<cGcInventoryStore, 7> mVehicleTechInventories;
	cTkFixedArray<cGcVehicleLocation, 7> mVehicleLocations;
	eVehicleType mePrimaryVehicle;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventories;
	std::vector<cGcInventoryStore, TkSTLAllocatorShim<cGcInventoryStore> > mShelvedShipInventories;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesCargo;
	cTkFixedArray<cGcInventoryStore, 12> mShipInventoriesTechOnly;
	cTkFixedArray<cGcResourceElement, 12> mShipResources;
	int miPrimaryShip;
	std::vector<cGcRepairTechData, TkSTLAllocatorShim<cGcRepairTechData> > mRepairTechBuffer;
	std::vector<cTkVector3, TkSTLAllocatorShim<cTkVector3> > maSurveyedEventPositions;
	cGcPlayerLogBook mPlayerLog;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >> mSeenBaseBuildingObjects;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mKnownTechnologies;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>> > mKnownProducts;
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>> > mKnownRefinerRecipes;
	std::vector<cGcWordGroupKnowledge, TkSTLAllocatorShim<cGcWordGroupKnowledge> > mKnownWordGroups;
	unsigned __int64 mu64TotalPlayTime;
	unsigned __int64 mu64TimeAlive;
	float mfTimeAccumulator;
	unsigned __int64 mu64HazardTimeAlive;
	float mfHazardTimeAccumulator;
	float mfLastInventoryStoreTime;
	float mfLastInventoryFailTime;
	int miProcTechIndex;
	cTkFixedArray<cGcSavedInteractionRaceData, 131> maSavedInteractionIndicies;
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>> > maInteractionLookupTable;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultSuitLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultWeaponLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mDefaultShipLoadout;
	std::vector<cGcInventoryElement, TkSTLAllocatorShim<cGcInventoryElement> > mGraveInventory;
	cGcUniverseAddressData mGraveLocation;
	cTkMatrix34 mGraveMatrix;
	bool mbSpawnGrave;
	bool mbSpaceGrave;
	bool mbPendingBootSpawnGrave;
	std::vector<cGcUniverseAddressData, TkSTLAllocatorShim<cGcUniverseAddressData> > mAtlasStationLocations;
	cTkLinearHashTable<unsigned __int64, TkID<256>, cTkLinearHashTableHash<unsigned __int64> > maInteractionDialogMap;
	bool mbFirstAtlasStationDiscovered;
	bool mbUsesThirdPersonCharacterCam;
	cTkVector4 mInitialSpawnPosition;
	cTkVector4 mInitialShipPosition;
	int miProgressionLevel;
	unsigned __int64 mActiveBattleUA;
	cGcPlayerState::ItemEvent mLastBuiltProduct;
	cGcPlayerState::ItemEvent mLastBuiltTech;
	cGcPlayerState::ItemEvent mLastRepairedTech;
	int miSlots;
	int miLevel;
	int miMaxTechValue;
	int miMaxTechs;
	bool mbFillAllSlots;
	bool mbWarpFromBlackHole;
	bool mbRevealBlackHoles;
	bool mbWarpFromRelicGate;
	bool mbWarpFromFreighterMegaWarp;
	bool mbUseSmallerBlackholeJumps;
	bool mbIsDataNew;
	std::vector<cGcSavedEntitlement, TkSTLAllocatorShim<cGcSavedEntitlement> > maUsedEntitlements;
	unsigned __int64 mu64LastSpaceBattleTime;
	int miLastSpaceBattleWarps;
	unsigned __int64 mu64LastMiniStationTime;
	int miLastMiniStationWarps;
	unsigned __int64 mMiniStationLocation;
	cTkVector3 mAnomalyPositionOverride;
	cGcPhotoModeSettings mPhotoModeSettings;
	std::vector<cGcTeleportEndpoint, TkSTLAllocatorShim<cGcTeleportEndpoint> > maTeleportEndpoints;
	cGcPlayerNPCWorkers mPlayerNPCWorkers;
	cGcInteractionData mHoloExplorerInteraction;
	cGcInteractionData mHoloScepticInteraction;
	cGcInteractionData mHoloNooneInteraction;
	cGcInteractionData mNetworkPlayerInteraction;
	cTkVector4 mStartGameShipPosition;
	bool mbShipNeedsTerrainPositioning;
	cTkFixedString<32, char> mCustomWeaponName;
	cTkFixedString<32, char> maCustomShipNames[12];
	cTkFixedString<32, char> maCustomVehicleNames[7];
	std::vector<cGcPortalSaveData, TkSTLAllocatorShim<cGcPortalSaveData> > maLastPortal;
	cGcPortalSaveData mLastPortal;
	int miKnownPortalRunes;
	bool mbOnOtherSideOfPortal;
	cGcTeleportEndpoint mOtherSideOfPortalReturnBase;
	cTkPhysRelVec3 mPortalMarkerPosition;
	unsigned __int64 mu64LastUABeforePortalWarp;
	unsigned __int64 mu64ActiveStoryPortalSeed;
	std::pair<TkID<128>, cTkSeed> mPreviousMission;
	std::pair<TkID<128>, cTkSeed> mCurrentMission;
	eWeaponMode meStartingPrimaryWeapon;
	eWeaponMode meStartingSecondaryWeapon;
	float mfVRCameraOffset;
	bool mbThirdPersonShipCam;
	bool mbThirdPersonVehicleCam;
	bool mbNextLoadSpawnsWithFreshStart;
	bool mbInitialised;
	bool mbVehicleAIControlEnabled;
	bool mbHasAccessToNexus;
	cGcUniverseAddressData mNexusUniverseLocation;
	cTkMatrix34 mNexusSavedMatrix;
	std::array<cGcResourceCustomisation, 23> mCustomisationData;
	std::array<cGcResourceCustomisation, 3> mOutfits;
	cTkFixedArray<cGcStoryPageSeenDataArray, 8> maSeenStoriesData;
	TkID<128> mJetpackEffect;
	cGcPlayerBanner mPlayerBanner;
	cGcSeasonState mSeasonState;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedSpecials;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedSeasonRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedTwitchRewards;
	robin_hood::detail::Table<1, 80, TkID<128>, void, robin_hood::hash<TkID<128>, void>, std::equal_to<TkID<128> >, -1> mRedeemedPlatformRewards;
	TkID<128> mPendingRewardId;
	bool mbHasPendingRewardFromSeason;
	bool mbHasPendingRewardFromTwitch;
	bool mbHasPendingRewardFromPlatform;
	ePlayerFinalisePurchaseState meFinalisePurchaseState;
	cGcSettlementState maSettlementStates[100];
	int miSettlementStateRingBufferIndex;
	cTkFixedString<128, char> macSaveName;
	cTkFixedString<128, char> macSaveSummary;
	const cGcRewardDeath* mpDeathReward;
	cGcCustomisationDescriptorGroups* mpCharacterCustomisationDescriptorGroups;
	cGcCustomisationTextureOptions* mpCharacterCustomisationTextureOptions;
	cGcCustomisationPresets* mpCharacterCustomisationPresets;
	cGcCustomisationColourPalettes* mpCustomisationColourPalettes;
	cGcCustomisationBannerGroup* mpCustomisationBannerData;
	cGcCustomisationThrusterEffects* mpCustomisationThrusterData;
	cGcCustomisationShipBobbleHeads* mpCustomisationShipBobbleHeads;
};

struct sPlayerTitleStatWatcher : IStatWatcher
{
	std::unordered_map<TkID<128>, cGcPlayerTitle const*, TkIDUnorderedMap::Hash128, std::equal_to<TkID<128> >, TkSTLAllocatorShim<std::pair<TkID<128> const, cGcPlayerTitle const*>> > mStatIdMap;
};

struct cGcPlayerLogBook
{
	std::vector<LogBookMessage, TkSTLAllocatorShim<LogBookMessage> > mPlayerLogs;
};

struct cGcInteractionData
{
	unsigned __int64 mu64GalacticAddress;
	unsigned __int64 mu64Value;
	cTkVector4 mPosition;
};

struct cGcSavedInteractionRaceData
{
	cTkFixedArray<int, 8> maiSavedRaceIndicies;
	cTkFixedArray<bool, 8> mabHasLoopedIndicies;
};

struct cGcPlayerBanner
{
	unsigned __int8 miIconIndex;
	unsigned __int8 miMainColourIndex;
	unsigned __int8 miBackgroundColourIndex;
	eInventoryClass meShipClass;
	TkID<128> mTitleId;
};


struct cGcPlayerEmoteProp
{
	enum eState : __int32
	{
		Inactive = 0x0,
		LoadingResource = 0x1,
		Visible = 0x2,
	};
};

struct cGcGraveManager
{
	cGcGraveManager::Data* mpData;
};

struct cGcMsgBeaconManager
{
	cGcMsgBeaconManager::Data* mpData;
};

struct cGcHand
{
	eHand meHand;
};

enum ePlayerBoostCheck : __int32
{
	EPlayerBoostCheck_Allowed = 0x0,
	EPlayerBoostCheck_TooCloseToStation = 0x1,
	EPlayerBoostCheck_TooCloseToFreighters = 0x2,
	EPlayerBoostCheck_EnemiesNearby = 0x3,
	EPlayerBoostCheck_InAtmosphere = 0x4,
	EPlayerBoostCheck_TooCloseToAnomaly = 0x5,
	EPlayerBoostCheck_UsingComms = 0x6,
	EPlayerBoostCheck_NumTypes = 0x7,
};

struct cGcPlayerCommon
{
	cGcPlayerCommon_vtbl* __vftable /*VFT*/;
	__declspec(align(16)) cGcOwnerConcept mOwnerConcept;
	cGcPlayerWanted mWanted;
	TkHandle mRootNode;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maBeingScannedBy;
	float mfLastBeingScannedTime;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maAttackingPredators;
	std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > maEngagedPredators;
	float mfLastAttackTime;
	float mfLastRespawnTime;
	cTkAttachmentPtr mpRidingCreature;
	cTkAttachmentPtr mpPetCreature;
	cTkAttachmentPtr mpFriendlyDrone;
};

struct __declspec(align(16)) cGcPlayerHazard
{
	cGcPlayerHazardTable* mpHazardTable;
	cTkBitArray<unsigned int, 1> mxHazardsActive;
	eHazard meHazardOverride;
	float mfHazardOverrideTarget;
	float mfHazardOverrideStrength;
	float mfLastHazardOverrideTime;
	cTkPhysRelVec3 mHazardOverridePosition;
	std::array<float, 6> mafHazardTimers;
	std::array<float, 6> mafHazardStateChangeTimes;
	std::array<int, 6> maiHazardChargeLastValues;
	std::array<float, 6> mafHazardLastPainTime;
	float mfLastWarningTime;
	float mfLastRestoreTime;
	std::array<cGcInventoryElement const*, 6> mapActiveShieldingItems;
	std::array<float, 6> mafLastEnergyDrainTime;
	std::array<bool, 6> mabTakenInitialHazardDamage;
	TkAudioObject mHazardAudioObject;
	TkAudioID mCurrentHazardAudioSwitch;
	bool mbHazardProtectionAudioLoopPlaying;
	std::vector<std::pair<cGcInventoryElement const*, float>, TkSTLAllocatorShim<std::pair<cGcInventoryElement const*, float>> > mapActiveShieldingItemQueues[6];
};

struct __declspec(align(16)) cGcPlayerRespawn
{
	cGcPlayerSpawnStateData mGeneratedPlayerSpawn;
	bool mbWasPlayerInShipWhenKilled;
	bool mbOverrideSpawnPlayerOnPlanet;
};

struct __declspec(align(16)) cGcPlayerLadderClimb
{

	enum State : __int32
	{
		OffLadder = 0x0,
		OnLadder = 0x1,
		Exiting = 0x2,
	};

	cGcPlayer* mpPlayer;
	bool mIsOnLadder;
	cTkMatrix34 mStartLocation;
	cTkMatrix34 mTargetLocation;
	cTkMatrix34 mTopEndPoint;
	cTkMatrix34 mBottomEndPoint;
	float mTimeInTransition;
	cGcPlayerLadderClimb::State meState;
};
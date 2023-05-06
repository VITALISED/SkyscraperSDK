#pragma once
#include "INetworkPlayerEventsHandler.h"
#include "cTkTypes.h"
#include "cGcPlayerShip.h"
#include "cGcNetwork.h"
#include "Alien.h"

struct __declspec(align(16)) cGcPlayerFreighterOwnership : INetworkPlayerEventsHandler
{
	typedef cGcPlayerShipOwnership::eMeshRefreshState eMeshRefreshState;

	TkHandle mGroupRootNode;
	cTkFixedString<32, char> mCustomFreighterName;
	cTkUserIdBase<cTkFixedString<64, char> > mOwnerId;
	cGcNetworkFreighterOwnershipSyncMessage mFreighterOwnershipSyncMessage;
	cGcUniverseAddressData mFreighterLocation;
	bool mbIsDismissed;
	cTkSeed mFreighterHomeSystemSeed;
	cTkSeed mPlayerFreighterSeed;
	unsigned __int64 mu64UTCTimeOfLastSpawn;
	cGcResourceElement mFreighterResource;
	cGcResourceElement mFreighterNPCResource;
	cTkModelResource mHangarResource;
	cTkSmartResHandle mPlayerFreighterResHandle;
	TkHandle mPlayerFreighterNode;
	cGcAISpaceshipComponent* mpPlayerFreighterComponent;
	cTkClassPoolHandle mInvalidAsteroidArea;
	cTkMatrix34 mFreighterMatrix;
	float mfRequestedFreighterSpawnTime;
	eAlienRace meRace;
	cGcScanEffectData mFreighterPreviewScanData;
	cTkColour mFreighterPreviewColour;
	TkHandle mPreviewFreighterNode;
	TkHandle mFalseFreighterNode;
	float mfFreighterPreviewFirstActiveTime;
	float mfFreighterPreviewLastActiveTime;
	bool mbShowFreighterPreview;
	bool mbNextSpawnIsInstant;
	bool mbSpawnFreighterWhenResourceIsLoaded;
	bool mbFreighterIsAbsentDueToWarpingWithPlayersOnBoard;
	bool mbHaveFreighterOwnershipSyncMessage;
	bool mbWantToDestroy;
	bool mbHasTeleporter;
	bool mbIsActiveFreighterInSystem;
	TkID<128> mFreighterEngineEffect;
	cGcNetReplicatedFreighterColourData mReplicatedCustomColours;
	bool mbShouldRefreshMesh;
	cGcPlayerFreighterOwnership::eMeshRefreshState mMeshRefreshState;
};
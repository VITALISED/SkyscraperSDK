#pragma once
#include "cGcCreature.h"
#include "cTkTypes.h"
#include "Fade.h"
#include "cGcSimulation.h"

struct cGcEcosystem
{
	struct __declspec(align(2)) cGcSpawnedCreatureRecord
	{
		cGcCreatureGUID mGUID;
		cGcFadeNode* mpFade;
		TkHandle mNode;
		int miSwarmIndex;
		float mfDespawnRadius;
		bool mbEcosystemControl;
		int miEcosystemIndex;
		bool mbUnderwater;
		char macDebugID[10];
	};

	int miTotalNumCreaturesSpawned;
	int miNumEcosystemCreaturesSpawned;
	int miNumBirdsSpawned;
	cGcFadeNode maCreatureFadeNodes[256];
	cGcEcosystem::cGcSpawnedCreatureRecord maSpawnedCreatures[256];
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle, 4, -1> > maDespawnNodes;
	__declspec(align(16)) cGcCreatureSwarm maSwarms[50];
	int miNumSwarms;
	cGcCreatureStats maCreatureStats[32];
	int miNumCreatureStats;
	int maiCreatureCounts[32];
	cGcCreatureDataTable* mapCreatureTables[32];
	int miNumCreatureTables;
	cGcCreatureFilenameTable* mpSpawnData;
	cGcCreatureAudioTable* mpCreatureAudioTable;
	cGcCreatureBehaviourTrees* mpBehaviourTrees;
	cGcRagdollLimiter mRagdollLimiter;
	bool mbImGuiShowCreatureList;
	TkID<128> mImGuiSelectedCreature;
	int miImGuiSelectedTable;
	eCreatureType meDebugBehaviour;
	int miSpawnDataIndex;
	cTkAttachment* mpDebugSelectedCreature;
	float mfPlayerUnderwaterAmount;
	float mfPlayerUnderwaterAmountVel;
};

struct __declspec(align(8)) cGcCreatureSwarm
{
	cGcCreatureNode maSwarmComponents[128];
	const cGcCreatureSwarmData* mpData;
	const cGcCreatureSwarmDataParams* mpParams;
	std::vector<cTkVector3, TkSTLAllocatorShim<cTkVector3, 16, -1> > mPath;
	cGcCreatureRoutinePtr mpRoutine;
	cTkPhysRelVec3 mSpawnPosition;
	cTkPhysRelVec3 mFollowPosition;
	cTkPhysRelVec3 mAveragePosition;
	cTkVector3 mAverageHeading;
	int miFreighterRoom;
	cTkAttachmentPtr mpFreighterAttachment;
	cTkVector3 maSearchPositions[4];
	int miNumComponents;
	int miNumSearchPositions;
	eMoveArea meMoveType;
	bool mbReserved;
	float mfTimer;
	float mfIgnoreTerrainTimer;
	bool mbIgnoreTerrain;
};

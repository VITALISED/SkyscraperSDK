#pragma once
#include "cTkTypes.h"
#include "cGcAsyncLoadOps.h"
#include "cGcSceneManager.h"
#include "cGcParticleManager.h"
#include "cGcEnvironment.h"

struct __declspec(align(16)) cGcSimulation
{
	struct DestructionPair
	{
		cTkRigidBodyPtr mDestroyed;
		cTkRigidBodyPtr mDestroyer;
	};

	cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedInstanceQueue;
	cTkInplaceLockFreeQueue<cGcSimulation::DestructionPair, 1024> gDestroyedCreatureQueue;
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maRemoveQueue;
	cTkFixedString<256, char> mCurrentScene;
	cGcScanManager mScanManager;
	cGcAvailableWeapons mAvailableWeapons;
	cGcSceneManager mSceneManager;
	cGcParticleManager mParticleManager;
	cGcEnvironment mEnvironment;
	cGcEcosystem mEcosystem;
	cGcProjectileManager mProjectileManager;
	cGcAISpaceshipManager mAISpaceshipManager;
	cGcNPCManager mNPCManager;
	cGcFullscreenEffectManager mFullscreenEffectManager;
	cGcSolarSystem* mpSolarSystem;
	cGcSolarSystemDirector* mpSolarSystemDirector;
	cGcSpaceshipWarp mWarp;
	cTkPhysRelVec3 mPortalMarkerPosition;
	eCentreJourneyDestination meRequestCentreJourney;
	cGcPlayerExperienceDirector mPlayerExperienceDirector;
	cGcPlayer mPlayer;
	cGcPlayerRespawn mPlayerRespawn;
	TkHandle mSimulationRootNode;
	TkHandle maGroupNodes[13];
	std::vector<cGcSimulation::sGroupNodeActivation, TkSTLAllocatorShim<cGcSimulation::sGroupNodeActivation> > mGroupNodeActivationStack;
	TkIterationState<1> mPrepareIterationState;
	bool mbTransitionFromGalacticMap;
	bool mbRequestGalaxyMap;
	bool mbSimulationPrepared;
	bool mbSimulationInLoadPhase;
	unsigned __int64 mCurrentUA;
	unsigned __int64 mCurrentUDA[2];
	cTkClock mMissionClock;
};

struct cGcRagdollLimiter
{
	cTkStackVector<cTkPhysicsComponent*> mRagdolls;
};

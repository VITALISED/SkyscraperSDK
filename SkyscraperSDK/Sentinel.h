#pragma once
#include "pch.h"
#include "cTkTypes.h"

struct cGcSentinelInfo
{
	struct Sentinels
	{
		std::vector<cTkAttachmentPtr, TkSTLAllocatorShim<cTkAttachmentPtr> > mapAttachments[9];
	};

	struct SentinelCounts
	{
		int maiCount[9];
	};

	cGcSentinelInfo::Sentinels mSentinels;
	cGcSentinelInfo::SentinelCounts mSizes;
	const cGcSentinelSpawnNamedSequence* mpCurrentSequence;
	int miCurrentWave;
	int miReinforceCount;
	int miWanted;
};

struct cGcPlayerExperienceDirector
{
	enum eCombatSquad : __int32
	{
		ECombatSquad_None = 0x0,
		ECombatSquad_Deploying = 0x1,
		ECombatSquad_Deployed = 0x2,
		ECombatSquad_RequestReinforcements = 0x3,
	};
};

struct __declspec(align(4)) cGcPlayerWanted
{
	cGcPlayerCommon* mpPlayer;
	std::vector<cGcWitness, TkSTLAllocatorShim<cGcWitness> > maWitnesses;
	bool mbWitnessing;
	float mfLastWitnessTime;
	float mfLastEvadeTime;
	bool mbIsBeingInvestigated;
	bool mbIsBeingAttackedByRobots;
	cTkVector3 mLastKnownPlayerPos;
	bool mbPlayerHasBeenSeen;
	cTkSmartResHandle mWantedIcon;
	int miWanted;
	float mfWanted;
	float mfLastBadTime;
	bool mbLastPlanetOpenEnvPosValid;
	cTkVector3 mvLastPlanetOpenEnvPos;
	bool mbLastPlanetOpenEnvPosBeforeCrimeValid;
	cTkVector3 mvLastPlanetOpenEnvPosBeforeCrime;
	cTkVector3 mLastDroneCrimePos;
	float mfLastDroneScanTime;
	bool mbDroneScanning;
	float mfLastWantedEscalationTime;
	int miMajorCrimes;
	float mfTimeout;
	float mfWitnessTimer;
	float mfSightTime;
	bool mbInSight;
};
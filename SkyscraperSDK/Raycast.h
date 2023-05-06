#pragma once
#include "cTkTypes.h"
#include "cGcPlayer.h"

struct __declspec(align(8)) cTkRaycastJob
{
	cTkRaycastJob::Status* maStatus;
	unsigned int miNumJobs;
	cTkRaycastJob::Ray* maRays;
	int miNumRays;
	bool mbConstructed;
	unsigned __int64 miFrameNum;
	eTkMemType meMemoryPool;
};

struct cGcPlacementArc
{
	cGcPlacementArc::TargetStatus meTargetStatus;
	cTkPhysRelMat34 mPrevAimMatrix;
	cTkPhysRelMat34 mAimMatrix;
	cTkPhysRelVec3 mTargetPosition;
	TkHandle mLadderNode;
	cTkVector3 mTargetNormal;
	cTkRigidBody* mpTargetBody;
	eHand meHand;
	float mfRange;
	cTkRaycastJob mRayJob;
};

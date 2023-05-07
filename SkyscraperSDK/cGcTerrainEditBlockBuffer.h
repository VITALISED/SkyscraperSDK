#pragma once
#include "pch.h"
#include "ctkTypes.h"

struct __declspec(align(16)) cGcTerrainEditBlockBuffer : cGcNetworkSynchronisedBuffer
{
	sSharedMutex* mSharedMutex;
	unsigned __int64 mu64GalacticAddress;
	cTkAABB mEditsBoundingBox;
	std::deque<cGcTerrainEdit, TkSTLAllocatorShim<cGcTerrainEdit, 4, -1> > mEdits;
	cTkUserIdBase<cTkFixedString<64, char> > mNetworkOwnerId;
	bool mbIsBaseProtected;
	__int16 miLastPlayerRequestTimestamp[31];
};

struct $86C56B5D9AAB26ECE1891020AFA1BD28
{
	unsigned __int8 mVoxelType : 3;
	unsigned __int8 mShape : 1;
	unsigned __int8 mCustom1 : 3;
	unsigned __int8 mCustom2 : 1;
};

/* 22638 */
union $1EA76F3DA753B0F7FC43238E56A613C5
{
	char miData8;
	$86C56B5D9AAB26ECE1891020AFA1BD28 __s1;
};

struct sTerrainEditData
{
	$1EA76F3DA753B0F7FC43238E56A613C5 ___u0;
};

struct __declspec(align(16)) cGcTerrainEditsPersistentBuffer
{
	struct __declspec(align(16)) sPendingEdit
	{
		cTkVector3 mPosition;
		sTerrainEditData mData;
		unsigned __int64 mUA;
		char miExtraData;
		bool mbIsUndo;
		bool mbSetBaseProtected;
		bool mbJobId;
	};

	struct sPendingBlockJob
	{
		unsigned __int64 mUA;
		cTkVector3 mAnchor;
		cTkVector3 mLimits;
		cTkUserIdBase<cTkFixedString<64, char> > mOwnerId;
		unsigned __int16 mHashOffset;
		std::deque<cGcTerrainEdit, TkSTLAllocatorShim<cGcTerrainEdit> > mEdits;
	};

	cGcTerrainEditBlockBuffer mBlockBuffers[256];
	int mBufferAges[256];
	unsigned __int64 mCurrentGalacticAddress;
	int miNonEmptyBuffersCount;
	bool mbInitialised;
	int mCachedProtectedEditsCount;
	int mCachedProtectedBlocksCount;
	cGcTerrainEditsPersistentBuffer::sPendingEdit mPendingEdits[50000];
	std::atomic<int> miJobPendingEditIndex;
	int miJobProcessedEditIndex;
	std::atomic<int> mbEditJobRunning;
	bool mbCurrentJobId;
	void* mJobMutex;
	cGcTerrainEditsPersistentBuffer::sPendingBlockJob mPendingBlockJobs[256];
	int miBlockJobPendingIndex;
	int miBlockJobProcessedIndex;
};
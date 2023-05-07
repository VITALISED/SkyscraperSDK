#pragma once
#include "pch.h"
#include "Procedural.h"

template <class Type>
struct TkSTLAllocatorShim {
	typedef std::string value_type;
};

template <unsigned int size, typename T>
struct cTkFixedString
{
	//template<unsigned int size, typename T>
	cTkFixedString(const char* buff)
	{
		strcpy_s(macBuffer, size, buff);
	}

	T macBuffer[size];
};

template <typename T>
struct cTkUserIdBase
{
	T mID;
};

template <unsigned int size>
union TkID
{
	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 32];
};

struct cTkVector2
{
	float mfX;
	float mfY;
};

// TODO: un-simd-ification would be cool
struct cTkVector3
{
	__m128 mVal;
};

struct cTkVector4
{
	__m128 mVal;
};

struct cTkColour : cTkVector4 { 
	cTkColour(__m128 _mVal)
	{
		mVal = _mVal;
	}
};

template <typename T>
struct cTkDynamicArray
{
	union cTkDynamicArrayPointer
	{
		T* mpaArray;
		__int64 miOffset;
	};

	cTkDynamicArray::cTkDynamicArrayPointer mArray;
};

template <typename T, unsigned int size>
struct cTkFixedArray
{
	T maArray[size];
};

struct cTkBBox2d
{
	cTkVector2 mMin;
	cTkVector2 mMax;
};

struct  cTk2dObject
{
	cTk2dObject_vtbl* __vftable /*VFT*/;
	cTkColour mColour;
	cTkVector2 mPosition;
	cTkVector2 mSize;
	cTkVector2 mAlignment;
	cTk2dObject* mpNextSibling;
};

struct cTk2dText : cTk2dObject
{
	enum ETextFormat : __int32
	{
		eParagraph = 0x0,
		eSentence = 0x1,
	};

	const cTkTextStyle* mpTextStyle;
	const wchar_t* mpacText;
	cTkFont* mpFont;
	float mfTextHeight;
	int miStringLength;
	cTk2dText::ETextFormat meFormat;
	cTkVector2 mvParagraphAlignment;
	bool mbEnableHighlight;
};

struct __declspec(align(8)) cTk2dTextPreset
{
	float mfTextHeight;
	cTkFont* mpFont;
	cTkColour mColour;
	const cTkTextStyle* mpTextStyle;
	bool mbEnableHighlight;
};

struct __declspec(align(8)) cTkFSM
{
	void(__fastcall * ~cTkFSM)(cTkFSM* _this);
	void(__fastcall* Update)(cTkFSM* _this, float);
	void(__fastcall* Destruct)(cTkFSM* _this);
	void(__fastcall* StatePrepare)(cTkFSM* _this, cTkFSMState*, const void*);
	void(__fastcall* StateRelease)(cTkFSM* _this, cTkFSMState*, const void*);
	cTkFSMState* mpState;
	TkID<128> mRequestedChangeNewState;
	const void* mpRequestedChangeUserData;
	bool mbRequestedChangeForceRestart;

	const struct cTkFSMStateOffset
	{
		TkID<128> mID;
		unsigned __int64 mnOffset;
	};

	const cTkFSMStateOffset* mpOffsetTable;
	void(__fastcall* Construct)(cTkFSM* _this, const cTkFSMStateOffset*, const TkID<128>*);
};

struct cTkFSMState
{
	cTkFSMState_vtbl* __vftable /*VFT*/;
	TkID<128> mID;
	cTkFSM* mpFSM;
	unsigned __int64 mu64StateTimingStart;
};

struct __declspec(align(8)) cTkStopwatch
{
	unsigned __int64 miDuration;
	unsigned __int64 miStartTime;
	bool mbRunning;
};

struct cTkPhysRelVec3
{
	cTkVector3 mvLocal;
	cTkVector3 mvOffset;
};

struct cTkPhysRelMat34
{
	cTkVector3 mRight;
	cTkVector3 mUp;
	cTkVector3 mAt;
	cTkPhysRelVec3 mPos;
};

template <typename T, TkStrongTypeIDs>
struct TkStrongType/*<int, TkStrongTypeIDs::TkResHandleID>*/
{
	T mValue;
};

struct cTkSmartResHandle
{
	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> miInternalHandle;
};

union $6414FEA29EB2BD4331652807C066E5EC
{
	float c[4][4];
	float x[16];
};

struct cTkMatrix34
{
	cTkVector3 mRight;
	cTkVector3 mUp;
	cTkVector3 mAt;
	cTkVector3 mPos;
};

struct cTkMatrix44
{
	$6414FEA29EB2BD4331652807C066E5EC ___u0;
};

struct EgRenderQueueHandle
{
	int miQueueId;
	int miFrameId;
};

// not sure what this template does?
template<int T>
struct cTkTimerTemplate
{
	float mfDuration;
	float mfStartTime;
};

template <typename T>
struct cTkSmoothCD/*<float>*/
{
	T mVelocity;
	T mValue;
};

template <typename T, int size>
struct cTkBitArrayStorage/*<unsigned __int64, 512>*/
{
	T mArray[8];
};

template <typename T, int size>
struct cTkBitArray/*<unsigned __int64, 1, 512>*/
{
	cTkBitArrayStorage<T, size> mStorage;
};

struct __declspec(align(2)) cGcGalacticVoxelCoordinate
{
	__int16 mX;
	__int16 mZ;
	__int16 mY;
	bool mbValid;
};

struct cTkMcQmcLFSRStore
{
	std::array<cTkMcQmcLFSR*, 3> mSamplers;
};

struct $C95292F60449243F991AE29653660CC7
{
	unsigned __int32 miLookup : 18;
	unsigned __int32 miIncrementor : 14;
};

union $6E20333A2A96572C8F77A44741341866
{
	$C95292F60449243F991AE29653660CC7 __s0;
	unsigned int miLookupInt;
};

struct TkHandle
{
	$6E20333A2A96572C8F77A44741341866 ___u0;
};

template <typename T, class U, class Y>
struct __declspec(align(8)) cTkLinearHashTable/*<unsigned __int64, TkID<256>, -1, 0, cTkLinearHashTableHash<unsigned __int64> >*/
{
	cTkLinearHashTable<T, U, Y>::cTkListNode* mpNodes;
	cTkLinearHashTable<T, U, Y>::cTkListNode** mapBucketTable;
	cTkLinearHashTable<T, U, Y>::cTkListNode* mpFirstFreeNode;
	int miCapacity;
	int miSize;
	int miTableSize;
};

struct cTkAttachmentPtr
{
	__int64 miUniqueID;
};

/* 21641 */
struct cTkAABB
{
	cTkVector3 mMin;
	cTkVector3 mMax;
};

enum eTkMemType : __int32
{
	EMemoryPool_Physics = 0x0,
	EMemoryPool_SingleBuffer = 0x1,
	EMemoryPool_DoubleBuffer = 0x2,
	EMemoryPool_DoubleBufferPausable = 0x3,
	EMemoryPool_IO = 0x4,
	EMemoryPool_Network = 0x5,
	EMemoryPool_Resources = 0x6,
	EMemoryPool_Audio = 0x7,
	EMemoryPool_Graphics = 0x8,
	EMemoryPool_Compute = 0x9,
	EMemoryPool_Nodes = 0xA,
	EMemoryPool_AnimStages = 0xB,
	EMemoryPool_BlockAllocator = 0xC,
	EMemoryPool_GraphicsContext = 0xD,
	EMemoryPool_CommandBuffers = 0xE,
	EMemoryPool_Debug = 0xF,
	EMemoryPool_Metadata = 0x10,
	EMemoryPool_NodeAllocator = 0x11,
	ENumTkMemoryPools = 0x12,
};

struct cTkResourceDescriptor
{
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>> > maDescriptors;
	cTkSeed mSeed;
	cTkSeed mSecondarySeed;
};

struct cTkClassPoolHandle
{
	int miArrayIndex;
	int miUniqueID;
};

template <int unk>
struct AutoPooled {};

template <int unk>
struct cTkVector3KD/*<-1>*/
{
	cTkVector3KD<unk>_vtbl* __vftable /*VFT*/;
	__declspec(align(16)) std::vector<cTkVector3KD<unk>::Float3, TkSTLAllocatorShim<cTkVector3KD<unk>::Float3> > mvPoints;
	cTkVector3 mBBoxMin;
	cTkVector3 mBBoxMax;
	bool mbBBoxValid;
};

template <typename T, int unk>
struct __declspec(align(16)) cTkVector3MetaKD/*<int, -1>*/ : cTkVector3KD<unk>
{
	std::vector<T, TkSTLAllocatorShim<T> > mvMetadata;
};

template <class T>
struct __declspec(align(8)) cTkLockFreeQueue/*<cGcSimulation::DestructionPair>*/
{
	std::atomic<int> miQueueMarkers;
	T* mpEntries;
	std::atomic<int>* maEntryValid;
	int miMaxNumEntries;
};

template <class T, int size>
struct __declspec(align(8)) cTkInplaceLockFreeQueue/*<cGcSimulation::DestructionPair, 1024>*/ : cTkLockFreeQueue<T>
{
	T maEntryBuffer[size + 1];
	std::atomic<int> maEntryValidBuffer[size + 1];
};

struct cTkRigidBodyPtr
{
	int miBodyIndex;
	__int64 miUniqueID;
};

template <class T, int size>
struct cTkClassPool/*<cGcSimpleScanEffectPool<3>::Data, 3>*/
{
	T::Data maPool[size];
	int maiUniqueIds[size];
	int maiRoster[size];
	int miRosterPartition;
	int miUniqueIDGenerator;
};

template <int wire>
struct __declspec(align(8)) TkIterationState/*<1>*/
{
	std::array<unsigned __int64, wire> muIndices;
	std::array<bool, wire> mbInnerStates;
};

enum ePrimaryAxis : __int32
{
	EPrimaryAxis_Z = 0x0,
	EPrimaryAxis_ZNeg = 0x1,
	EPrimaryAxis_X = 0x2,
	EPrimaryAxis_XNeg = 0x3,
	EPrimaryAxis_Y = 0x4,
	EPrimaryAxis_YNeg = 0x5,
	EPrimaryAxis_NumTypes = 0x6,
};

template <class T, int size>
struct __declspec(align(8)) cTkRosterPool/*<cGcAIShipSpawn, 128>*/
{
	T maPool[size];
	int maiRoster[size];
	int miRosterPartition;
};

struct __declspec(align(8)) TkAddNodesHandle
{
	enum eAddNodesState : __int32
	{
		EAddNodesState_None = 0x0,
		EAddNodesState_Searching = 0x1,
		EAddNodesState_Adding = 0x2,
	};

	/* 852 */
	enum eState : __int32
	{
		EState_Adding = 0x0,
		EState_Preparing = 0x1,
		EState_Complete = 0x2,
	};

	TkStrongType<int, TkStrongTypeIDs::TkResHandleID> mSceneGraphResource;
	TkHandle mParentNode;
	TkHandle mNode;
	TkHandle mLastAddedNode;
	std::shared_ptr<TkAddNodesHandle> mpAddReferencedResourceHandle;
	unsigned __int64 mu64Timeout;
	cEgSceneNodeTemplate* mpLastAddedTemplate;
	cTkAttachment* mpCurrentAttachment;
	int miCount;
	TkAddNodesHandle::eAddNodesState meAddNodesState;
	TkAddNodesHandle::eState meState;
};

template <int size>
struct cTkMetaMessageMap/*<2>*/
{
	robin_hood::detail::Table<0, 80, unsigned __int64, cTkStackVector<std::function<void __cdecl(cTkMetaMessageWrapperTemplated<void> const&)>, 2, -1>, robin_hood::hash<unsigned __int64, void>, std::equal_to<unsigned __int64>> mSubscriptionMap;
};

template <class T>
struct __declspec(align(8)) cTkMetaMessageSink/*<cTkAttachmentPtr>*/
{
	cTkMetaMessageMap<T> mMetaMessageSubscriptions;
	T mData;
	bool mbConstructed;
};

struct cTkDynamicTexture
{
	cTkSmartResHandle mRenderTarget;
	int miWidth;
	int miHeight;
};

struct cTkAnimLayerHandle
{
	int miChannelIndex;
	int miAnimIndex;
	int miUid;
};

struct __declspec(align(16)) cTkPlane
{
	cTkVector3 mNormal;
	float mfDistance;
};

template <class T>
struct cTkSmoothCD
{
	T mVelocity;
	T mValue;
};

struct __declspec(align(8)) cTkClock
{
	unsigned __int64 mu64StartTime;
	unsigned __int64 mu64CurrentTime;
	unsigned __int64 muLastWaitTicksFinish;
	float mfTimeStep;
	float mfTotalTime;
	float mfPrevTotalTime;
	float mfSlowMotionFactor;
	unsigned __int64 muFrameCount;
	bool mbMinFrameTimeSynced;
	bool mbPaused;
	bool mbRealtime;
};
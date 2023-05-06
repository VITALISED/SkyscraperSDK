#pragma once
#include "cGcPlayer.h"
#include "cGcAtlastBrokerAuth.h"

struct cGcNetworkConstants
{
	typedef cGcAtlasBrokerAuth::State::Constants TransmissionChannels;
};

const struct cGcNetworkMessage
{
	cGcNetworkMessage_vtbl* __vftable /*VFT*/;
	eGcNetworkMessageType meMessageType;
	cGcNetworkConstants::TransmissionChannels meChannel;
	cGcNetworkSerializer mSerializer;
};


struct __declspec(align(8)) cGcNetworkSerializer
{
	typedef cGcPlayer::eRocketBootsDoubleTapState CurrentAction;

	unsigned __int8* macBuffer;
	unsigned int muCurrentBit;
	unsigned int muLastFinishedBit;
	unsigned int muBufferSize;
	unsigned int muCurrentReadWriteByte;
	cGcNetworkSerializer::CurrentAction meCurrentAction;
	cTkFixedString<64, char> mSenderId;
};

struct cGcNetReplicatedFreighterColourData
{
	int maaiColours[2][3];
};

struct __declspec(align(8)) cGcNetworkFreighterOwnershipSyncMessage : cGcNetworkMessage
{
	cTkMatrix34 mRequestedFreighterMatrix;
	cTkFixedString<32, char> macCustomFreighterName;
	cGcResourceElement mFreighterResource;
	cGcResourceElement mFreighterNPCResource;
	cTkSeed mFreighterHomeSystemSeed;
	cTkSeed mFleetSeed;
	unsigned __int64 mFreighterPackedUA;
	unsigned __int64 mu64UTCTimeOfLastSpawn;
	TkID<128> mEngineEffect;
	cGcNetReplicatedFreighterColourData mCustomColourOptions;
	std::vector<unsigned __int64, TkSTLAllocatorShim<unsigned __int64> > mau64ExpeditionSeedsSelectedToday;
	unsigned __int64 mu64LastKnownDay;
	bool mbWarpingWithPlayerAboard;
	bool mbIsDismissed;
};

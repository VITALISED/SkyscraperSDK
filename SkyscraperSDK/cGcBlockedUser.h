#pragma once
#include "cTkTypes.h"

struct cGcBlockedUser
{
	cTkFixedString<64, char> macUserId;
	cTkFixedString<64, char> macUsername;
	cTkFixedString<32, char> macPlatform;
};

struct cGcBlockedMessage
{
	cTkFixedString<128, char> macMessageId;
};

struct cGcBlockListPersistence
{
	cTkFixedArray<cGcBlockedUser, 50> maBlockedUserArray;
	int miNextSlot;
	int miListSize;
	cTkFixedArray<cGcBlockedMessage, 50> maBlockedMessageArray;
	int miMessageNextSlot;
	int miMessageListSize;
};

struct cGcBlockList
{
	cGcBlockList::Data* mpData;
};

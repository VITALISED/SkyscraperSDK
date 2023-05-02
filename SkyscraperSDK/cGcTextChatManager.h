#pragma once
#include "cTkTypes.h"
#include "Stubs.h"
#include "UnorderedMapHashes.h"

#include <robin_hood.h>
#include <vector>

enum TextChatMessageType : __int8
{
	Internal = 0x0,
	Local = 0x1,
	Group = 0x2,
	GroupVoice = 0x3,
	Whisper = 0x4,
	NumMessageTypes = 0x5,
};

enum ePendingMessageState : __int32
{
	EPendingMessageState_Free = 0x0,
	EPendingMessageState_StartProfanityCheck = 0x1,
	EPendingMessageState_WaitingForProfanityCheck = 0x2,
	EPendingMessageState_ProfanityCheckComplete = 0x3,
	EPendingMessageState_ProfanityCheckSkipped = 0x4,
};

struct __declspec(align(16)) PendingMessage
{
	ePendingMessageState mePendingMessageState;
	cTkFixedString<1023, char> msUncensoredMessageBody;
	cTkFixedString<1023, char> msMessageBody;
	std::vector<cTkUserIdBase<cTkFixedString<64, char> >, TkSTLAllocatorShim<cTkUserIdBase<cTkFixedString<64, char> >> > maRecipients;
	cTkUserIdBase<cTkFixedString<64, char> > mSender;
	float mfDisplayDuration;
	bool mbShowNamePrefix;
	bool mbIncludeLocalPlayer;
	TextChatMessageType meMessageType;
	cTkColour mBackgroundColour;
	int mMessageId;
};

struct std::array<PendingMessage, 10>
{
	PendingMessage _Elems[10];
};

struct __declspec(align(16)) DisplayMessage
{
	float mfDisplayStartTime;
	float mfDisplayDuration;
	cTkFixedString<1121, char> msMessage;
	cTkColour mBackgroundColour;
	int mMessageId;
};

struct std::array<DisplayMessage, 10>
{
	DisplayMessage _Elems[10];
};

struct TextChatMessageBuffer
{
	int miNextMessageInsertIndex;
	int miMessages;
	std::array<DisplayMessage, 10> maMessageBuffer;
};

struct cGcTextChatManager
{
	std::array<PendingMessage, 10> maPendingMessages;
	TextChatMessageBuffer maMessageBuffer;
	TextChatMessageType meLastMessageType;
	int mNextMessageId;
	cGcStatusMessageDefinitions* mpStatusMessageTable;
	robin_hood::detail::Table<0, 80, cTkFixedString<128, char>, int, UnorderedMapHashes::Hash<cTkFixedString<128, char> >, std::equal_to<cTkFixedString<128, char> >> mStringCountHash;

	typedef void(__fastcall* Say)(cGcTextChatManager* _this, const cTkFixedString<1024, char>* lsMessageBody, bool lbSystemMessage);
};

//struct __cppobj UnorderedMapHashes::Hash<cTkFixedString<128, char> > {};


#pragma once

#include "cTkTypes.h"
#include "cGcCreature.h"

#include "UnorderedMapHashes.h"
#include "pch.h"

enum eMissionMarkup /*: __int32*/
{
	EMissionMarkup_KillFiend = 0x0,
	EMissionMarkup_KillPirate = 0x1,
	EMissionMarkup_KillSentinel = 0x2,
	EMissionMarkup_KillHazardousPlants = 0x3,
	EMissionMarkup_KillTraders = 0x4,
	EMissionMarkup_KillCreatures = 0x5,
	EMissionMarkup_KillPredators = 0x6,
	EMissionMarkup_KillDepot = 0x7,
	EMissionMarkup_KillWorms = 0x8,
	EMissionMarkup_FeedCreature = 0x9,
	EMissionMarkup_CollectBones = 0xA,
	EMissionMarkup_CollectScrap = 0xB,
	EMissionMarkup_Discover = 0xC,
	EMissionMarkup_CollectSubstanceProduct = 0xD,
	EMissionMarkup_Build = 0xE,
	EMissionMarkup_Always = 0xF,
	EMissionMarkup_None = 0x10,
	EMissionMarkup_NumTypes = 0x11,
	EMissionMarkup_Unspecified = 0xFFFFFFFF,
};

struct cGcStatusMessageMissionMarkup
{
	eMissionMarkup meMissionMarkup;
};

enum eReplicateTo : __int32
{
	EReplicateTo_None = 0x0,
	EReplicateTo_Fireteam = 0x1,
	EReplicateTo_Fireteam_SameUA = 0x2,
	EReplicateTo_Global = 0x3,
	EReplicateTo_Global_Distance = 0x4,
	EReplicateTo_Fireteam_Distance = 0x5,
	EReplicateTo_Fireteam_Global_Distance = 0x6,
	EReplicateTo_Not_Fireteam = 0x7,
	EReplicateTo_NumTypes = 0x8,
};

struct __declspec(align(8)) cGcStatusMessageDefinition
{
	TkID<128> mId;
	TkID<256> mMessage;
	bool mbAddPlayerNamePrefix;
	bool mbAddPetNamePrefix;
	bool mbAddFriendlyDronePrefix;
	bool mbIncludePlayerName;
	eReplicateTo meReplicateTo;
	bool mbPostLocally;
	float mfDistance;
	float mfDisplayDurationMultiplier;
	bool mbOnlyInMultiplayer;
	bool mbOnlyOnFireteam;
	cGcStatusMessageMissionMarkup mMissionMarkup;
};

struct cGcCreaturePetTraits
{
	ePetTrait mePetTrait;
};

struct cGcPetVocabularyTraitEntry
{
	cGcCreaturePetTraits mTrait;
	TkID<256> mPositive;
	TkID<256> mNegative;
};

struct cGcPetVocabularyEntry
{
	TkID<256> mGenericFallback;
	float mfOddsOfProcReplacement;
	cTkDynamicArray<cGcPetVocabularyTraitEntry> maVocabulary;
};

struct cGcFriendlyDroneVocabularyEntry
{
	TkID<256> mGenericFallback;
};

struct cGcStatusMessageDefinitions
{
	cTkDynamicArray<cGcStatusMessageDefinition> maMessages;
	cTkColour mMissionMarkupColour;
	cTkFixedArray<cGcPetVocabularyEntry, 15> maPetVocabulary;
	cTkFixedArray<cGcPetVocabularyEntry, 21> maPetChatTemplates;
	cTkFixedArray<cGcFriendlyDroneVocabularyEntry, 5> maFriendlyDroneChatTemplates;
};

enum TextChatMessageType : __int8
{
	Internal = 0x0,
	Local = 0x1,
	Group = 0x2,
	GroupVoice = 0x3,
	Whisper = 0x4,
	NumMessageTypes = 0x5,
};

struct __declspec(align(16)) PendingMessage
{
	enum class ePendingMessageState
	{
		EPendingMessageState_Free = 0x0,
		EPendingMessageState_StartProfanityCheck = 0x1,
		EPendingMessageState_WaitingForProfanityCheck = 0x2,
		EPendingMessageState_ProfanityCheckComplete = 0x3,
		EPendingMessageState_ProfanityCheckSkipped = 0x4,
	};

	PendingMessage::ePendingMessageState mePendingMessageState;
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

struct __declspec(align(16)) DisplayMessage
{
	float mfDisplayStartTime;
	float mfDisplayDuration;
	cTkFixedString<1121, char> msMessage;
	cTkColour mBackgroundColour;
	int mMessageId;
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

	typedef void(__fastcall* Say)(
		cGcTextChatManager* _this,
		const cTkFixedString<1023, char>* lsMessageBody,
		const cTkUserIdBase<cTkFixedString<64, char> >* lSender,
		const std::vector<cTkUserIdBase<cTkFixedString<64, char> >, TkSTLAllocatorShim<cTkUserIdBase<cTkFixedString<64, char> >> >* laRecipients,
		bool lbShowNamePrefix,
		bool lbIncludeLocalPlayer,
		bool lbSystemMessage,
		TextChatMessageType leMessageType,
		const cTkColour* lBackgroundColour,
		int lOverwriteMessageId,
		float lfDisplayDuration);

	typedef void(__fastcall* PostLocalMessage)(
		cGcTextChatManager* _this,
		const cTkFixedString<1121, char>* lsMessage,
		const char* lpRelevantPlayerName,
		const cTkColour lBackgroundColour,
		int liRelevantPlayerIndex,
		float lfDisplayDuration);
};

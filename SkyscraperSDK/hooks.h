#pragma once
#include "patterns.h"
#include "cGcTextChatManager.h"
#include "cGcTextChatInput.h"
#include "TextChatHandler.h"

namespace Hooks
{
	void Init();
	void SHOOK SayHook(
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
		float lfDisplayDuration
	);
	typedef void(__fastcall* OriginalSay)(
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
};
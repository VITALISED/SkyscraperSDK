#include "hooks.h"

Hooks::OriginalSay originalSay;

void SHOOK Hooks::SayHook(
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
)
{
	LOG("Wires");
	LOG(lsMessageBody->macBuffer);

	uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
	auto ptrthing = reinterpret_cast<cGcTextChatManager::PostLocalMessage>(base + 0x94A2B0);


	cTkFixedString<1121, char> thing = cTkFixedString<1121, char>("wirreee HOCH:07B3:00FE:0EA4:007B");

	cTkColour newCol1 {
		newCol1.mVal = lBackgroundColour->mVal
	};

	ptrthing(_this, &thing, "Explorer", (cTkColour)newCol1, 0, lfDisplayDuration);


	originalSay(_this, lsMessageBody, lSender, laRecipients, lbShowNamePrefix, lbIncludeLocalPlayer, lbSystemMessage, leMessageType, lBackgroundColour, lOverwriteMessageId, lfDisplayDuration);
	return;
}

void SHOOK wire(cGcTextChatInput* _this, const cTkFixedString<1023, char>* lMessageText)
{
	uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
	auto ptrthing = reinterpret_cast<cGcTextChatManager::PostLocalMessage>(base + 0x94A2B0);

	if (lMessageText->macBuffer == "/wire")
	{
		ptrthing(_this, &thing, "Explorer", (cTkColour)newCol1, 0, lfDisplayDuration)
	}
}

void Hooks::Init()
{
	uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
	uintptr_t target = (uintptr_t)Patterns::Scan("41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44 8B B5 ? ? ? ? 4D 8B E1");

	uintptr_t foil = 0x949870;

	cGcTextChatManager::Say SayFunc = cGcTextChatManager::Say(target - 0x14);
	cGcTextChatInput::ParseTextForCommand ParseCmdFunc = cGcTextChatInput::ParseTextForCommand(base + foil);

	MH_CreateHook(ParseCmdFunc, wire, NULL);

	//MH_CreateHook(SayFunc, Hooks::SayHook, (void**) & originalSay);

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		LOG("SDK had explosions while hooking (tragic)")
	}
}

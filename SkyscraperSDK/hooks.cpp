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

	uintptr_t base = (uintptr_t)GetModuleHandleA("xgog release_x64.exe");

	auto ptrthing = reinterpret_cast<cGcTextChatManager::PostLocalMessage>(base + 0x94A2B0);


	cTkFixedString<1121, char> thing = cTkFixedString<1121, char>("wirreee HOCH:07B3:00FE:0EA4:007B");

	cTkColour newCol1 {
		newCol1.mVal = lBackgroundColour->mVal
	};

	ptrthing(_this, &thing, "Explorer", (cTkColour)newCol1, 0, lfDisplayDuration);


	originalSay(_this, lsMessageBody, lSender, laRecipients, lbShowNamePrefix, lbIncludeLocalPlayer, lbSystemMessage, leMessageType, lBackgroundColour, lOverwriteMessageId, lfDisplayDuration);
	return;
}

void Hooks::Init()
{
	uintptr_t base = (uintptr_t)GetModuleHandleA("xgog release_x64.exe");
	uintptr_t target = (uintptr_t)Patterns::Scan("41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 44 8B B5 ? ? ? ? 4D 8B E1");

	cGcTextChatManager::Say SayFunc = cGcTextChatManager::Say(target - 0x14);

	MH_CreateHook(SayFunc, Hooks::SayHook, (void**) & originalSay);

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		LOG("SDK had explosions while hooking (tragic)")
	}
}

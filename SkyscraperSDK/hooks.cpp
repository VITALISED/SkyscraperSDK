#include "hooks.h"

void Hooks::Init()
{
	uintptr_t base = (uintptr_t)GetModuleHandleA("xgog release_x64.exe");
	uintptr_t target = Patterns::Scan("0F 57 C0 48 C7 44 24 ??");


	cGcTextChatManager::Say SayFunc = cGcTextChatManager::Say(base + target);

	MH_CreateHook(SayFunc, SayHook, NULL);

	MH_EnableHook(MH_ALL_HOOKS);
}

void __fastcall SayHook(cGcTextChatManager* _this, const cTkFixedString<1024, char>* lsMessageBody, bool lbSystemMessage)
{
	LOG("Wires");
}
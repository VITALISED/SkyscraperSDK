// dllmain.cpp : Defines the entry point for the DLL application.
#include "macros.h"
#include "patterns.h"
#include "hooks.h"

DWORD WINAPI MainThread(LPVOID lpReserved)
{
    bool hooked = false;
    while (!hooked)
    {
        Hooks::Init();
        auto offset = Patterns::Scan("48 8D 05 ? ? ? ? C6 44 24 ? ? F3 0F 10 05"); // cGcTextChatManager::Say(cGcTextChatManager *this, const cTkFixedString<1023,char> *lsMessageBody, bool lbSystemMessage)
        LOG(offset);
        hooked = true;
    }
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    uintptr_t offset;

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LOG("SDK Attached");
        MH_Initialize();
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, MainThread, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


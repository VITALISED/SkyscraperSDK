#pragma once
#include "pch.h"
#include "cGcTextChatManager.h"

namespace TextChatHandler
{
	struct ChatCommand
	{

	};
	struct ChatCommandHandler
	{
		cGcTextChatManager::PostLocalMessage* pPostLocalMessage;
		std::vector<ChatCommand*> pCommands;
	};

}
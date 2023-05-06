#pragma once
#include "cTkTypes.h"

struct cTkStoragePersistent
{
	struct LowSpaceWarningData
	{
		unsigned __int64 mu64RequestedMB;
		unsigned __int64 mu64RemainingMB;
		cTkFixedString<32, char> mDrive;
	};
};
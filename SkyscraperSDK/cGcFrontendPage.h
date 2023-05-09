#pragma once
#include "cTkTypes.h"

struct cGcFrontendPage
{
	struct ButtonIcon
	{
		enum Size : __int32
		{
			Normal = 0x0,
			Wide = 0x1,
			VR = 0x2,
		};

		TkStrongType<int, TkStrongTypeIDs::cTkNGuiFontHandleID> miPadIcon;
		cGcFrontendPage::ButtonIcon::Size meSize;
		eInputAction meBoundAction;
	};
};
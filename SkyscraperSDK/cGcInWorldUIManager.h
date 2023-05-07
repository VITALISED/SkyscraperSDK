#pragma once

struct cGcInWorldUIManager
{
	struct cGcScreenProjector
	{
		enum RepositioningState : __int32
		{
			Idle = 0x0,
			Hovered = 0x1,
			Repositioning = 0x2,
			Repositioned = 0x3,
			Resetting = 0x4,
		};
	};
};
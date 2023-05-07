#pragma once

struct cGcFrontendManager
{
	enum eState : __int32
	{
		EState_Inactive = 0x0,
		EState_Booting = 0x1,
		EState_Wait = 0x2,
		EState_Activating = 0x3,
		EState_Active = 0x4,
		EState_Deactivating = 0x5,
		EState_ChangePageOut = 0x6,
		EState_ChangePageIn = 0x7,
	};
};
#pragma once

struct cGcFrontendManager
{
	struct MessageBoxData
	{
		bool mbRequestHide;
		bool mbEverVisible;
		bool mbVisible;
		TkID<256> mTitle;
		cTkFixedString<512, char> mMessage;
	};

	struct DialogBoxData : cGcFrontendManager::MessageBoxData
	{
		TkID<128> mBoxName;
		TkID<256> mYesLabel;
		TkID<256> mNoLabel;
		bool mbAccepted;
		bool mbDeclined;
		bool mbIsSoft;
		void(__fastcall* mpOnDialogCloseFunc)(void*, bool, bool);
		void* mpOnCloseData;
	};

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
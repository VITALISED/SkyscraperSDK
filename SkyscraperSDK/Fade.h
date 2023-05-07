#pragma once
#include "cTkTypes.h"

enum eFadeState : __int32
{
	EFade_In = 0x0,
	EFade_Out = 0x1,
	EFade_Visible = 0x2,
	EFade_Hidden = 0x3,
};

enum eFadeType : __int8
{
	FadeInThenFadeOut = 0x0,
	CrossFade = 0x1,
};

struct __declspec(align(4)) cGcFadeNodeBase
{
	cGcFadeNodeBase_vtbl* __vftable /*VFT*/;
	float mfTimer;
	float mfTotalTime;
	int miNodeParam;
	int miNodeSetIndex;
	eFadeState meFadeState;
	eFadeType meFadeType;
};

struct __declspec(align(8)) cGcFadeNode : cGcFadeNodeBase
{
	TkHandle mNode;
};

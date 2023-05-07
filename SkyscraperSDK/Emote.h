#pragma once

enum eEmoteState : __int32
{
	EEmoteState_None = 0x0,
	EEmoteState_Playing = 0x1,
	EEmoteState_Playing_Sit = 0x2,
};

struct __declspec(align(8)) cGcPlayerEmoteProp
{
	cGcPlayerEmoteProp::eState meState;
	const cGcPlayerEmotePropData* mpData;
	cTkSmartResHandle mModelResource;
	TkHandle mNode;
	TkHandle mAttachNode;
	cTkAttachmentPtr mpPlayerAttachment;
	cTkSmoothCD<float> mCurrentScale;
	float mfConstructTime;
	bool mbRequestedRemove;
	TkHandle mLightNode;
	TkHandle mScanEffectNode;
	float mfDefaultLightIntensity;
};
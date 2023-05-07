#pragma once
#include "cTkTypes.h"
#include "Fade.h"

struct __declspec(align(4)) cGcExplosion
{
	struct cGcDebris
	{
		cGcFadeNode mFade;
		TkHandle mNode;
		cTkPhysicsComponent* mpPhysics;
	};

	const cGcExplosionData* mpData;
	cTkMatrix34 mOffset;
	TkHandle mNode;
	TkHandle mParent;
	bool mbUpdateFromParent;
	int miNumDebris;
	TkHandle mDebrisNode;
	std::array<cGcExplosion::cGcDebris, 16> maDebris;
	TkID<128> mUserColourId;
	cTkColour mUserColour;
	TkAudioObject mAudioObject;
	float mfLife;
	bool mbIsPermanent;
	bool mbUserColourChanged;
};
#pragma once
#include "AKEvent.h"

struct TkAudioObject
{
	unsigned __int64 mID;
};

struct cGcAudioWwiseEvents
{
	eAkEvent meAkEvent;
};

struct __declspec(align(4)) TkAudioID
{
	const char* mpacName;
	unsigned int muID;
	bool mbValid;
};
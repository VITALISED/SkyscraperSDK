#pragma once
#include "cTkTypes.h"

struct __declspec(align(16)) sGrabbedObjectInfo
{
	cTkPhysRelMat34 mGrabMatrix;
	const cGcGrabbableComponent* mpGrabbedComponent;
	float mfMovementCompletion;
	int miDataIndex;
	bool mbIsAttached;
	bool mbGrabToggleActive;
	float mfGrabTime;
};
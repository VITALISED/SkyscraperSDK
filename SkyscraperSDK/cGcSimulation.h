#pragma once
#include "cTkTypes.h"

struct cGcSimulation
{
	struct DestructionPair
	{
		cTkRigidBodyPtr mDestroyed;
		cTkRigidBodyPtr mDestroyer;
	};
};
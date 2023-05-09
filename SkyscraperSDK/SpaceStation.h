#pragma once
#include "Procedural.h"

struct cGcSpaceStationSpawnData
{
	eSpawnMode meSpawnMode;
	cTkSeed mSeed;
	cTkFixedString<256, char> macAltId;
	cTkVector3 mSpawnPosition;
	cTkVector3 mSpawnFacing;
};

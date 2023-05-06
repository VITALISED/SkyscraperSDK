#pragma once

struct cGcFirstBootContext
{
	enum GenerationMode : __int32
	{
		Random = 0x0,
		BlackHoleDestination = 0x1,
		StoryPortalPlanet = 0x2,
	};

	cGcFirstBootContext::State meState;
	cGcFirstBootContext::GenerationMode meGenerationMode;
	SystemSeed mSystemSeed;
	cTkSeed mStarSeed;
	cGcGalacticVoxelCoordinate mBootCoordinate;
	int miDestinationIndex;
	unsigned __int64 mResultSpawnUA;
};
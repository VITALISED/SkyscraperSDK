#pragma once
#include "cGcEnvironment.h"

enum ePlanetSize : __int32
{
	EPlanetSize_Large = 0x0,
	EPlanetSize_Medium = 0x1,
	EPlanetSize_Small = 0x2,
	EPlanetSize_Moon = 0x3,
	EPlanetSize_NumTypes = 0x4,
};

enum eBiome : __int32
{
	EBiome_Lush = 0x0,
	EBiome_Toxic = 0x1,
	EBiome_Scorched = 0x2,
	EBiome_Radioactive = 0x3,
	EBiome_Frozen = 0x4,
	EBiome_Barren = 0x5,
	EBiome_Dead = 0x6,
	EBiome_Weird = 0x7,
	EBiome_Red = 0x8,
	EBiome_Green = 0x9,
	EBiome_Blue = 0xA,
	EBiome_Test = 0xB,
	EBiome_Swamp = 0xC,
	EBiome_Lava = 0xD,
	EBiome_Waterworld = 0xE,
	EBiome_All = 0xF,
	EBiome_NumTypes = 0x10,
};

enum eWeather : __int32
{
	EWeather_Clear = 0x0,
	EWeather_Dust = 0x1,
	EWeather_Humid = 0x2,
	EWeather_Snow = 0x3,
	EWeather_Toxic = 0x4,
	EWeather_Scorched = 0x5,
	EWeather_Radioactive = 0x6,
	EWeather_RedWeather = 0x7,
	EWeather_GreenWeather = 0x8,
	EWeather_BlueWeather = 0x9,
	EWeather_Swamp = 0xA,
	EWeather_Lava = 0xB,
	EWeather_Bubble = 0xC,
	EWeather_Weird = 0xD,
	EWeather_Fire = 0xE,
	EWeather_ClearCold = 0xF,
	EWeather_NumTypes = 0x10,
};

enum eWeatherIntensity : __int32
{
	EWeatherIntensity_Default = 0x0,
	EWeatherIntensity_Extreme = 0x1,
	EWeatherIntensity_NumTypes = 0x2,
};

enum eStormFrequency : __int32
{
	EStormFrequency_None = 0x0,
	EStormFrequency_Low = 0x1,
	EStormFrequency_High = 0x2,
	EStormFrequency_NumTypes = 0x3,
};

enum eAtmosphereType : __int32
{
	EAtmosphereType_None = 0x0,
	EAtmosphereType_Normal = 0x1,
	EAtmosphereType_NumTypes = 0x2,
};

enum eScreenFilter : __int32
{
	EScreenFilter_Default = 0x0,
	EScreenFilter_DefaultStorm = 0x1,
	EScreenFilter_Frozen = 0x2,
	EScreenFilter_FrozenStorm = 0x3,
	EScreenFilter_Toxic = 0x4,
	EScreenFilter_ToxicStorm = 0x5,
	EScreenFilter_Radioactive = 0x6,
	EScreenFilter_RadioactiveStorm = 0x7,
	EScreenFilter_Scorched = 0x8,
	EScreenFilter_ScorchedStorm = 0x9,
	EScreenFilter_Barren = 0xA,
	EScreenFilter_BarrenStorm = 0xB,
	EScreenFilter_Weird1 = 0xC,
	EScreenFilter_Weird2 = 0xD,
	EScreenFilter_Weird3 = 0xE,
	EScreenFilter_Weird4 = 0xF,
	EScreenFilter_Weird5 = 0x10,
	EScreenFilter_Weird6 = 0x11,
	EScreenFilter_Weird7 = 0x12,
	EScreenFilter_Weird8 = 0x13,
	EScreenFilter_Vintage = 0x14,
	EScreenFilter_HyperReal = 0x15,
	EScreenFilter_Desaturated = 0x16,
	EScreenFilter_Amber = 0x17,
	EScreenFilter_GBGreen = 0x18,
	EScreenFilter_Apocalypse = 0x19,
	EScreenFilter_Diffusion = 0x1A,
	EScreenFilter_Green = 0x1B,
	EScreenFilter_BlackAndWhite = 0x1C,
	EScreenFilter_Isolation = 0x1D,
	EScreenFilter_Sepia = 0x1E,
	EScreenFilter_Filmic = 0x1F,
	EScreenFilter_GBGrey = 0x20,
	EScreenFilter_Binoculars = 0x21,
	EScreenFilter_Surveying = 0x22,
	EScreenFilter_Nexus = 0x23,
	EScreenFilter_SpaceStation = 0x24,
	EScreenFilter_Freighter = 0x25,
	EScreenFilter_FreighterAbandoned = 0x26,
	EScreenFilter_Frigate = 0x27,
	EScreenFilter_MissionSurvey = 0x28,
	EScreenFilter_NewVibrant = 0x29,
	EScreenFilter_NewVibrantBright = 0x2A,
	EScreenFilter_NewVibrantWarm = 0x2B,
	EScreenFilter_NewVintageBright = 0x2C,
	EScreenFilter_NewVintageWash = 0x2D,
	EScreenFilter_Drama = 0x2E,
	EScreenFilter_MemoryBold = 0x2F,
	EScreenFilter_Memory = 0x30,
	EScreenFilter_MemoryWash = 0x31,
	EScreenFilter_Autumn = 0x32,
	EScreenFilter_AutumnFade = 0x33,
	EScreenFilter_ClassicBright = 0x34,
	EScreenFilter_Classic = 0x35,
	EScreenFilter_ClassicWash = 0x36,
	EScreenFilter_BlackAndWhiteDream = 0x37,
	EScreenFilter_ColourTouchB = 0x38,
	EScreenFilter_ColourTouchC = 0x39,
	EScreenFilter_NegativePrint = 0x3A,
	EScreenFilter_SepiaExtreme = 0x3B,
	EScreenFilter_Solarise = 0x3C,
	EScreenFilter_TwoToneStrong = 0x3D,
	EScreenFilter_TwoTone = 0x3E,
	EScreenFilter_Dramatic = 0x3F,
	EScreenFilter_Fuchsia = 0x40,
	EScreenFilter_Violet = 0x41,
	EScreenFilter_Cyan = 0x42,
	EScreenFilter_GreenNew = 0x43,
	EScreenFilter_AmberNew = 0x44,
	EScreenFilter_Red = 0x45,
	EScreenFilter_HueShiftA = 0x46,
	EScreenFilter_HueShiftB = 0x47,
	EScreenFilter_HueShiftC = 0x48,
	EScreenFilter_HueShiftD = 0x49,
	EScreenFilter_WarmStripe = 0x4A,
	EScreenFilter_NMSRetroA = 0x4B,
	EScreenFilter_NMSRetroB = 0x4C,
	EScreenFilter_NMSRetroC = 0x4D,
	EScreenFilter_NMSRetroD = 0x4E,
	EScreenFilter_NMSRetroE = 0x4F,
	EScreenFilter_NMSRetroF = 0x50,
	EScreenFilter_NMSRetroG = 0x51,
	EScreenFilter_NumTypes = 0x52,
};

enum eBiomeSubType : __int32
{
	EBiomeSubType_None = 0x0,
	EBiomeSubType_Standard = 0x1,
	EBiomeSubType_HighQuality = 0x2,
	EBiomeSubType_Structure = 0x3,
	EBiomeSubType_Beam = 0x4,
	EBiomeSubType_Hexagon = 0x5,
	EBiomeSubType_FractCube = 0x6,
	EBiomeSubType_Bubble = 0x7,
	EBiomeSubType_Shards = 0x8,
	EBiomeSubType_Contour = 0x9,
	EBiomeSubType_Shell = 0xA,
	EBiomeSubType_BoneSpire = 0xB,
	EBiomeSubType_WireCell = 0xC,
	EBiomeSubType_HydroGarden = 0xD,
	EBiomeSubType_HugePlant = 0xE,
	EBiomeSubType_HugeLush = 0xF,
	EBiomeSubType_HugeRing = 0x10,
	EBiomeSubType_HugeRock = 0x11,
	EBiomeSubType_HugeScorch = 0x12,
	EBiomeSubType_HugeToxic = 0x13,
	EBiomeSubType_Variant_A = 0x14,
	EBiomeSubType_Variant_B = 0x15,
	EBiomeSubType_Variant_C = 0x16,
	EBiomeSubType_Variant_D = 0x17,
	EBiomeSubType_Infested = 0x18,
	EBiomeSubType_Swamp = 0x19,
	EBiomeSubType_Lava = 0x1A,
	EBiomeSubType_NumTypes = 0x1B,
};


enum eRainbowType : __int32
{
	ERainbowType_Always = 0x0,
	ERainbowType_Occasional = 0x1,
	ERainbowType_Storm = 0x2,
	ERainbowType_None = 0x3,
	ERainbowType_NumTypes = 0x4,
};

struct cGcWeatherOptions
{
	eWeather meWeather;
};

struct cGcHeavyAirColourData
{
	cTkColour mColour1;
	cTkColour mColour2;
};

struct cGcScreenFilters
{
	eScreenFilter meScreenFilter;
};

struct cGcRainbowType
{
	eRainbowType meRainbowType;
};

struct __declspec(align(16)) cGcPlanetWeatherData
{
	cGcWeatherOptions mWeatherType;
	cGcPlanetHeavyAirData mHeavyAir;
	eWeatherIntensity meWeatherIntensity;
	eStormFrequency meStormFrequency;
	eAtmosphereType meAtmosphereType;
	int miDayColourIndex;
	int miDuskColourIndex;
	cGcScreenFilters mScreenFilter;
	cGcScreenFilters mStormScreenFilter;
	cGcRainbowType mRainbowType;
	int miNightColourIndex;
};

struct cGcPlanetHazardData
{
	cTkFixedArray<float, 5> mafTemperature;
	cTkFixedArray<float, 5> mafToxicity;
	cTkFixedArray<float, 5> mafRadiation;
	cTkFixedArray<float, 5> mafLifeSupportDrain;
};

struct __declspec(align(8)) cGcCreatureRoleDataTable
{
	cTkDynamicArray<cGcCreatureRoleData> maAvailableRoles;
	float mfMaxProportionFlying;
	bool mbHasSandWorms;
	float mfSandWormFrequency;
};

struct __declspec(align(16)) cGcPlanetGenerationWonderQuery
{
	float mfPlanetRadius;
	ePlanetSize mePlanetSize;
	float mfDeepestOcean;
	float mfHighestPeak;
	cGcPlanetWeatherData mWeather;
	cGcPlanetHazardData mHazard;
	bool mbHasSentinels;
	bool mbHasExtremeSentinels;
	eBiome meBiome;
	eBiomeSubType meBiomeSubType;
	bool mbHasWater;
	bool mbHasRings;
	bool mbHasCaves;
	bool mbIsPrime;
	cTkColour mMainColour;
	cTkColour mWaterColour;
	float mfCloudIntensity;
	cTkFixedString<128, char> macWeather;
	cGcCreatureRoleDataTable mCreatureRoles;
	cTkDynamicArray<cGcCreatureSpawnData> maCreatureSpawnData;
};

struct cGcPlanetMappingManager
{
	std::vector<MappingDataInternal, TkSTLAllocatorShim<MappingDataInternal> > mMappingInternal;
};

struct cGcBiomeType
{
	eBiome meBiome;
};

struct cGcScanEventTable
{
	cTkDynamicArray<cGcScanEventData> maEvents;
};

struct __declspec(align(8)) cGcWeatherHazardGiftManager
{
	std::vector<TkHandle, TkSTLAllocatorShim<TkHandle> > maGifts;
	std::vector<unsigned __int64, TkSTLAllocatorShim<unsigned __int64> > maGiftSpawnTimes;
	int miNextGiftToProcess;
};

struct cGcPlanetWeatherColourData
{
	cTkColour mSkyColour;
	cTkColour mSkyUpperColour;
	cTkColour mSkySolarColour;
	cTkColour mHorizonColour;
	cTkColour mSunColour;
	cTkColour mFogColour;
	cTkColour mHeightFogColour;
	cTkVector3 mSkyGradientSpeed;
	cTkColour mLightColour;
	cTkColour mCloudColour1;
	cTkColour mCloudColour2;
};

struct cGcSkyProperties
{
	float mfAtmosphereThickness;
	float mfHorizonMultiplier;
	float mfDuskHorizonMultiplier;
	float mfNightHorizonMultiplier;
	float mfHorizonFadeSpeed;
	float mfDayHorizonTightness;
	float mfSunSize;
	float mfSunStrength;
	float mfSunSurroundSize;
	float mfSunSurroundStrength;
	float mfUpperSkyFadeSpeed;
	float mfUpperSkyFadeOffset;
};

struct cTkPaletteTexture
{
	ePalette mePalette;
	eColourAlt meColourAlt;
};

struct cGcHeavyAirSettingValues
{
	float mfThickness;
	float mfSpeed;
	float mfAlpha1;
	float mfAlpha2;
	cTkPaletteTexture mColour1;
	cTkPaletteTexture mColour2;
};

struct cGcHeavyAirSetting
{
	cTkFixedArray<cGcHeavyAirSettingValues, 5> maSettings;
};

enum eVoxelType : __int32
{
	EVoxel_Air = 0x0,
	EVoxel_Base = 0x1,
	EVoxel_Rock = 0x2,
	EVoxel_Mountain = 0x3,
	EVoxel_Underwater = 0x4,
	EVoxel_Cave = 0x5,
	EVoxel_Dirt = 0x6,
	EVoxel_Liquid = 0x7,
	EVoxel_Substance_Res1 = 0x8,
	EVoxel_Substance_Res2 = 0x9,
	EVoxel_Substance_Res3 = 0xA,
	EVoxel_Num = 0xB,
};

struct cTkRegionHeightResult
{
	cTkVector3 mPosition;
	cTkVector3 mNormal;
	eVoxelType meMaterial;
	eVoxelType meSecondaryMaterial;
	float mfSlopeValue;
	float mfRatio;
};

enum eHazardValue : __int32
{
	EHazardValue_Ambient = 0x0,
	EHazardValue_Water = 0x1,
	EHazardValue_Cave = 0x2,
	EHazardValue_Storm = 0x3,
	EHazardValue_Night = 0x4,
	EHazardValue_NumTypes = 0x5,
};

enum eCollisionGroup : __int32
{
	ECollisionGroup_Normal = 0x1,
	ECollisionGroup_Water = 0x2,
	ECollisionGroup_Terrain = 0x4,
	ECollisionGroup_Substance = 0x8,
	ECollisionGroup_Asteroid = 0x10,
	ECollisionGroup_TerrainInstance = 0x20,
	ECollisionGroup_TerrainActivated = 0x40,
	ECollisionGroup_Player = 0x80,
	ECollisionGroup_Creature = 0x100,
	ECollisionGroup_Spaceship = 0x200,
	ECollisionGroup_Debris = 0x400,
	ECollisionGroup_Shield = 0x800,
	ECollisionGroup_Raycast = 0x1000,
	ECollisionGroup_NetworkPlayer = 0x2000,
	ECollisionGroup_NPCs = 0x4000,
	ECollisionGroup_Trigger = 0x8000,
	ECollisionGroup_NumTypes = 0x10,
};

enum eHazard : __int32
{
	EHazard_None = 0x0,
	EHazard_NoOxygen = 0x1,
	EHazard_ExtremeHeat = 0x2,
	EHazard_ExtremeCold = 0x3,
	EHazard_ToxicGas = 0x4,
	EHazard_Radiation = 0x5,
	EHazard_NumTypes = 0x6,
};

enum eBuildingDensity : __int32
{
	EBuildingDensity_Dead = 0x0,
	EBuildingDensity_Low = 0x1,
	EBuildingDensity_Mid = 0x2,
	EBuildingDensity_Full = 0x3,
	EBuildingDensity_Weird = 0x4,
	EBuildingDensity_HalfWeird = 0x5,
	EBuildingDensity_NumTypes = 0x6,
};

enum eTerrainSettings : __int32
{
	ETerrainSettings_FloatingIslands = 0x0,
	ETerrainSettings_GrandCanyon = 0x1,
	ETerrainSettings_MountainRavines = 0x2,
	ETerrainSettings_HugeArches = 0x3,
	ETerrainSettings_Alien = 0x4,
	ETerrainSettings_Craters = 0x5,
	ETerrainSettings_Caverns = 0x6,
	ETerrainSettings_Alpine = 0x7,
	ETerrainSettings_LilyPad = 0x8,
	ETerrainSettings_Desert = 0x9,
	ETerrainSettings_WaterworldPrime = 0xA,
	ETerrainSettings_FloatingIslandsPrime = 0xB,
	ETerrainSettings_GrandCanyonPrime = 0xC,
	ETerrainSettings_MountainRavinesPrime = 0xD,
	ETerrainSettings_HugeArchesPrime = 0xE,
	ETerrainSettings_AlienPrime = 0xF,
	ETerrainSettings_CratersPrime = 0x10,
	ETerrainSettings_CavernsPrime = 0x11,
	ETerrainSettings_AlpinePrime = 0x12,
	ETerrainSettings_LilyPadPrime = 0x13,
	ETerrainSettings_DesertPrime = 0x14,
	ETerrainSettings_NumTypes = 0x15,
};

struct __declspec(align(8)) PlanetGenerationQuery
{
	cTkFixedString<127, char> mName;
	eBiome meBiome;
	eBiomeSubType meBiomeSubType;
	TkID<128> mCommonSubstanceID;
	TkID<128> mUncommonSubstanceID;
	TkID<128> mRareSubstanceID;
	eBuildingDensity meBuildingDensity;
	std::vector<cGcPlanetObjectSpawnData, TkSTLAllocatorShim<cGcPlanetObjectSpawnData> > maDetailObjects;
	std::vector<cGcPlanetObjectSpawnData, TkSTLAllocatorShim<cGcPlanetObjectSpawnData> > maObjects;
	std::vector<cGcPlanetObjectSpawnData, TkSTLAllocatorShim<cGcPlanetObjectSpawnData> > maLandmarks;
	std::vector<cGcPlanetObjectSpawnData, TkSTLAllocatorShim<cGcPlanetObjectSpawnData> > maDistantObjects;
	std::vector<cGcPlanetDataResourceHint, TkSTLAllocatorShim<cGcPlanetDataResourceHint> > maResourceHints;
	bool mbHasWater;
	bool mbHasCaves;
	bool mbHasRings;
	bool mbHasSentinels;
	bool mbHasExtremeSentinels;
	bool mbHasExtremeWeather;
	bool mbHasExtremeHazard;
	bool mbIsPrime;
	eTerrainSettings meTerrainSettings;
	bool mbSuitableForCreatureDiscovery;
	bool mbSuitableForCreatureTaming;
	cTkColour mMainColour;
	cTkColour mWaterColour;
	float mfDiscoveryImageCloudIntensity;
	eWeather meWeather;
	eStormFrequency meStormFrequency;
};

enum ePlanetClass : __int32
{
	EPlanetClass_Default = 0x0,
	EPlanetClass_Initial = 0x1,
	EPlanetClass_InInitialSystem = 0x2,
	EPlanetClass_NumTypes = 0x3,
};

struct cGcPlanetClass
{
	ePlanetClass mePlanetClass;
};

struct cGcBiomeSubType
{
	eBiomeSubType meBiomeSubType;
};

struct cGcPlanetGenerationInputData
{
	cTkSeed mSeed;
	cGcGalaxyStarTypes mStar;
	cGcPlanetClass mClass;
	TkID<128> mCommonSubstance;
	TkID<128> mRareSubstance;
	cGcPlanetSize mPlanetSize;
	cGcBiomeType mBiome;
	cGcBiomeSubType mBiomeSubType;
	bool mbHasRings;
	bool mbForceContinents;
	bool mbInEmptySystem;
	bool mbInAbandonedSystem;
	bool mbInPirateSystem;
	bool mbPrime;
	int miRealityIndex;
};

enum eWeatherColourSet : __int32
{
	EWeatherColourSet_Common = 0x0,
	EWeatherColourSet_Rare = 0x1,
	EWeatherColourSet_NumTypes = 0x2,
};

struct cGcPlanetWeatherColourIndex
{
	eWeatherColourSet meWeatherColourSet;
	int miIndex;
};

struct __declspec(align(16)) cGcSpaceSkyProperties
{
	cGcPlanetWeatherColourIndex mColourIndex;
	cTkColour mPlanetSkyColour;
	cTkColour mPlanetHorizonColour;
	float mfSunStrength;
	float mfSunSize;
	float mfStarVisibility;
	float mfCenterPower;
	float mfAtmosphereThickness;
	float mfHorizonMultiplier;
	float mfHorizonFadeSpeed;
	float mfPlanetFogStrength;
	float mfSpaceFogStrength;
	float mfSpaceFogColourStrength;
	float mfSpaceFogColour2Strength;
	float mfSpaceFogMax;
	float mfSpaceFogPlanetMax;
	float mfNebulaFrequency;
	float mfNebulaSparseness;
	float mfNebulaWispyness;
	float mfNebulaWispyness1;
	float mfNebulaBrightness;
	float mfNebulaSeed;
	float mfNebulaTendrilStrength;
	float mfNebulaFogAmount;
	float mfNebulaCloudStrength;
	float mfNebulaCloudStrength1;
	float mfNebulaNoiseFrequency;
	float mfCloudNoiseFrequency;
	float mfNebulaTurbulenceStrength;
	float mfNebulaFBMStrength;
	float mfNebulaFBMStrength1;
	float mfNebulaDistortionStrength;
};

struct cGcPlanetLife
{
	eLifeSetting meLifeSetting;
};

enum eResourceLevel : __int32
{
	EResourceLevel_Low = 0x0,
	EResourceLevel_High = 0x1,
	EResourceLevel_NumTypes = 0x2,
};

struct cGcBuildingDensityLevels
{
	eBuildingDensity meBuildingDensity;
};

enum eCloudiness : __int32
{
	ECloudiness_CloudyWithClearSpells = 0x0,
	ECloudiness_ClearWithCloudySpells = 0x1,
	ECloudiness_NumTypes = 0x2,
};

struct cGcPlanetCloudProperties
{
	cTkSeed mSeed;
	float mfCoverage1;
	float mfCoverage2;
	float mfCoverage3;
	float mfOffset1;
	float mfOffset2;
	float mfOffset3;
	cTkVector2 mCoverExtremes;
	float mfRatio;
	float mfRateOfChange;
	float mfSecondaryRateOfChange;
	eCloudiness meCloudiness;
};

struct cGcPlanetWaterData
{
	int miColourIndex;
	float mfWaterStrength;
	float mfWaterColourStrength;
	float mfWaterMultiplyStrength;
	float mfWaterMultiplyMax;
	float mfWaterRoughness;
	float mfFresnelPower;
	float mfFresnelMin;
	float mfFresnelMax;
	float mfWave1Scale;
	float mfWave1Height;
	float mfWave1Speed;
	float mfWave2Scale;
	float mfWave2Height;
	float mfWave2Speed;
	float mfNormalMap1Scale;
	float mfNormalMap1Speed;
	float mfNormalMap2Scale;
	float mfNormalMap2Speed;
	float mfFoamFadeHeight;
	float mfFoam1Scale;
	float mfFoam1Speed;
	float mfFoam2Scale;
	float mfFoam2Speed;
	cGcPlanetHeavyAirData mHeavyAir;
};

enum eNoiseVoxelType : __int32
{
	ENoiseVoxelType_Base = 0x0,
	ENoiseVoxelType_Rock = 0x1,
	ENoiseVoxelType_Mountain = 0x2,
	ENoiseVoxelType_Sand = 0x3,
	ENoiseVoxelType_Cave = 0x4,
	ENoiseVoxelType_Substance_1 = 0x5,
	ENoiseVoxelType_Substance_2 = 0x6,
	ENoiseVoxelType_Substance_3 = 0x7,
	ENoiseVoxelType_RandomRock = 0x8,
	ENoiseVoxelType_RandomRockOrSubstance = 0x9,
	ENoiseVoxelType_NumTypes = 0xA,
};

struct cTkNoiseVoxelTypeEnum
{
	eNoiseVoxelType meNoiseVoxelType;
};

enum eDebugNoiseType : __int32
{
	EDebugNoiseType_Plane = 0x0,
	EDebugNoiseType_Check = 0x1,
	EDebugNoiseType_Sine = 0x2,
	EDebugNoiseType_Uber = 0x3,
	EDebugNoiseType_NumTypes = 0x4,
};

enum eOffsetType : __int32
{
	EOffsetType_Zero = 0x0,
	EOffsetType_Base = 0x1,
	EOffsetType_All = 0x2,
	EOffsetType_SeaLevel = 0x3,
	EOffsetType_NumTypes = 0x4,
};

struct cTkNoiseOffsetEnum
{
	eOffsetType meOffsetType;
};

enum eWaterFade : __int32
{
	EWaterFade_None = 0x0,
	EWaterFade_Above = 0x1,
	EWaterFade_Below = 0x2,
	EWaterFade_NumTypes = 0x3,
};

struct cTkNoiseUberLayerData
{
	cTkNoiseUberData mNoiseData;
	bool mbActive;
	int miMaximumLOD;
	bool mbSubtract;
	cTkNoiseVoxelTypeEnum mVoxelType;
	float mfHeight;
	float mfWidth;
	float mfRegionRatio;
	float mfRegionScale;
	float mfRegionGain;
	float mfSmoothRadius;
	float mfHeightOffset;
	cTkNoiseOffsetEnum mOffset;
	eWaterFade meWaterFade;
	float mfPlateauStratas;
	int miPlateauSharpness;
	float mfPlateauRegionSize;
	int miSeedOffset;
	float mfTileBlendMeters;
};

enum eNoiseGridType : __int32
{
	ENoiseGridType_Cube = 0x0,
	ENoiseGridType_Cone = 0x1,
	ENoiseGridType_Torus = 0x2,
	ENoiseGridType_Sphere = 0x3,
	ENoiseGridType_Cylinder = 0x4,
	ENoiseGridType_Capsule = 0x5,
	ENoiseGridType_Corridor = 0x6,
	ENoiseGridType_Pipe = 0x7,
	ENoiseGridType_Puck = 0x8,
	ENoiseGridType_SuperPrimitiveRandom = 0x9,
	ENoiseGridType_SuperFormula_01 = 0xA,
	ENoiseGridType_SuperFormula_02 = 0xB,
	ENoiseGridType_SuperFormula_03 = 0xC,
	ENoiseGridType_SuperFormula_04 = 0xD,
	ENoiseGridType_SuperFormula_05 = 0xE,
	ENoiseGridType_SuperFormula_06 = 0xF,
	ENoiseGridType_SuperFormula_07 = 0x10,
	ENoiseGridType_SuperFormula_08 = 0x11,
	ENoiseGridType_SuperFormulaRandom = 0x12,
	ENoiseGridType_SuperFormula = 0x13,
	ENoiseGridType_SuperPrimitive = 0x14,
	ENoiseGridType_File = 0x15,
	ENoiseGridType_NumTypes = 0x16,
};

struct cTkNoiseSuperFormulaData
{
	float mfForm_m;
	float mfForm_n1;
	float mfForm_n2;
	float mfForm_n3;
};

struct cTkNoiseSuperPrimitiveData
{
	float mfWidth;
	float mfHeight;
	float mfDepth;
	float mfThickness;
	float mfCornerRadiusXY;
	float mfCornerRadiusZ;
	float mfBottomRadiusOffset;
};

struct cTkNoiseGridData
{
	bool mbActive;
	int miMaximumLOD;
	bool mbSubtract;
	bool mbSwapZY;
	bool mbHemisphere;
	cTkNoiseVoxelTypeEnum mVoxelType;
	eNoiseGridType meNoiseGridType;
	cTkFixedString<128, char> macFilename;
	float mfMinWidth;
	float mfMaxWidth;
	float mfMinHeight;
	float mfMaxHeight;
	float mfMinHeightOffset;
	float mfMaxHeightOffset;
	float mfHeightOffset;
	cTkNoiseOffsetEnum mOffset;
	float mfRegionRatio;
	float mfRegionScale;
	cTkNoiseUberLayerData mTurbulenceNoiseLayer;
	float mfYaw;
	float mfPitch;
	float mfRoll;
	float mfVaryYaw;
	float mfVaryPitch;
	float mfVaryRoll;
	float mfSmoothRadius;
	int miSeedOffset;
	float mfRandomPrimitive;
	cTkNoiseSuperFormulaData mSuperFormula1;
	cTkNoiseSuperFormulaData mSuperFormula2;
	cTkNoiseSuperPrimitiveData mSuperPrimitive;
	float mfTileBlendMeters;
};

enum eFeatureType : __int32
{
	EFeatureType_Tube = 0x0,
	EFeatureType_Blob = 0x1,
	EFeatureType_NumTypes = 0x2,
};

struct cTkNoiseFeatureData
{
	bool mbActive;
	int miMaximumLOD;
	bool mbSubtract;
	bool mbTrench;
	cTkNoiseVoxelTypeEnum mVoxelType;
	eFeatureType meFeatureType;
	float mfWidth;
	float mfHeight;
	int miOctaves;
	float mfRegionSize;
	float mfRatio;
	float mfHeightVarianceAmplitude;
	float mfHeightVarianceFrequency;
	float mfHeightOffset;
	cTkNoiseOffsetEnum mOffset;
	float mfSmoothRadius;
	int miSeedOffset;
	float mfTileBlendMeters;
};

struct cTkNoiseCaveData
{
	cTkNoiseFeatureData mMouth;
	cTkNoiseFeatureData mTunnel;
};

struct __declspec(align(8)) cTkVoxelGeneratorData
{
	cTkSeed mBaseSeed;
	float mfSeaLevel;
	float mfBeachHeight;
	float mfNoSeaBaseLevel;
	cTkNoiseVoxelTypeEnum mBuildingVoxelType;
	cTkNoiseVoxelTypeEnum mResourceVoxelType;
	cTkFixedArray<cTkNoiseUberLayerData, 8> maNoiseLayers;
	cTkFixedArray<cTkNoiseGridData, 9> maGridLayers;
	cTkFixedArray<cTkNoiseFeatureData, 7> maFeatures;
	cTkFixedArray<cTkNoiseCaveData, 1> maCaves;
	float mfMinimumCaveDepth;
	float mfCaveRoofSmoothingDist;
	float mfMaximumSeaLevelCaveDepth;
	float mfBuildingTextureRadius;
	float mfBuildingSmoothingRadius;
	float mfBuildingSmoothingHeight;
	float mfWaterFadeInDistance;
};

struct __declspec(align(4)) cGcPlanetBuildingData
{
	cTkDynamicArray<cGcBuildingSpawnSlot> maBuildingSlots;
	cTkDynamicArray<cGcBuildingSpawnData> maBuildings;
	cTkDynamicArray<cGcBuildingOverrideData> maOverrideBuildings;
	float mfSpacing;
	float mfPlanetRadius;
	float mfVoronoiPointDivisions;
	int miVoronoiSectorSeed;
	int miVoronoiPointSeed;
	bool mbInitialBuildingsPlaced;
	bool mbIsPrime;
};

struct __declspec(align(4)) cGcTerrainControls
{
	cTkFixedArray<float, 8> mafNoiseLayers;
	cTkFixedArray<float, 9> mafGridLayers;
	cTkFixedArray<float, 7> mafFeatures;
	cTkFixedArray<float, 1> mafCaves;
	float mfWaterActiveFrequency;
	float mfHighWaterActiveFrequency;
	float mfRockTileFrequency;
	float mfSubstanceTileFrequency;
	bool mbForceContinentalNoise;
};

struct __declspec(align(8)) cGcPlanetGenerationIntermediateData
{
	cTkSeed mSeed;
	int miTerrainSettingIndex;
	cGcGalaxyStarTypes mStarType;
	cGcPlanetClass mClass;
	cGcPlanetSize mSize;
	cGcCreatureRoleDataTable mCreatureRoles;
	cGcTerrainControls mTerrain;
	cGcBiomeType mBiome;
	cGcBiomeSubType mBiomeSubType;
	cTkFixedString<128, char> macTerrainFile;
	cTkFixedString<128, char> macCreatureLandFile;
	cTkFixedString<128, char> macCreatureCaveFile;
	cTkFixedString<128, char> macCreatureWaterFile;
	cTkFixedString<128, char> macCreatureExtraWaterFile;
	cTkFixedString<128, char> macCreatureAirFile;
	cTkFixedString<128, char> macCreatureRobotFile;
	cTkDynamicArray<cGcExternalObjectListOptions> maExternalObjectLists;
	cTkDynamicArray<int> maiExternalObjectListIndices;
	bool mbPrime;
};

struct cGcPlanetInfo
{
	cTkFixedString<128, char> macPlanetDescription;
	cTkFixedString<128, char> macPlanetType;
	cTkFixedString<128, char> macWeather;
	cTkFixedString<128, char> macResources;
	cTkFixedString<128, char> macFlora;
	cTkFixedString<128, char> macFauna;
	cTkFixedString<128, char> macSentinels;
	bool mbIsWeatherExtreme;
	bool mbAreSentinelsExtreme;
	bool mbAreSentinelsModerate;
	// TODO: potential bool mbAreSentinelsCorrupt in the future?
};

enum eSentinelLevel : __int32
{
	ESentinelLevel_Low = 0x0,
	ESentinelLevel_Default = 0x1,
	ESentinelLevel_Aggressive = 0x2,
	ESentinelLevel_NumTypes = 0x3,
};

struct cGcPlanetSentinelData
{
	eSentinelLevel meSentinelLevel;
	int miMaxActiveDrones;
};

/* 22212 */
struct cGcPlanetRingData
{
	bool mbHasRings;
	cTkVector3 mUp;
	cTkColour mColour1;
	cTkColour mColour2;
	float mfLargeScale1;
	float mfLargeScale2;
	float mfMidScale;
	float mfSmallScale;
	float mfMidStrength;
	float mfOffset;
	float mfDepth;
	float mfAlphaMultiplier;
};

struct __declspec(align(16)) cGcPlanetData
{
	cTkFixedString<128, char> macName;
	cGcPlanetLife mLife;
	cGcPlanetLife mCreatureLife;
	cGcPlanetHazardData mHazard;
	eResourceLevel meResourceLevel;
	cGcBuildingDensityLevels mBuildingLevel;
	TkID<128> mCommonSubstanceID;
	TkID<128> mUncommonSubstanceID;
	TkID<128> mRareSubstanceID;
	cTkDynamicArray<cGcPlanetDataResourceHint> maExtraResourceHints;
	cGcPlanetColourData mColours;
	cTkFixedArray<cTkColour, 23> maTileColours;
	cGcPlanetWeatherData mWeather;
	cGcPlanetCloudProperties mClouds;
	cGcPlanetWaterData mWater;
	cTkFixedString<128, char> macTerrainFile;
	cTkVoxelGeneratorData mTerrain;
	int miTileTypeSet;
	cTkDynamicArray<int> maiTileTypeIndices;
	cGcEnvironmentSpawnData mSpawnData;
	cGcAlienRace mInhabitingRace;
	__declspec(align(8)) cGcPlanetBuildingData mBuildingData;
	cGcPlanetGenerationIntermediateData mGenerationData;
	cTkVector2 mSentinelTimer;
	cTkVector2 mFlybyTimer;
	cGcPlanetInfo mPlanetInfo;
	cGcPlanetSentinelData mSentinelData;
	cGcPlanetRingData mRings;
	bool mbInEmptySystem;
	bool mbInAbandonedSystem;
	float mfFuelMultiplier;
};
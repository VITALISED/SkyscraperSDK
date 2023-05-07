#pragma once

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
#pragma once
#include "pch.h"
#include "cTkTypes.h"

struct SystemSeed
{
	unsigned __int64 mu64Hash1;
	unsigned __int64 mu64Hash2;
};

struct __declspec(align(8)) cTkSeed
{
	unsigned __int64 mu64SeedValue;
	bool mbValid;
};

struct cGcMarkovAssembler
{
};

struct __declspec(align(8)) cGcNameGenerator
{
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>, 8, -1> > maSectorLocIDs[12];
	cGcMarkovAssembler mMarkovAssembler;
};

struct cGcExactResource
{
	cTkFixedString<128, char> macFilename;
	cTkSeed mGenerationSeed;
};

struct __declspec(align(8)) cGcInventoryLayout
{
	int miSlots;
	cTkSeed mSeed;
	int miLevel;
};

struct cTkProceduralTextureChosenOptionList
{
	cTkDynamicArray<cTkProceduralTextureChosenOptionSampler> maSamplers;
};

struct cGcResourceElement
{
	cTkFixedString<128, char> macFilename;
	cTkSmartResHandle mResHandle;
	cTkSeed mSeed;
	cTkFixedString<512, char> macAltId;
	cTkProceduralTextureChosenOptionList mProceduralTexture;
};

struct __declspec(align(16)) cGcColourPaletteData
{
	cTkFixedArray<cTkColour, 5> maColours;
	cTkFixedArray<int, 5> maiColourIndices;
};

struct cGcPlanetColourData
{
	cTkFixedArray<cGcColourPaletteData, 58> maPalettes;
};

struct __declspec(align(16)) CustomisationData
{
	cTkSeed mResourceSeed;
	std::vector<TkID<256>, TkSTLAllocatorShim<TkID<256>> > mDescriptors;
	cTkProceduralTextureChosenOptionList mTextureOptions;
	std::map<TkID<128>, float, std::less<TkID<128> >, std::allocator<std::pair<TkID<128> const, float> > > mBoneScales;
	bool mbUseLegacyColourPalettes;
	bool mbEditedColours;
	cGcPlanetColourData mEditColours;
	cGcPlanetColourData mFinalColours;
	float mfScale;
};

struct cGcResourceCustomisation
{
	CustomisationData mResourceCustomisation;
	TkID<128> mPresetName;
	std::vector<TkID<128>, TkSTLAllocatorShim<TkID<128>, 8, -1> > mDescriptorGroups;
	std::map<TkID<128>, TkID<256>, std::less<TkID<128> >, std::allocator<std::pair<TkID<128> const, TkID<256> > > > mChosenTextureOptions;
	TkID<256> mForcedTextureName;
	const ePalette kReplicatedPalettes[11];
	const eColourAlt kReplicatedColourAlts[3];
};

struct cTkPersonalRNG
{
	unsigned int mState0;
	unsigned int mState1;
};

enum eSpawnMode : __int32
{
	ESpawnMode_None = 0x0,
	ESpawnMode_UseSeed = 0x1,
	ESpawnMode_UseAltID = 0x2,
	ESpawnMode_NumTypes = 0x3,
};
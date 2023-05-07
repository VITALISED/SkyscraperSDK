#pragma once
#include "Planet.h"
#include "Discovery.h"
#include "cTkModelResourceRenderer.h"
#include "Raycast.h"

enum eCreatureType : __int32
{
	ECreatureType_None = 0x0,
	ECreatureType_Bird = 0x1,
	ECreatureType_FlyingLizard = 0x2,
	ECreatureType_FlyingSnake = 0x3,
	ECreatureType_Butterfly = 0x4,
	ECreatureType_FlyingBeetle = 0x5,
	ECreatureType_Beetle = 0x6,
	ECreatureType_Fish = 0x7,
	ECreatureType_Shark = 0x8,
	ECreatureType_Crab = 0x9,
	ECreatureType_Snake = 0xA,
	ECreatureType_Dino = 0xB,
	ECreatureType_Antelope = 0xC,
	ECreatureType_Rodent = 0xD,
	ECreatureType_Cat = 0xE,
	ECreatureType_Fiend = 0xF,
	ECreatureType_Drone = 0x10,
	ECreatureType_Quad = 0x11,
	ECreatureType_Walker = 0x12,
	ECreatureType_Predator = 0x13,
	ECreatureType_PlayerPredator = 0x14,
	ECreatureType_Prey = 0x15,
	ECreatureType_Passive = 0x16,
	ECreatureType_FishPredator = 0x17,
	ECreatureType_FishPrey = 0x18,
	ECreatureType_FiendFishSmall = 0x19,
	ECreatureType_FiendFishBig = 0x1A,
	ECreatureType_Jellyfish = 0x1B,
	ECreatureType_LandJellyfish = 0x1C,
	ECreatureType_RockCreature = 0x1D,
	ECreatureType_MiniFiend = 0x1E,
	ECreatureType_Floater = 0x1F,
	ECreatureType_Scuttler = 0x20,
	ECreatureType_Slug = 0x21,
	ECreatureType_MiniDrone = 0x22,
	ECreatureType_MiniRobo = 0x23,
	ECreatureType_SpaceFloater = 0x24,
	ECreatureType_Weird = 0x25,
	ECreatureType_SeaSnake = 0x26,
	ECreatureType_SandWorm = 0x27,
	ECreatureType_ProtoRoller = 0x28,
	ECreatureType_ProtoFlyer = 0x29,
	ECreatureType_ProtoDigger = 0x2A,
	ECreatureType_Plough = 0x2B,
	ECreatureType_Digger = 0x2C,
	ECreatureType_Drill = 0x2D,
	ECreatureType_Brainless = 0x2E,
	ECreatureType_Pet = 0x2F,
	ECreatureType_NumTypes = 0x30,
};

enum ePetTrait : __int32
{
	EPetTrait_Helpfulness = 0x0,
	EPetTrait_Aggression = 0x1,
	EPetTrait_Independence = 0x2,
	EPetTrait_NumTypes = 0x3,
};

enum ePetAction : __int32
{
	EPetAction_Tickle = 0x0,
	EPetAction_Treat = 0x1,
	EPetAction_Ride = 0x2,
	EPetAction_Customise = 0x3,
	EPetAction_Abandon = 0x4,
	EPetAction_LayEgg = 0x5,
	EPetAction_Adopt = 0x6,
	EPetAction_Milk = 0x7,
	EPetAction_HarvestSpecial = 0x8,
	EPetAction_NumTypes = 0x9,
};

enum eAge : __int32
{
	EAge_Regular = 0x0,
	EAge_Weird = 0x1,
	EAge_NumTypes = 0x2,
};

enum eRarity
{
	ERarity_Common = 0x0,
	ERarity_Uncommon = 0x1,
	ERarity_Rare = 0x2,
	ERarity_NumTypes = 0x3,
	ERarity_Unspecified = 0xFFFFFFFF,
};

struct cGcRarity
{
	eRarity meRarity;
};

struct cGcCreatureInfo
{
	eAge meAge;
	cTkFixedString<128, char> macGender1;
	cTkFixedString<128, char> macGender2;
	cTkFixedString<128, char> macTemperament;
	cTkFixedString<128, char> macDiet;
	cTkFixedString<128, char> macWeight1;
	cTkFixedString<128, char> macHeight1;
	cTkFixedString<128, char> macWeight2;
	cTkFixedString<128, char> macHeight2;
	float mfWeight1;
	float mfHeight1;
	float mfWeight2;
	float mfHeight2;
	cTkFixedString<128, char> macNotes;
	cGcRarity mRarity;
	TkID<256> mBiomeDesc;
	TkID<256> mTempermentDesc;
	TkID<256> mDietDesc;
	TkID<256> mNotesDesc;
};

struct cGcCreatureTypes
{
	eCreatureType meCreatureType;
};

struct __declspec(align(16)) sOwnedCreatureInfo
{
	enum eLoadState : __int32
	{
		ELoadState_Complete = 0x0,
		ELoadState_LoadResource = 0x1,
		ELoadState_WaitForResource = 0x2,
		ELoadState_GetStats = 0x3,
	};

	enum eEggSenderNameState : __int32
	{
		EEggSenderNameState_Unchecked = 0x0,
		EEggSenderNameState_Processing = 0x1,
		EEggSenderNameState_Done = 0x2,
	};

	cGcPlanetColourData mColourPalette;
	TkID<128> mCreatureID;
	unsigned __int64 muFileHash;
	bool mbRequestStarted;
	sOwnedCreatureInfo::eLoadState meLoadState;
	sOwnedCreatureInfo::eEggSenderNameState meEggSenderNameState;
	cTkResourceDescriptor mDescriptor;
	unsigned __int64 mSpeciesSeed;
	unsigned __int64 mGenusSeed;
	TkID<256> mCustomSpeciesName;
	bool mbPredator;
	unsigned __int64 mPackedUA;
	cTkSeed mColourBaseSeed;
	cTkSeed mBoneScaleSeed;
	eBiome meBiome;
	eCreatureType meCreatureType;
	unsigned __int64 muBirthTime;
	unsigned __int64 muLastEggTime;
	unsigned __int64 muLastTrustIncreaseTime;
	unsigned __int64 muLastTrustDecreaseTime;
	cTkFixedString<32, char> mProcName;
	cTkFixedString<32, char> mCustomName;
	bool mbHasFur;
	cGcDiscoveryOwner mSenderData;
	float mfScale;
	float mfHeight;
	float mfWeight;
	float mfTrust;
	float mafTraits[3];
	float mafMoods[2];
	cTkSmoothCD<float> mafSmoothedMoods[2];
	cTkSmartResHandle mResource;
	cGcProceduralTextureManager::TaskContext* mpTC;
	cTkModelResourceRenderer mThumbnailRenderer;
	cTkModelResourceRenderer mLargeThumbnailRenderer;
	bool mbReadyToLayEgg;
	bool mbEggModified;
	bool mbAllowUnmodifiedReroll;
	bool mbHasBeenSummoned;
};

struct cGcPetData
{
	float mfScale;
	TkID<128> mCreatureID;
	cTkDynamicArray<TkID<256> > maDescriptors;
	cTkSeed mCreatureSeed;
	cTkSeed mCreatureSecondarySeed;
	unsigned __int64 mu64SpeciesSeed;
	unsigned __int64 mu64GenusSeed;
	TkID<256> mCustomSpeciesName;
	bool mbPredator;
	unsigned __int64 mu64UA;
	bool mbAllowUnmodifiedReroll;
	cTkSeed mColourBaseSeed;
	cTkSeed mBoneScaleSeed;
	bool mbHasFur;
	cGcBiomeType mBiome;
	cGcCreatureTypes mCreatureType;
	unsigned __int64 mu64BirthTime;
	unsigned __int64 mu64LastEggTime;
	unsigned __int64 mu64LastTrustIncreaseTime;
	unsigned __int64 mu64LastTrustDecreaseTime;
	bool mbEggModified;
	bool mbHasBeenSummoned;
	cTkFixedString<32, char> macCustomName;
	float mfTrust;
	cGcDiscoveryOwner mSenderData;
	cTkFixedArray<float, 3> mafTraits;
	cTkFixedArray<float, 2> mafMoods;
};

struct cGcPlayerCreatureOwnership
{
	sOwnedCreatureInfo maCreatures[18];
	sOwnedCreatureInfo maEggs[18];
	cGcResourceCustomisation maAccessoryCustomisation[18][3];
	bool mabUnlockedSlots[18];
	TkHandle mThumbnailsGroup;
	int miSummonedIndex;
	TkHandle mGroupRootNode;
	cTkMatrix34 mPlacementMatrix;
	cGcPlacementArc mPlacementArc;
	int miPreviewCreature;
	cGcScanEffectData mPreviewScanData;
	cTkColour mPreviewColour;
	float mfPreviewFirstActiveTime;
	float mfPreviewLastActiveTime;
	TkHandle mPreviewNode;
	bool mbClearPreview;
	bool mbShowEmoteArc;
	TkID<128> mEmoteArcID;
	float mfLastRewardActionTime;
	ePetAction meLastRewardActionType;
	cTkSmartResHandle mPetEggResource;
	cTkSmartResHandle mPetHatchEggResource;
	cTkSmartResHandle mLightMaterial;
	cGcPetEggSpeciesOverrideTable* mpPetEggSpeciesOverrideTable;
};
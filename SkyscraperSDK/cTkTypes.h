#pragma once
#include "pch.h"

template <class Type>
struct TkSTLAllocatorShim {
	typedef std::string value_type;
};

template <unsigned int size, typename T>
struct cTkFixedString
{
	//template<unsigned int size, typename T>
	cTkFixedString(const char* buff)
	{
		strcpy_s(macBuffer, size, buff);
	}

	T macBuffer[size];
};

template <typename T>
struct cTkUserIdBase
{
	T mID;
};

template <unsigned int size>
union TkID
{
	char mChars[size / 8];
	unsigned __int64 mUInt64[size / 32];
};

struct cTkVector2
{
	float mfX;
	float mfY;
};

// TODO: un-simd-ification would be cool
struct cTkVector4
{
	__m128 mVal;
};

struct cTkColour : cTkVector4 { 
	cTkColour(__m128 _mVal)
	{
		mVal = _mVal;
	}
};

template <typename T>
struct cTkDynamicArray
{
	union cTkDynamicArrayPointer
	{
		T* mpaArray;
		__int64 miOffset;
	};

	cTkDynamicArray::cTkDynamicArrayPointer mArray;
};

template <typename T, unsigned int size>
struct cTkFixedArray
{
	T maArray[size];
};

struct cTkBBox2d
{
	cTkVector2 mMin;
	cTkVector2 mMax;
};
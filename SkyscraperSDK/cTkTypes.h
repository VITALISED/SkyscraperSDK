#pragma once
#include <xmmintrin.h>
#include <string>

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


// thanks IDA this really looks like a Vector4
//union __m128
//{
//	float m128_f32[4];
//	unsigned __int64 m128_u64[2];
//	char m128_i8[16];
//	__int16 m128_i16[8];
//	int m128_i32[4];
//	__int64 m128_i64[2];
//	unsigned __int8 m128_u8[16];
//	unsigned __int16 m128_u16[8];
//	unsigned int m128_u32[4];
//};

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
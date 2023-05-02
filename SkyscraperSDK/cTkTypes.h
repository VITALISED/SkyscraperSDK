#pragma once

template<typename T>
struct TkSTLAllocatorShim;/*<cTkUserIdBase<cTkFixedString<64, char> >, 1, -1>*/

template <unsigned int size, typename T>
struct cTkFixedString
{
	T macBuffer[size];
};

template <typename T>
struct cTkUserIdBase
{
	T mID;
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

struct cTkColour : cTkVector4 { };

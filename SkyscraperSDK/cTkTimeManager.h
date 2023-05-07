#pragma once

struct cTkTimeManager
{
	struct __declspec(align(8)) UTCFractional
	{
		unsigned __int64 muSeconds;
		float mfFractional;
	};
};
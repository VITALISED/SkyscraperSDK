#pragma once

struct cGcRegionHotspots
{
	enum eHotspotCategory
	{
		EHotspotCategory_Invalid = 0xFFFFFFFF,
		EHotspotCategory_Power = 0x0,
		EHotspotCategory_Mineral = 0x1,
		EHotspotCategory_Gas = 0x2,
	};
};
#pragma once
#include "pch.h"
#include "cTkTypes.h"

struct cGcTradingSupplyBuffer
{
	int miDebugCurrentPage;
	int miCurrentIndex;
	std::vector<cGcTradingSupplyData, TkSTLAllocatorShim<cGcTradingSupplyData> > maTradingData;
};

struct cGcTradeData
{
	cTkDynamicArray<TkID<128> > maAlwaysPresentProducts;
	cTkDynamicArray<TkID<128> > maAlwaysPresentSubstances;
	cTkDynamicArray<TkID<128> > maOptionalProducts;
	cTkDynamicArray<TkID<128> > maOptionalSubstances;
	int miMinItemsForSale;
	int miMaxItemsForSale;
	float mfPercentageOfItemsAreProducts;
	float mfBuyPriceIncreaseRedThreshold;
	float mfBuyPriceDecreaseGreenThreshold;
	float mfSellPriceIncreaseGreenThreshold;
	float mfSellPriceDecreaseRedThreshold;
	bool mbShowSeasonRewards;
	cTkFixedArray<int, 4> maiMinAmountOfProductAvailable;
	cTkFixedArray<int, 4> maiMaxAmountOfProductAvailable;
	cTkFixedArray<int, 4> maiMinAmountOfSubstanceAvailable;
	cTkFixedArray<int, 4> maiMaxAmountOfSubstanceAvailable;
	cTkFixedArray<int, 4> maiMinExtraSystemProducts;
	cTkFixedArray<int, 4> maiMaxExtraSystemProducts;
	cTkFixedArray<float, 4> mafTradeProductsPriceImprovements;
};
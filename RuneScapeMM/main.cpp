//Jack Simpson
#pragma once
#include <cstdio>
#include <math.h>
#include <iostream>
#include "AvellanedaStoikov.h"
#include "Volatility.h"


// The Avellaneda-Stoikov model
// https://quant.stackexchange.com/questions/36400/avellaneda-stoikov-market-making-model 

// Volaltilty Handling
// Historical Volatility Based on https://oldschool.runescape.wiki/w/RuneScape:Real-time_Prices#5-minute_prices
// Max 5 minute data 365 data points per api call?

// Using Sockets (Client-Server Approach) for data transfer (RAII style baby)


int main()
{
	std::vector<double> prices = { 100, 200, 300, 400, 500, 100, 200, 300, 500, 600 };
	std::cout << Daily_Volatility(prices) << std::endl;
	return 0;
}


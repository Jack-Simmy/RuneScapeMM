#pragma once
#include "AvellanedaStoikov.h"

double reservation_price_ask(double P, int Q, double gamma, double sigma, float t)
{
	//Mid-Price (P): This is the midpoint of the current bid and ask prices in the market.
	//Inventory Level (Q): This is the current inventory of the market maker.
	//Risk Aversion Parameter (γ): This represents how risk - averse the market maker is
	//Market Volatility (σ): This is the volatility of the security's price.
	//Time Decay (t): This is the normalized time to the end of the trading horizon 1
	return P + (1 - 2 * Q) * ((gamma * pow(sigma, 2) * (1 - t)) / 2);
}

double reservation_price_bid(double P, int Q, double gamma, double sigma, float t)
{
	//Mid-Price (P): This is the midpoint of the current bid and ask prices in the market.
	//Inventory Level (Q): This is the current inventory of the market maker.
	//Risk Aversion Parameter (γ): This represents how risk - averse the market maker is
	//Market Volatility (σ): This is the volatility of the security's price.
	//Time Decay (t): This is the normalized time to the end of the trading horizon 1
	return P + (-1 - (2 * Q)) * ((gamma * pow(sigma, 2) * (1 - t)) / 2);
}

double Avellaneda_StoiKov_Spread(double gamma, double sigma, float t, float k)
{
	//γ (Gamma): This represents the market maker's risk aversion. A higher value of gamma indicates that the market maker is more risk-averse, and thus will set a wider spread to compensate for the increased perceived risk.
	//σ 2(Sigma squared) : This is the variance of the asset's return, representing the asset's price volatility.Higher volatility leads to a wider spread as the market maker compensates for the increased risk of price movements.
	//T: This represents the time horizon over which the market maker seeks to maximize their expected utility. A longer time horizon may lead to a different approach in setting the spread compared to a shorter one.
	//k: This is the market depth parameter.It indicates how sensitive the market is to the trades of the market maker.A higher value ofk means the market can absorb larger trades without significantly impacting the asset price.
	//ln(1 + γ / k) : This term is derived from the market depth parameter k and the risk aversion parameter γ.It reflects the market maker's expected utility from trading, considering both their risk aversion and the market's ability to absorb trades.
	return (gamma * pow(sigma, 2) * (1 - t)) + (2 / gamma) * (log(1 + gamma / k));
}

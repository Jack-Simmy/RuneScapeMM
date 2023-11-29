#pragma once
#include <math.h>
#include <cstdio>

double reservation_price_ask(double P, int Q, double gamma, double sigma, float t);
double reservation_price_bid(double P, int Q, double gamma, double sigma, float t);
double Avellaneda_StoiKov_Spread(double gamma, double sigma, float t, float k);

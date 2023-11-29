#include "Volatility.h"

double Daily_Volatility(const std::vector<double>& prices)
{
    
    if (prices.size() < 2)
    {
        throw std::runtime_error("Not enough data points to calculate historical volatility.");
    }
    // create a vector for log normal Returns
    std::vector<double> log_Returns;
    
    //loops over prices and calulates Log Returns ln(Pt/ Pt-1)
    for (size_t i = 1; i < prices.size(); ++i)
    {
        if (prices[i-1] == 0)
        {
            throw std::runtime_error("Encountered a price of zero, cannot compute log return.");
        }
        //pushes our log returns into out vector 
        log_Returns.push_back(log(prices[i] / prices[i - 1]));
    }

    //compute mean of log return
    double sum{};
    for (double lr : log_Returns)
    {
        sum += lr;
    }
    double mean = sum / log_Returns.size();

    //computes the variance
    double variance{};
    for (double lr : log_Returns)
    {
        variance += pow(lr - mean, 2);
    }

    double  standard_Deviation = sqrt(variance);

    double Scaled_Volatility = standard_Deviation * sqrt(288); //volatility from a 5 minutes daily
    
    return Scaled_Volatility;
}

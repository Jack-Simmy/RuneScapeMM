#pragma once
#include "KalmanPricePrediction.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Eigen/Dense>

std::vector<Eigen::VectorXd> readDataFromFile(const std::string& filename) {
    std::vector<Eigen::VectorXd> data;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double avgHighPrice, highPriceVolume;
        char delimiter;

        if (ss >> avgHighPrice >> delimiter >> highPriceVolume && delimiter == ',') {
            Eigen::VectorXd dataPoint(2);
            dataPoint << avgHighPrice, highPriceVolume;
            data.push_back(dataPoint);
        }
        else {
            // Handle parsing error if necessary
            std::cerr << "Warning: Line format error -> " << line << std::endl;
        }
    }

    return data;
}


Eigen::VectorXd processAndPredict(KalmanFilter& kf, const std::vector<Eigen::VectorXd>& historicalData)
{
    for (const auto& measurement : historicalData)
    {
        kf.predict();
        kf.update(measurement);
    }

    return kf.state;
}

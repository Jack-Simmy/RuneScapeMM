#pragma once
#include "KalmanFilter.h"
#include <vector>

Eigen::VectorXd processAndPredict(KalmanFilter& kf, const std::vector<Eigen::VectorXd>& historicalData);
std::vector<Eigen::VectorXd> readDataFromFile(const std::string& filename);

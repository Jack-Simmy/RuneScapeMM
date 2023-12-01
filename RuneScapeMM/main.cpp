//Jack Simpson
#pragma once
#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <Eigen/Dense> //lfg matrix calculations now added
#include "AvellanedaStoikov.h"
#include "Volatility.h"
#include "KalmanFilter.h"
#include "KalmanPricePrediction.h"


/*
Write the code to continiously update the kalman filter based on the txt file with all the prices and data 

*/
int main()
{
	std::string filePath = "C:\\Users\\slimr\\Downloads\\1511_20231130.txt";

	// Read the data from the file
	std::vector<Eigen::VectorXd> historicalData = readDataFromFile(filePath);

    // Initialize Kalman Filter with 2 state variables (high price and volume)
    int stateSize = 2;
    int measurementSize = 2;
    KalmanFilter kf(stateSize, measurementSize);

    // State Transition Matrix (F)
    kf.F = Eigen::MatrixXd::Identity(stateSize, stateSize);

    // Measurement Matrix (H)
    kf.H = Eigen::MatrixXd::Identity(measurementSize, stateSize);

    // Process Noise Covariance (Q)
    kf.Q = Eigen::MatrixXd::Identity(stateSize, stateSize) * 0.01;

    // Measurement Noise Covariance (R)
    kf.R = Eigen::MatrixXd::Identity(measurementSize, measurementSize) * 0.01;

    // Check if historicalData is not empty to avoid accessing an empty vector
    if (!historicalData.empty()) {
        // Set initial kf.state to the first data point in historicalData
        kf.state = historicalData[0];
    }
    else {
        std::cerr << "Error: historicalData is empty." << std::endl;
        return 1;  // Or handle the error as appropriate
    }

    // Initial State Covariance (P)
    kf.P = Eigen::MatrixXd::Identity(stateSize, stateSize);

    // Process the data and get the final prediction
    Eigen::VectorXd finalPrediction = processAndPredict(kf, historicalData);

    // Output the result
    std::cout << "Final Prediction:\n" << finalPrediction << std::endl;
	


	return 0;
}
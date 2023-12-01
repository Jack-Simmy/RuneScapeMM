#pragma once
#include <Eigen/Dense>
#include <iostream>

class KalmanFilter {
public:
    Eigen::VectorXd state; // State vector
    Eigen::MatrixXd P;     // State covariance matrix
    Eigen::MatrixXd Q;     // Process noise covariance matrix
    Eigen::MatrixXd R;     // Measurement noise covariance matrix
    Eigen::MatrixXd H;     // Measurement matrix
    Eigen::MatrixXd F;     // State transition matrix

    KalmanFilter(int state_dim, int measure_dim) {
        state = Eigen::VectorXd(state_dim);
        P = Eigen::MatrixXd::Identity(state_dim, state_dim);
        Q = Eigen::MatrixXd::Identity(state_dim, state_dim);
        R = Eigen::MatrixXd::Identity(measure_dim, measure_dim);
        H = Eigen::MatrixXd::Zero(measure_dim, state_dim);
        F = Eigen::MatrixXd::Identity(state_dim, state_dim);
    }

    void predict() {
        state = F * state;
        P = F * P * F.transpose() + Q;
    }

    void update(const Eigen::VectorXd& measurement) {
        Eigen::MatrixXd S = H * P * H.transpose() + R;
        Eigen::MatrixXd K = P * H.transpose() * S.inverse();
        state = state + K * (measurement - H * state);
        int size = state.size();
        P = (Eigen::MatrixXd::Identity(size, size) - K * H) * P;
    }
};

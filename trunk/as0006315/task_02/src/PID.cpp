/**
 * @file PID.cpp
 *
 * @brief The file contains the implementation of the PID controller.
 *
 * @author Loginov Gleb
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#include "PID.h"
#include "models.h"

/**
 * @brief The method to calculate the control signal by PID.
 *
 * The method calculates the control signal by PID using the formulas:
 * Uk = Uk_1 + delta_Uk
 * delta_Uk = q0 * e0 + q1 * e1 + q2 * e2
 * q0 = K * (1 + TD / T0)
 * q1 = -K * (1 + 2 * TD / T0 - T0 / T)
 * q2 = K * TD / T0
 *
 * @param w The desired value of the output signal.
 * @param T0 The time step.
 * @param temp The vector of output signals.
 */
void PID::calculate(const double& w, const double& T0, const std::vector<double>& temp) {
    double q0;
    double q1;
    double q2;
    double e0;
    double e1 = 0;
    double e2 = 0;
    double Uk;
    double delta_Uk;
    double Uk_1 = 0;
    for (const auto& y0 : temp) {
        e0 = w - y0;
        q0 = K * (1 + TD / T0);
        q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        q2 = K * TD / T0;
        delta_Uk = q0 * e0 + q1 * e1 + q2 * e2;
        Uk = Uk_1 + delta_Uk;
        Uk_1 = Uk;
        e2 = e1;
        e1 = e0;
        res_liner.push_back({e0, y0, Uk});
    }
}

/**
 * @brief The method to get the control signals.
 *
 * The method returns the vector of control signals.
 *
 * @return The vector of control signals.
 */
std::vector<std::vector<double>> PID::getControlSignals() const {
    return this->res_liner;
}


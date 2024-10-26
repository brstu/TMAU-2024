/**
 * @file PID.h
 *
 * @brief The header file contains the definition of the PID controller.
 *
 * @author Loginov Gleb
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#ifndef PID_S
#define PID_S

#include "models.h"
#include <vector>

/**
 * @brief The class implements the PID controller.
 *
 * The class contains the method to calculate the control signal by PID.
 */
class PID {
private:
    /// The coefficient K in the PID controller.
    const double K = 10;
    /// The coefficient T in the PID controller.
    const double T = 0.1;
    /// The coefficient TD in the PID controller.
    const double TD = 50;
    /// The vector of control signals.
    std::vector<std::vector<double>> res_liner;

public:
    /**
     * @brief The method to calculate the control signal by PID.
     *
     * @param error The vector of errors.
     */
    void calculate(const double& w, const double& T0, const std::vector <double>& temps_linear);
    /**
     * @brief The method to get the control signals.
     *
     * @return The vector of control signals.
     */
    std::vector<std::vector<double>> getControlSignals() const;
};

#endif //PID_S

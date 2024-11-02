/**
 * @file main.cpp
 * @brief A simulation program for temperature regulation using PID control.
 * 
 * This program models two types of temperature control systems: a simple linear model
 * and a more complex nonlinear model. It simulates how these models respond to a PID
 * controller attempting to reach a target temperature.
 *
 * @section class_diagram Class Diagram
 * 
 * ```
 * +-----------------+         +--------------+
 * | TemperatureModel|<------- | SimpleModel  |
 * +-----------------+         +--------------+
 * | +calculate_temperature()   |
 * +-----------------+         +--------------+
 * | TemperatureModel|<------- | ComplexModel |
 * +-----------------+         +--------------+
 * | +calculate_temperature()   |
 * +-----------------+
 * | PIDRegulator   |
 * +-----------------+
 * | +Regulate()     |
 * +-----------------+
 * ```
 * 
 * The program consists of the following classes:
 * 
 * - `TemperatureModel`: An abstract base class that defines the interface for temperature models.
 * - `SimpleModel`: A concrete implementation of the `TemperatureModel` that uses a linear relationship.
 * - `ComplexModel`: A concrete implementation of the `TemperatureModel` that uses a nonlinear relationship.
 * - `PIDRegulator`: A class that implements a PID control algorithm to regulate the temperature.
 * 
 * @section usage Usage
 * 
 * Users are prompted to input parameters for both the SimpleModel and ComplexModel.
 * After inputting the parameters, the program will simulate the temperature regulation process 
 * for each model and print the results to the console.
 */

#include <iostream>
#include <cmath>

/**
 * @brief Abstract class for temperature models.
 */
class TemperatureModel {
public:
    /**
     * @brief Calculates the resulting temperature based on the current temperature and input signal.
     * @param current_temp The current temperature.
     * @param input_signal The control output from the PID controller.
     * @return The calculated temperature.
     */
    virtual double calculate_temperature(double current_temp, double input_signal) = 0;
    virtual ~TemperatureModel() = default;
};

/**
 * @brief Simple linear temperature model.
 */
class SimpleModel : public TemperatureModel {
private:
    double coefficient_a; ///< Coefficient influencing the current temperature
    double coefficient_b; ///< Coefficient influencing the input signal
public:
    /**
     * @brief Constructs a SimpleModel with specified coefficients.
     * @param a Coefficient for current temperature
     * @param b Coefficient for input signal
     */
    SimpleModel(double a, double b) : coefficient_a(a), coefficient_b(b) {}

    /**
     * @brief Calculates the temperature using a linear equation.
     * @param current_temp The current temperature.
     * @param input_signal The control output.
     * @return The computed temperature.
     */
    double calculate_temperature(double current_temp, double input_signal) final {
        return coefficient_a * current_temp + coefficient_b * input_signal;
    }

    ~SimpleModel() override = default;
};

/**
 * @brief Complex nonlinear temperature model.
 */
class ComplexModel : public TemperatureModel {
private:
    double coefficient_a; ///< Coefficient influencing the current temperature
    double coefficient_b; ///< Coefficient influencing the square of the last current temperature
    double coefficient_c; ///< Coefficient influencing the input signal
    double coefficient_d; ///< Coefficient influencing the sine of the last input signal
    double last_current_temp = 0;  ///< Previous current temperature
    double last_input_signal = 0;   ///< Previous input signal
public:
    /**
     * @brief Constructs a ComplexModel with specified coefficients.
     * @param a Coefficient for current temperature
     * @param b Coefficient for last current temperature
     * @param c Coefficient for input signal
     * @param d Coefficient for sine function of last input signal
     */
    ComplexModel(double a, double b, double c, double d) :
        coefficient_a(a), coefficient_b(b), coefficient_c(c), coefficient_d(d) {}

    /**
     * @brief Calculates the temperature using a nonlinear equation.
     * @param current_temp The current temperature.
     * @param input_signal The control output.
     * @return The computed temperature.
     */
    double calculate_temperature(double current_temp, double input_signal) final {
        double temp = coefficient_a * current_temp - coefficient_b * pow(last_current_temp, 2) + coefficient_c * input_signal + coefficient_d * sin(last_input_signal);
        last_current_temp = current_temp;
        last_input_signal = input_signal;
        return temp;
    }

    ~ComplexModel() override = default;
};

/**
 * @brief PID regulator for temperature control.
 */
class PIDRegulator {
private:
    const double gain = 0.1;     ///< Proportional gain
    const double integral_time = 10;   ///< Integral time constant
    const double derivative_time = 80; ///< Derivative time constant
    const double time_step = 50;       ///< Time step for simulation
    const double total_time = 30;       ///< Total simulation time
    double control_output = 0; ///< Control output value

    /**
     * @brief Computes the control output using PID algorithm.
     * @param error Current error
     * @param previous_error Previous error
     * @param previous_error2 Second previous error
     * @return The computed control output.
     */
    double compute_control_output(double error, double previous_error, double previous_error2) {
        double q0 = gain * (1 + derivative_time / time_step);
        double q1 = -gain * (1 + 2 * derivative_time / time_step - time_step / integral_time);
        double q2 = gain * derivative_time / time_step;
        control_output += q0 * error + q1 * previous_error + q2 * previous_error2;
        return control_output;
    }

public:
    /**
     * @brief Regulates the temperature to reach the target temperature.
     * @param target_temp The desired target temperature.
     * @param initial_temp The initial temperature.
     * @param model The temperature model used for regulation.
     */
    void Regulate(double target_temp, double initial_temp, TemperatureModel& model) {
        double error_prev = 0;
        double error_prev2 = 0;
        double current_temp = initial_temp;
        for (int time = 1; time <= total_time; time++) {
            double error = target_temp - current_temp;
            control_output = compute_control_output(error, error_prev, error_prev2);
            current_temp = model.calculate_temperature(initial_temp, control_output);
            std::cout << "Error = " << error << ", Current Temp = " << current_temp << ", Control Output = " << control_output << std::endl;
            error_prev2 = error_prev;
            error_prev = error;
        }
        control_output = 0;
    }
};

/**
 * @brief Input parameters for the models.
 * @param a Coefficient a for the model.
 * @param b Coefficient b for the model.
 * @param c Coefficient c for the model (used for ComplexModel).
 * @param d Coefficient d for the model (used for ComplexModel).
 * @param is_complex Indicates whether to input parameters for the ComplexModel.
 */
void input_parameters(double& a, double& b, double& c, double& d, bool is_complex) {
    std::cout << "Enter parameter a: "; std::cin >> a;
    std::cout << "Enter parameter b: "; std::cin >> b;

    if (is_complex) {
        std::cout << "Enter parameter c: "; std::cin >> c;
        std::cout << "Enter parameter d: "; std::cin >> d;
    }
}

/**
 * @brief Main function to run the temperature regulation simulation.
 * @return Exit status of the program.
 */
int main() {
    const double target_temperature = 8;  ///< Desired temperature to reach
    const double initial_temperature = 3;  ///< Initial temperature of the system
    double a, b, c, d;

    std::cout << "---Input parameters for SimpleModel---" << std::endl;
    input_parameters(a, b, c, d, false);
    SimpleModel simple_model{ a, b };

    std::cout << "---Input parameters for ComplexModel---" << std::endl;
    input_parameters(a, b, c, d, true);
    ComplexModel complex_model{ a, b, c, d };

    PIDRegulator pid_regulator;

    std::cout << "\t---Simulation with SimpleModel---" << std::endl;
    pid_regulator.Regulate(target_temperature, initial_temperature, simple_model);
    std::cout << std::endl;

    std::cout << "\t---Simulation with ComplexModel---" << std::endl;
    pid_regulator.Regulate(target_temperature, initial_temperature, complex_model);
    system("Pause");
}

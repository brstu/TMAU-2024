#include <iostream>
#include <cmath>
#include <locale>

/**
 * \mainpage
 * \brief Lab work 2. PID controller modeling.
 * \author Chugarin Daniil Alexandrovich, AS-61.
 */

/**
 * \class PIDModelBase
 * \brief Abstract base class for PID models.
 *
 * This class describes the interface for different PID controller models.
 * It defines a pure virtual method `calculate_model` which must be implemented in derived classes.
 */
class PIDModelBase {
public:
    virtual ~PIDModelBase() = default;

    /**
     * \brief Pure virtual method to calculate the PID model.
     * \param current_value The current value of the parameter to be adjusted.
     * \param input_flow The incoming energy or other control parameter.
     * \return The calculated new value.
     */
    virtual double calculate_model(double current_value, double input_flow) = 0;
};

/**
 * \class NonlinearPIDModel
 * \brief Class to implement the nonlinear PID model.
 *
 * This class implements a nonlinear PID controller model, using methods to account for past values.
 */
class NonlinearPIDModel : public PIDModelBase {
private:
    double a, b, c, d;
    double prev_temperature_value = 0;
    double new_value;
    double prev_input_heat = 0;

public:
    NonlinearPIDModel(double a, double b, double c, double d) :
        a(a), b(b), c(c), d(d) { }

    /**
     * \brief Calculates the PID model using the nonlinear formula.
     * \param current_value Current parameter value.
     * \param input_flow Incoming energy flow.
     * \return The calculated value using the nonlinear model.
     */
    double calculate_model(double current_value, double input_flow) override {
        new_value = a * current_value - b * std::pow(prev_temperature_value, 2) +
                    c * input_flow + d * std::sin(prev_input_heat);
        prev_temperature_value = current_value;
        prev_input_heat = input_flow;
        return new_value;
    }
};

/**
 * \class LinearPIDModel
 * \brief Class to implement the linear PID model.
 *
 * This class implements a linear PID controller model.
 */
class LinearPIDModel : public PIDModelBase {
private:
    double a, b;
    double new_value;

public:
    LinearPIDModel(double a, double b) :
        a(a), b(b) { }

    /**
     * \brief Calculates the PID model using the linear formula.
     * \param current_value Current parameter value.
     * \param input_flow Incoming energy flow.
     * \return The calculated value using the linear model.
     */
    double calculate_model(double current_value, double input_flow) override {
        new_value = a * current_value + b * input_flow;
        return new_value;
    }
};

/**
 * \class Controller
 * \brief Class for simulating the PID controller.
 *
 * This class implements the PID controller operation and outputs results to the console.
 */
class Controller {
private:
    double integration_constant, quantization_step, differentiation_constant, transfer_coefficient;
    double current_control_action = 0;

    double calculate_control_action(double error1, double error2, double error3) {
        double param1 = transfer_coefficient * (1 + differentiation_constant / quantization_step);
        double param2 = -transfer_coefficient * (1 + 2 * differentiation_constant / quantization_step - quantization_step / integration_constant);
        double param3 = transfer_coefficient * differentiation_constant / quantization_step;
        current_control_action += (param1 * error1 + param2 * error2 + param3 * error3);
        return current_control_action;
    }

public:
    Controller(double T, double T0, double TD, double K) :
        integration_constant(T), quantization_step(T0), differentiation_constant(TD), transfer_coefficient(K) { }

    void calculate_and_output_results(double required, double initial) {
        double error1 = 0, error2 = 0, error3 = 0;
        double temperature = initial;
        double control_action = 0;

        LinearPIDModel linear(0.333, 0.667);

        std::cout << "Linear model: " << std::endl;

        for (int i = 0; i < 50; ++i) {
            error1 = required - temperature;
            control_action = calculate_control_action(error1, error2, error3);
            temperature = linear.calculate_model(initial, control_action);
            std::cout << "E=" << error1 << " Y=" << temperature << " U=" << control_action << std::endl;
            error3 = error2;
            error2 = error1;
        }

        error2 = 0;
        error3 = 0;
        temperature = initial;

        std::cout << "Nonlinear model: " << std::endl;

        NonlinearPIDModel nonlinear(1, 0.0033, 0.525, 0.525);

        for (int i = 0; i < 50; ++i) {
            error1 = required - temperature;
            control_action = calculate_control_action(error1, error2, error3);
            temperature = nonlinear.calculate_model(initial, control_action);
            std::cout << "E=" << error1 << " Y=" << temperature << " U=" << control_action << std::endl;
            error3 = error2;
            error2 = error1;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Controller controller(10, 10, 40, 0.1);

    controller.calculate_and_output_results(5, 2);

    return 0;
}

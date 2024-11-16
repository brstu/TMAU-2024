#include <iostream>
#include <cmath>

using namespace std;

class Model {
public:
    virtual double simulate_temperature(double currentTemp, double externalInput) = 0;
    virtual ~Model() = default;
};

class NonlinearModel : public Model {
private:
    double previousTemp = 0;
    double previousInput = 0;
    double coefficientA;
    double coefficientB;
    double coefficientC;
    double coefficientD;

public:
    double simulate_temperature(double currentTemp, double externalInput) final {
        double result = coefficientA * currentTemp - coefficientB * pow(previousTemp, 2) + coefficientC * externalInput + coefficientD * sin(previousInput);
        previousTemp = currentTemp;
        previousInput = externalInput;
        return result;
    }

    NonlinearModel(double a, double b, double c, double d) :
        coefficientA(a), coefficientB(b), coefficientC(c), coefficientD(d) {}

    ~NonlinearModel() override = default;
};

void input_parameters(double& a, double& b, double& c, double& d, bool isNonlinear) {
    if (isNonlinear) {
        cout << "Enter parameter c: "; cin >> c;
        cout << "Enter parameter d: "; cin >> d;
    }
    cout << "Enter parameter a: "; cin >> a;
    cout << "Enter parameter b: "; cin >> b;
}

class PIDRegulator {
private:
    const double initialTemperature = 50;
    const double simulationDuration = 30;
    double controlSignal = 0;
    const double gainK = 0.1;
    const double timeConstantT = 10;
    const double derivativeTimeTD = 80;

    double calculate_control_signal(double error, double previousError1, double previousError2) {
        double q0 = gainK * (1 + derivativeTimeTD / initialTemperature);
        double q1 = -gainK * (1 + 2 * derivativeTimeTD / initialTemperature - initialTemperature / timeConstantT);
        double q2 = gainK * derivativeTimeTD / initialTemperature;
        controlSignal += q0 * error + q1 * previousError1 + q2 * previousError2;
        return controlSignal;
    }

public:
    void regulate(double desiredValue, double initialValue, Model& model) {
        double previousError2 = 0;
        double currentValue = initialValue;
        double previousError1 = 0;

        for (int i = 1; i <= simulationDuration; i++) {
            double error = desiredValue - currentValue;
            controlSignal = calculate_control_signal(error, previousError1, previousError2);
            currentValue = model.simulate_temperature(currentValue, controlSignal);
            cout << "Error = " << error << ", Current Temp = " << currentValue << ", Control Signal = " << controlSignal << endl;
            previousError2 = previousError1;
            previousError1 = error;
        }
        controlSignal = 0;
    }
};

class LinearModel : public Model {
private:
    double coefficientA;
    double coefficientB;

public:
    LinearModel(double a, double b) : coefficientA(a), coefficientB(b) {}

    double simulate_temperature(double currentTemp, double externalInput) final {
        return coefficientA * currentTemp + coefficientB * externalInput;
    }

    ~LinearModel() override = default;
};

int main() {
    setlocale(LC_ALL, "English");
    const double desiredValue = 8;
    const double initialValue = 3;

    double a;
    double b;
    double c;
    double d;

    cout << "---Please enter parameters for the linear model---" << endl;
    input_parameters(a, b, c, d, false);
    LinearModel linearModel{ a, b };

    cout << "---Please enter parameters for the nonlinear model---" << endl;
    input_parameters(a, b, c, d, true);
    NonlinearModel nonlinearModel{ a, b, c, d };

    PIDRegulator pidRegulator;

    cout << "\t---Nonlinear Model---" << endl;
    pidRegulator.regulate(desiredValue, initialValue, nonlinearModel);

    cout << "\t---Linear Model---" << endl;
    pidRegulator.regulate(desiredValue, initialValue, linearModel);
    cout << endl;

    system("Pause");
    return 0;
}
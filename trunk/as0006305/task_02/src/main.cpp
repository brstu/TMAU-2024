#include <iostream>
#include <cmath>

using namespace std;

class TemperatureModel {
public:
    virtual double computeTemperature(double currentTemp, double heatInput) = 0;
    virtual ~TemperatureModel() = default;
};

class LinearModel : public TemperatureModel {
private:
    double coeffAlpha;
    double coeffBeta;
public:
    LinearModel(double alpha, double beta) : coeffAlpha(alpha), coeffBeta(beta) {}

    double computeTemperature(double currentTemp, double heatInput) override {
        return coeffAlpha * currentTemp + coeffBeta * heatInput;
    }

    ~LinearModel() override = default;
};

class NonlinearModel : public TemperatureModel {
private:
    double k1, k2, k3, k4;
    double lastTemperature = 0;
    double lastHeatInput = 0;
public:
    NonlinearModel(double k1, double k2, double k3, double k4)
        : k1(k1), k2(k2), k3(k3), k4(k4) {
    }

    double computeTemperature(double currentTemp, double heatInput) override {
        double result = k1 * currentTemp - k2 * pow(lastTemperature, 2)
            + k3 * heatInput + k4 * sin(lastHeatInput);
        lastTemperature = currentTemp;
        lastHeatInput = heatInput;
        return result;
    }

    ~NonlinearModel() override = default;
};

class ControlSystem {
private:
    const double gain = 0.1;
    const double iTime = 10;
    const double dTime = 80;
    const double stepTime = 50;
    const double simulationTime = 30;
    double output = 0;

    double calculateSignal(double err, double prevErr1, double prevErr2) {
        double pTerm = gain * (1 + dTime / stepTime);
        double iTerm = -gain * (1 + 2 * dTime / stepTime - stepTime / iTime);
        double dTerm = gain * dTime / stepTime;
        output += pTerm * err + iTerm * prevErr1 + dTerm * prevErr2;
        return output;
    }

public:
    void executeSimulation(double targetTemp, double startTemp, TemperatureModel& model) {
        double prevError1 = 0, prevError2 = 0;
        double currentTemp = startTemp;

        for (int timeStep = 1; timeStep <= simulationTime; ++timeStep) {
            double error = targetTemp - currentTemp;
            output = calculateSignal(error, prevError1, prevError2);
            currentTemp = model.computeTemperature(currentTemp, output);

            cout << "Шаг " << timeStep << " -> Ошибка: " << error
                << ", Температура: " << currentTemp
                << ", Управляющий сигнал: " << output << '\n';

            prevError2 = prevError1;
            prevError1 = error;
        }
        output = 0;
    }
};

void requestParams(double& p1, double& p2, double& p3, double& p4, bool nonlinear) {
    cout << "Параметр 1: "; cin >> p1;
    cout << "Параметр 2: "; cin >> p2;

    if (nonlinear) {
        cout << "Параметр 3: "; cin >> p3;
        cout << "Параметр 4: "; cin >> p4;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const double targetTemp = 8;
    const double initTemp = 3;
    double p1, p2, p3, p4;

    cout << "--- Линейная модель ---\n";
    requestParams(p1, p2, p3, p4, false);
    LinearModel linearModel(p1, p2);

    cout << "--- Нелинейная модель ---\n";
    requestParams(p1, p2, p3, p4, true);
    NonlinearModel nonlinearModel(p1, p2, p3, p4);

    ControlSystem system;

    cout << "\n--- Линейная модель ---\n";
    system.executeSimulation(targetTemp, initTemp, linearModel);

    cout << "\n--- Нелинейная модель ---\n";
    system.executeSimulation(targetTemp, initTemp, nonlinearModel);

    return 0;
}

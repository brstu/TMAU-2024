#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the next temperature for the linear model
double linearTempUpdate(double factorA, double factorB, double prevTemp, double currentHeat) {
    return factorA * prevTemp + factorB * currentHeat;
}

// Function to compute the next temperature for the nonlinear model
double nonlinearTempUpdate(double factorA, double factorB, double factorC, double factorD, double prevTemp, double currentHeat) {
    return factorA * prevTemp - factorB * pow(prevTemp, 2) + factorC * currentHeat + factorD * sin(currentHeat);
}

// Function to simulate a model based on the provided update function
vector<double> simulateTemperatureModel(
    double (*updateFunction)(double, double, double, double, double, double),
    double factorA, double factorB, double factorC, double factorD, double initialTemp, const vector<double>& heatInput, int timeSteps
) {
    vector<double> temperatures(timeSteps);
    temperatures[0] = initialTemp; // Set initial temperature

    for (int t = 1; t < timeSteps; ++t) {
        temperatures[t] = updateFunction(factorA, factorB, factorC, factorD, temperatures[t - 1], heatInput[t - 1]);
    }

    return temperatures;
}

// Wrapper for linear model update function
double linearModelWrapper(double factorA, double factorB, double, double, double prevTemp, double currentHeat) {
    return linearTempUpdate(factorA, factorB, prevTemp, currentHeat);
}

double nonlinearModelWrapper(double factorA, double factorB, double factorC, double factorD, double prevTemp, double currentHeat) {
    return nonlinearTempUpdate(factorA, factorB, factorC, factorD, prevTemp, currentHeat);
}

int main() {
    setlocale(LC_ALL, "RU");
    
    double factorA, factorB, factorC, factorD, initialTemp;
    cout << "Введите коэффициент A для модели: ";
    cin >> factorA;
    cout << "Введите коэффициент B для линейной модели: ";
    cin >> factorB;
    cout << "Введите коэффициент C для нелинейной модели: ";
    cin >> factorC;
    cout << "Введите коэффициент D для нелинейной модели: ";
    cin >> factorD;
    cout << "Введите начальную температуру: ";
    cin >> initialTemp;

    int timeSteps;
    cout << "Введите количество временных моментов: ";
    cin >> timeSteps;

    vector<double> heatInput(timeSteps);
    cout << "Введите теплоемкость (u) на каждый временной момент:" << endl;
    for (int i = 0; i < timeSteps; ++i) {
        cout << "u[" << i + 1 << "]: ";
        cin >> heatInput[i]; 
    }

    vector<double> linearTemperatures = simulateTemperatureModel(linearModelWrapper, factorA, factorB, 0, 0, initialTemp, heatInput, timeSteps);
    vector<double> nonlinearTemperatures = simulateTemperatureModel(nonlinearModelWrapper, factorA, factorB, factorC, factorD, initialTemp, heatInput, timeSteps);

    // Output results for linear model
    cout << "\nЛинейная модель:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "Время " << t + 1 << ": Температура = " << linearTemperatures[t] << endl;
    }

    // Output results for nonlinear model
    cout << "\nНелинейная модель:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "Время " << t + 1 << ": Температура = " << nonlinearTemperatures[t] << endl;
    }

    return 0; // Indicate successful completion
}
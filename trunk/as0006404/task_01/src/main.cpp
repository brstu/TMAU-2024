#include <iostream>
#include <cmath>

double linearModel(double alpha, double beta, double prevTemp, double inputHeat) {
    return alpha * prevTemp + beta * inputHeat;
}

double nonlinearModel(double alpha, double beta, double gamma, double delta, double prevTemp, double inputHeat) {
    return alpha * prevTemp - beta * prevTemp * prevTemp + gamma * inputHeat + delta * sin(inputHeat - 1);
}

int main() {
    int timeSteps = 10;
    double alpha = 0.5, beta = 0.1, gamma = 0.05, delta = 0.02;
    double currentTemp = 20;
    double inputHeat = 5;
    
    std::cout << "Linear Model:" << std::endl;
    for (int step = 1; step <= timeSteps; ++step) {
        currentTemp = linearModel(alpha, beta, currentTemp, inputHeat);
        std::cout << "Step " << step << ": Temperature = " << currentTemp << std::endl;
    }

    currentTemp = 20;

    std::cout << "\nNonlinear Model:" << std::endl;
    for (int step = 1; step <= timeSteps; ++step) {
        currentTemp = nonlinearModel(alpha, beta, gamma, delta, currentTemp, inputHeat);
        std::cout << "Step " << step << ": Temperature = " << currentTemp << std::endl;
    }

    return 0;
}

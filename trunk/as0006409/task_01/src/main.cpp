#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class TemperatureController {
public:
    TemperatureController(double Y0, double a, double b, double c, double d)
        : Y0(Y0), a(a), b(b), c(c), d(d), y(0.0) {}

    void simulate(int timeSteps, double inputWarm) {
        std::vector<double> temperatures;

        for (int t = 1; t <= timeSteps; ++t) {
            // Linear model
            double y_linear = a * y + b * inputWarm;
            temperatures.push_back(y_linear);
            y = y_linear; // Update for next step
        }

        std::cout << "Linear Model Temperatures:\n";
        for (double temp : temperatures) {
            std::cout << temp << " ";
        }
        std::cout << std::endl;

        // Reset for nonlinear model
        y = 0.0;
        temperatures.clear();

        for (int t = 1; t <= timeSteps; ++t) {
            // Nonlinear model
            double y_nonlinear = a * y - b * pow(y, 2) + c * inputWarm + d * sin(inputWarm);
            temperatures.push_back(y_nonlinear);
            y = y_nonlinear; // Update for next step
        }

        std::cout << "Nonlinear Model Temperatures:\n";
        for (double temp : temperatures) {
            std::cout << temp << " ";
        }
        std::cout << std::endl;
    }

private:
    double Y0; // Room temperature
    double a;  // Constant
    double b;  // Constant
    double c;  // Constant
    double d;  // Constant
    double y;  // Current temperature
};

int main() {
    // Constants
    double Y0 = 20.0; // Room temperature
    double a = 0.5;   // Example constant
    double b = 0.2;   // Example constant
    double c = 0.1;   // Example constant
    double d = 0.05;  // Example constant
    double inputWarm = 5.0; // Input warm value

    // Create temperature controller
    TemperatureController controller(Y0, a, b, c, d);

    // Simulate for 10 time steps
    controller.simulate(10, inputWarm);

    return 0;
}
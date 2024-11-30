#include <iostream>
#include <cmath>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BaseModel {
public:
    virtual ~BaseModel() = default;
    virtual double calculate(double Yt, double Ut) = 0;
    virtual void simulate(double initialY, double initialU, int iterations) = 0;
};

class NonLinearModel : public BaseModel {
private:
    double a, b, c, d;
    double prevY = 0, prevU = 0;

public:
    NonLinearModel(double a_, double b_, double c_, double d_)
        : a(a_), b(b_), c(c_), d(d_) {}

    double calculate(double yt, double ut) override {
        return a * yt - b * prevY * prevY + c * ut + d * sin(prevU);
    }

    void simulate(double initialY, double initialU, int iterations) override {
        double currentY = initialY, currentU = initialU;

        cout << "\n\nNon-Linear Model Simulation\n";
        cout << "Iteration\tYt\n";

        for (int i = 0; i < iterations; ++i) {
            if (i > 0) {
                prevU = currentU;
                prevY = currentY;
            }
            cout << "Enter Ut: ";
            cin >> currentU;

            currentY = calculate(currentY, currentU);
            cout << i + 1 << "\t\t" << currentY << endl;
        }
    }
};

class LinearModel : public BaseModel {
private:
    double a, b;

public:
    LinearModel(double a_, double b_) : a(a_), b(b_) {}

    double calculate(double yt, double ut) override {
        return a * yt + b * ut;
    }

    void simulate(double initialY, double initialU, int iterations) override {
        double currentY = initialY, currentU = initialU;

        cout << "\n\nLinear Model Simulation\n";
        cout << "Iteration\tYt\n";

        for (int i = 0; i < iterations; ++i) {
            cout << "Enter Ut: ";
            cin >> currentU;

            currentY = calculate(currentY, currentU);
            cout << i + 1 << "\t\t" << currentY << endl;
        }
    }
};

class PIDController {
private:
    const double Td = 40;
    const double T0 = 10;
    const double K = 0.1;
    const double simulationTime = 30;
    double Uk = 0;

    double computeControlSignal(double eK, double eK1, double eK2) {
        double q0 = K * (1 + Td / T0);
        double q1 = -K * (1 + 2 * Td);
        double q2 = K * Td / T0;
        Uk += q0 * eK + q1 * eK1 + q2 * eK2;
        return Uk;
    }

public:
    void regulate(double setPoint, double initialY, BaseModel& model) {
        double e1 = 0, e2 = 0, currentY = initialY;

        for (int i = 1; i <= simulationTime; ++i) {
            double error = setPoint - currentY;
            Uk = computeControlSignal(error, e1, e2);
            currentY = model.calculate(initialY, Uk);

            cout << "Error = " << error << ", Yt = " << currentY << ", Uk = " << Uk << endl;

            e2 = e1;
            e1 = error;
        }
        Uk = 0;
    }
};

template <typename T>
T getInput(const string& prompt) {
    T value;
    cout << prompt;
    cin >> value;
    return value;
}

int main() {
    double initialY = 0, initialU = 0;
    double linearA = 0, linearB = 0;
    double nonLinearA = 0, nonLinearB = 0, nonLinearC = 0, nonLinearD = 0;
    int linearIterations = 0, nonLinearIterations = 0;
    const double targetValue = 8, initialValue = 3;

    cout << "Simulation Setup\n";
    linearIterations = getInput<int>("Linear Model Iterations: ");
    nonLinearIterations = getInput<int>("Non-Linear Model Iterations: ");
    initialY = getInput<double>("Initial Y: ");
    initialU = getInput<double>("Initial U: ");

    cout << "\nLinear Model Parameters\n";
    linearA = getInput<double>("A: ");
    linearB = getInput<double>("B: ");

    cout << "\nNon-Linear Model Parameters\n";
    nonLinearA = getInput<double>("A: ");
    nonLinearB = getInput<double>("B: ");
    nonLinearC = getInput<double>("C: ");
    nonLinearD = getInput<double>("D: ");

    LinearModel linearModel(linearA, linearB);
    linearModel.simulate(initialY, initialU, linearIterations);

    NonLinearModel nonLinearModel(nonLinearA, nonLinearB, nonLinearC, nonLinearD);
    nonLinearModel.simulate(initialY, initialU, nonLinearIterations);

    PIDController pid;
    cout << "\nRegulating Linear Model:\n";
    pid.regulate(targetValue, initialValue, linearModel);

    cout << "\nRegulating Non-Linear Model:\n";
    pid.regulate(targetValue, initialValue, nonLinearModel);

    return 0;
}

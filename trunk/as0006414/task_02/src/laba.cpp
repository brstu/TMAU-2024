#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Abstract base class for mathematical models
class MathModel {
public:
   virtual double computeOutput(double currentOutput, double prevOutput, double inputSignal) const = 0;
   virtual ~MathModel() = default;
};

// Class for a nonlinear mathematical model
class NonlinearModel : public MathModel {
private:
    double factorA;
    double factorB;
    double factorC;
    double factorD;
public:
   NonlinearModel(double factorA, double factorB, double factorC, double factorD)
        : factorA(factorA), factorB(factorB), factorC(factorC), factorD(factorD) {}
   double computeOutput(double currentOutput, double prevOutput, double inputSignal) const override {
       return factorA * currentOutput - factorB * pow(prevOutput, 2) + factorC * inputSignal + factorD * sin(inputSignal);
   }
};

// Class for a linear mathematical model
class LinearModel : public MathModel {
private:
   double linearCoefA;
   double linearCoefB;
public:
   explicit LinearModel(double linearCoefA, double linearCoefB) 
       : linearCoefA(linearCoefA), linearCoefB(linearCoefB) {}
   double computeOutput(double currentOutput, double prevOutput, double inputSignal) const override {
       return linearCoefA * currentOutput + linearCoefB * inputSignal;
   }
};

// Class for PID regulator implementation
class PIDController {
private:
   double gainP;
   double gainI;
   double gainD;
   double lastError = 0.0;
   double cumulativeError = 0.0;
   double lastControlSignal = 0.0;
public:
   explicit PIDController(double gainP, double gainI, double gainD)
        : gainP(gainP), gainI(gainI), gainD(gainD) {}
   double computeControl(double currentError) {
       cumulativeError += currentError;
       double rateError = currentError - lastError;
       double controlSignal = gainP * currentError + gainI * cumulativeError + gainD * rateError;
       lastError = currentError;
       lastControlSignal = controlSignal;
       return controlSignal;
   }
};

// Main function
int main() {
     double linFactorA = 0.7;
     double linFactorB = 0.4;
     double nonlinFactorA = 0.7;
     double nonlinFactorB = 0.4;
     double nonlinFactorC = 0.1;
     double nonlinFactorD = 0.1;
     double linearOutput = 0.0;
     double nonlinearOutput = 0.0;
     double previousNonlinearOutput = 0.0;
     double inputSignal = 1.0;

     NonlinearModel nonlinearModel(nonlinFactorA, nonlinFactorB, nonlinFactorC, nonlinFactorD);
     LinearModel linearModel(linFactorA, linFactorB);
     PIDController pidController(1.0, 0.5, 0.2);

     vector<double> linearOutputs;
     vector<double> nonlinearOutputs;
     vector<double> errors;
     vector<double> controlSignals;

     for (int t = 1; t <= 10; t++) {
         linearOutput = linearModel.computeOutput(linearOutput, 0, inputSignal);
         nonlinearOutput = nonlinearModel.computeOutput(nonlinearOutput, previousNonlinearOutput, inputSignal);
         previousNonlinearOutput = nonlinearOutput;

         double error = linearOutput - nonlinearOutput;
         double controlSignal = pidController.computeControl(error);

         linearOutputs.push_back(linearOutput);
         nonlinearOutputs.push_back(nonlinearOutput);
         errors.push_back(error);
         controlSignals.push_back(controlSignal);
     }

     // Output results
     for (int t = 0; t < 10; t++) {
         cout << "Iteration " << t + 1 << ":\n";
         cout << "Linear model output: " << linearOutputs[t] << '\n';
         cout << "Nonlinear model output: " << nonlinearOutputs[t] << '\n';
         cout << "Error: " << errors[t] << '\n';
         cout << "Control signal: " << controlSignals[t] << '\n';
         cout << '\n';
     }
     return 0;
}

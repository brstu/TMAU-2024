#include <iostream>
#include <cmath>

using namespace std;

class Model {
private:
    double a, b, c, d;
    double prevY = 0;
    double prevU = 0;
    bool isLinear;

public:
    Model(double a, double b, double c = 0, double d = 0, bool isLinear = true)
        : a(a), b(b), c(c), d(d), isLinear(isLinear) {}

    double getTemp(double Y, double U) {
        if (isLinear) {
            return a * Y + b * U;
        } else {
            double res = a * Y - b * pow(prevY, 2) + c * U + d * sin(prevU);
            prevY = Y;
            prevU = U;
            return res;
        }
    }
};

class PID {
private:
    const double T0 = 30;
    const double Time = 10;
    double Uk = 0;
    const double k = 0.5;
    const double T = 25;
    const double Td = 15;

    double getUk(double e, double e1, double e2) {
        double q0 = k * (1 + (Td / T0));
        double q1 = -k * (1 + 2 * (Td / T0) - (T0 / T));
        double q2 = k * (Td / T0);
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:

    void regulator(double W, double Y0, Model& model) {
        double e2 = 0, e1 = 0, y = Y0;
        for (int i = 1; i <= Time; i++) {
            double e = W - y;
            Uk = getUk(e, e1, e2);
            y = model.getTemp(Y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

void inputParser(double& A, double& B, double& C, double& D, bool isNonlinearModel) {
    cout << "Enter A: "; cin >> A;
    cout << "Enter B: "; cin >> B;
    if (isNonlinearModel) {
        cout << "Enter C: "; cin >> C;
        cout << "Enter D: "; cin >> D;
    }
}

int main() {
    const double W = 10;
    const double Y0 = 5;
    double A, B, C, D;
    bool isNonlinearModel = false;

    inputParser(A, B, C, D, isNonlinearModel);
    
    Model linearModel{ A, B, true };
    Model nonlinearModel{ A, B, C, D, false };
    PID pidRegulator;
    cout << "Nonlinear mode" << endl;
    pidRegulator.regulator(W, Y0, nonlinearModel);
    cout << "Linear mode" << endl;
    pidRegulator.regulator(W, Y0, linearModel);
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

class Model {
private:
    double a, b, c, d;
    double Prew_Y = 0;
    double Prew_U = 0;
    bool is_linear;

public:
    Model(double A, double B, double c = 0, double d = 0, bool is_linear = true)
        : a(A), b(B), c(c), d(d), is_linear(is_linear) {}

    double get_temp(double Y, double U) {
        if (is_linear) {
            return a * Y + b * U;
        }
        else {
            double res = a * Y - b * pow(Prew_Y, 2) + c * U + d * sin(Prew_U);
            Prew_Y = Y;
            Prew_U = U;
            return res;
        }
    }
};

class PID {
private:
    const double T_0 = 30;
    const double Time = 10;
    double Uk = 0;
    const double k = 0.5;
    const double T = 25;
    const double T_d = 15;

    double get_Uk(double e, double e1, double e2) {
        double q0 = k * (1 + (T_d / T_0));
        double q1 = -k * (1 + 2 * (T_d / T_0) - (T_0 / T));
        double q2 = k * (T_d / T_0);
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:

    void regulAtor(double W, double Y0, Model& model) {
        double e2 = 0, e1 = 0, y = Y0;
        for (int i = 1; i <= Time; i++) {
            double e = W - y;
            Uk = get_Uk(e, e1, e2);
            y = model.get_temp(Y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

void input_par(double& A, double& B, double& c, double& d, bool is_nonlinearModel) {
    cout << "Enter A: "; cin >> A;
    cout << "Enter B: "; cin >> B;
    if (is_nonlinearModel) {
        cout << "Enter c: "; cin >> c;
        cout << "Enter d: "; cin >> d;
    }
}

int main() {
    const double W = 10;
    const double Y0 = 5;
    const double A = 0.21;
    const double B = 0.64;
    const double C = 0.80;
    const double D = 0.07;
    Model linear_model{ A, B, true };
    Model nonlinear_model{ A, B, C, D, false };
    PID pid_regulAtor;
    cout << "Not Linear mode" << endl;
    pid_regulAtor.regulAtor(W, Y0, nonlinear_model);
    cout << "Linear mode" << endl;
    pid_regulAtor.regulAtor(W, Y0, linear_model);
    return 0;
}
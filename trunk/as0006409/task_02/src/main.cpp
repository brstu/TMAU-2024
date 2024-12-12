#include <iostream>
#include <cmath>

using namespace std;
/**
 * @class Model
 * @brief ����� ��� ������������� ������������� ������� � �������� � ���������� ��������.
 */
class Model {
private:
    double a, b, c, d;
    double Prew_Y = 0;
    double Prew_U = 0;
    bool is_linear;
    /**
     * @brief ����������� ������ Model.
     * @param a �������� ������.
     * @param b �������� ������.
     * @param c �������� ������ (������������ ������ � ���������� ������).
     * @param d �������� ������ (������������ ������ � ���������� ������).
     * @param is_linear ����, ������������ ���������� ������.
     */
public:
    Model(double a, double b, double c = 0, double d = 0, bool is_linear = true)
        : a(a), b(b), c(c), d(d), is_linear(is_linear) {}
    /**
  * @brief ����� ��������� ����������� ������� � ����������� �� ������� ����������.
  * @param Y ������� �������� ������ �������.
  * @param U ������� �������� ���������� �������.
  * @return ���������� ����������� � ����������� �� �������� ��� ���������� ������.
  */
    double get_temperature(double Y, double U) {
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
/**
 * @class PID_Regulator
 * @brief ����� ��� ���������� ���-����������.
 */
class PID_Regulator {
private:
    const double T_0 = 50;
    const double Time = 10;
    double Uk = 0;
    const double k = 0.1;
    const double T = 10;
    const double T_d = 10;
    /**
    * @brief ���������� ������������ ����������� Uk.
    * @param e ������� ������.
    * @param e1 ���������� ������.
    * @param e2 ������ �� ��� ���� �����.
    * @return ���������� ����� ����������� �����������.
    */
    double get_Uk(double e, double e1, double e2) {
        double q0 = k * (1 + (T_d / T_0));
        double q1 = -k * (1 + 2 * (T_d / T_0) - (T_0 / T));
        double q2 = k * (T_d / T_0);
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:
    /**
  * @brief ������ ���������� ��� ������.
  */
    void regulator(double w, double y0, Model& model) {
        double e2 = 0, e1 = 0, y = y0;
        for (int i = 1; i <= Time; i++) {
            double e = w - y;
            Uk = get_Uk(e, e1, e2);
            y = model.get_temperature(y0, Uk);
            cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

int main() {
    const double w = 10;
    const double y0 = 5;
    const double a = 0.5;
    const double b = 0.2;
    const double c = 0.1;
    const double d = 0.05;
    Model linear_model{ a, b, true };
    Model nonlinear_model{ a, b, c, d, false };
    PID_Regulator pid_regulator;

    cout << "Not Linear mode" << endl;
    pid_regulator.regulator(w, y0, nonlinear_model);
    cout << "Linear mode" << endl;
    pid_regulator.regulator(w, y0, linear_model);
    return 0;
}
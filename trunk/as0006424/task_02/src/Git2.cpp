#include <iostream>
#include <cmath>

using namespace std;

//Abstract clasd
class Model {
public:
    virtual double temperature_simulation(double Yt, double Uw) = 0;
    virtual ~Model() = default;
};

//Linear model
class LinearModel : public Model {
private:
    double a; 
    double b; 
public:
    LinearModel(double a, double b) : a(a), b(b) {}
    double temperature_simulation(double Yt, double Uw) final {
        return a * Yt + b * Uw;
    }
    ~LinearModel() override = default;
};

//Nonlinear model
class NonlinearModel : public Model {
private:
    double a; 
    double b; 
    double c; 
    double d; 
    double Yt_last = 0;
    //! Previous warm value
    double Uw_last = 0;
public:

 //Nonlinear object
    NonlinearModel(double a, double b, double c, double d) :
        a(a),
        b(b),
        c(c),
        d(d) {}

    double temperature_simulation(double Yt, double Uw) final {
        double result = a * Yt - b * pow(Yt_last, 2) + c * Uw + d * sin(Uw_last);
        Yt_last = Yt;
        Uw_last = Uw;
        return result;
    }
    ~NonlinearModel() override = default;
};

class PIDregulator
{
private:
    const double K = 0.1;
    const double T = 10;
    const double TD = 80;
    const double T0 = 50;
    const double SimulationTime = 30;
    double Uk = 0;

    double calculate_Uk(double e, double e1, double e2)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        double q2 = K * TD / T0;
        Uk += q0 * e + q1 * e1 + q2 * e2;
        return Uk;
    }

public:

    void Regulate(double w, double y0, Model& model)
    {
        double e1 = 0;
        double e2 = 0;
        double y = y0;
        for (int i = 1; i <= SimulationTime; i++) {
            double e;
            e = w - y;
            Uk = calculate_Uk(e, e1, e2);
            y = model.temperature_simulation(y0, Uk);
            std::cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

void add_parameters(double& a, double& b, double& c, double& d, bool is_nonlinearModel) {
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;

    if (is_nonlinearModel) {
        cout << "Enter c: "; cin >> c;
        cout << "Enter d: "; cin >> d;
    }
}
int main() {

    const double w = 8;
    const double y0 = 3;
    double a;
    double b;
    double c;
    double d;

    cout << "\tLinear parameters:" << std::endl;
    add_parameters(a, b, c, d, false);
    LinearModel linear_model{ a,b };

    cout << "\tNonlinear parameters:" << std::endl;
    add_parameters(a, b, c, d, true);
    NonlinearModel nonlinear_model{ a,b,c,d };

    PIDregulator pid;

    cout << "\tLinear Model:" << std::endl;
    pid.Regulate(w, y0, linear_model);
    cout << endl;

    cout << "\tNonlinear Model:" << std::endl;
    pid.Regulate(w, y0, nonlinear_model);
}
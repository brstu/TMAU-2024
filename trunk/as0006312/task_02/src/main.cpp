#include <iostream>
#include <cmath>

class Simulation {
public:
    virtual double compute(double Yt, double Uw) = 0;
    virtual ~Simulation() = default;
};

class LinearSim : public Simulation {
private:
    double a;
    double b;
public:
    LinearSim(double a, double b) : a(a), b(b) {}

    double compute(double Yt, double Uw) final {
        return a * Yt + b * Uw;
    }

    ~LinearSim() override = default;
};

class NonlinearSim : public Simulation {
private:
    double a;
    double b;
    double c;
    double d;
    double PreYt = 0;
    double PreUw = 0;
public:
    NonlinearSim(double a, double b, double c, double d) :
        a(a),
        b(b),
        c(c),
        d(d) {}

    double compute(double Yt, double Uw) final {
        double calc = a * Yt - b * pow(PreYt, 2) + c * Uw + d * sin(PreUw);
        PreYt = Yt;
        PreUw = Uw;
        return calc;
    }

    ~NonlinearSim() override = default;
};

class Controller {
private:
    const double K = 0.1;
    const double T = 10;
    const double TD = 80;
    const double T0 = 50;
    const double numOfSteps = 30;
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
    void Control(double w, double y0, Simulation& model)
    {
        double e1 = 0;
        double e2 = 0;
        double y = y0;
        for (int i = 1; i <= numOfSteps; i++) {
            double e = w - y;
            Uk = calculate_Uk(e, e1, e2);
            y = model.compute(y0, Uk);
            std::cout << "E = " << e << ", Yt = " << y << ", Uk = " << Uk << std::endl;
            e2 = e1;
            e1 = e;
        }
        Uk = 0;
    }
};

void input_params(double& a, double& b, double& c, double& d, bool is_nonlinear) {
    std::cout << "Input a: "; std::cin >> a;
    std::cout << "Input b: "; std::cin >> b;

    if (is_nonlinear) {
        std::cout << "Input c: "; std::cin >> c;
        std::cout << "Input d: "; std::cin >> d;
    }
}

int main() {
    const double w = 8;
    const double y0 = 3;
    double a, b, c, d;

    std::cout << "Linear Model Parameters" << std::endl;
    input_params(a, b, c, d, false);
    LinearSim linear_model{ a, b };

    std::cout << "Nonlinear Model Parameters" << std::endl;
    input_params(a, b, c, d, true);
    NonlinearSim nonlinear_model{ a, b, c, d };

    Controller ctrl;

    std::cout << "\tLinear Model" << std::endl;
    ctrl.Control(w, y0, linear_model);
    std::cout << std::endl;

    std::cout << "\tNonlinear Model" << std::endl;
    ctrl.Control(w, y0, nonlinear_model);

    system("Pause");
}
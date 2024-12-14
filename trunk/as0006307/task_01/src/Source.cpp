#include <iostream>
#include <cmath>

using namespace std;


double calculateLinear(double y, double u, double a, double b) {
    return a * y + b * u;
}


double calculateNonlinear(double y, double u, double a, double b, double c, double d, double prev_u) {
    return a * y - b * pow(y, 2) + c * u + d * sin(prev_u);
}

int main()
{
    const double a = 0.5;
    const double b = 0.1;
    const double c = 0.05;
    const double d = 0.01;
    const int n = 17;

    double y = 25;
    double u = 6;
    double prev_u = 4;

    cout << "Simulation Results:\n";
    cout << "-------------------------------------\n";
    cout << "Step\tLinear y\tNonlinear y\n";
    cout << "-------------------------------------\n";

    for (int t = 1; t <= n; ++t)
    {
        double y_next_linear = calculateLinear(y, u, a, b);
        double y_next_nonlinear = calculateNonlinear(y, u, a, b, c, d, prev_u);

        cout << t << "\t" << y_next_linear << "\t\t" << y_next_nonlinear << endl;

        y = y_next_linear;
        prev_u = u;
        u += 0.1;
    }

    cout << "-------------------------------------\n";
    return 0;
}
    
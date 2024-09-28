#include <iostream>
#include <cmath>

using namespace std;

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

    for (int t = 1; t <= n; ++t)
    {
        // Linear
        double y_next_linear = a * y + b * u;

        // Nonlinear
        double y_next_nonlinear = a * y - b * pow(y, 2) + c * u + d * sin(prev_u);

        cout << "Step " << t << ": Linear y = " << y_next_linear
             << ", Nonlinear y = " << y_next_nonlinear << endl;

        y = y_next_linear;
        prev_u = u;
        u += 0.1;
    }

    return 0;
}


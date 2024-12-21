#include <iostream>
#include <cmath>

using namespace std;

double computeLinear(double coeffA, double coeffB, double coeffC, double coeffD, double currentY, double currentU);
double computeNonlinear(double coeffA, double coeffB, double currentY, double currentU);

int main() {
    double coeffA, coeffB, coeffC, coeffD, currentY, currentU, steps, nextY;

    cout << "Enter coеffA, coеffB, coеffC, coеffD, currentY, currentU, steps\n";
    cin >> coeffA >> coeffB >> coeffC >> coeffD >> currentY >> currentU >> steps;

    cout << "Lineаr Calculаtion:\n";
    for (int step = 0; step < steps; step++) {
        nextY = computeLinear(coeffA, coeffB, coeffC, coeffD, currentY, currentU);
        cout << "Step-" << (step + 1) << ": " << nextY << '\n';
        currentY = nextY;
    }

    cout << "Nonlineаr Calculаtion:\n";
    for (int step = 0; step < steps; step++) {
        nextY = computeNonlinear(coeffA, coeffB, currentY, currentU);
        cout << "Step-" << (step + 1) << ": " << nextY << '\n';
        currentY = nextY;
    }
}

double computeLinear(double coeffA, double coeffB, double coeffC, double coeffD, double currentY, double currentU) {
    double previousY = 0, previousU = 0;
    double nextY = coeffA * currentY - coeffB * previousY * previousY + coeffC * currentU + coeffD * sin(previousU);
    return nextY;
}

double computeNonlinear(double coeffA, double coeffB, double currentY, double currentU) {
    double nextY = coeffA * currentY + coeffB * currentY;
    return nextY;
}
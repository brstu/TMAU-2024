#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 16;

void linearModel(double *values, double input, double coeffA, double coeffB)
{
    double tempValues[SIZE];

    for (int i = 1; i < SIZE; i++)
    {
        values[i] = coeffA * values[i - 1] + coeffB * input;
        tempValues[i] = values[i];
    }

    cout << "Результаты для линейной модели:\n";
    for (int i = 1; i < SIZE; i++)
    {
        cout << "values[" << i << "] = " << tempValues[i] << "\n";
    }
}

void nonLinearModel(double *values, double input, double coeffA, double coeffB, double coeffC, double coeffD)
{
    double tempValues[SIZE];

    for (int i = 2; i < SIZE; i++)
    {
        values[i] = coeffA * values[i - 1] - coeffB * values[i - 2] + coeffC * input + coeffD * sin(input);
        tempValues[i] = values[i];
    }

    cout << "Результаты для нелинейной модели:\n";
    for (int i = 2; i < SIZE; i++)
    {
        cout << "values[" << i << "] = " << tempValues[i] << "\n";
    }
}

int main()
{
    double coeffA = 1.2;
    double coeffB = -0.4;
    double coeffC = 0.6;
    double coeffD = -0.2;
    double values[SIZE] = {20.0};
    double input = 5.0;

    linearModel(values, input, coeffA, coeffB);
    nonLinearModel(values, input, coeffA, coeffB, coeffC, coeffD);

    return 0;
}

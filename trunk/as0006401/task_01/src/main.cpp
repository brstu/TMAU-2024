#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double aN = 2.34;
const double bN = 5.13;
const double cN = 4.17;
const double dN = 3.05;

double LineModel(double Yt, double a, double b, double Ut) {
    return a * Yt + b * Ut;
}

double NLineModel(double Yt, double PreviousYt, double Ut, double PreviousUt) {
    return aN * Yt - bN * PreviousYt * PreviousYt + cN * Ut + dN * sin(PreviousUt);
}

int main() {
    setlocale(LC_ALL, "Russian");

    srand(static_cast<unsigned>(time(0)));

    double y0 = 1.0;
    double u0 = 0.5;
    double aL = 1.2;
    double bL = 0.8;
    int LinIter = 5;
    int NLinIter = 5;

    cout << endl << "Линейная модель";
    double Yt = y0;
    double Ut = u0;
    cout << "\nИтерация\t\tYt";

    for (int iterator = 0; iterator < LinIter; iterator++) {
        Ut = static_cast<double>(rand()) / RAND_MAX;
        Yt = LineModel(Yt, aL, bL, Ut);
        cout << "\n" << iterator + 1 << "\t\t\t" << Yt;
    }

    cout << endl << endl << "Нелинейная модель";
    Yt = y0;
    Ut = u0;
    double PreviousYt = 0.0;
    double PreviousUt = 0.0;
    cout << "\nИтерация\t\tYt";

    for (int iterator = 0; iterator < NLinIter; iterator++) {
        if (iterator > 0) {
            PreviousUt = Ut;
            PreviousYt = Yt;
        }
        Ut = static_cast<double>(rand()) / RAND_MAX;
        Yt = NLineModel(Yt, PreviousYt, Ut, PreviousUt);
        cout << "\n" << iterator + 1 << "\t\t\t" << Yt;
    }

    return 0;
}

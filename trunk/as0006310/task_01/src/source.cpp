#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// константы для моделей
const double const_a = 1.34; const double const_b = 5.23; const double const_c = 4.37; const double const_d = 3.95;

// функция для линейной модели
double LineModel(double Yt, double a, double b, double Ut)
{
    return a * Yt + b * Ut;
}

// функция для нелинейной модели
double NotLineModel(double Yt, double PrevioustYt, double Ut, double PrevioustUt)
{
    return const_a * Yt - const_b * pow(PrevioustYt, 2) + const_c * Ut + const_d * sin(PrevioustUt);
}

int main()
{
    // переменные для входных данных
    double Yt; double PreviousYt; double Ut; double PreviousUt; double y0; double u0; double aL; double bL;
    int LineIter; int NotLineIter;

    cout << "Linear Model Parameters" << endl;
    cout << "Enter a:\t";
    cin >> aL;
    cout << "Enter b:\t";
    cin >> bL;

    cout << "Enter y:\t";
    cin >> y0;
    cout << "Enter u:\t";
    cin >> u0;

    cout << endl;
    cout << "Number of tests" << endl;
    cout << "Linear model: ";
    cin >> LineIter;
    cout << "Nonlinear model: ";
    cin >> NotLineIter;

    cout << endl;
    cout << "Linear model";
    Yt = y0; Ut = u0;
    for (int iterator = 0; iterator < LineIter; iterator++) {
        cout << endl;
        cout << "Enter Ut: ";
        cin >> Ut;
        Yt = LineModel(Yt, aL, bL, Ut);
        cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
    }

    cout << endl;
    cout << endl;
    cout << "Nonlinear model";
    Yt = y0; Ut = u0;
    for (int iterator = 0; iterator < NotLineIter; iterator++) {
        if (iterator > 0) {
            // сохраняем предыдущие значения
            PreviousUt = Ut; PreviousYt = Yt;
            cout << endl;
            cout << "Enter Ut: ";
            cin >> Ut;
            // вычисляем Yt
            Yt = NotLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
        }
        else {
            // инициализируем предыдущие значения
            PreviousUt = 0; PreviousYt = 0;
            cout << endl;
            cout << "Enter Ut: ";
            cin >> Ut;
            // вычисляем Yt
            Yt = NotLineModel(Yt, PreviousYt, Ut, PreviousUt);
            cout << "iteration: " << iterator + 1 << ";" << " Yt: " << Yt;
        }
        cout << endl;
    }
}

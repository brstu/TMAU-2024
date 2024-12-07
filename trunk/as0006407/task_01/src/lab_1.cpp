#include <iostream>
#include <math.h>

using namespace std;

const double a = 0.21;
const double b = 0.64;
const double c = 0.80;
const double d = 0.07;

const int step_number = 10;

double Linear_Model(double y, double u){
    double res = a * y + b * u;
    cout << res << endl;
    return res;
}

double Not_Linear_Model(double y, double y_prev, double u, double u_prev){
    double res = a * y - b * pow(y_prev, 2) + c * u + d * sin(u_prev);
    cout << res << endl;
    return res;
}

int main() {
    double y = 0.0;
    double u = 1.0;
    cout << "Linear:" << endl;
    for(int i = 0; i < step_number; i++){
        y = Linear_Model(y, u);
        y += 0.1;
        u += 0.1;
    }
    y = 0;
    u = 1;
    cout << "Not Linear:" << endl;
    for(int i = 0; i < step_number; i++){
        double y_prev = y;
        double u_prev = u;
        y = Not_Linear_Model(y + 0.1, y_prev, u + 0.1, u_prev);
    }
    return 0;
}
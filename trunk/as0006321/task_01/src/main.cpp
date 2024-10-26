#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    double a, b, c , d;
    int t;

    cout << "Enter  a: ";
    cin >> a;
    cout << "Enter  b: ";
    cin >> b;
    cout << "Enter  c: ";
    cin >> c;
    cout << "Enter  d: ";
    cin >> d;
    cout << "Enter  t: ";
    cin >> t;

    float* y1 = new float[t + 1];
    float* u1 = new float[t + 1];

    cout << "Enter  y: ";
    cin >> y1[0];
    for (int i = 0; i < t; i++) {
        cout << "Enter  u: ";
        cin >> u1[i];
        y1[i + 1] = a * y1[i] + b * u1[i];
        cout << y1[i+1] << endl;
    }
    
    cout << "Enter  t: ";
    cin >> t;

    float* y2 = new float[t + 2];
    float* u2 = new float[t + 2];

    cout << "Enter  y: ";
    cin >> y2[1];
    y2[0] = 0;
    u2[0] = 0;
    for (int i = 1; i <= t; i++) {
        cout << "Enter  u: ";
        cin >> u2[i];
        y2[i + 1] = a * y2[i] - pow(y2[i - 1], 2) * b + c * u2[i] + d * sin(u2[i - 1]);
        cout << y2[i + 1] << endl;
    }
    
    delete[] y1;
    delete[] u1;
    delete[] y2;
    delete[] u2;
    return 0;
}
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// ������� ��� ������������� �������� ��������
vector<double> linearDynamics(double alpha, double beta, double initialTemp, const vector<double>& heatInput, int timeSteps) {
    vector<double> temp(timeSteps);
    temp[0] = initialTemp; // ��������� �����������

    // ���� �� ������� ���������� ���� ��� ������� �����������
    for (int t = 1; t < timeSteps; ++t) {
        temp[t] = alpha * temp[t - 1] + beta * heatInput[t - 1]; // ���������� ����������� � �������� ������
    }

    return temp; // ���������� ������ ����������
}

// ������� ��� ������������� ���������� ��������
vector<double> nonlinearDynamics(double alpha, double beta, double gamma, double delta, double initialTemp, const vector<double>& heatInput, int timeSteps) {
    vector<double> temp(timeSteps);
    temp[0] = initialTemp; // ��������� �����������

    // ���� �� ������� ���������� ���� ��� ������� �����������
    for (int t = 1; t < timeSteps; ++t) {
        double prev_temp = temp[t - 1];
        double prev_heat = heatInput[t - 1];
        temp[t] = alpha * prev_temp - beta * pow(prev_temp, 2) + gamma * prev_heat + delta * sin(prev_heat); // ���������� ��� ���������� ������
    }

    return temp; // ���������� ������ ����������
}

int main() {
    // ���� �������� �� ������������
    double alpha, beta, gamma, delta, initialTemp;
    cout << "������� ����������� alpha: ";
    cin >> alpha;
    cout << "������� ����������� beta ��� �������� ������: ";
    cin >> beta;
    cout << "������� ����������� gamma ��� ���������� ������: ";
    cin >> gamma;
    cout << "������� ����������� delta ��� ���������� ������: ";
    cin >> delta;
    cout << "������� ��������� ����������� (initialTemp): ";
    cin >> initialTemp;

    // ���� ���������� ��������� �����
    int timeSteps;
    cout << "������� ���������� ��������� �����: ";
    cin >> timeSteps;

    // ���� �������� ��������� �����������
    vector<double> heatInput(timeSteps);
    cout << "������� �������� ��������� ����������� ��� ������� ���������� �������:" << endl;
    for (int i = 0; i < timeSteps; ++i) {
        cout << "heatInput[" << i + 1 << "]: ";
        cin >> heatInput[i]; // ������ �������� �������� �����
    }

    // ������������� �������� ��������
    vector<double> linearTemp = linearDynamics(alpha, beta, initialTemp, heatInput, timeSteps);

    // ������������� ���������� ��������
    vector<double> nonlinearTemp = nonlinearDynamics(alpha, beta, gamma, delta, initialTemp, heatInput, timeSteps);

    // ����� �����������
    cout << "\n������������� �������� ��������:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "����� " << t + 1 << ": ����������� = " << linearTemp[t] << endl;
    }

    cout << "\n������������� ���������� ��������:" << endl;
    for (int t = 0; t < timeSteps; ++t) {
        cout << "����� " << t + 1 << ": ����������� = " << nonlinearTemp[t] << endl;
    }

    return 0; // ���������� ���������
}
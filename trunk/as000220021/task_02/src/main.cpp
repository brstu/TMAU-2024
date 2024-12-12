#include <iostream>
#include <vector>
#include "models.h"
#include "PID.h"

using namespace std;

/**
 * @file main.cpp
 *
 * @brief ��������� ��������� ���������� ��� ������� � ����� ��������:
 * �������� � ����������.
 *
 * @author ���������� ���������
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

void start();
bool choice_input(int& choice);
LinearModel get_liner_model(const int& T0);
NonLinearModel get_nonlinear_model(const int& T0);
template<typename T> bool input_value(T& value, const string& name);
void output(const vector <vector<double>>& control_signals, const string& name);

/**
 * @brief ������� �������.
 *
 * ������� ������� ��������� ���������, �������� ������ �����.
 *
 * @return 0, ���� ��� � �������.
 */

int main() {
    /**
     * @brief ������ ������� ��� ������������ ����� ����.
     */
    void (*point[])() = { []() { exit(0); }, start };
    int choice;
    while (true) {
        /**
         * @brief ����� ������ ��� ������������.
         */
        cout << "\n\t������� ����� (0 - �����, 1 - ������)\n";
        /**
         * @brief ���� ������ �� ������������.
         */
        if (!choice_input(choice)) {
            /**
             * @brief ���� ���� �����������, ������� ��������� �� ������.
             */
            cerr << "\n\a\t\t***������������ �������� �����***\n\n";
            continue;
        }
        /**
         * @brief �������� ������� �� ������� � ����������� �� ������.
         */
        point[choice]();
    }
    return 0;
}

/**
 * @brief ������� ��� ������ ���������.
 *
 * ������� ��������� ���������, ������ ������ ��� �������� � ���������� �������,
 * ��������� ������, ������������ ����������� ������ � ������� PID � ������� ����������.
 */
void start() {
    double w;
    int T0;

    do {
        /**
         * @brief ������ ����� ��������� ���������������� �������.
         */
        cout << "������� �������� ���������������� �������\n";
    } while (!input_value(w, "w(t)"));

    /**
     * @brief ������ ����� ����.
     */
    cout << "������� ���\n";
    input_value(T0, "T0");

    /**
     * @brief ������ ����� ������ ��� �������� ������.
     */
    cout << "\t��������� ������ ��� �������� ������\n";
    LinearModel liner_model = get_liner_model(T0);

    /**
     * @brief �������� ����������� �� �������� ������.
     */
    vector <double> temps_linear = liner_model.getTemp();

    /**
     * @brief ������� ������� PID-����������.
     */
    PID pid_liner, pid_nonlinear;

    /**
     * @brief ������������ ����������� ������ � ������� PID ��� �������� ������.
     */
    pid_liner.calculate(w, T0, temps_linear);

    /**
     * @brief �������� ����������� ������� �� PID-���������� ��� �������� ������.
     */
    vector <vector<double>> control_signals_liner = pid_liner.getControlSignals();

    /**
     * @brief ������ ����� ������ ��� ���������� ������.
     */
    cout << "\t��������� ������ ��� ���������� ������\n";
    NonLinearModel non_liner_model = get_nonlinear_model(T0);

    /**
     * @brief �������� ����������� �� ���������� ������.
     */
    vector <double> temps_nonlinear = non_liner_model.getTemp();

    /**
     * @brief ������������ ����������� ������ � ������� PID ��� ���������� ������.
     */
    pid_nonlinear.calculate(w, T0, temps_nonlinear);

    /**
     * @brief �������� ����������� ������� �� PID-���������� ��� ���������� ������.
     */
    vector <vector<double>> control_signals_nonlinear = pid_nonlinear.getControlSignals();

    /**
     * @brief ������� ���������� ��� �������� ������.
     */
    output(control_signals_liner, "�������� ������");
    /**
     * @brief ������� ���������� ��� ���������� ������.
     */
    output(control_signals_nonlinear, "���������� ������");
}

/**
 * @brief ������� ��� ������ �����������.
 *
 * @param control_signals ����������� ������� ��� ������.
 * @param name ��� ������.
 */
void output(const vector <vector<double>>& control_signals, const string& name) {
    /**
     * @brief ����� ��������� �������.
     */
    cout << "\n\t\t\t\t\t\t\t\t����������\n\n";
    cout << "\t\t\t\t\t\t\t\t" << name << "\n\n";
    cout.setf(ios::left);
    cout << setw(15) << "����� (T0)";
    cout << setw(20) << "���������� (e)";
    cout << setw(27) << "�������� ���������� (Yt)";
    cout << setw(35) << "����������� ������� (Uk)" << endl;
    cout << setfill('=') << setw(85) << "" << setfill(' ') << endl;
    int i = 1;
    for (const auto& signal : control_signals) {
        /**
         * @brief ����� ������ �������.
         */
        cout << setw(15) << i++;
        cout << setw(20) << signal[0];
        cout << setw(27) << signal[1];
        cout << setw(35) << signal[2] << endl;
    }
}

/**
 * @brief ��������� ������� ��� ����� ��������.
 *
 * @param value �������� ��� �����.
 * @param name ��� ��������.
 *
 * @return true, ���� ��� � �������.
 */
template<typename T> bool input_value(T& value, const string& name) {
    while (true) {
        /**
         * @brief ������ ����� ��������.
         */
        cout << "������� " << name << ": ";
        if (cin >> value) {
            /**
             * @brief ���� ���� ���������, ���������� true.
             */
            return true;
        }
        else {
            /**
             * @brief ���� ���� �����������, ������� ��������� �� ������.
             */
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\n\a\t\t***������������ �������� �����***\n\n";
        }
    }
}

/**
 * @brief ������� ��� ����� ������ ��� �������� ������.
 *
 * @return �������� ������.
 */
LinearModel get_liner_model(const int& T0) {
    double A, B, current_temperature, warm;
    /**
     * @brief ���� ������ ��� �������� ������.
     */
    input_value(A, "A");
    input_value(B, "B");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    LinearModel model(A, B, current_temperature, warm);
    model.calculate(T0);
    return model;
}

/**
 * @brief ������� ��� ����� ������ ��� ���������� ������.
 *
 * @return ���������� ������.
 */
NonLinearModel get_nonlinear_model(const int& T0) {
    double A, B, C, D, current_temperature, warm;
    /**
     * @brief ���� ������ ��� ���������� ������.
     */
    input_value(A, "A");
    input_value(B, "B");
    input_value(C, "C");
    input_value(D, "D");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    NonLinearModel model(A, B, C, D, current_temperature, warm);
    model.calculate(T0);
    return model;
}

/**
 * @brief ������� ��� ����� ������.
 *
 * @param choice �����.
 *
 * @return true, ���� ��� � �������.
 */
bool choice_input(int& choice) {
    while (true) {
        if (input_value(choice, "�����")) {
            if (choice >= 0 && choice <= 1) {
                /**
                 * @brief ���� ���� ���������, ���������� true.
                 */
                return true;
            }
            else {
                /**
                 * @brief ���� ���� �����������, ������� ��������� �� ������.
                 */
                cerr << "\n\a\t\t***������������ �������� �����***\n\n";
            }
        }
    }
}
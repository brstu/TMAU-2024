#include "models.h"
#include <iostream>
#include <limits>

using namespace std;

void get_liner_model();
void get_nonlinear_model();
bool choice_input(int &choice);

int main() {
    void (*point[])() = { []() { exit(0); }, get_liner_model, get_nonlinear_model};
    int choice;
    while (true) {
        cout << "\n\tInput choice (0 - exit, 1 - linear model, 2 - nonlinear model)\n";
        if (!choice_input(choice)) {
            cerr << "\n\a\t\t***Input value is not correct***\n\n";
            continue;
        }
        point[choice]();
    }

    return 0;
}

template<typename T> bool input_value(T &value, const string &name) {
    while (true) {
        cout << "Input " << name << ": ";
        if (cin >> value) {
            return true;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\n\a\t\t***Input value is not correct***\n\n";
        }
    }
}

void get_liner_model() {
    double A, B, current_temperature, warm;
    int time;
    input_value(A, "A");
    input_value(B, "B");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    input_value(time, "time");
    LinearModel model(A, B, current_temperature, warm);
    model.calculate_and_print(time);
}

void get_nonlinear_model() {
    double A, B, C, D, current_temperature, warm;
    int time;
    input_value(A, "A");
    input_value(B, "B");
    input_value(C, "C");
    input_value(D, "D");
    input_value(current_temperature, "current_temperature");
    input_value(warm, "warm");
    input_value(time, "time");
    NonLinearModel model(A, B, C, D, current_temperature, warm);
    model.calculate_and_print(time);
}

bool choice_input(int &choice) {
    while (true) {
        if (input_value(choice, "choice")) {
            if (choice >= 0 && choice <= 2) {
                return true;
            }
            else {
                cerr << "\n\a\t\t***Input value is not correct***\n\n";
            }
        }
    }
}


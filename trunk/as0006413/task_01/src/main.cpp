#include <iostream>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

void run_linear_model();
void run_nonlinear_model();
bool get_choice(int &choice);

void get_input(double &value, const string &prompt) {
    cout << prompt << ": ";
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Try again.\n" << prompt << ": ";
    }
}

void get_input(int &value, const string &prompt) {
    cout << prompt << ": ";
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Try again.\n" << prompt << ": ";
    }
}

void display_results(const map<int, double> &temps, const string &model_type) {
    cout << "\n--- " << model_type << " Results ---\n";
    for (const auto &entry : temps) {
        cout << "Step " << entry.first << ": Temperature = " << entry.second << endl;
    }
}

void run_linear_model() {
    double A, B, temp, heat;
    int steps;
    get_input(A, "Enter coefficient A");
    get_input(B, "Enter coefficient B");
    get_input(temp, "Enter initial temperature");
    get_input(heat, "Enter heat input");
    get_input(steps, "Enter number of steps");

    map<int, double> temps;
    for (int i = 1; i <= steps; ++i) {
        temp = A * temp + B * heat;
        temps[i] = temp;
    }
    display_results(temps, "Linear Model");
}

void run_nonlinear_model() {
    double A, B, C, D, temp, heat;
    int steps;
    get_input(A, "Enter coefficient A");
    get_input(B, "Enter coefficient B");
    get_input(C, "Enter coefficient C");
    get_input(D, "Enter coefficient D");
    get_input(temp, "Enter initial temperature");
    get_input(heat, "Enter heat input");
    get_input(steps, "Enter number of steps");

    map<int, double> temps;
    double prev_temp = 0;
    for (int i = 1; i <= steps; ++i) {
        double new_temp = A * temp - B * pow(prev_temp, 2) + C * heat + D * sin(heat);
        prev_temp = temp;
        temp = new_temp;
        temps[i] = temp;
    }
    display_results(temps, "Nonlinear Model");
}

bool get_choice(int &choice) {
    get_input(choice, "Choose option (0 - Exit, 1 - Linear, 2 - Nonlinear)");
    return choice >= 0 && choice <= 2;
}

int main() {
    void (*models[])() = { []() { exit(0); }, run_linear_model, run_nonlinear_model };
    int choice;

    while (true) {
        if (!get_choice(choice)) {
            cout << "Invalid choice! Try again.\n";
        } else {
            models[choice]();
        }
    }
}

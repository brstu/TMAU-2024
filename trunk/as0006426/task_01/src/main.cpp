#include <iostream>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

void execute_linear_simulation();
void execute_nonlinear_simulation();
bool retrieve_choice(int &selection);

void obtain_input(double &value, const string &message) {
    cout << message << ": ";
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again.\n" << message << ": ";
    }
}

void obtain_input(int &value, const string &message) {
    cout << message << ": ";
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again.\n" << message << ": ";
    }
}

void show_results(const map<int, double> &temperatures, const string &model_name) {
    cout << "\n--- Results for " << model_name << " ---\n";
    for (const auto &entry : temperatures) {
        cout << "Step " << entry.first << ": Temperature = " << entry.second << endl;
    }
}

void execute_linear_simulation() {
    double coefA, coefB, initial_temp, heat_input;
    int total_steps;
    obtain_input(coefA, "Enter coefficient A");
    obtain_input(coefB, "Enter coefficient B");
    obtain_input(initial_temp, "Enter initial temperature");
    obtain_input(heat_input, "Enter heat input");
    obtain_input(total_steps, "Enter number of steps");

    map<int, double> results;
    for (int step = 1; step <= total_steps; ++step) {
        initial_temp = coefA * initial_temp + coefB * heat_input;
        results[step] = initial_temp;
    }
    show_results(results, "Linear Model");
}

void execute_nonlinear_simulation() {
    double coefA, coefB, coefC, coefD, initial_temp, heat_input;
    int total_steps;
    obtain_input(coefA, "Enter coefficient A");
    obtain_input(coefB, "Enter coefficient B");
    obtain_input(coefC, "Enter coefficient C");
    obtain_input(coefD, "Enter coefficient D");
    obtain_input(initial_temp, "Enter initial temperature");
    obtain_input(heat_input, "Enter heat input");
    obtain_input(total_steps, "Enter number of steps");

    map<int, double> results;
    double previous_temp = 0;
    for (int step = 1; step <= total_steps; ++step) {
        double new_temp = coefA * initial_temp - coefB * pow(previous_temp, 2) + coefC * heat_input + coefD * sin(heat_input);
        previous_temp = initial_temp;
        initial_temp = new_temp;
        results[step] = initial_temp;
    }
    show_results(results, "Nonlinear Model");
}

bool retrieve_choice(int &selection) {
    obtain_input(selection, "Select an option (0 - Exit, 1 - Linear Model, 2 - Nonlinear Model)");
    return selection >= 0 && selection <= 2;
}

int main() {
    void (*simulation_methods[])() = { []() { exit(0); }, execute_linear_simulation, execute_nonlinear_simulation };
    int selection;

    while (true) {
        if (!retrieve_choice(selection)) {
            cout << "Invalid selection! Please try again.\n";
        } else {
            simulation_methods[selection]();
        }
    }
}
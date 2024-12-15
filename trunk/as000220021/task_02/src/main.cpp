#include <iostream>
#include <cmath>
#include <array>
using namespace std;

// Abstract class model intended for inheritance by other models

class Model {
public:
    /*
Virtual function for simulating temperature with input parameters:
curr_temp - current temperature of the model
control_var - input temperature
return - output temperature
*/
    virtual double temperature_sim(double curr_temp, double control_var) = 0;

    virtual ~Model() = default;
};

// Linear temperature control model
class Linear_Model : public Model {
private:
    double alpha; // Model parameter alpha
    double beta; // Model parameter beta

public:
    // Constructor for an object with fixed parameters alpha and beta
    Linear_Model(double alpha, double beta) : alpha(alpha), beta(beta) {};

    //  Method for calculating the output temperature of the linear model
    double temperature_sim(double curr_temp, double control_var) final {
        return alpha * curr_temp + beta * control_var;
    }

    // Destructor of the Linear_Model object
    ~Linear_Model() override = default;
};

class NonLinear_Model : public Model {
private:
    double alpha; // Model parameter alpha
    double beta; // Model parameter beta
    double charlie; // Model parameter charlie
    double delta; /// Model parameter alpha
    double prev_temp = 0;
    double prev_control_var = 0;
    
public:
    //  Constructor for a new object with constant parameters alpha, beta, charlie, delta
     NonLinear_Model(double alpha, double beta, double charlie, double delta) :
        alpha(alpha),
        beta(beta),
        charlie(charlie),
        delta(delta) {};

    // Method for calculating the output temperature of the nonlinear model
    double temperature_sim(double curr_temp, double control_var) {
        double temp = alpha * curr_temp + beta * pow(prev_temp, 2) + charlie * control_var + delta * sin(prev_control_var);
        prev_temp = curr_temp;
        prev_control_var = control_var;
        return temp;
    }

    // Destructor of the NonLinear_Model object
    ~NonLinear_Model() override = default;
};

class PID_regulator {
private:
    // Constant transfer coefficient of the regulator
    const double K = 0.1;
    // Constant for integration
    const double T = 10;
    // Constant for differentiation
    const double TD = 80;
    // Quantization step constant
    const double T0 = 50;
    // Simulation time
    const double model_lifetime = 30;
    // Value of the control variable
    double Uk = 0;

    /*
    Method for calculating control values
        err - array of errors
        return - value of the control variable
    */
    double calculate_Uk(double err) {
        // Use an array to store errors and a loop to compute Uk
        array <double, 3> errors = { 0, 0, 0 }; /// Store the last three errors 
        errors[2] = errors[1]; /// Shift errors to the left
        errors[1] = errors[0];
        errors[0] = err; /// Store the current error

        // Coefficients for the PID formula
        array<double, 3> q = { K * (1 + TD / T0), -K * (1 + 2 * TD / T0 - T0 / T), K * TD / T0 };

        // Loop through errors and add their products with coefficients to Uk
        for (int i = 0; i < 3; i++) {
            Uk += q[i] * errors[i];
        }

        return Uk;
    }
public:
    /*
    Simulation regulator
        goal_temp - desired temperature value
        start_temp - initial temperature
        model - linear or nonlinear model
    */
    void regulate(double goal_temp, double start_temp, Model& model) {
        double now_temp = start_temp;
        for (int i = 1; i <= model_lifetime; i++) {
            double err = goal_temp - now_temp;
            Uk = calculate_Uk(err);
            now_temp = model.temperature_sim(start_temp, Uk);
            cout << "Err = " << err << "\t"
                << "Yt = " << now_temp << "\t"
                << "Uk = " << Uk << endl;
        }
        Uk = 0;
    }
};

/*
Function for inputting model parameters
    alpha - constant
    beta - constant
    charlie - constant
    delta - constant
    is_linear - model type
*/
void input_consts(double& alpha, double& beta, double& charlie, double& delta, bool is_NonLinear) { 
    cout << "Введите параметр alpha: ";
    cin >> alpha;
    cout << "Введите параметр beta: ";
    cin >> beta;
    if (is_NonLinear) {
        cout << "Введите параметр charlie: ";
        cin >> charlie;
        cout << "Введите параметр delta: ";
        cin >> delta;
    }
}

int main() {

    system("chcp 1251");
    system("cls");

    struct ModelParams {
        double alpha;
        double beta;
        double charlie;
        double delta;
    };
    
    array<const char*, 2> model_names = { "Линейная модель", "Нелинейная модель" }; /// Model names
    array<ModelParams, 2> model_params;/// Loop through models and input their parameters
    for (int i = 0; i < 2; i++) {
        cout << "----------" << model_names[i] << ". Введите параметры----------" << endl;
        input_consts(model_params[i].alpha, model_params[i].beta, model_params[i].charlie, model_params[i].delta, i);
    }

    // Creation of the models themselves with the entered parameters
    Linear_Model linear_model(model_params[0].alpha, model_params[0].beta);
    NonLinear_Model nonlinear_model(model_params[1].alpha, model_params[1].beta, model_params[1].charlie, model_params[1].delta);

    PID_regulator pid_regulator;

    const double goal_temp = 12;
    const double start_temp = 5;

    cout << "\t----------Линейная модель----------" << endl;
    pid_regulator.regulate(goal_temp, start_temp, linear_model);
    cout << endl;

    cout << "\t----------Нелинейная модель----------" << endl;
    pid_regulator.regulate(goal_temp, start_temp, nonlinear_model);
}
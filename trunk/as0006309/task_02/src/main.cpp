#include <iostream>
#include <cmath>
#include <array>
using namespace std;

// Абстрактный класс модели для наследнования другими моделями
class Model {
public:
    /*
    Виртуальная функция для симулирования температуры с входными вариантами:
        curr_temp - текущая температура модели
        control_var - температура на входе
        return - температура на выходе
    */
    virtual double temperature_sim(double curr_temp, double control_var) = 0;

    virtual ~Model() = default;
};

// Линейная модель контроля температуры
class Linear_Model : public Model {
private:
    double alpha; // Параметр модели alpha
    double beta; // Параметр модели beta

public:
    // Конструктор нового объекта с константными параметрами alpha и beta
    Linear_Model(double alpha, double beta) : alpha(alpha), beta(beta) {};

    // Метод расчёта выходной температуры линеной модели
    double temperature_sim(double curr_temp, double control_var) final {
        return alpha * curr_temp + beta * control_var;
    }

    // Деструктор объекта Linear_Model
    ~Linear_Model() override = default;
};

class NonLinear_Model : public Model {
private:
    double alpha; // Параметр модели alpha
    double beta; // Параметр модели beta
    double charlie; // Параметр модели charlie
    double delta; // Параметр модели alpha
    double prev_temp = 0;
    double prev_control_var = 0;
    
public:
    // Конструктор нового объекта с константными параметрами alpha, beta, charlie, delta
    NonLinear_Model(double alpha, double beta, double charlie, double delta) :
        alpha(alpha),
        beta(beta),
        charlie(charlie),
        delta(delta) {};

    // Метод расчёта выходной температуры нелиненой модели
    double temperature_sim(double curr_temp, double control_var) {
        double temp = alpha * curr_temp + beta * pow(prev_temp, 2) + charlie * control_var + delta * sin(prev_control_var);
        prev_temp = curr_temp;
        prev_control_var = control_var;
        return temp;
    }

    // Деструктор объекта NonLinear_Model
    ~NonLinear_Model() override = default;
};

class PID_regulator {
private:
    // Постоянный коэффициент передачи регулятора
    const double K = 0.1;
    // Постоянная интегрирования
    const double T = 10;
    // Постоянная дифференцирования
    const double TD = 80;
    // Постоянная шага квантования
    const double T0 = 50;
    // Время моделирования
    const double model_lifetime = 30;
    // Значение управляющей переменной
    double Uk = 0;

    /*
    Метод для расчёта контрольных значений
        err - массив ошибок
        return - значение переменной управления
    */
    double calculate_Uk(double err) {
        // используем массив для хранения ошибок и цикл для вычисления Uk
        array <double, 3> errors = { 0, 0, 0 }; /// хранение последних трех ошибок
        errors[2] = errors[1]; /// сдвиг ошибок влево
        errors[1] = errors[0];
        errors[0] = err; /// хранение текущей ошибки

        // коэффициенты для формулы PID
        array<double, 3> q = { K * (1 + TD / T0), -K * (1 + 2 * TD / T0 - T0 / T), K * TD / T0 };

        // цикл по ошибкам и добавление их произведений с коэффициентами к Uk
        for (int i = 0; i < 3; i++) {
            Uk += q[i] * errors[i];
        }

        return Uk;
    }
public:
    /*
    Регулятор моделирования
        goal_temp - требуемое значение температуры
        start_temp - начальная температура
        model - линейная или нелинейная модель
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
Функция для ввода параметров модели
    alpha - константа
    beta - константа
    charlie - константа
    delta - константа
    is_linear - тип модели
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
    
    array<const char*, 2> model_names = { "Линейная модель", "Нелинейная модель" }; /// названия моделей
    array<ModelParams, 2> model_params;/// цикл по моделям и ввод их параметров
    for (int i = 0; i < 2; i++) {
        cout << "----------" << model_names[i] << ". Введите параметры----------" << endl;
        input_consts(model_params[i].alpha, model_params[i].beta, model_params[i].charlie, model_params[i].delta, i);
    }

    // Создание самих моделей с введёнными параметрами
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
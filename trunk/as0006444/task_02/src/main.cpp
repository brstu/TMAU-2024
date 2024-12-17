#include <iostream>
#include <cmath>
#include <fstream>
#include <locale>

/**
* \mainpage
* \brief Лабораторная работа 2. ПИД-регуляторы
* \author Леонович А.А. АС-61
*/

using namespace std;

/**
 * @brief Абстрактный базовый класс для ПИД-регуляторов
 */
class AbsModPID
{
public:
    virtual ~AbsModPID() = default;

    /**
     * @brief Метод расчета ПИД-регулятора
     * @param current_temperature Текущая температура
     * @param teplo_vhod Входное значение тепла
     * @return Следующее значение температуры
     */
    virtual double calc_PID(double current_temperature, double teplo_vhod) = 0;
};

/**
 * @brief Класс для линейного ПИД-регулятора
 */
class Line_PID : public AbsModPID
{
private:
    double _a_, _b_, _nextY_;

public:
    /**
     * @brief Конструктор для линейной модели ПИД-регулятора
     * @param a Параметр a
     * @param b Параметр b
     * @param yNext Начальное значение отклика
     */
    Line_PID(double a, double b, double yNext) :
        _a_(a), _b_(b), _nextY_(yNext) { }

    /**
     * @brief Расчет следующего значения отклика
     */
    double calc_PID(double current_temperature, double teplo_vhod) override {
        _nextY_ = _a_ * current_temperature + _b_ * teplo_vhod;
        return _nextY_;
    }
};

/**
 * @brief Класс для нелинейного ПИД-регулятора
 */
class Non_line_PID : public AbsModPID
{
private:
    double _a_, _b_, _c_, _d_;
    double _prevY_ = 0;
    double _nextY_;
    double _prevW_ = 0;

public:
    /**
     * @brief Конструктор для нелинейной модели ПИД-регулятора
     */
    Non_line_PID(double a, double b, double c, double d, double yNext) :
        _a_(a), _b_(b), _c_(c), _d_(d), _nextY_(yNext) { }

    /**
     * @brief Расчет следующего значения отклика
     */
    double calc_PID(double current_temperature, double teplo_vhod) override {
        _nextY_ = _a_ * current_temperature - _b_ * pow(_prevY_, 2) + _c_ * teplo_vhod + _d_ * sin(_prevW_);
        _prevY_ = current_temperature;
        _prevW_ = teplo_vhod;
        return _nextY_;
    }
};

/**
 * @brief Класс для выполнения расчетов с ПИД-регулятором
 */
class regulator_detka
{
private:
    double _const_int_, _stepen_kvantovania_, _const_diferentsivania_, _koevicient_peredachi_;
    double zadanii_tochki = 0;

    /**
     * @brief Метод расчета корректирующего сигнала
     * @param _ek_b_1_ Переменная 1
     * @param _ek_b_2_ Переменная 2
     * @param _ek_b_3_ Переменная 3
     */
    double calculation_c_uk(double _ek_b_1_, double _ek_b_2_, double _ek_b_3_) {
        double _q1_ = _koevicient_peredachi_ * (1 + _const_diferentsivania_ / _stepen_kvantovania_);
        double _q2_ = -_koevicient_peredachi_ * (1 + 2 * _const_diferentsivania_ / _stepen_kvantovania_ - _stepen_kvantovania_ / _const_int_);
        double _q3_ = _koevicient_peredachi_ * _const_diferentsivania_ / _stepen_kvantovania_;
        zadanii_tochki += (_q1_ * _ek_b_1_ + _q2_ * _ek_b_2_ + _q3_ * _ek_b_3_);
        return zadanii_tochki;
    }

public:
    /**
     * @brief Конструктор регулятора
     * @param T Интегральная составляющая
     * @param T0 Дискретизация
     * @param TD Диф. составляющая
     * @param K Коэффициент передачи
     */
    regulator_detka(double T, double T0, double TD, double K) :
        _const_int_(T), _stepen_kvantovania_(T0), _const_diferentsivania_(TD), _koevicient_peredachi_(K) { }

    /**
     * @brief Метод для выполнения расчета и записи в файл
     */
    void _pid_calculate_write_(double neobhodima, double nach) {
        ofstream fout("results.txt");

        if (fout) {
            double _ek_b_1_, _ek_b_2_ = 0, _ek_b_3_ = 0;
            double y = nach, u;
            Line_PID linear(0.333, 0.667, 1);

            fout << "Линейная модель: " << endl;

            for (int i = 0; i < 50; ++i) {
                _ek_b_1_ = neobhodima - y;
                u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
                y = linear.calc_PID(nach, u);
                fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << endl;
                _ek_b_3_ = _ek_b_2_;
                _ek_b_2_ = _ek_b_1_;
            }

            _ek_b_2_ = 0;
            _ek_b_3_ = 0;
            y = nach;
            zadanii_tochki = 0;

            fout << "Нелинейная модель: " << endl;

            Non_line_PID nonLinear(1, 0.0033, 0.525, 0.525, 1);

            for (int i = 0; i < 50; ++i) {
                _ek_b_1_ = neobhodima - y;
                u = calculation_c_uk(_ek_b_1_, _ek_b_2_, _ek_b_3_);
                y = nonLinear.calc_PID(nach, u);
                fout << "E=" << _ek_b_1_ << " Y=" << y << " U=" << u << endl;
                _ek_b_3_ = _ek_b_2_;
                _ek_b_2_ = _ek_b_1_;
            }
        } else {
            cout << "Не удалось открыть файл для записи результатов." << endl;
        }
    }
};

int main() {
    locale::global(locale("ru_RU.UTF-8"));
    setlocale(LC_ALL, "ru_RU.UTF-8");

    regulator_detka object(10, 10, 40, 0.1);
    object._pid_calculate_write_(5, 2);

    cout << "Данные сохранены в файл results.txt" << endl;

    return 0;
}
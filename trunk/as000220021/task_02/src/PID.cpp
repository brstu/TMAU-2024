/**
 * @file PID.cpp
 *
 * @brief ‘айл содержит реализацию PID-контроллера.
 *
 * @author ѕоплавский ¬ладислав
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#include "PID.h"
#include "models.h"

 /**
  * @brief ћетод дл€ расчета управл€ющего сигнала по PID.
  *
  * ћетод вычисл€ет управл€ющий сигнал по PID, использу€ формулы:
  * Uk = Uk_1 + delta_Uk
  * delta_Uk = q0 * e0 + q1 * e1 + q2 * e2
  * q0 = K * (1 + TD / T0)
  * q1 = -K * (1 + 2 * TD / T0 - T0 / T)
  * q2 = K * TD / T0
  *
  * @param w ∆елаемое значение выходного сигнала.
  * @param T0 Ўаг времени.
  * @param temp ¬ектор выходных сигналов.
  */
void PID::calculate(const double& w, const double& T0, const std::vector<double>& temp) {
    double q0;
    double q1;
    double q2;
    double e0;
    double e1 = 0;
    double e2 = 0;
    double Uk;
    double delta_Uk;
    double Uk_1 = 0;
    for (const auto& y0 : temp) {
        e0 = w - y0;
        q0 = K * (1 + TD / T0);
        q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        q2 = K * TD / T0;
        delta_Uk = q0 * e0 + q1 * e1 + q2 * e2;
        Uk = Uk_1 + delta_Uk;
        Uk_1 = Uk;
        e2 = e1;
        e1 = e0;
        res_liner.push_back({ e0, y0, Uk });
    }
}

/**
 * @brief ћетод дл€ получени€ управл€ющих сигналов.
 *
 * ћетод возвращает вектор управл€ющих сигналов.
 *
 * @return ¬ектор управл€ющих сигналов.
 */
std::vector<std::vector<double>> PID::getControlSignals() const {
    return this->res_liner;
}
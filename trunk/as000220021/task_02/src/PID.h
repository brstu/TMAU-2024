/**
 * @file PID.h
 *
 * @brief Заголовочный файл содержит определение PID-контроллера.
 *
 * @author Поплавский Владислав
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#ifndef PID_S
#define PID_S

#include "models.h"
#include <vector>

 /**
  * @brief Класс реализует PID-контроллер.
  *
  * Класс содержит метод для расчета управляющего сигнала по PID.
  */
class PID {
private:
    /// Коэффициент K в PID-контроллере.
    const double K = 10;
    /// Коэффициент T в PID-контроллере.
    const double T = 0.1;
    /// Коэффициент TD в PID-контроллере.
    const double TD = 50;
    /// Вектор управляющих сигналов.
    std::vector<std::vector<double>> res_liner;

public:
    /**
     * @brief Метод для расчета управляющего сигнала по PID.
     *
     * @param error Вектор ошибок.
     */
    void calculate(const double& w, const double& T0, const std::vector <double>& temps_linear);
    /**
     * @brief Метод для получения управляющих сигналов.
     *
     * @return Вектор управляющих сигналов.
     */
    std::vector<std::vector<double>> getControlSignals() const;
};

#endif //PID_S
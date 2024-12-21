/**
 * @file PID.h
 *
 * @brief ������������ ���� �������� ����������� PID-�����������.
 *
 * @author ���������� ���������
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
  * @brief ����� ��������� PID-����������.
  *
  * ����� �������� ����� ��� ������� ������������ ������� �� PID.
  */
class PID {
private:
    /// ����������� K � PID-�����������.
    const double K = 10;
    /// ����������� T � PID-�����������.
    const double T = 0.1;
    /// ����������� TD � PID-�����������.
    const double TD = 50;
    /// ������ ����������� ��������.
    std::vector<std::vector<double>> res_liner;

public:
    /**
     * @brief ����� ��� ������� ������������ ������� �� PID.
     *
     * @param error ������ ������.
     */
    void calculate(const double& w, const double& T0, const std::vector <double>& temps_linear);
    /**
     * @brief ����� ��� ��������� ����������� ��������.
     *
     * @return ������ ����������� ��������.
     */
    std::vector<std::vector<double>> getControlSignals() const;
};

#endif //PID_S
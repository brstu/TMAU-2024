/**
 * @file models.h
 *
 * @brief ������������ ���� � ����������� �������� ������ ModelingObject
 * � ����������� ������� LinearModel � NonLinearModel.
 *
 * @author ���������� ���������
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <vector>

 /**
  * @brief ������� ����� ��� �������.
  *
  * ����� �������� ����������� ����� calculate(),
  * ����� print() � ����� getTemp().
  */
class ModelingObject {
public:
    /**
     * @brief ����������� ����� ��� ������� ����������.
     *
     * @param time �����.
     */
    virtual void calculate(const int& time) = 0;

    /**
     * @brief ����� ��� ������ ����������.
     *
     * @param temps �����������.
     * @param name ��� ������.
     */
    void print(const std::map<int, double>& temps, const std::string& name);

    /**
     * @brief ����� ��� ��������� ����������.
     *
     * @param temps �����������.
     * @return �����������.
     */
    std::vector<double> getTemp(const std::map<int, double>& temps);
};

/**
 * @brief ����� ��� �������� ������.
 *
 * ����� �������� �����������, ����� calculate(),
 * ����� print() � ����� getTemp().
 */
class LinearModel : public ModelingObject {
private:
    double A;
    double B;
    double current_temperature;
    double warm;
    std::map<int, double> temps;

public:
    /**
     * @brief �����������.
     *
     * @param a ����������� A.
     * @param b ����������� B.
     * @param current_temperature ������� �����������.
     * @param warm ����������� ��� �������.
     */
    LinearModel(double a, double b, double current_temperature, double warm);

    /**
     * @brief ����� ��� ������� ����������.
     *
     * @param time �����.
     */
    void calculate(const int& time);

    /**
     * @brief ����� ��� ������ ����������.
     */
    void print();

    /**
     * @brief ����� ��� ��������� ����������.
     *
     * @return �����������.
     */
    std::vector<double> getTemp();
};

/**
 * @brief ����� ��� ���������� ������.
 *
 * ����� �������� �����������, ����� calculate(),
 * ����� print() � ����� getTemp().
 */
class NonLinearModel : public ModelingObject {
private:
    double A;
    double B;
    double C;
    double D;
    double current_temperature;
    double previous_temperature;
    double warm;
    std::map<int, double> temps;

public:
    /**
     * @brief �����������.
     *
     * @param A ����������� A.
     * @param B ����������� B.
     * @param C ����������� C.
     * @param D ����������� D.
     * @param current_temperature ������� �����������.
     * @param warm ����������� ��� �������.
     */
    NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm);

    /**
     * @brief ����� ��� ������� ����������.
     *
     * @param time �����.
     */
    void calculate(const int& time);

    /**
     * @brief ����� ��� ������ ����������.
     */
    void print();

    /**
     * @brief ����� ��� ��������� ����������.
     *
     * @return �����������.
     */
    std::vector<double> getTemp();
};

#endif  // MODELS_H
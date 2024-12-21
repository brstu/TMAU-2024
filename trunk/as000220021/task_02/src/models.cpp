/**
 * @file models.cpp
 *
 * @brief ���� �������� ���������� �������� � ���������� �������.
 *
 * @author ���������� ���������
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#include "models.h"

 /**
  * @brief ������� ������� �����������, ������������ ����� �� �������.
  *
  * @param temps ����� ����������.
  * @param name ��� ������.
  */
void ModelingObject::print(const std::map<int, double>& temps, const std::string& name) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(10) << "�����";
    std::cout << std::setw(30) << name << std::endl;
    std::cout << std::setfill('=') << std::setw(25) << "" << std::setfill(' ') << std::endl;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        std::cout << std::setw(10) << it->first;
        std::cout << std::setw(30) << it->second << std::endl;
    }
}

/**
 * @brief ������� �������� �����������, ������������ ����� �� �������.
 *
 * @param temps ����� ����������.
 *
 * @return ������ ����������.
 */
std::vector<double> ModelingObject::getTemp(const std::map<int, double>& temps) {
    std::vector<double> temp;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        temp.push_back(it->second);
    }
    return temp;
}

/**
 * @brief ����������� ������ LinearModel.
 *
 * @param a ����������� a � �������� ������.
 * @param b ����������� b � �������� ������.
 * @param current_temperature ������� �����������.
 * @param warm ����������� ��� �������.
 */
LinearModel::LinearModel(double a, double b, double current_temperature, double warm)
    : A(a), B(b), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief ������� ��������� ����������� � ������� �������� ������.
 *
 * @param time �����.
 */
void LinearModel::calculate(const int& time) {
    double temp = current_temperature;
    for (int i = 1; i <= time; ++i) {
        temp = A * temp + B * warm;
        temps[i] = temp;
    }
}

/**
 * @brief ������� ������� �����������, ������������ �������� �������.
 */
void LinearModel::print() {
    ModelingObject::print(this->temps, "�������� ������");
}

/**
 * @brief ������� �������� �����������, ������������ �������� �������.
 *
 * @return ������ ����������.
 */
std::vector<double> LinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}

/**
 * @brief ����������� ������ NonLinearModel.
 *
 * @param A ����������� A � ���������� ������.
 * @param B ����������� B � ���������� ������.
 * @param C ����������� C � ���������� ������.
 * @param D ����������� D � ���������� ������.
 * @param current_temperature ������� �����������.
 * @param warm ����������� ��� �������.
 */
NonLinearModel::NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm)
    : A(A), B(B), C(C), D(D), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief ������� ��������� ����������� � ������� ���������� ������.
 *
 * @param time �����.
 */
void NonLinearModel::calculate(const int& time) {
    double curr_temp = current_temperature;
    double previous_temperature = 0.0;
    double buffer = 0.0;
    for (int i = 1; i <= time; ++i) {
        buffer = A * curr_temp - B * pow(previous_temperature, 2) + C * warm + D * sin(warm);
        previous_temperature = curr_temp;
        curr_temp = buffer;
        temps[i] = curr_temp;
    }
}

/**
 * @brief ������� ������� �����������, ������������ ���������� �������.
 */
void NonLinearModel::print() {
    ModelingObject::print(this->temps, "���������� ������");
}

/**
 * @brief ������� �������� �����������, ������������ ���������� �������.
 *
 * @return ������ ����������.
 */
std::vector<double> NonLinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}
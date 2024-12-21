/**
 * @file models.cpp
 *
 * @brief Файл содержит реализацию линейных и нелинейных моделей.
 *
 * @author Поплавский Владислав
 *
 * @version 1.0.0
 *
 * @date 21-09-2024
 */

#include "models.h"

 /**
  * @brief Функция выводит температуры, рассчитанные одной из моделей.
  *
  * @param temps Карта температур.
  * @param name Имя модели.
  */
void ModelingObject::print(const std::map<int, double>& temps, const std::string& name) {
    std::cout.setf(std::ios::left);
    std::cout << std::setw(10) << "ВРЕМЯ";
    std::cout << std::setw(30) << name << std::endl;
    std::cout << std::setfill('=') << std::setw(25) << "" << std::setfill(' ') << std::endl;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        std::cout << std::setw(10) << it->first;
        std::cout << std::setw(30) << it->second << std::endl;
    }
}

/**
 * @brief Функция получает температуры, рассчитанные одной из моделей.
 *
 * @param temps Карта температур.
 *
 * @return Вектор температур.
 */
std::vector<double> ModelingObject::getTemp(const std::map<int, double>& temps) {
    std::vector<double> temp;
    for (auto it = temps.begin(); it != temps.end(); ++it) {
        temp.push_back(it->second);
    }
    return temp;
}

/**
 * @brief Конструктор класса LinearModel.
 *
 * @param a Коэффициент a в линейной модели.
 * @param b Коэффициент b в линейной модели.
 * @param current_temperature Текущая температура.
 * @param warm Температура для нагрева.
 */
LinearModel::LinearModel(double a, double b, double current_temperature, double warm)
    : A(a), B(b), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief Функция вычисляет температуры с помощью линейной модели.
 *
 * @param time Время.
 */
void LinearModel::calculate(const int& time) {
    double temp = current_temperature;
    for (int i = 1; i <= time; ++i) {
        temp = A * temp + B * warm;
        temps[i] = temp;
    }
}

/**
 * @brief Функция выводит температуры, рассчитанные линейной моделью.
 */
void LinearModel::print() {
    ModelingObject::print(this->temps, "ЛИНЕЙНАЯ МОДЕЛЬ");
}

/**
 * @brief Функция получает температуры, рассчитанные линейной моделью.
 *
 * @return Вектор температур.
 */
std::vector<double> LinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}

/**
 * @brief Конструктор класса NonLinearModel.
 *
 * @param A Коэффициент A в нелинейной модели.
 * @param B Коэффициент B в нелинейной модели.
 * @param C Коэффициент C в нелинейной модели.
 * @param D Коэффициент D в нелинейной модели.
 * @param current_temperature Текущая температура.
 * @param warm Температура для нагрева.
 */
NonLinearModel::NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm)
    : A(A), B(B), C(C), D(D), current_temperature(current_temperature), warm(warm) {}

/**
 * @brief Функция вычисляет температуры с помощью нелинейной модели.
 *
 * @param time Время.
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
 * @brief Функция выводит температуры, рассчитанные нелинейной моделью.
 */
void NonLinearModel::print() {
    ModelingObject::print(this->temps, "НЕЛИНЕЙНАЯ МОДЕЛЬ");
}

/**
 * @brief Функция получает температуры, рассчитанные нелинейной моделью.
 *
 * @return Вектор температур.
 */
std::vector<double> NonLinearModel::getTemp() {
    return ModelingObject::getTemp(this->temps);
}
/**
 * @file models.h
 *
 * @brief Заголовочный файл с объявлением базового класса ModelingObject
 * и производных классов LinearModel и NonLinearModel.
 *
 * @author Поплавский Владислав
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
  * @brief Базовый класс для моделей.
  *
  * Класс содержит виртуальный метод calculate(),
  * метод print() и метод getTemp().
  */
class ModelingObject {
public:
    /**
     * @brief Виртуальный метод для расчета температур.
     *
     * @param time Время.
     */
    virtual void calculate(const int& time) = 0;

    /**
     * @brief Метод для вывода температур.
     *
     * @param temps Температуры.
     * @param name Имя модели.
     */
    void print(const std::map<int, double>& temps, const std::string& name);

    /**
     * @brief Метод для получения температур.
     *
     * @param temps Температуры.
     * @return Температуры.
     */
    std::vector<double> getTemp(const std::map<int, double>& temps);
};

/**
 * @brief Класс для линейной модели.
 *
 * Класс содержит конструктор, метод calculate(),
 * метод print() и метод getTemp().
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
     * @brief Конструктор.
     *
     * @param a Коэффициент A.
     * @param b Коэффициент B.
     * @param current_temperature Текущая температура.
     * @param warm Температура для нагрева.
     */
    LinearModel(double a, double b, double current_temperature, double warm);

    /**
     * @brief Метод для расчета температур.
     *
     * @param time Время.
     */
    void calculate(const int& time);

    /**
     * @brief Метод для вывода температур.
     */
    void print();

    /**
     * @brief Метод для получения температур.
     *
     * @return Температуры.
     */
    std::vector<double> getTemp();
};

/**
 * @brief Класс для нелинейной модели.
 *
 * Класс содержит конструктор, метод calculate(),
 * метод print() и метод getTemp().
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
     * @brief Конструктор.
     *
     * @param A Коэффициент A.
     * @param B Коэффициент B.
     * @param C Коэффициент C.
     * @param D Коэффициент D.
     * @param current_temperature Текущая температура.
     * @param warm Температура для нагрева.
     */
    NonLinearModel(double A, double B, double C, double D, double current_temperature, double warm);

    /**
     * @brief Метод для расчета температур.
     *
     * @param time Время.
     */
    void calculate(const int& time);

    /**
     * @brief Метод для вывода температур.
     */
    void print();

    /**
     * @brief Метод для получения температур.
     *
     * @return Температуры.
     */
    std::vector<double> getTemp();
};

#endif  // MODELS_H
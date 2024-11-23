# SummaryNon_line_PID

| Members                                  | Descriptions                                                 |
|------------------------------------------|--------------------------------------------------------------|
| `class `[`AbsModPID`](#class-AbsModPID)        | Данный класс необходим классам, рассчитывающим нелинейную и линейную модели ПИД-регулятора |
| `class `[`Line_PID`](#class-Line_PID)           | Класс для реализации линейной модели ПИД-регулятора           |
| `class `[`regulator_detka`](#class-regulator_detka) | Класс регулятора                                              |
| `class `[`Non_line_PID`](#class-Non_line_PID)      | Класс для реализации нелинейной модели ПИД-регулятора        |

---

# class `AbsModPID`

Класс, предоставляющий интерфейс для расчетов линейной и нелинейной моделей ПИД-регулятора. Содержит виртуальную функцию `_calculate_pid_model`, которая переопределяется в дочерних классах ([Line_PID](#class-Line_PID) и [Non_line_PID](#class-Non_line_PID)).

## Summary

| Members                                                   | Descriptions                                                                      |
|-----------------------------------------------------------|------------------------------------------------------------------------------------|
| `public virtual ~AbsModPID()`                             | Деструктор по умолчанию                                                           |
| `public double _calculate_pid_model(double, double)`      | Виртуальная функция, переопределенная в дочерних классах для расчета модели ПИД-регулятора |

## Members

### `public virtual ~AbsModPID()`

Деструктор по умолчанию.

### `public double _calculate_pid_model(double current_temperature, double teplo_vhod)`

Виртуальная функция для расчета модели ПИД-регулятора, переопределенная в дочерних классах ([Line_PID](#class-Line_PID) и [Non_line_PID](#class-Non_line_PID)).

* **Параметры:**
  - `current_temperature` — текущая температура помещения.
  - `teplo_vhod` — входное тепло.

---

# class `Line_PID`

Класс для реализации линейной модели ПИД-регулятора. Наследует [AbsModPID](#class-AbsModPID) и реализует линейную модель через функцию `_calculate_pid_model`.

## Summary

| Members                                                 | Descriptions                                                     |
|---------------------------------------------------------|-------------------------------------------------------------------|
| `public inline Line_PID(double a, double b, double yNext)` | Конструктор класса                                               |
| `public inline virtual double _calculate_pid_model(double, double)` | Метод для расчета линейной модели ПИД-регулятора                   |

## Members

### `public inline Line_PID(double a, double b, double yNext)`

Конструктор класса.

### `public inline virtual double _calculate_pid_model(double current_temperature, double teplo_vhod)`

Метод для расчета линейной модели ПИД-регулятора.

Код:
```cpp
nextY__ = a_ * current_temperature + b_ * teplo_vhod;
return nextY__;
```

---

# class `Non_line_PID`

Класс для реализации нелинейной модели ПИД-регулятора. Наследует [AbsModPID](#class-AbsModPID) и реализует нелинейную модель через функцию `_calculate_pid_model`.

## Summary

| Members                                                   | Descriptions                                                 |
|-----------------------------------------------------------|---------------------------------------------------------------|
| `public inline Non_line_PID(double a, double b, double c, double d, double yNext)` | Конструктор класса                                            |
| `public inline virtual double _calculate_pid_model(double, double)` | Метод для расчета нелинейной модели ПИД-регулятора            |

## Members

### `public inline Non_line_PID(double a, double b, double c, double d, double yNext)`

Конструктор класса.

### `public inline virtual double _calculate_pid_model(double current_temperature, double teplo_vhod)`

Метод для расчета нелинейной модели ПИД-регулятора.

Код:
```cpp
nextY__ = a_ * current_temperature - b_ * pow(prevY__, 2) + c_ * teplo_vhod + d_ * sin(prevW__);
prevY__ = nextY__;
prevW__ = teplo_vhod;
return nextY__;
```

---

# class `regulator_detka`

Класс для реализации регулятора.

## Summary

| Members                                                   | Descriptions                                                |
|-----------------------------------------------------------|--------------------------------------------------------------|
| `public inline regulator_detka(double T, double T0, double TD, double K)` | Конструктор класса                                         |
| `public inline void pid_calculate_write(double need, double start)` | Метод для выполнения расчета и записи параметров регулятора |

## Members

### `public inline regulator_detka(double T, double T0, double TD, double K)`

Конструктор класса.

### `public inline void pid_calculate_write(double need, double start)`

Метод для расчета параметров регулятора.

---

Сохраните этот файл под названием `moxygen.md`. Этот формат документации может быть использован для создания HTML-страниц с подробным описанием всех классов и методов с помощью системы генерации документации, такой как Doxygen или аналогичные инструменты.
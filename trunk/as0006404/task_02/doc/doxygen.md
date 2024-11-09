# Обзор

Элементы                      | Описание                                
--------------------------------|---------------------------------------------
`class `[`TemperatureModel`](#class_temperature_model) | Абстрактный класс, служащий основой для температурных моделей.
`class `[`LinearTemperatureModel`](#class_linear_temperature_model) | Линейная модель, используемая для вычисления температуры.
`class `[`NonlinearTemperatureModel`](#class_nonlinear_temperature_model) | Нелинейная модель для расчета температурных значений.
`class `[`TemperatureControlSystem`](#class_temperature_control_system) | Система управления на основе пропорционально-интегрально-дифференциального подхода.

## class `TemperatureModel`

Абстрактный класс, предназначенный для представления температурных моделей.

### Обзор

Элементы                      | Описание                                
--------------------------------|---------------------------------------------
`public virtual double `[`calculateTemperature`](#class_temperature_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemperature, double heatInput) = 0` | Функция для вычисления температуры на основе текущего значения и теплового ввода.
`public virtual  `[`~TemperatureModel`](#class_temperature_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Стандартный деструктор.

### Элементы

#### `public virtual double `[`calculateTemperature`](#class_temperature_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemperature, double heatInput) = 0`

Функция, вычисляющая выходную температуру на основе входной температуры и теплового потока.

**Параметры**
* `currentTemperature` - Значение текущей температуры.
* `heatInput` - Величина теплового потока.

#### `public virtual  `[`~TemperatureModel`](#class_temperature_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Уничтожает экземпляр `TemperatureModel`.

## class `LinearTemperatureModel`

Линейная модель для вычисления температуры.

### Обзор

Элементы                      | Описание                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearTemperatureModel`](#class_linear_temperature_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)` | Конструктор линейной модели с заданными параметрами.
`public inline virtual double `[`calculateTemperature`](#class_linear_temperature_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemperature, double heatInput)` | Функция для вычисления температуры в рамках линейной модели.
`public virtual  `[`~LinearTemperatureModel`](#class_linear_temperature_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Стандартный деструктор.

### Элементы

#### `public inline  `[`LinearTemperatureModel`](#class_linear_temperature_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)`

Создает новый объект `LinearTemperatureModel` с указанными параметрами.

**Параметры**
* `a` - Коэффициент линейной зависимости для текущей температуры.
* `b` - Коэффициент для теплового ввода.

#### `public inline virtual double `[`calculateTemperature`](#class_linear_temperature_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemperature, double heatInput)`

Функция, вычисляющая выходную температуру с использованием линейной модели.

#### `public virtual  `[`~LinearTemperatureModel`](#class_linear_temperature_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Уничтожает экземпляр `LinearTemperatureModel`.

## class `NonlinearTemperatureModel`

Нелинейная модель для вычисления температуры.

### Обзор

Элементы                      | Описание                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearTemperatureModel`](#class_nonlinear_temperature_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double c1, double c2, double c3, double c4)` | Конструктор для нелинейной модели с определенными параметрами.
`public inline virtual double `[`calculateTemperature`](#class_nonlinear_temperature_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemperature, double heatInput)` | Функция для вычисления температуры в рамках нелинейной модели.
`public virtual  `[`~NonlinearTemperatureModel`](#class_nonlinear_temperature_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Стандартный деструктор.

### Элементы

#### `public inline  `[`NonlinearTemperatureModel`](#class_nonlinear_temperature_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double c1, double c2, double c3, double c4)`

Создает новый объект `NonlinearTemperatureModel` с указанными параметрами.

**Параметры**
* `c1` - Коэффициент для текущей температуры.
* `c2` - Коэффициент для квадрата предыдущего значения температуры.
* `c3` - Коэффициент для теплового ввода.
* `c4` - Коэффициент для синуса предыдущего теплового ввода.

#### `public inline virtual double `[`calculateTemperature`](#class_nonlinear_temperature_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemperature, double heatInput)`

Функция, вычисляющая выходную температуру на основе нелинейной модели.

#### `public virtual  `[`~NonlinearTemperatureModel`](#class_nonlinear_temperature_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Уничтожает экземпляр `NonlinearTemperatureModel`.

## class `TemperatureControlSystem`

Система управления, основанная на пропорционально-интегрально-дифференциальном подходе, для моделирования температурного контроля.

### Обзор

Элементы                      | Описание                                
--------------------------------|---------------------------------------------
`public void `[`runSimulation`](#class_temperature_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemperature, double initialTemperature, TemperatureModel& model)` | Имитация работы системы управления для температурной модели.
`private double `[`calculateControlSignal`](#class_temperature_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error, double previousError1, double previousError2)` | Вычисляет управляющий сигнал на основе текущей и предыдущих ошибок.

### Элементы

#### `public void `[`runSimulation`](#class_temperature_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemperature, double initialTemperature, TemperatureModel& model)`

Имитация системы управления температурой для заданной целевой температуры и модели.

**Параметры**
* `targetTemperature` - Желаемое значение температуры.
* `initialTemperature` - Начальное значение температуры.
* `model` - Используемая модель температуры в процессе симуляции.

#### `private double `[`calculateControlSignal`](#class_temperature_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error, double previousError1, double previousError2)`

Вычисление управляющего сигнала на основании текущей и предыдущих ошибок.

**Параметры**
* `error` - Текущая ошибка.
* `previousError1` - Ошибка предыдущего шага.
* `previousError2` - Ошибка на два шага назад.
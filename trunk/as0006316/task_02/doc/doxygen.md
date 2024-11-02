# Резюме

| Members                         | Descriptions                                                               
| ------------------------------- | ---------------------------------------------------------------------------
| `class `[`Model`](#class_model) | Абстрактный базовый класс для математических моделей.                       |
| `class `[`LinearModel`](#class_linear_model) | Реализация линейной модели для расчетов.                               |
| `class `[`NonlinearModel`](#class_nonlinear_model) | Реализация нелинейной модели для расчетов.                           |
| `class `[`PIDRegulator`](#class_pid_regulator) | Пропорционально-интегрально-дифференциальный контроллер для симуляции. |

# class `Model`

Абстрактный класс, представляющий математическую модель.

## Резюме

| Members                         | Descriptions                                                               
| ------------------------------- | ---------------------------------------------------------------------------
| `public virtual double `[`simulate_temperature`](#class_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp, double externalInput) = 0` | Вычисляет выходные значения на основе текущей температуры и внешнего воздействия. |
| `public virtual  `[`~Model`](#class_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Дефолтный деструктор.                                                    |

## Members

#### `public virtual double `[`simulate_temperature`](#class_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp, double externalInput) = 0`

Вычисляет выход на основе входных параметров.

##### Параметры
* `currentTemp` - Текущая температура.
* `externalInput` - Внешнее воздействие.

#### `public virtual  `[`~Model`](#class_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Уничтожает объект `Model`.

# class `LinearModel`

Реализация линейной модели для расчетов.

## Резюме

| Members                         | Descriptions                                                               
| ------------------------------- | ---------------------------------------------------------------------------
| `public inline  `[`LinearModel`](#class_linear_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)` | Конструирует линейную модель с заданными параметрами.                   |
| `public inline virtual double `[`simulate_temperature`](#class_linear_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp, double externalInput)` | Вычисляет выход для линейной модели.                                     |
| `public virtual  `[`~LinearModel`](#class_linear_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Дефолтный деструктор.                                                   |

## Members

#### `public inline  `[`LinearModel`](#class_linear_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)`

Конструирует новый объект `LinearModel` с заданными параметрами.

##### Параметры
* `a` - Коэффициент для текущего значения.
* `b` - Коэффициент для входного значения.

#### `public inline virtual double `[`simulate_temperature`](#class_linear_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp, double externalInput)`

Вычисляет выход на основе линейной модели.

#### `public virtual  `[`~LinearModel`](#class_linear_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Уничтожает объект `LinearModel`.

# class `NonlinearModel`

Реализация нелинейной модели для расчетов.

## Резюме

| Members                         | Descriptions                                                               
| ------------------------------- | ---------------------------------------------------------------------------
| `public inline  `[`NonlinearModel`](#class_nonlinear_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)` | Конструирует нелинейную модель с заданными параметрами.                 |
| `public inline virtual double `[`simulate_temperature`](#class_nonlinear_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp, double externalInput)` | Вычисляет выход для нелинейной модели.                                   |
| `public virtual  `[`~NonlinearModel`](#class_nonlinear_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Дефолтный деструктор.                                                   |

## Members

#### `public inline  `[`NonlinearModel`](#class_nonlinear_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)`

Конструирует новый объект `NonlinearModel` с заданными параметрами.

##### Параметры
* `a` - Коэффициент для текущего значения.
* `b` - Коэффициент для квадрата предыдущего значения.
* `c` - Коэффициент для входного значения.
* `d` - Коэффициент для синуса входного значения.

#### `public inline virtual double `[`simulate_temperature`](#class_nonlinear_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp, double externalInput)`

Вычисляет выход на основе нелинейной модели.

#### `public virtual  `[`~NonlinearModel`](#class_nonlinear_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Уничтожает объект `NonlinearModel`.

# class `PIDRegulator`

Пропорционально-интегрально-дифференциальный контроллер для симуляции.

## Резюме

| Members                         | Descriptions                                                               
| ------------------------------- | ---------------------------------------------------------------------------
| `public void `[`regulate`](#class_pid_regulator_1acb8cf7932d39a2bcd053dc22bca24672)`(double desiredValue, double initialValue, Model& model)` | Выполняет регулирование на основе заданного значения и начальной температуры. |
| `private double `[`controlSignal`](#class_pid_regulator_1a7dcb55c416527f9644de795b6ff16f3b)` | Хранит текущее значение управляющего сигнала.                            |
| `private const double `[`gainK`](#class_pid_regulator_1a7dcb55c416527f9644de795b6ff16f3b)` | Коэффициент усиления.                                                   |

## Members

#### `public void `[`regulate`](#class_pid_regulator_1acb8cf7932d39a2bcd053dc22bca24672)`(double desiredValue, double initialValue, Model& model)`

Выполняет регулирование, используя модель для расчета температуры.

##### Параметры
* `desiredValue` - Желаемое значение температуры.
* `initialValue` - Начальное значение температуры.
* `model` - Модель, используемая для симуляции.

#### `private double `[`controlSignal`](#class_pid_regulator_1a7dcb55c416527f9644de795b6ff16f3b)`

Текущее значение управляющего сигнала, используемого в расчетах.

#### `private const double `[`gainK`](#class_pid_regulator_1a7dcb55c416527f9644de795b6ff16f3b)`

Коэффициент, определяющий реакцию регулятора на ошибку.
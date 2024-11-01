# Резюме

 Members                         | Descriptions                                                               
-------------------------------|---------------------------------------------
`class `[`Model`](#class_model) | Абстрактный базовый класс для математических моделей.
`class `[`Linear`](#class_linear) | Реализация линейной модели для расчетов.
`class `[`NonLinear`](#class_nonlinear) | Реализация нелинейной модели для расчетов.
`class `[`PID`](#class_pid) | Пропорционально-интегрально-дифференциальный контроллер для симуляции.

# class `Model`

Абстрактный класс, представляющий математическую модель.

## Резюме

 Members                         | Descriptions                                                               
-------------------------------|---------------------------------------------
`public virtual double `[`compute`](#class_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double current, double previous, double input) = 0` | Вычисляет выходные значения на основе текущих, предыдущих и входных значений.
`public virtual  `[`~Model`](#class_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Дефолтный деструктор.

## Members

#### `public virtual double `[`compute`](#class_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double current, double previous, double input) = 0`

Вычисляет выход на основе входных параметров.

#### Параметры
* `current` - Текущая величина.
* `previous` - Предыдущая величина.
* `input` - Входная величина.

#### `public virtual  `[`~Model`](#class_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Уничтожает объект `Model`.

# class `Linear`

Реализация линейной модели для расчетов.

## Резюме

 Members                         | Descriptions                                                               
-------------------------------|---------------------------------------------
`public inline  `[`Linear`](#class_linear_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)` | Конструирует линейную модель с заданными параметрами.
`public inline virtual double `[`compute`](#class_linear_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double current, double previous, double input)` | Вычисляет выход для линейной модели.
`public virtual  `[`~Linear`](#class_linear_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Дефолтный деструктор.

## Members

#### `public inline  `[`Linear`](#class_linear_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double a, double b)`

Конструирует новый объект `Linear` с заданными параметрами.

#### Параметры
* `a` - Коэффициент для текущего значения.
* `b` - Коэффициент для входного значения.

#### `public inline virtual double `[`compute`](#class_linear_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double current, double previous, double input)`

Вычисляет выход на основе линейной модели.

#### `public virtual  `[`~Linear`](#class_linear_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Уничтожает объект `Linear`.

# class `NonLinear`

Реализация нелинейной модели для расчетов.

## Резюме

 Members                         | Descriptions                                                               
-------------------------------|---------------------------------------------
`public inline  `[`NonLinear`](#class_nonlinear_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)` | Конструирует нелинейную модель с заданными параметрами.
`public inline virtual double `[`compute`](#class_nonlinear_1a25dc6765a041b63ec20976f80ad23fa4)`(double current, double previous, double input)` | Вычисляет выход для нелинейной модели.
`public virtual  `[`~NonLinear`](#class_nonlinear_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Дефолтный деструктор.

## Members

#### `public inline  `[`NonLinear`](#class_nonlinear_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)`

Конструирует новый объект `NonLinear` с заданными параметрами.

#### Параметры
* `a` - Коэффициент для текущего значения.
* `b` - Коэффициент для квадрата предыдущего значения.
* `c` - Коэффициент для входного значения.
* `d` - Коэффициент для синуса входного значения.

#### `public inline virtual double `[`compute`](#class_nonlinear_1a25dc6765a041b63ec20976f80ad23fa4)`(double current, double previous, double input)`

Вычисляет выход на основе нелинейной модели.

#### `public virtual  `[`~NonLinear`](#class_nonlinear_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Уничтожает объект `NonLinear`.

# class `PID`

Пропорционально-интегрально-дифференциальный контроллер для симуляции.

## Резюме

 Members                         | Descriptions                                                               
-------------------------------|---------------------------------------------
`public double `[`control`](#class_pid_1acb8cf7932d39a2bcd053dc22bca24672)`(double error)` | Вычисляет управляющий сигнал на основе ошибки.
`private double `[`lastError`](#class_pid_1a7dcb55c416527f9644de795b6ff16f3b)` | Хранит значение последней ошибки.
`private double `[`integralError`](#class_pid_1a7dcb55c416527f9644de795b6ff16f3b)` | Хранит интеграл ошибок.

## Members

#### `public double `[`control`](#class_pid_1acb8cf7932d39a2bcd053dc22bca24672)`(double error)`

Вычисляет управляющий сигнал на основе текущей ошибки.

#### Параметры
* `error` - Текущее значение ошибки.

#### `private double `[`lastError`](#class_pid_1a7dcb55c416527f9644de795b6ff16f3b)`

Значение последней ошибки, используемое в расчетах PID.

#### `private double `[`integralError`](#class_pid_1a7dcb55c416527f9644de795b6ff16f3b)`

Интеграл предыдущих ошибок, используемый для расчетов PID.
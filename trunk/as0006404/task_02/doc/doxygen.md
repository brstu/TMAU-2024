# Обзор


- `class `[`TempEquation`](#class_temp_equation)  Абстрактный класс, служащий основой для температурных уравнений.
- `class `[`SimpleTempEquation`](#class_simple_temp_equation) Простое уравнение, используемое для вычисления температуры.
- `class `[`ComplexTempEquation`](#class_complex_temp_equation) Сложное уравнение для расчета температурных значений.
- `class `[`ControlUnit`](#class_control_unit) Система управления, моделирующая температурный контроль.

## class `TempEquation`

Абстрактный класс, предназначенный для представления температурных уравнений.

### Обзор


- `public virtual double `[`compute`](#class_temp_equation_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentState, double powerInput) = 0` | Функция для вычисления температуры на основе текущего состояния и теплового ввода.
- `public virtual  `[`~TempEquation`](#class_temp_equation_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Стандартный деструктор.

### Элементы

- #### `public virtual double `[`compute`](#class_temp_equation_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentState, double powerInput) = 0`

Функция, вычисляющая выходное значение на основе входного состояния и теплового потока.

**Параметры**
* `currentState` - Значение текущего состояния.
* `powerInput` - Величина теплового ввода.

#### `public virtual  `[`~TempEquation`](#class_temp_equation_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Уничтожает экземпляр `TempEquation`.

## class `SimpleTempEquation`

Простое уравнение для вычисления температуры.

### Обзор


- `public inline  `[`SimpleTempEquation`](#class_simple_temp_equation_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double x, double y)` | Конструктор простого уравнения с заданными параметрами.
- `public inline virtual double `[`compute`](#class_simple_temp_equation_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentState, double powerInput)` | Функция для вычисления состояния в рамках простого уравнения.
- `public virtual  `[`~SimpleTempEquation`](#class_simple_temp_equation_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Стандартный деструктор.

### Элементы

#### `public inline  `[`SimpleTempEquation`](#class_simple_temp_equation_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double x, double y)`

Создает новый объект `SimpleTempEquation` с указанными параметрами.

**Параметры**
- `x` - Коэффициент для текущего состояния.
- `y` - Коэффициент для теплового ввода.

#### `public inline virtual double `[`compute`](#class_simple_temp_equation_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentState, double powerInput)`

Функция, вычисляющая выходное значение с использованием простого уравнения.

#### `public virtual  `[`~SimpleTempEquation`](#class_simple_temp_equation_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Уничтожает экземпляр `SimpleTempEquation`.

## class `ComplexTempEquation`

Сложное уравнение для вычисления температуры.

### Обзор


- `public inline  `[`ComplexTempEquation`](#class_complex_temp_equation_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)` | Конструктор для сложного уравнения с определенными параметрами.
- `public inline virtual double `[`compute`](#class_complex_temp_equation_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentState, double powerInput)` | Функция для вычисления состояния в рамках сложного уравнения.
- `public virtual  `[`~ComplexTempEquation`](#class_complex_temp_equation_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Стандартный деструктор.

### Элементы

#### `public inline  `[`ComplexTempEquation`](#class_complex_temp_equation_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double a, double b, double c, double d)`

Создает новый объект `ComplexTempEquation` с указанными параметрами.

**Параметры**
- `a` - Коэффициент для текущего состояния.
- `b` - Коэффициент для квадрата предыдущего состояния.
- `c` - Коэффициент для теплового ввода.
- `d` - Коэффициент для синуса предыдущего теплового ввода.

#### `public inline virtual double `[`compute`](#class_complex_temp_equation_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentState, double powerInput)`

Функция, вычисляющая выходное значение на основе сложного уравнения.

#### `public virtual  `[`~ComplexTempEquation`](#class_complex_temp_equation_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Уничтожает экземпляр `ComplexTempEquation`.

## class `ControlUnit`

Система управления для моделирования температурного контроля.

### Обзор


- `public void `[`simulate`](#class_control_unit_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetState, double initialState, TempEquation& equation)` | Имитация работы системы управления для температурного уравнения.
- `private double `[`computeSignal`](#class_control_unit_1a7dcb55c416527f9644de795b6ff16f3b)`(double deviation, double prevDeviation1, double prevDeviation2)` | Вычисляет управляющий сигнал на основе текущих и предыдущих отклонений.

### Элементы

#### `public void `[`simulate`](#class_control_unit_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetState, double initialState, TempEquation& equation)`

Имитация системы управления температурой для заданного состояния.

**Параметры**
* `targetState` - Желаемое значение состояния.
* `initialState` - Начальное значение состояния.
* `equation` - Используемое уравнение в процессе симуляции.

#### `private double `[`computeSignal`](#class_control_unit_1a7dcb55c416527f9644de795b6ff16f3b)`(double deviation, double prevDeviation1, double prevDeviation2)`

Вычисление управляющего сигнала на основании текущих и предыдущих отклонений.

**Параметры**
* `deviation` - Текущее отклонение.
* `prevDeviation1` - Отклонение предыдущего шага.
* `prevDeviation2` - Отклонение на два шага назад.
# Резюме

Члены                        | Описание                                
--------------------------------|---------------------------------------------
`class `[`TempModel`](#class_temp_model) | Абстрактный базовый класс для моделей температуры.
`class `[`LinearTempModel`](#class_linear_temp_model) | Линейная модель для расчета температуры.
`class `[`NonlinearTempModel`](#class_nonlinear_temp_model) | Нелинейная модель для расчета температуры.
`class `[`ControlSystem`](#class_control_system) | Пропорционально-интегрально-дифференциальная система управления.

## class `TempModel`

Абстрактный класс, представляющий модель температуры.

### Резюме

Члены                        | Описание                                
--------------------------------|---------------------------------------------
`public virtual double `[`computeTemperature`](#class_temp_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp,double heatInput) = 0` | Вычисляет температуру на основе текущей температуры и теплового потока.
`public virtual  `[`~TempModel`](#class_temp_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Дефолтный деструктор.

### Члены

#### `public virtual double `[`computeTemperature`](#class_temp_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp,double heatInput) = 0`

Вычисляет выходную температуру на основе входной температуры и теплового потока.

**Параметры**
* `currentTemp` - Текущая температура.
* `heatInput` - Значение теплового потока.

#### `public virtual  `[`~TempModel`](#class_temp_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Уничтожает объект `TempModel`.

## class `LinearTempModel`

Линейная модель для расчета температуры.

### Резюме

Члены                        | Описание                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearTempModel`](#class_linear_temp_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double param1,double param2)` | Конструирует линейную модель с заданными параметрами.
`public inline virtual double `[`computeTemperature`](#class_linear_temp_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp,double heatInput)` | Вычисляет температуру для линейной модели.
`public virtual  `[`~LinearTempModel`](#class_linear_temp_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Дефолтный деструктор.

### Члены

#### `public inline  `[`LinearTempModel`](#class_linear_temp_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double param1,double param2)`

Конструирует новый объект `LinearTempModel` с заданными параметрами.

**Параметры**
* `param1` - Линейный коэффициент для текущей температуры.
* `param2` - Коэффициент для теплового потока.

#### `public inline virtual double `[`computeTemperature`](#class_linear_temp_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp,double heatInput)`

Вычисляет выходную температуру на основе линейной модели.

#### `public virtual  `[`~LinearTempModel`](#class_linear_temp_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Уничтожает объект `LinearTempModel`.

## class `NonlinearTempModel`

Нелинейная модель для расчета температуры.

### Резюме

Члены                        | Описание                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearTempModel`](#class_nonlinear_temp_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double param1,double param2,double param3,double param4)` | Конструирует нелинейную модель с заданными параметрами.
`public inline virtual double `[`computeTemperature`](#class_nonlinear_temp_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp,double heatInput)` | Вычисляет температуру для нелинейной модели.
`public virtual  `[`~NonlinearTempModel`](#class_nonlinear_temp_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Дефолтный деструктор.

### Члены

#### `public inline  `[`NonlinearTempModel`](#class_nonlinear_temp_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double param1,double param2,double param3,double param4)`

Конструирует новый объект `NonlinearTempModel` с заданными параметрами.

**Параметры**
* `param1` - Коэффициент для текущей температуры.
* `param2` - Коэффициент для квадрата предыдущей температуры.
* `param3` - Коэффициент для теплового потока.
* `param4` - Коэффициент для синуса предыдущего теплового потока.

#### `public inline virtual double `[`computeTemperature`](#class_nonlinear_temp_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp,double heatInput)`

Вычисляет выходную температуру на основе нелинейной модели.

#### `public virtual  `[`~NonlinearTempModel`](#class_nonlinear_temp_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Уничтожает объект `NonlinearTempModel`.

## class `ControlSystem`

Пропорционально-интегрально-дифференциальная система управления для моделирования контроля температуры.

### Резюме

Члены                        | Описание                                
--------------------------------|---------------------------------------------
`public void `[`simulate`](#class_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemp,double initialTemp,`[`TempModel`](#class_temp_model)` & model)` | Моделирует систему управления для модели температуры.
`private double `[`computeControlSignal`](#class_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error,double prevError1,double prevError2)` | Вычисляет управляющий сигнал для данной ошибки.

### Члены

#### `public void `[`simulate`](#class_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemp,double initialTemp,`[`TempModel`](#class_temp_model)` & model)`

Моделирует систему управления температурой для заданной целевой температуры и модели.

**Параметры**
* `targetTemp` - Желаемая температура.
* `initialTemp` - Начальная температура.
* `model` - Модель температуры, используемая в симуляции.

#### `private double `[`computeControlSignal`](#class_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error,double prevError1,double prevError2)`

Вычисляет управляющий сигнал на основе ошибки и предыдущих ошибок.

**Параметры**
* `error` - Текущая ошибка.
* `prevError1` - Предыдущая ошибка.
* `prevError2` - Ошибка два шага назад.
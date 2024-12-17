# Обзор

- `class` [`TemperatureModel`](#class_temperaturemodel)  
  Абстрактный базовый класс для моделирования температурных систем.
- `class` [`LinearModel`](#class_linearmodel)  
  Реализация линейной модели для расчета температуры.
- `class` [`NonlinearModel`](#class_nonlinearmodel)  
  Сложная модель для нелинейного расчета температуры.
- `class` [`ControlSystem`](#class_controlsystem)  
  Система управления для моделирования температурного контроля.

## class `TemperatureModel`

Абстрактный базовый класс для представления температурных моделей.

### Обзор

- `public virtual double `[`computeTemperature`](#class_temperaturemodel_1a09)`(double currentTemp, double heatInput) = 0`  
  Вычисляет температуру на основе текущего состояния и теплового ввода.
- `public virtual `[`~TemperatureModel`](#class_temperaturemodel_1a10)`() = default`  
  Деструктор.

### Элементы

#### `public virtual double `[`computeTemperature`](#class_temperaturemodel_1a09)`(double currentTemp, double heatInput) = 0`

Абстрактная функция для расчета температуры.

**Параметры**
- `currentTemp` - Текущая температура.
- `heatInput` - Ввод тепловой энергии.

#### `public virtual `[`~TemperatureModel`](#class_temperaturemodel_1a10)`() = default`

Деструктор базового класса.

---

## class `LinearModel`

Простая линейная модель для расчета температуры.

### Обзор

- `public `[`LinearModel`](#class_linearmodel_1a01)`(double alpha, double beta)`  
  Конструктор с параметрами линейной модели.
- `public virtual double `[`computeTemperature`](#class_linearmodel_1a02)`(double currentTemp, double heatInput)`  
  Вычисляет температуру с использованием линейной зависимости.
- `public virtual `[`~LinearModel`](#class_linearmodel_1a03)`() = default`  
  Деструктор.

### Элементы

#### `public `[`LinearModel`](#class_linearmodel_1a01)`(double alpha, double beta)`

Создает новый объект линейной модели.

**Параметры**
- `alpha` - Коэффициент для текущей температуры.
- `beta` - Коэффициент для теплового ввода.

#### `public virtual double `[`computeTemperature`](#class_linearmodel_1a02)`(double currentTemp, double heatInput)`

Вычисляет температуру по линейной формуле.

#### `public virtual `[`~LinearModel`](#class_linearmodel_1a03)`() = default`

Деструктор.

---

## class `NonlinearModel`

Нелинейная модель для расчета температуры.

### Обзор

- `public `[`NonlinearModel`](#class_nonlinearmodel_1a01)`(double k1, double k2, double k3, double k4)`  
  Конструктор с параметрами нелинейной модели.
- `public virtual double `[`computeTemperature`](#class_nonlinearmodel_1a02)`(double currentTemp, double heatInput)`  
  Вычисляет температуру с использованием сложной зависимости.
- `public virtual `[`~NonlinearModel`](#class_nonlinearmodel_1a03)`() = default`  
  Деструктор.

### Элементы

#### `public `[`NonlinearModel`](#class_nonlinearmodel_1a01)`(double k1, double k2, double k3, double k4)`

Создает объект нелинейной модели.

**Параметры**
- `k1` - Коэффициент для текущей температуры.
- `k2` - Коэффициент для квадрата предыдущей температуры.
- `k3` - Коэффициент для теплового ввода.
- `k4` - Коэффициент для синуса предыдущего теплового ввода.

#### `public virtual double `[`computeTemperature`](#class_nonlinearmodel_1a02)`(double currentTemp, double heatInput)`

Расчет температуры по нелинейной формуле.

#### `public virtual `[`~NonlinearModel`](#class_nonlinearmodel_1a03)`() = default`

Деструктор.

---

## class `ControlSystem`

Система управления для моделирования температурного контроля.

### Обзор

- `public void `[`executeSimulation`](#class_controlsystem_1a01)`(double targetTemp, double startTemp, TemperatureModel& model)`  
  Запускает симуляцию системы управления.
- `private double `[`calculateSignal`](#class_controlsystem_1a02)`(double error, double prevError1, double prevError2)`  
  Рассчитывает управляющий сигнал.

### Элементы

#### `public void `[`executeSimulation`](#class_controlsystem_1a01)`(double targetTemp, double startTemp, TemperatureModel& model)`

Симуляция управления температурой.

**Параметры**
- `targetTemp` - Желаемая температура.
- `startTemp` - Начальная температура.
- `model` - Модель температуры для использования в расчетах.

#### `private double `[`calculateSignal`](#class_controlsystem_1a02)`(double error, double prevError1, double prevError2)`

Вычисляет управляющий сигнал для регулирования температуры.

**Параметры**
- `error` - Текущее отклонение.
- `prevError1` - Отклонение предыдущего шага.
- `prevError2` - Отклонение на два шага назад.
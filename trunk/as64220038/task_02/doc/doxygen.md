# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinearModel`](#class_linear_model) | Класс для линейной математической модели.
`class `[`MathematicModel`](#class_mathematic_model) | Абстрактный класс для математической модели.
`class `[`NonLinearModel`](#class_non_linear_model) | Класс для нелинейной математической модели.
`class `[`Regulator`](#class_regulator) | Класс регулятора для управления ошибкой.

# class `LinearModel` 

```
class LinearModel
  : public MathematicModel
```  

Класс для линейной математической модели.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` | Конструктор класса [LinearModel](#class_linear_model).
`public inline virtual double `[`calculateOutput`](#class_linear_model_1ad48d1592db21785a57c50325f2f02000)`(double currentVal,double,double inputVal) const` | Вычисление выходного значения линейной модели.

## Members

#### `public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` 

Конструктор класса [LinearModel](#class_linear_model).

#### Parameters
* `a` Коэффициент для текущего значения. 

* `b` Коэффициент для входного значения.

#### `public inline virtual double `[`calculateOutput`](#class_linear_model_1ad48d1592db21785a57c50325f2f02000)`(double currentVal,double,double inputVal) const` 

Вычисление выходного значения линейной модели.

#### Parameters
* `currentVal` Текущее значение. 

* `prevVal` Не используется в линейной модели. 

* `inputVal` Входное значение. 

#### Returns
Выходное значение линейной модели.

# class `MathematicModel` 

Абстрактный класс для математической модели.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`calculateOutput`](#class_mathematic_model_1a16811daf509bcc0deedc9d25ef5330f5)`(double currentVal,double prevVal,double inputVal) const` | Вычисление выходного значения модели.
`public virtual  `[`~MathematicModel`](#class_mathematic_model_1af4422c063029d4dea1e0dda9819a1840)`() = default` | Виртуальный деструктор.

## Members

#### `public double `[`calculateOutput`](#class_mathematic_model_1a16811daf509bcc0deedc9d25ef5330f5)`(double currentVal,double prevVal,double inputVal) const` 

Вычисление выходного значения модели.

#### Parameters
* `currentVal` Текущее значение. 

* `prevVal` Предыдущее значение. 

* `inputVal` Входное значение. 

#### Returns
Выходное значение модели.

#### `public virtual  `[`~MathematicModel`](#class_mathematic_model_1af4422c063029d4dea1e0dda9819a1840)`() = default` 

Виртуальный деструктор.

# class `NonLinearModel` 

```
class NonLinearModel
  : public MathematicModel
```  

Класс для нелинейной математической модели.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearModel`](#class_non_linear_model_1a188b8497584a8b7abd6b06e7b584234b)`(double a,double b,double c,double d)` | Конструктор класса [NonLinearModel](#class_non_linear_model).
`public inline virtual double `[`calculateOutput`](#class_non_linear_model_1a0af62607d4bf49e307965979eac27d6f)`(double currentVal,double prevVal,double inputVal) const` | Вычисление выходного значения нелинейной модели.

## Members

#### `public inline  `[`NonLinearModel`](#class_non_linear_model_1a188b8497584a8b7abd6b06e7b584234b)`(double a,double b,double c,double d)` 

Конструктор класса [NonLinearModel](#class_non_linear_model).

#### Parameters
* `a` Коэффициент для текущего значения. 

* `b` Коэффициент для квадрата предыдущего значения. 

* `c` Коэффициент для входного значения. 

* `d` Коэффициент для синуса входного значения.

#### `public inline virtual double `[`calculateOutput`](#class_non_linear_model_1a0af62607d4bf49e307965979eac27d6f)`(double currentVal,double prevVal,double inputVal) const` 

Вычисление выходного значения нелинейной модели.

#### Parameters
* `currentVal` Текущее значение. 

* `prevVal` Предыдущее значение. 

* `inputVal` Входное значение. 

#### Returns
Выходное значение нелинейной модели.

# class `Regulator` 

Класс регулятора для управления ошибкой.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a9382f8046783a96bac749cf01ed097a7)`(double q0,double q1,double q3)` | Конструктор класса [Regulator](#class_regulator).
`public inline double `[`calculateControl`](#class_regulator_1a0173367f2f8a0718bd61a2fefa10c741)`(double currentError)` | Вычисление управляющего сигнала на основе текущей ошибки.

## Members

#### `public inline  `[`Regulator`](#class_regulator_1a9382f8046783a96bac749cf01ed097a7)`(double q0,double q1,double q3)` 

Конструктор класса [Regulator](#class_regulator).

#### Parameters
* `q0` Пропорциональный коэффициент. 

* `q1` Интегральный коэффициент. 

* `q3` Дифференциальный коэффициент.

#### `public inline double `[`calculateControl`](#class_regulator_1a0173367f2f8a0718bd61a2fefa10c741)`(double currentError)` 

Вычисление управляющего сигнала на основе текущей ошибки.

#### Parameters
* `currentError` Текущая ошибка. 

#### Returns
Управляющий сигнал.

Generated by [Moxygen](https://sourcey.com/moxygen)
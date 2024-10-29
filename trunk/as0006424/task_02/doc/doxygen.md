# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinearModel`](#class_linear_model) | Класс для линейной модели
`class `[`Model`](#class_model) | Абстрактный класс
`class `[`NonlinearModel`](#class_nonlinear_model) | Класс для нелинейной модели
`class `[`PIDregulator`](#class_p_i_dregulator) | Класс для пропорционально-интегрально-дифференцирующего регулятора.

# class `LinearModel` 

```
class LinearModel
  : public Model
```  

Класс для линейной модели

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` | Конструктор класса [LinearModel](#class_linear_model)
`public inline virtual double `[`temperature_simulation`](#class_linear_model_1a4f7bb9064ad7490ab43980ac00a392be)`(double Yt,double Uw)` | Переопределенный метод расчета выходного значения линейной модели
`public virtual  `[`~LinearModel`](#class_linear_model_1a37b91fcf8384e576cf874c34bd58fc24)`() = default` | Деструктор класса [LinearModel](#class_linear_model)
`private double `[`a`](#class_linear_model_1ad1c29ddadacd1fe5bd0440d8baca21d7) | Параметр a.
`private double `[`b`](#class_linear_model_1a8e0bce9ea83faf2e1de914875545ef88) | Параметр b.

## Members

#### `public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` 

Конструктор класса [LinearModel](#class_linear_model).

#### Parameters
* `a` `b` - константы

#### `public inline virtual double `[`temperature_simulation`](#class_linear_model_1a4f7bb9064ad7490ab43980ac00a392be)`(double Yt,double Uw)` 

Переопределенный метод расчета выходного значения линейной модели.

#### `public virtual  `[`~LinearModel`](#class_linear_model_1a37b91fcf8384e576cf874c34bd58fc24)`() = default` 

Деструктор класса [LinearModel](#class_linear_model).

#### `private double `[`a`](#class_linear_model_1ad1c29ddadacd1fe5bd0440d8baca21d7) 

Параметр a.

#### `private double `[`b`](#class_linear_model_1a8e0bce9ea83faf2e1de914875545ef88) 

Параметр b.

# class `Model` 

Абстрактный класс.

[Model](#class_model) используется для представления других моделей.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`temperature_simulation`](#class_model_1a5a90c717f9a81a28dc7c01e83d60c507)`(double Yt,double Uw)` | Виртуальная функция для определения температуры
`public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` | Деструктор модели

## Members

#### `public double `[`temperature_simulation`](#class_model_1a5a90c717f9a81a28dc7c01e83d60c507)`(double Yt,double Uw)` 

Виртуальная функция для определения температуры.

#### Параметры
* `Yt` входная температура 

* `Uw` входное тепло

#### Возвращает
Выходное значение температуры типа double 

#### `public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` 

Деструктор модели

# class `NonlinearModel` 

```
class NonlinearModel
  : public Model
```  

Класс для нелинейной модели.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearModel`](#class_nonlinear_model_1a9f3a611ca0c92ff58940e6c17e2ee55d)`(double a,double b,double c,double d)` | Конструктор класса [NonlinearModel](#class_nonlinear_model).
`public inline virtual double `[`temperature_simulation`](#class_nonlinear_model_1a5fc532df0aa33e129ce6721d536922bf)`(double Yt,double Uw)` | Переопределенный метод расчета выходного значения нелинейной модели.
`public virtual  `[`~NonlinearModel`](#class_nonlinear_model_1ae267221772fc580efedbef866a92a1b1)`() = default` | Деструктор класса [NonlinearModel](#class_nonlinear_model).
`private double `[`a`](#class_nonlinear_model_1af1c74b613ca790cdda544b0ca3e13cb0) | Параметр a.
`private double `[`b`](#class_nonlinear_model_1a271d228355d448b5c52dce540ef69898) | Параметр b.
`private double `[`c`](#class_nonlinear_model_1ac58220681e73f7cf9e819b8b30d07a00) | Параметр c.
`private double `[`d`](#class_nonlinear_model_1a60542abc380c49c3fa5558a62579576f) | Параметр d
`private double `[`Yt_last`](#class_nonlinear_model_1afb44c15c8470524681ab4a96334bf937) | Предыдущее значение температуры
`private double `[`Uw_last`](#class_nonlinear_model_1a45037db07192e3c82a2163d171c002c9) | Предыдущее значение тепла

## Members

#### `public inline  `[`NonlinearModel`](#class_nonlinear_model_1a9f3a611ca0c92ff58940e6c17e2ee55d)`(double a,double b,double c,double d)` 

Конструктор класса [NonlinearModel](#class_nonlinear_model).

#### Параметры
* `a` `b` `c` `d` - константы

#### `public inline virtual double `[`temperature_simulation`](#class_nonlinear_model_1a5fc532df0aa33e129ce6721d536922bf)`(double Yt,double Uw)` 

Переопределенный метод расчета выходного значения нелинейной модели.

#### `public virtual  `[`~NonlinearModel`](#class_nonlinear_model_1ae267221772fc580efedbef866a92a1b1)`() = default` 

Деструктор класса [NonlinearModel](#class_nonlinear_model).

#### `private double `[`a`](#class_nonlinear_model_1af1c74b613ca790cdda544b0ca3e13cb0) 

Параметр a.

#### `private double `[`b`](#class_nonlinear_model_1a271d228355d448b5c52dce540ef69898) 

Параметр b.

#### `private double `[`c`](#class_nonlinear_model_1ac58220681e73f7cf9e819b8b30d07a00) 

Параметр c.

#### `private double `[`d`](#class_nonlinear_model_1a60542abc380c49c3fa5558a62579576f) 

Параметр d

#### `private double `[`Yt_last`](#class_nonlinear_model_1afb44c15c8470524681ab4a96334bf937) 

Предыдущее значение температуры

#### `private double `[`Uw_last`](#class_nonlinear_model_1a45037db07192e3c82a2163d171c002c9) 

Предыдущее значение тепла

# class `PIDregulator` 

Класс для пропорционально-интегрально-дифференцирующего регулятора.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`Regulate`](#class_p_i_dregulator_1a237cb281c5134ada08cee584ac6cfb2b)`(double w,double y0,`[`Model`](#class_model)` & model)` | Модель регулятора
`private const double `[`K`](#class_p_i_dregulator_1a0662b7bf934444667649c14086f299c7) | Коэффициент передачи.
`private const double `[`T`](#class_p_i_dregulator_1ab778b871c7d009fcb3106e05073cd7ca) | Константа интегрирования.
`private const double `[`TD`](#class_p_i_dregulator_1ae4e1c1b2e61f4f64bd48310937b059c8) | Константа дифференциации.
`private const double `[`T0`](#class_p_i_dregulator_1a16035e1bc023b64a518ad4bee9d91b14) | Шаг квантования.
`private const double `[`SimulationTime`](#class_p_i_dregulator_1a621ad60a30ce0526c479b42b51c5fd43) | Время симуляции
`private double `[`Uk`](#class_p_i_dregulator_1abb293000d9ac7ba842434418998c6ced) | Значение управляющей переменной.
`private inline double `[`calculate_Uk`](#class_p_i_dregulator_1a4dbcf92693b3c7052e48305919ed1e29)`(double e,double e1,double e2)` | Расчет текущего контролирующего значения.

## Members

#### `public inline void `[`Regulate`](#class_p_i_dregulator_1a237cb281c5134ada08cee584ac6cfb2b)`(double w,double y0,`[`Model`](#class_model)` & model)` 

Модель регулятора

#### Параметры

* `w` желаемое значение 

* `y0` начальная температура

* `model` линейная или нелинейная модель

#### `private const double `[`K`](#class_p_i_dregulator_1a0662b7bf934444667649c14086f299c7) 

Коэффициент передачи.

#### `private const double `[`T`](#class_p_i_dregulator_1ab778b871c7d009fcb3106e05073cd7ca) 

Константа интегрирования.

#### `private const double `[`TD`](#class_p_i_dregulator_1ae4e1c1b2e61f4f64bd48310937b059c8) 

Константа дифференциации.

#### `private const double `[`T0`](#class_p_i_dregulator_1a16035e1bc023b64a518ad4bee9d91b14) 

Шаг квантования.

#### `private const double `[`SimulationTime`](#class_p_i_dregulator_1a621ad60a30ce0526c479b42b51c5fd43) 

Время симуляции

#### `private double `[`Uk`](#class_p_i_dregulator_1abb293000d9ac7ba842434418998c6ced) 

Значение управляющей переменной.

#### `private inline double `[`calculate_Uk`](#class_p_i_dregulator_1a4dbcf92693b3c7052e48305919ed1e29)`(double e,double e1,double e2)` 

Расчет текущего контролирующего значения.

#### Параметры

* `e` отклонение от желаемого значения 

* `e1` предыдущее отклонение от желаемого значения

* `e2` предыдущее отклонение от e1

#### Возвращает

обновленное значение управляющей переменной типа double 
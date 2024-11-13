# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`TempModel`](#class_temp_model) | Abstract base class for temperature models.
`class `[`LinearTempModel`](#class_linear_temp_model) | Linear model for temperature calculation.
`class `[`NonlinearTempModel`](#class_nonlinear_temp_model) | Nonlinear model for temperature calculation.
`class `[`ControlSystem`](#class_control_system) | Proportional–integral–derivative control system.

# class `TempModel` 

An abstract class representing a temperature model.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual double `[`computeTemperature`](#class_temp_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp,double heatInput) = 0` | Computes temperature based on current temperature and heat input.
`public virtual  `[`~TempModel`](#class_temp_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default` | Default destructor.

## Members

#### `public virtual double `[`computeTemperature`](#class_temp_model_1a09f70a5d58f9a836b682c4ad9d75ddc4)`(double currentTemp,double heatInput) = 0`

Computes the temperature output based on the input temperature and heat input.

#### Parameters
* `currentTemp` - Current temperature.
* `heatInput` - Heat input value.

#### `public virtual  `[`~TempModel`](#class_temp_model_1a4e7d514b4b9a840b746a686048ab1f18)`() = default`

Destroy the `TempModel` object.

# class `LinearTempModel`

A linear model for temperature calculation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearTempModel`](#class_linear_temp_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double param1,double param2)` | Constructs a linear model with specified parameters.
`public inline virtual double `[`computeTemperature`](#class_linear_temp_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp,double heatInput)` | Computes the temperature for the linear model.
`public virtual  `[`~LinearTempModel`](#class_linear_temp_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default` | Default destructor.

## Members

#### `public inline  `[`LinearTempModel`](#class_linear_temp_model_1a29c36f0f2d6a1ecb27dfe676fe4a6b6a)`(double param1,double param2)`

Constructs a new `LinearTempModel` object with specified parameters.

#### Parameters
* `param1` - Linear coefficient for current temperature.
* `param2` - Coefficient for heat input.

#### `public inline virtual double `[`computeTemperature`](#class_linear_temp_model_1ac0c3db10c3b3be2ae5dc1e227bbfb09c)`(double currentTemp,double heatInput)`

Computes the temperature output based on the linear model.

#### `public virtual  `[`~LinearTempModel`](#class_linear_temp_model_1ad78eae7d3bfb0a40147e39d3060f3629)`() = default`

Destroy the `LinearTempModel` object.

# class `NonlinearTempModel`

A nonlinear model for temperature calculation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearTempModel`](#class_nonlinear_temp_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double param1,double param2,double param3,double param4)` | Constructs a nonlinear model with specified parameters.
`public inline virtual double `[`computeTemperature`](#class_nonlinear_temp_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp,double heatInput)` | Computes the temperature for the nonlinear model.
`public virtual  `[`~NonlinearTempModel`](#class_nonlinear_temp_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default` | Default destructor.

## Members

#### `public inline  `[`NonlinearTempModel`](#class_nonlinear_temp_model_1abf94db879e6a11a3b8d4c5d6e2a8c8a2)`(double param1,double param2,double param3,double param4)`

Constructs a new `NonlinearTempModel` object with specified parameters.

#### Parameters
* `param1` - Coefficient for current temperature.
* `param2` - Coefficient for square of previous temperature.
* `param3` - Coefficient for heat input.
* `param4` - Coefficient for sine of previous heat input.

#### `public inline virtual double `[`computeTemperature`](#class_nonlinear_temp_model_1a25dc6765a041b63ec20976f80ad23fa4)`(double currentTemp,double heatInput)`

Computes the temperature output based on the nonlinear model.

#### `public virtual  `[`~NonlinearTempModel`](#class_nonlinear_temp_model_1ae7cf4cb5096b5fbd3bff78c3bfb63b2f)`() = default`

Destroy the `NonlinearTempModel` object.

# class `ControlSystem`

Proportional–integral–derivative control system to simulate temperature control.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`simulate`](#class_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemp,double initialTemp,`[`TempModel`](#class_temp_model)` & model)` | Simulates the control system for a temperature model.
`private double `[`computeControlSignal`](#class_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error,double prevError1,double prevError2)` | Computes the control signal for a given error.

## Members

#### `public void `[`simulate`](#class_control_system_1acb8cf7932d39a2bcd053dc22bca24672)`(double targetTemp,double initialTemp,`[`TempModel`](#class_temp_model)` & model)`

Simulates the temperature control system for a given target temperature and model.

#### Parameters
* `targetTemp` - Desired temperature.
* `initialTemp` - Initial temperature.
* `model` - Temperature model to be used in the simulation.

#### `private double `[`computeControlSignal`](#class_control_system_1a7dcb55c416527f9644de795b6ff16f3b)`(double error,double prevError1,double prevError2)`

Computes the control signal based on the error and previous errors.

#### Parameters
* `error` - Current error.
* `prevError1` - Previous error.
* `prevError2` - Error two steps ago.

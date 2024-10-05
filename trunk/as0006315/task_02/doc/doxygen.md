# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinearModel`](#class_linear_model) | The class for the linear model.
`class `[`ModelingObject`](#class_modeling_object) | The base class for the models.
`class `[`NonLinearModel`](#class_non_linear_model) | The class for the nonlinear model.
`class `[`PID`](#class_p_i_d) | The class implements the [PID](#class_p_i_d) controller.

# class `LinearModel` 

```
class LinearModel
  : public ModelingObject
```  

The class for the linear model.

The class contains the constructor, the method [calculate()](#class_linear_model_1a16ea154f7093c782f84fc86962fd9de2), the method [print()](#class_linear_model_1a28a124825e15c0afabd72f4c77bf2c4b) and the method [getTemp()](#class_linear_model_1a38f807229ee645e3714c23286c4e9249).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`LinearModel`](#class_linear_model_1a7856080f476ad52c1ba670cd7c94fad4)`(double a,double b,double current_temperature,double warm)` | The constructor.
`public virtual void `[`calculate`](#class_linear_model_1a16ea154f7093c782f84fc86962fd9de2)`(const int & time)` | The method to calculate the temperatures.
`public void `[`print`](#class_linear_model_1a28a124825e15c0afabd72f4c77bf2c4b)`()` | The method to output the temperatures.
`public std::vector< double > `[`getTemp`](#class_linear_model_1a38f807229ee645e3714c23286c4e9249)`()` | The method to get the temperatures.

## Members

#### `public  `[`LinearModel`](#class_linear_model_1a7856080f476ad52c1ba670cd7c94fad4)`(double a,double b,double current_temperature,double warm)` 

The constructor.

The constructor of the [LinearModel](#class_linear_model) class.

#### Parameters
* `a` The coefficient A. 

* `b` The coefficient B. 

* `current_temperature` The current temperature. 

* `warm` The warm temperature.

* `a` The coefficient a in the linear model. 

* `b` The coefficient b in the linear model. 

* `current_temperature` The current temperature. 

* `warm` The temperature of the warm.

#### `public virtual void `[`calculate`](#class_linear_model_1a16ea154f7093c782f84fc86962fd9de2)`(const int & time)` 

The method to calculate the temperatures.

The function calculates the temperatures with the linear model.

#### Parameters
* `time` The time.

#### `public void `[`print`](#class_linear_model_1a28a124825e15c0afabd72f4c77bf2c4b)`()` 

The method to output the temperatures.

The function prints the temperatures calculated by the linear model.

#### `public std::vector< double > `[`getTemp`](#class_linear_model_1a38f807229ee645e3714c23286c4e9249)`()` 

The method to get the temperatures.

The function gets the temperatures calculated by the linear model.

#### Returns
The temperatures.

#### Returns
The vector of temperatures.

# class `ModelingObject` 

The base class for the models.

The class contains the virtual method [calculate()](#class_modeling_object_1acbedd169db5d9840a65a99d052bcd360), the method [print()](#class_modeling_object_1ad3b5dccf9e0924b4e3b2d84b95515a2c) and the method [getTemp()](#class_modeling_object_1ae75562c4783bf9040a2be623739f0841).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`calculate`](#class_modeling_object_1acbedd169db5d9840a65a99d052bcd360)`(const int & time)` | The virtual method to calculate the temperatures.
`public void `[`print`](#class_modeling_object_1ad3b5dccf9e0924b4e3b2d84b95515a2c)`(const std::map< int, double > & temps,const std::string & name)` | The method to output the temperatures.
`public std::vector< double > `[`getTemp`](#class_modeling_object_1ae75562c4783bf9040a2be623739f0841)`(const std::map< int, double > & temps)` | The method to get the temperatures.

## Members

#### `public void `[`calculate`](#class_modeling_object_1acbedd169db5d9840a65a99d052bcd360)`(const int & time)` 

The virtual method to calculate the temperatures.

#### Parameters
* `time` The time.

#### `public void `[`print`](#class_modeling_object_1ad3b5dccf9e0924b4e3b2d84b95515a2c)`(const std::map< int, double > & temps,const std::string & name)` 

The method to output the temperatures.

The function prints the temperatures calculated by one of the models.

#### Parameters
* `temps` The temperatures. 

* `name` The name of the model.

* `temps` The map of temperatures. 

* `name` The name of the model.

#### `public std::vector< double > `[`getTemp`](#class_modeling_object_1ae75562c4783bf9040a2be623739f0841)`(const std::map< int, double > & temps)` 

The method to get the temperatures.

The function gets the temperatures calculated by one of the models.

#### Parameters
* `temps` The temperatures. 

#### Returns
The temperatures.

#### Parameters
* `temps` The map of temperatures.

#### Returns
The vector of temperatures.

# class `NonLinearModel` 

```
class NonLinearModel
  : public ModelingObject
```  

The class for the nonlinear model.

The class contains the constructor, the method [calculate()](#class_non_linear_model_1a8995f5733434779cb30c383becd18821), the method [print()](#class_non_linear_model_1a700c7325263350324c22c495b533291d) and the method [getTemp()](#class_non_linear_model_1a6b3f51788a775ec49e5ae2f851aaaf95).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`NonLinearModel`](#class_non_linear_model_1a4daf98a2c47ac96474330daf04feedc3)`(double A,double B,double C,double D,double current_temperature,double warm)` | The constructor.
`public virtual void `[`calculate`](#class_non_linear_model_1a8995f5733434779cb30c383becd18821)`(const int & time)` | The method to calculate the temperatures.
`public void `[`print`](#class_non_linear_model_1a700c7325263350324c22c495b533291d)`()` | The method to output the temperatures.
`public std::vector< double > `[`getTemp`](#class_non_linear_model_1a6b3f51788a775ec49e5ae2f851aaaf95)`()` | The method to get the temperatures.

## Members

#### `public  `[`NonLinearModel`](#class_non_linear_model_1a4daf98a2c47ac96474330daf04feedc3)`(double A,double B,double C,double D,double current_temperature,double warm)` 

The constructor.

The constructor of the [NonLinearModel](#class_non_linear_model) class.

#### Parameters
* `A` The coefficient A. 

* `B` The coefficient B. 

* `C` The coefficient C. 

* `D` The coefficient D. 

* `current_temperature` The current temperature. 

* `warm` The warm temperature.

* `A` The coefficient A in the nonlinear model. 

* `B` The coefficient B in the nonlinear model. 

* `C` The coefficient C in the nonlinear model. 

* `D` The coefficient D in the nonlinear model. 

* `current_temperature` The current temperature. 

* `warm` The temperature of the warm.

#### `public virtual void `[`calculate`](#class_non_linear_model_1a8995f5733434779cb30c383becd18821)`(const int & time)` 

The method to calculate the temperatures.

The function calculates the temperatures with the nonlinear model.

#### Parameters
* `time` The time.

#### `public void `[`print`](#class_non_linear_model_1a700c7325263350324c22c495b533291d)`()` 

The method to output the temperatures.

The function prints the temperatures calculated by the nonlinear model.

#### `public std::vector< double > `[`getTemp`](#class_non_linear_model_1a6b3f51788a775ec49e5ae2f851aaaf95)`()` 

The method to get the temperatures.

The function gets the temperatures calculated by the nonlinear model.

#### Returns
The temperatures.

#### Returns
The vector of temperatures.

# class `PID` 

The class implements the [PID](#class_p_i_d) controller.

The class contains the method to calculate the control signal by [PID](#class_p_i_d).

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public void `[`calculate`](#class_p_i_d_1ae89c0bb07b0d62a0ea2569ec3338a960)`(const double & w,const double & T0,const std::vector< double > & temps_linear)` | The method to calculate the control signal by [PID](#class_p_i_d).
`public std::vector< std::vector< double > > `[`getControlSignals`](#class_p_i_d_1a4f18b22156745f389a97f73ed4c91e39)`() const` | The method to get the control signals.

## Members

#### `public void `[`calculate`](#class_p_i_d_1ae89c0bb07b0d62a0ea2569ec3338a960)`(const double & w,const double & T0,const std::vector< double > & temps_linear)` 

The method to calculate the control signal by [PID](#class_p_i_d).

#### Parameters
* `error` The vector of errors.

The method calculates the control signal by [PID](#class_p_i_d) using the formulas: Uk = Uk_1 + delta_Uk delta_Uk = q0 * e0 + q1 * e1 + q2 * e2 q0 = K * (1 + TD / T0) q1 = -K * (1 + 2 * TD / T0 - T0 / T) q2 = K * TD / T0

#### Parameters
* `w` The desired value of the output signal. 

* `T0` The time step. 

* `temp` The vector of output signals.

#### `public std::vector< std::vector< double > > `[`getControlSignals`](#class_p_i_d_1a4f18b22156745f389a97f73ed4c91e39)`() const` 

The method to get the control signals.

#### Returns
The vector of control signals.

The method returns the vector of control signals.

#### Returns
The vector of control signals.

Generated by [Moxygen](https://sourcey.com/moxygen)
# Лабораторная работа №1

## Задание

Имеется объект. Необходимо контроллировать его температуру, это можно описать формулой

$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC}$ 

где $\tau$ - время, $y(\tau)$ - входная температура, $u(\tau)$ - входное тепло, $Y_0$ - температура комнаты, $C,RC$ - константы.

После преобразований получаем линейную модель

$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$

и нелинейную модель

$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$ 

где $\tau$ - дискретное время, ($1,2,3{\dots}n$); $a,b,c,d$ - константы.

Задача - написать программу на С++, которая симулирует температуру объекта.

## Вывод консоли

```cmd
Enter constant a: 2
Enter constant b: 3
Enter constant c: 4
Enter constant d: 5
Enter input temperature y(t): 15
Enter input warm u(t): 3
Enter number of iterations n: 3

Simulating linear model:
Iteration 1     y(t) = 39
Iteration 2     y(t) = 87
Iteration 3     y(t) = 183

Simulating nonlinear model:
Iteration 1     y(t) = 42
Iteration 2     y(t) = -578.294
Iteration 3     y(t) = -6435.88
```

## Вывод

В ходе данной работы мы создали программу, позволяющую симулировать температуру контроллируемого объекта.
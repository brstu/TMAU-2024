<p align="center">Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br>
<p align="center"><strong>Лабораторная работа №5</strong></p>
<p align="center"><strong>По дисциплине</strong> “Теория и методы автоматического управления”</p>
<p align="center"><strong>Тема:</strong> “Работа с контроллером AXC F 2152”</p>
<br><br><br><br><br><br>
<p align="right"><strong>Выполнил</strong>:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-63</p>
<p align="right">Стельмашук И.А.</p>
<p align="right"><strong>Проверил:</strong></p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center"><strong>Брест 2024</strong></p>

---

### Ход работы:

В функцию "user_eval" файла main.plua был добавлен следующий код:
```bash
function user_init()
    local DELTA = 200
    A5HL8_info.start_time = get_millisec()
    A5HL6_info.start_time = A5HL8_info.start_time - DELTA
    A5HL4_info.start_time = A5HL6_info.start_time - DELTA
    A5HL2_info.start_time = A5HL4_info.start_time - DELTA
    A5HL7_info.start_time = A5HL2_info.start_time - DELTA
    A5HL5_info.start_time = A5HL7_info.start_time - DELTA
    A5HL3_info.start_time = A5HL5_info.start_time - DELTA
    A5HL1_info.start_time = A5HL3_info.start_time - DELTA
end
```

## Результат

Устанавливается интервал в 200 мс между стартовыми временами объектов, затем устанавливается стартовое время для A5HL8_info в качестве текущего времени в миллисекундах. Далее разница во времени между ними составляет 200 мс. Таким образом, при работе кода меняется порядок свечения диодов.
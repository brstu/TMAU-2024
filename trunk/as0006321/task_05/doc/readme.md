<p align="center">������������ ����������� ���������� ��������</p>
<p align="center">���������� �����������</p>
<p align="center">���������� ��������������� ����������� �����������</p>
<p align="center">������� ���</p>
<br><br><br><br><br><br>
<p align="center"><strong>������������ ������ �5</strong></p>
<p align="center"><strong>�� ����������</strong> ������� � ������ ��������������� �����������</p>
<p align="center"><strong>����:</strong> ������� � ������������ AXC F 2152�</p>
<br><br><br><br><br><br>
<p align="right"><strong>��������</strong>:</p>
<p align="right">������� 3 �����</p>
<p align="right">������ ��-63</p>
<p align="right">���������� �.�.</p>
<p align="right"><strong>��������:</strong></p>
<p align="right">������ �. �.</p>
<br><br><br><br><br>
<p align="center"><strong>����� 2024</strong></p>

---

### ��� ������:

� ������� "user_eval" ����� main.plua ��� �������� ��������� ���:
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

## ���������

��������������� �������� � 200 �� ����� ���������� ��������� ��������, ����� ��������������� ��������� ����� ��� A5HL8_info � �������� �������� ������� � �������������. ����� ������� �� ������� ����� ���� ���������� 200 ��. ����� �������, ��� ������ ���� �������� ������� �������� ������.
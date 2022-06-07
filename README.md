# Studentu-vidurkis


(v0.1)Padarytos dvi versijos:<br>
Pirmoji su masyvais<br>
Antroji su vektoriais

Programa apskaičiuoja studentų vidurkius

Programa taip pat apsaugota nuo neteisingų duomenų įvedimo

(v0.2)

Papildyta programa, kad būtų galima skaityti duomenis iš duomenų failų

(v0.3)
 
Išskaidyta programa į header ir cpp failiukus

(v0.4)

Studentai dabar skaidomi į vargšiukus ir kietiakus pagal jų vidurkio rezultatą.

Galimybė generuoti atsitiktinius studentų sąrašus

Taip pat atlikta programos veikimo greičio analizė, programa matuoja:<br>
Duomenų generacijos laiką<br>
Duomenų išrikiavimo laiką<br>
Studentų skirstymo laiką<br>
Duomenų išvedimo laiką<br>
Visos programos veikimo laiką<br>

(v0.5)

Programa dabar realizuota su trimis konteineriais: Vektoriais, Deque, List<br>
Buvo atlikti spartos testavimai su 1000, 10000, 100000, 1000000, 10000000 failais<Br>
 Vektorius<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.008s| 0.036s | 0.28s | 2.91s | 28.79s |
|Studentų rūšiavimas   |0.00016s| 0.0019s | 0.02s | 0.23s | 2.33s |
 
  Deque<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.007s| 0.032s | 0.29s | 2.81s | 27.8s |
|Studentų rūšiavimas   |0.00056s| 0.0015s | 0.018s | 0.18s | 1.9s |
 
  List<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.009s| 0.031s | 0.27s | 2.96s | 28.05s |
|Studentų rūšiavimas   |0.00019s| 0.0013s | 0.015s | 0.16s | 1.51s |
 
 
 (v1.0)
 
 v0.5 studentų skirstymas buvo padarytas pagal pirma strategiją, kad buvo sukūrti du nauji to paties tipo konteineriai<br>
 v1.0 buvo realizuota kita strategija, pagal kurią kuriamas tik vienas naujas konteineris o iš pirmo konteinerio ištrinami seni duomenys<br>
 padarytas makefile
 
 Vėl buvo atlikta spartos analizė
 
  Vektorius<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.007s| 0.033s | 0.43s | 4,44s | 28.38s |
|Studentų rūšiavimas   |0.00099s| 0.004s | 0.04s | 0.46s | 0.96s |
 
  Deque<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.009s| 0.032s | 0.29s | 2.83s | 27.9s |
|Studentų rūšiavimas   |0.00011s| 0.0007s | 0.012s | 0.45s | 0.94s |
 
  List<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.011s| 0.032s | 0.29s | 2.86s | 28s |
|Studentų rūšiavimas   |0.000073s| 0.0009s | 0.012s | 0.13s | 1.26s |



Sistemos parametrai:
i7-6700k
16gb RAM
480gb SSD


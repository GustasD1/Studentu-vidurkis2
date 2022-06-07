 v1.1
 Studentų struktūra pakeista į klasę atlikti testai
 
 Vektorius su structūra<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.007s| 0.033s | 0.29s | 4,5s | 28.75s |
|Studentų rūšiavimas   |0.0009s| 0.008s | 0.04s | 0.47s | 0.97s |

Vektorius su klase<br>
| Dydis                | 1000 | 10000 | 100000 | 1000000 | 10000000 |
| -------------------- | ---- | ----- | ----- | ------- | -------- |
|Duomenų nuskaitymas   |0.009s| 0.052s | 0.44s | 4.43s | 28.16s |
|Studentų rūšiavimas   |0.0009s| 0.004s | 0.05s | 0.46s | 0.87s |

Vektorius su -O1<br>
| Dydis                | 100000 | 1000000 |
| -------------------- | ----- | ------- | 
|Duomenų nuskaitymas   | 0.43s | 4.45s |
|Studentų rūšiavimas   | 0.047s | 0.46s|

Vektorius su -O2<br>
| Dydis                | 100000 | 1000000 |
| -------------------- | ----- | ------- | 
|Duomenų nuskaitymas   | 0.44s | 4.41s |
|Studentų rūšiavimas   | 0.047s | 0.46s|

Vektorius su -O3<br>
| Dydis                | 100000 | 1000000 |
| -------------------- | ----- | ------- | 
|Duomenų nuskaitymas   | 0.43s | 4.58s |
|Studentų rūšiavimas   | 0.043s | 0.45s|

#ifndef prototipai_H_INCLUDE
#define prototipai_H_INCLUDE


#include "biblioteka.h"





void ivestis(data& temp, int& n);
void isvedimas(const data& temp);
void apskaiciavimas(data& temp, int n);
void skaitymas(deque<data>& temp);
void FailoIsvedimas(deque<data>& temp, deque<data>& temp2);
void generacija(deque<data>& temp);
void skirstymas(deque<data>& temp,deque<data>& temp2);
bool maziau(const data& temp);





#endif
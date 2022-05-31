#ifndef biblioteka_H_INCLUDE
#define biblioteka_H_INCLUDE


#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream> 
#include <chrono>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <deque>


using namespace std::chrono; 
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::stringstream;
using std::deque;



class data{
public:
	string vardas = "", pavarde = "";
	vector<int>paz;
	int egz = 0;
	double rezultatas = 0;
	double mediana = 0;
	double rezultatasm = 0;
	double vidurkis = 0;
	~data();
	data& operator=(const data& dataa) {
		if (&dataa == this) return *this;
		vardas = dataa.vardas;
		pavarde = dataa.pavarde;
		paz = dataa.paz;
		egz = dataa.egz;
		rezultatas = dataa.rezultatas;
		mediana = dataa.mediana;
		rezultatasm = dataa.rezultatasm;
		vidurkis = dataa.vidurkis;
		return *this;

	}
};





#endif

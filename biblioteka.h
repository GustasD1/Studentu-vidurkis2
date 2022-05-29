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

class zmogus {
protected:
    string vardas2;
    string pavarde2;
public:
    explicit zmogus() {
        vardas2 = " ";
        pavarde2 = " ";
    };
    explicit zmogus(const string& vardas, const string& pavarde) {
        vardas2 = vardas;
        pavarde2 = pavarde;
    };
    virtual const string& vardas() const = 0;
    virtual const string& pavarde() const = 0;


};



class data: public zmogus{
public:
	vector<int>paz;
	int egz = 0;
	double rezultatas = 0;
	double mediana = 0;
	double rezultatasm = 0;
	double vidurkis = 0;

	~data();
   data(const data& dataa);
	data& operator = (const data& dataa);

    explicit data(const string& vardas, const string& pavarde):zmogus(vardas, pavarde) {};
    const string& vardas() const override;
    const string& pavarde() const override;
};





#endif

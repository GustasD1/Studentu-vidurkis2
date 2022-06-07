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





using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::sort;
using std::stringstream;



struct data {
	string vardas = "", pavarde = "";
	vector<int>paz;
	int egz = 0;
	double rezultatas = 0;
	double mediana = 0;
	double rezultatasm = 0;
	double vidurkis = 0;

};

void ivestis(data& temp, int & n);
void isvedimas(const data& temp);
void apskaiciavimas(data& temp, int n);
void skaitymas(vector<data> & temp);
void FailoIsvedimas(vector<data>& temp);
int main() {
	vector<data> sarasas;
	data laik;
	int n;
	int sk;
	int a;
	cout << "Ar norite nuskaityti duomenis is failo, 1-taip, 0-ne" << std::endl;
	cin >> a;
	while (!cin || a != 0 && a != 1) {
		cout << "Prasome ivesti skaiciu 0 arba 1" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a;
	}
	if (a == 1) {
		skaitymas(sarasas);
		FailoIsvedimas(sarasas);
	}
	else {
		cout << "Kiek studentu noresite ivesti" << std::endl;
		cin >> sk;
		while (!cin) {
			cout << "Prasome ivesti skaiciu" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> sk;
		}
		sarasas.reserve(sk);
		for (int i = 0; i < sk; i++) {
			ivestis(laik, n);
			apskaiciavimas(laik, n);

			sarasas.push_back(laik);

		}
		cout << std::setw(20) << "vardas" << std::setw(20) << "pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis(Med.)" << std::endl;
		for (int i = 0; i < sarasas.size(); i++) {
			isvedimas(sarasas.at(i));


		}
		sarasas.clear();
	}

}
void ivestis(data& temp, int & n) {
	int pas;
	int r;
	cout << "Iveskite studento varda" << std::endl;
	cin >> temp.vardas;
	while (std::find_if(temp.vardas.begin(), temp.vardas.end(), std::isdigit) != temp.vardas.end())
	{
		cout << "skaiciai neleidziami, veskite is naujo" <<std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp.vardas;


	}

	cout << "Iveskite studento pavarde" << std::endl;
	cin >> temp.pavarde;
	while (std::find_if(temp.pavarde.begin(), temp.pavarde.end(), std::isdigit) != temp.pavarde.end())
	{
		cout << "skaiciai neleidziami, veskite is naujo" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp.pavarde;


	}
	
	cout << "Iveskite kiek pazymiu turi studentas" << std::endl;
	cin >> n;
	temp.paz.resize(n);
	while (!cin) {
		cout << "Prasome ivesti skaiciu" <<std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	cout << "Ar norite jog pazymiai buti generuojami atsitiktinai? Jei taip iveskite 1, jei ne iveskite 0" <<std::endl;
	cin >> pas;
	while (!cin || pas!=0 && pas!=1) {
		cout << "Prasome ivesti skaiciu 0 arba 1" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> pas;
	}
	if (pas == 1) {
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			r = rand() % 10 + 1;
			temp.paz[i]=r;

		}
	
		r = rand() % 10 + 1;
		temp.egz = (double)r;

	}
	if (pas == 0) {
		for (int i = 0; i < n; i++) {
			cout << "Iveskite " << i + 1 << " -a(i) pazymi";
			cin >> temp.paz[i];
			while (!cin) {
				cout << "Prasome ivesti skaiciu" << std::endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> temp.paz[i];
			}

		}

		cout << "Iveskite egzamino pazymi: ";
		cin >> temp.egz;
		while (!cin) {
			cout << "Prasome ivesti skaiciu" << std::endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> temp.egz;
		}
	}

}
void apskaiciavimas(data& temp, int n) {
	for (int i = 0; i < n; i++) {              //Galutinio balo skaiciavimas pagal vidurki
		temp.vidurkis = temp.vidurkis + temp.paz[i];

	
	}

	temp.rezultatas = (temp.vidurkis / n) * 0.4 + 0.6 * temp.egz;
	temp.vidurkis = 0;


	//Galutinio balo skaiciavimas pagal mediana
	int sk = 0;
	int s;
	int laik = n;
	if (n % 2 == 0) {
		sk = 1; //patikrinam ar skaiciu imtis yra lygine ar nelygine, jei sk=1 tai lygine jei sk=0 tai nelygine
	}
	else sk = 0;


	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (temp.paz[i] > temp.paz[j])
			{
				s = temp.paz[i];
				temp.paz[i] = temp.paz[j];
				temp.paz[j] = s;
			}
		}
	}



	if (sk == 1) {
		laik = laik / 2 - 1;
		temp.mediana = ((double)temp.paz[laik] + (double)temp.paz[laik + 1]) / 2;
		
		temp.rezultatasm = temp.mediana * 0.4 + 0.6 * temp.egz;
	

	}
	else {
		laik = laik / 2;

		temp.rezultatasm = (double)temp.paz[laik] * 0.4 + 0.6 * temp.egz;


	}




}
void isvedimas(const data& temp) {
	cout <<std::left<< std::setw(20) << temp.vardas <<std::left<< std::setw(20) << temp.pavarde;
	cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp.rezultatas << std::left << std::setw(20) << temp.rezultatasm <<std::endl;


}
void skaitymas(vector<data>& temp){

	std::ifstream  fd("kursiokai.txt");


	string eil;
	stringstream buf;
	int pazymys;
	int k = 0;

	buf << fd.rdbuf();
	fd.close();


	getline(buf, eil);
	data laik;
	while (getline(buf, eil)) {
		bool error = false;
		std::istringstream s(eil);
		s >> laik.vardas >> laik.pavarde;
	
		while (s >> pazymys) {
			k++;
			if (pazymys >= 1 && pazymys <= 10) {
				laik.paz.push_back(pazymys);
			}
			else {
				error = true;
				break;
			}
		}
			laik.paz.pop_back();
			laik.egz = pazymys;
			for (int i = 0; i < laik.paz.size(); i++) {           
				laik.vidurkis = laik.vidurkis + laik.paz[i];


			}
			laik.rezultatas = (laik.vidurkis / laik.paz.size()) * 0.4 + 0.6 * laik.egz;
			laik.vidurkis = 0;
			double med;
			int kiekis = laik.paz.size();
			std::sort(laik.paz.begin(), laik.paz.end());
			if ((kiekis + 1) % 2 == 0) {
				med = laik.paz[kiekis / 2];
			}
			else {
				med = (laik.paz[kiekis / 2 - 1] + laik.paz[kiekis / 2]) / 2.0;
			}
			laik.rezultatasm = med * 0.4 + 0.6 * laik.egz;

			temp.push_back(laik);
		
		 
		

	}


}
void FailoIsvedimas(vector<data>& temp) {
	int kiekis = temp.size();
	cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20)<<"Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
	cout << "---------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < kiekis; i++) {
		cout << std::left << std::setw(20) << temp[i].vardas << std::left << std::setw(20) << temp[i].pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatasm << std::endl;
	}
}

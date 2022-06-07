#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;


struct data {
	string vardas = "", pavarde = "";
	int paz[100] = { 0 }, egz = 0;
	double vidurkis = 0;
	double mediana = 0;
	double rezultatas = 0;
	double rezultatasm = 0;

};
void skaitymas(data& temp, int & n);
void isvedimas(data& temp, int n);
void apskaiciavimas(data& temp, int n);
int main() {
	data* mas = new data[2];
	int n;
	for (data* a = mas; a < mas + 2; a++) {
		skaitymas(*a,n);
		apskaiciavimas(*a, n);
	}










	cout << std::setw(20) << "vardas" << std::setw(20) << "pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20)<<"Galutinis(Med.)"<< endl;
	for (data* a = mas; a < mas + 2; a++) {
		isvedimas(*a,n);
	}
	delete[] mas;


}
void skaitymas(data& temp, int & n) {
	int pas;
	int r;
	cout << "Iveskite studento varda" << std::endl;
	cin >> temp.vardas;
	while (std::find_if(temp.vardas.begin(), temp.vardas.end(), std::isdigit) != temp.vardas.end())
	{
		cout << "skaiciai neleidziami, veskite is naujo" << std::endl;
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
	while (!cin) {
		cout << "Prasome ivesti skaiciu" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	cout << "Ar norite jog pazymiai buti generuojami atsitiktinai? Jei taip iveskite 1, jei ne iveskite 0" << std::endl;
	cin >> pas;
	while (!cin || pas != 0 && pas != 1) {
		cout << "Prasome ivesti skaiciu 0 arba 1" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> pas;
	}
	if (pas == 1) {
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			r = rand() % 10 + 1;
			temp.paz[i] = r;

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
void isvedimas(data& temp, int n) {

	cout << std::setw(20) << temp.vardas << std::setw(20) << temp.pavarde;
	cout << std::setw(20)<< std::fixed<<std::setprecision(2)<< temp.rezultatas <<std::setw(20)<<temp.rezultatasm<< endl;


}
void apskaiciavimas(data& temp, int n) {
	for (int i = 0; i < n; i++) {              //Galutinio balo skaiciavimas pagal vidurki
		temp.vidurkis = temp.vidurkis + temp.paz[i];
	}
	temp.rezultatas = (temp.vidurkis / n) * 0.4 + 0.6 * temp.egz;


	//Galutinio balo skaiciavimas pagal mediana
	int sk=0;
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
		laik = laik / 2-1;
		temp.mediana = ((double) temp.paz[laik] + (double) temp.paz[laik + 1]) / 2;
			temp.rezultatasm = temp.mediana * 0.4 + 0.6 * temp.egz;

		}
		else {
			laik = laik / 2;
			
			temp.rezultatasm = (double) temp.paz[laik] * 0.4 + 0.6 * temp.egz;


		}
}
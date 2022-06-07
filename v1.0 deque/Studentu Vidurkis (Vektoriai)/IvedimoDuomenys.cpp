#include "biblioteka.h"
#include "prototipai.h"

void ivestis(data& temp, int& n) {
	int pas;
	int r;
	cout << "Iveskite studento varda" << std::endl;
	cin >> temp.vardas;


	cout << "Iveskite studento pavarde" << std::endl;
	cin >> temp.pavarde;


	cout << "Iveskite kiek pazymiu turi studentas" << std::endl;
	cin >> n;
	temp.paz.resize(n);

	cout << "Ar norite jog pazymiai buti generuojami atsitiktinai? Jei taip iveskite 1, jei ne iveskite 0" << std::endl;
	cin >> pas;

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
		
		}

		cout << "Iveskite egzamino pazymi: ";
		cin >> temp.egz;
	
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
void isvedimas(const data& temp)
{
	cout << std::left << std::setw(20) << temp.vardas << std::left << std::setw(20) << temp.pavarde;
	cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp.rezultatas << std::left << std::setw(20) << temp.rezultatasm << std::endl;


}
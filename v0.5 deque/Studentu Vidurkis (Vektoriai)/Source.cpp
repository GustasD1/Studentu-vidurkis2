#include "biblioteka.h"
#include "prototipai.h"





int main() {
	deque<data> sarasas;
	deque<data> kietiakai, vargsiukai;
	data laik;
	int n;
	int sk;
	int a;
	auto startas = high_resolution_clock::now();
	cout << "Ar norite nuskaityti duomenis is failo, 1-taip, 0-ne, jei norite kad butu sugeneruotas atsitiktinis failas - 2" << std::endl;
	cin >> a;
	while (!cin) {
		cout << "Prasome ivesti skaiciu" << std::endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a;
	}
	if (a == 1) {
		skaitymas(sarasas);
		skirstymas(sarasas, kietiakai, vargsiukai);
		sarasas.clear();
		FailoIsvedimas(kietiakai,vargsiukai);
	}
	else if (a==2) {
		auto start = high_resolution_clock::now();
		generacija(sarasas);
		auto end = high_resolution_clock::now();
		duration<double> diff = end - start;
		cout << "Duomenu generacija uztruko " << diff.count() << "s" << std::endl;
		start = high_resolution_clock::now();
		skaitymas(sarasas);
		end = high_resolution_clock::now();
		diff = end - start;
		cout << "Duomenu nuskaitymas uztruko " << diff.count() << "s" << std::endl;
		start = high_resolution_clock::now();
		skirstymas(sarasas, kietiakai, vargsiukai);
		end = high_resolution_clock::now();
		diff = end - start;
		cout << "Skirstymas uztruko " << diff.count() << "s" << std::endl;
		sarasas.clear();
		start = high_resolution_clock::now();
		FailoIsvedimas(kietiakai,vargsiukai);
		end = high_resolution_clock::now();
	    diff = end - start;
		cout << "Duomenu isvedimas uztruko " << diff.count() << "s" << std::endl;
		

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
		//sarasas.reserve(sk);
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

	auto endas = high_resolution_clock::now();
	duration<double> differencija = endas - startas;
	cout<<"visos programos veikimo laikas "<< differencija.count() << "s" << std::endl;

}

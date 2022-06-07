#include "biblioteka.h"
#include "prototipai.h"

void skaitymas(vector<data>& temp) {

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
		laik.paz.clear();
		temp.push_back(laik);




	}


}
void FailoIsvedimas(vector<data>& temp) {
	auto start = high_resolution_clock::now();
	std::sort(temp.begin(), temp.end(), [](data a, data b) {
		return a.vardas < b.vardas;
		});
	auto end = high_resolution_clock::now();
	duration<double> diff = end - start;
	cout << "Duomenu isrikiavimas uztruko " << diff.count() << "s" << std::endl;



	int kiekis = temp.size();
	std::ofstream fr("vargsiukai.txt");
	std::ofstream out("kietiakai.txt");
		fr << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
		fr << "---------------------------------------------------------------------------" << std::endl;
		out<< std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
		start = high_resolution_clock::now();
		out << "---------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < kiekis; i++) {
			if (temp[i].rezultatas < 5.0) {
				fr << std::left << std::setw(20) << temp[i].vardas << std::left << std::setw(20) << temp[i].pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatasm << std::endl;
			}
			else {
				out << std::left << std::setw(20) << temp[i].vardas << std::left << std::setw(20) << temp[i].pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatasm << std::endl;

			}

		}
		end = high_resolution_clock::now();
		diff = end - start;
		cout << "Studentu skirstymas uztruko " << diff.count() << "s" << std::endl;

	}

void generacija(vector<data>& temp) {
	int n;
	cout << "kiek norite studentu sugeneruoti" << std::endl;
	cin >> n;
	int pazymys;
	data laik;
	for (int i = 0; i < n; i++) {
		laik.vardas="Vardas"+std::to_string(i+1);
		laik.pavarde = "Pavarde" + std::to_string(i+1);
		for (int j = 0; j < 5; j++) {
			pazymys = rand() % 10 + 1;
			laik.paz.push_back(pazymys);
			laik.vidurkis = laik.vidurkis + pazymys;
		}
		pazymys = rand() % 10 + 1;
		laik.egz = pazymys;
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
		laik.paz.clear();
		temp.push_back(laik);
	}

	

}
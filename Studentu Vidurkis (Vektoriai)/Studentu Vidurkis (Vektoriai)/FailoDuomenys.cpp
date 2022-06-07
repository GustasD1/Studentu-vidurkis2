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

		temp.push_back(laik);




	}


}
void FailoIsvedimas(vector<data>& temp) {
	int kiekis = temp.size();
	cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
	cout << "---------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < kiekis; i++) {
		cout << std::left << std::setw(20) << temp[i].vardas << std::left << std::setw(20) << temp[i].pavarde << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatasm << std::endl;
	}
}

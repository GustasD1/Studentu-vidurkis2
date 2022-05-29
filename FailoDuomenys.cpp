#include "biblioteka.h"
#include "prototipai.h"
data::~data() = default;


data::data(const data& dataa) {
	vardas2 = dataa.vardas2;
	pavarde2 = dataa.pavarde2;
	paz = dataa.paz;
	egz = dataa.egz;
	rezultatas = dataa.rezultatas;
	mediana = dataa.mediana;
	rezultatasm = dataa.rezultatasm;
	vidurkis = dataa.vidurkis;
}

data& data::operator=(const data & dataa) {
	if (&dataa == this) return *this;
	vardas2 = dataa.vardas2;
	pavarde2 = dataa.pavarde2;
	paz = dataa.paz;
	egz = dataa.egz;
	rezultatas = dataa.rezultatas;
	mediana = dataa.mediana;
	rezultatasm = dataa.rezultatasm;
	vidurkis = dataa.vidurkis;
	return *this;

}
const string& data::vardas() const { return vardas2; }
const string& data::pavarde() const { return pavarde2; }

void skaitymas(vector<data>& temp) {

	std::ifstream  fd("kursiokai.txt");
	

	string eil;
	stringstream buf;
	int pazymys;
	int k = 0;
	string vardas, pavarde;
	buf << fd.rdbuf();
	fd.close();

	data laik(vardas, pavarde);
	getline(buf, eil);


	while (getline(buf, eil)) {
		bool error = false;
		std::istringstream s(eil);
		s >> vardas >> pavarde;

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
void FailoIsvedimas(vector<data>& temp, vector<data>& temp2) {
	//	auto start = high_resolution_clock::now();
	//	std::sort(temp.begin(), temp.end(), [](data a, data b) {
	//		return a.vardas < b.vardas;
	//		});
	//	std::sort(temp2.begin(), temp2.end(), [](data a, data b) {
	//		return a.vardas < b.vardas;
	//		});

	int kiekis = temp.size();
	std::ofstream fr("vargsiukai.txt");
	std::ofstream out("kietiakai.txt");
	fr << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
	fr << "---------------------------------------------------------------------------" << std::endl;
	out << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis(vid.)" << std::left << std::setw(20) << "Galutinis(med.)" << std::endl;
	out << "---------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < kiekis; i++) {
		if (temp[i].rezultatas > 5.0)
			out << std::left << std::setw(20) << temp[i].vardas() << std::left << std::setw(20) << temp[i].pavarde() << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp[i].rezultatasm << std::endl;

	}
	kiekis = temp2.size();
	for (int i = 0; i < kiekis; i++) {
		if (temp[i].rezultatas < 5.0)
			fr << std::left << std::setw(20) << temp2[i].vardas() << std::left << std::setw(20) << temp2[i].pavarde() << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp2[i].rezultatas << std::left << std::setw(20) << std::fixed << std::setprecision(2) << temp2[i].rezultatasm << std::endl;

	}
}
void generacija(vector<data>& temp) {
	int n;
	cout << "kiek norite studentu sugeneruoti" << std::endl;
	cin >> n;
	int pazymys;
	string vardas, pavarde;
	data laik(vardas, pavarde);
	std::ofstream fr("kursiokai.txt");
	for (int i = 0; i < n; i++) {
		vardas = "Vardas" + std::to_string(i + 1);
		pavarde = "Pavarde" + std::to_string(i + 1);
		fr << vardas << " " << pavarde;
		fr << " ";
		for (int j = 0; j < 5; j++) {
			pazymys = rand() % 10 + 1;
			laik.paz.push_back(pazymys);
			laik.vidurkis = laik.vidurkis + pazymys;

			fr << pazymys << " ";
		}
		pazymys = rand() % 10 + 1;
		laik.egz = pazymys;
		fr << laik.egz << " ";
		fr << " " << std::endl;
		laik.paz.clear();

	}
}
void skirstymas(vector<data>& temp, vector<data>& temp2) {
	string vardas, pavarde;
	data laik(vardas, pavarde);
	int n = temp.size();
	for (int i = 0; i < n; i++) {

		if (temp[i].rezultatas < 5.0) {
			vardas = "Vardas" + std::to_string(i + 1);
			pavarde = "Pavarde" + std::to_string(i + 1);
			laik.rezultatas = temp[i].rezultatas;
			laik.rezultatasm = temp[i].rezultatasm;
			temp2.push_back(laik);
		}
	}
	for (int i = 0; i < n; i++) {
		if (temp[i].rezultatas < 5.0) {
			temp.erase(temp.begin() + i, temp.begin() + i);
			n--;
			temp.resize(n);
		}
	}

}


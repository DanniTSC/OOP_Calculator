#include<iostream>
#include<string>
using namespace std;
//7:20
class CartelaTransport {
	const string serieCartela;
	string numePosesor;
	char* producatorCartela;
	int nrZileUtilizare;
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	static float valoareMinCalatorie;
public:
	string getNumePosesor() {
		return this->numePosesor;
	}

	void setNumePosesor(string x) {
		if (x != " ")
		{
			this->numePosesor = x;
		}
	}
	
	float* getValoriCalatorii() {
		return this->valoriCalatorii;
	}

	void setValoriCalatorii(float* v, int nrCal) {
		if (v != nullptr && nrCal > 0)
		{
			this->nrCalatorii = nrCal;
			this->valoriCalatorii = new float[nrCal];
			for (int i = 0; i < nrCal; i++)
			{
				this->valoriCalatorii[i] = v[i];
			}
		}
	}

	CartelaTransport() : serieCartela("123ABC") {
		numePosesor = "Unknown";
		producatorCartela = nullptr;
		nrZileUtilizare = 0;
		sumaPortofel = 0;
		nrCalatorii = 0;
		valoriCalatorii = nullptr;
		valoareMinCalatorie = 0;
	}
	CartelaTransport(string numePosesor, int sumaPortofel, float* valoriCalatorii, int nrCalatorii) : serieCartela("123ABC") {
		this->numePosesor = numePosesor;
		this->sumaPortofel = sumaPortofel;
		this->nrCalatorii = nrCalatorii;
		producatorCartela = nullptr;
		nrZileUtilizare = 0;
		valoareMinCalatorie = 0;
		if (valoriCalatorii != nullptr)
		{
			this->valoriCalatorii = new float[sizeof(valoriCalatorii)];
			for (int i = 0; i < nrCalatorii; i++)
				this->valoriCalatorii[i] = valoriCalatorii[i];
		}

	}

	CartelaTransport(const CartelaTransport& c) {

	}

	~CartelaTransport() {
		if (producatorCartela != nullptr)
		{
			delete[] producatorCartela;
			producatorCartela = nullptr;
		}

		if (valoriCalatorii != nullptr)
		{
			delete[] valoriCalatorii;
			valoriCalatorii = nullptr;
		}

	}
};

float CartelaTransport::valoareMinCalatorie = 0;



int main() {
	float valori[] = { 23.0, 1.0, 1.0 };
	CartelaTransport t("Nume Posesor", 23.0, valori, 3);
	t.setValoriCalatorii(valori, 3);

}
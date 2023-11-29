#include<iostream>
#include<string>
using namespace std;

class JucatorMonopoly {
private:
	char* numeJucator;
	int valoareZar;
	int* chiriiIncasate;
	int nrMutari; //nr element vector chirii
	static int sumaInitiala;
	const int pion = 1;
public:
	JucatorMonopoly() {
		numeJucator = new char[strlen("N/A") + 1];
		strcpy_s(numeJucator,strlen("N/A") + 1, "N/A");
		valoareZar = 1;
		chiriiIncasate = nullptr;
		nrMutari = 0;
	}

	JucatorMonopoly(int pion, char* numeJucator, int valoareZar) : pion(pion) {
		if (this->numeJucator)
		{
			delete[] this->numeJucator;
		}
		if (numeJucator != nullptr) {
			this->numeJucator = new char[strlen(numeJucator) + 1];
			strcpy_s(this->numeJucator, strlen(numeJucator) + 1, numeJucator);
		}
		else
		{
			strcpy_s(numeJucator, strlen("N/A") + 1, "N/A");
		}
		
		if (valoareZar <= 12 && valoareZar >= 1) {
			this->valoareZar = valoareZar;
		}
		else {
			this->valoareZar = 1;
		}
		this->chiriiIncasate = NULL;
		this->nrMutari = 0;

	}

	int getValoareZar() {
		return this->valoareZar;
	}

	void setValoareZar(int x) {
		if (x <= 12 && x >= 1) {
			this->valoareZar = x;
		}
		else {
			this->valoareZar = 1 ;
		}
	}

	int* getChiriiIncasate() {
		return this->chiriiIncasate;
	}

	void setChiriiIncasate(int* nouChirii, int nouNr) {
		//evit shallow 
		if (this->chiriiIncasate != nullptr) {
			delete[] chiriiIncasate;
		}
		//validez
		if (nouChirii != nullptr && nouNr > 0) {
			chiriiIncasate = new int[nouNr];
			for (int i = 0; i < nouNr; i++) {
				chiriiIncasate[i] = nouChirii[i];
			}
			this->nrMutari = nouNr;
		}
		else
		{
			chiriiIncasate = nullptr;
			nrMutari = 0;
		}

	}

	JucatorMonopoly(const JucatorMonopoly& j1) : pion(j1.pion)
	{
		if (nrMutari != 0) {
			this->nrMutari = j1.nrMutari;
		}
		
		if (j1.valoareZar <= 12 && j1.valoareZar >= 1) {
			this->valoareZar = j1.valoareZar;
		}
		
		if (j1.numeJucator != nullptr) {
			numeJucator = new char[strlen(j1.numeJucator) + 1];
			strcpy_s(this->numeJucator, strlen(j1.numeJucator) + 1, j1.numeJucator);
		}
		if (j1.nrMutari != 0 && j1.chiriiIncasate != nullptr) {
			nrMutari = j1.nrMutari;
			chiriiIncasate = new int[j1.nrMutari];
			for (int i = 0; i < j1.nrMutari; i++) {
				chiriiIncasate[i] = j1.chiriiIncasate[i];
			}
		}

	}

	JucatorMonopoly& operator=(const JucatorMonopoly& j1) {
		if (this == &j1)
		{
			return *this;
		}
		else
		{
			if (nrMutari != 0) {
				this->nrMutari = j1.nrMutari;
			}

			if (j1.valoareZar <= 12 && j1.valoareZar >= 1) {
				this->valoareZar = j1.valoareZar;
			}

			if (j1.numeJucator != nullptr) {
				delete[] this->numeJucator;
				numeJucator = new char[strlen(j1.numeJucator) + 1];
				strcpy_s(this->numeJucator, strlen(j1.numeJucator) + 1, j1.numeJucator);
			}
			if (j1.nrMutari != 0 && j1.chiriiIncasate != nullptr) {
				nrMutari = j1.nrMutari;
				chiriiIncasate = new int[j1.nrMutari];
				for (int i = 0; i < j1.nrMutari; i++) {
					chiriiIncasate[i] = j1.chiriiIncasate[i];
				}
			}
		}
		return *this;
	}

	long bugetCurent() {
		long s = 0;
		if (this->chiriiIncasate == nullptr)
		{
			return s;
		}
		else
		{
			s += sumaInitiala;
			for (int i = 0; i < this->nrMutari; i++)
			{
				s += chiriiIncasate[i];
			}
		}
		return s;
	}

	static string castigatorJoc(JucatorMonopoly* j, int nrJuc) {
		int max = 0;
		for (int i = 0; i < nrJuc; i++) {
			if (max < (j[i].bugetCurent()))
			{
				max = j[i].bugetCurent();
			}

		}
		for (int i = 0; i < nrJuc; i++)
		{
			if (max == j[i].bugetCurent())
			{
				return j[i].numeJucator;
			}
		}
	}

	JucatorMonopoly& operator+=(int x) {
		int* tempVect;

		tempVect = new int[nrMutari];

		for (int i = 0; i < nrMutari; i++)
		{
			tempVect[i] = chiriiIncasate[i];
		}
		delete[] chiriiIncasate;

		chiriiIncasate = new int[nrMutari + 1];

		for (int i = 0; i < nrMutari; i++)
		{
			chiriiIncasate[i] = tempVect[i];
		}

		chiriiIncasate[nrMutari] = x;
		++nrMutari;

		delete[] tempVect;

		return *this;
	}




	~JucatorMonopoly() {
		if (chiriiIncasate != nullptr) {
			delete[] chiriiIncasate;
			chiriiIncasate = nullptr;
		}
		if (numeJucator != nullptr) {
			delete[] numeJucator;
			numeJucator = nullptr;
		}
	}
	friend istream& operator>>(istream& i,  JucatorMonopoly& j);
	friend ostream& operator<<(ostream& o,  JucatorMonopoly& j);
};

istream& operator>>(istream& i, JucatorMonopoly& j)
{
	// Elibereaza memoria 
	if (j.chiriiIncasate != nullptr)
	{
		delete[] j.chiriiIncasate;
	}

	// Elibereaza memoria 
	if (j.numeJucator != nullptr)
	{
		delete[] j.numeJucator;
	}


	char buffer[255];
	cout << "denumire:";
	i >> buffer;

	// Aloca spatiu 
	j.numeJucator = new char[strlen(buffer) + 1];
	strcpy_s(j.numeJucator, strlen(buffer) + 1, buffer);

	cout << "valzar:";
	i >> j.valoareZar;
	cout << "nrMutari";
	i >> j.nrMutari;

	// Alocã spatiu pentru 
	j.chiriiIncasate = new int[j.nrMutari];
	for (int k = 0; k < j.nrMutari; k++)
	{
		i >> j.chiriiIncasate[k];
	}

	return i;
}




ostream& operator<<(ostream& o, JucatorMonopoly& j)
{
	o << "nume:";
	if (j.numeJucator != nullptr)
	{
		o << j.numeJucator<<"\n";
	}
	o << "val zar" << j.valoareZar<<"\n";
	o << "nr mutari:" << j.nrMutari << "\n";
	o << "chirii:" << endl;
	
	if (j.chiriiIncasate) {
		for (int i = 0; i < j.nrMutari; i++)
		{
			o << j.chiriiIncasate[i] << " ";
		}
	}

	return o;
}

int JucatorMonopoly::sumaInitiala = 2000;

int main() {
	JucatorMonopoly j1;
	JucatorMonopoly j2;
	int nrMutari = 3;
	int Chirii[] = {100,250,150};
	j1.setChiriiIncasate(Chirii, nrMutari);
	long buget = j1.bugetCurent();
	cout << "bueget test" << buget<<endl;
	
	const int nrJuc = 3;
	//cin >> j2;
	//cout << j2;

	j1 += 200;

	cout << j1;

}
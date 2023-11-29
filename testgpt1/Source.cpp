#include<iostream>
#include<string>
using namespace std;

enum TYPE { INDIVIDUAL , TEAM };

class ProjectInfo {
	const int projectId;
	string* members;
	int noMembers;
	int noLinesOfCode;
	TYPE type;
	bool isComplex = false;
	const static int LINES_OF_CODE_PER_HOUR = 25 ;

public:
	
	ProjectInfo() : projectId(0)
	{
		this->members = nullptr;
		noMembers = 0;
		noLinesOfCode = 0;
		type = INDIVIDUAL;
		isComplex = false;
	}

	TYPE getType() {
		return this->type;
	}

	void setNoLinesOfCode(int nr) {
		this->noLinesOfCode = nr;
	}

	int getNoLinesOfCode() {
		if (this->noLinesOfCode > 0) {
			return this->noLinesOfCode;
		}
		return 0;
	}

	const int getId() {
		return this->projectId;
	}

	bool isEasy() {
		return this->isComplex == 0; //intoarce adevarat daca nu e isComplex e fals 
	}

	bool markAsEasy() {
		if (this->isComplex == true) {
			this->isComplex = false;
		}
		return this->isComplex;
	}



	ProjectInfo(int proiectId, string nume): projectId(proiectId) {
	
			this->members = new string[1];
			this->members[0] = nume;
			this->noMembers = 1;
			this->type = INDIVIDUAL;

	}
	int writeCode(int x) {
		if (this->noLinesOfCode > 0) {
			this->noLinesOfCode += x;
			return this->noLinesOfCode;
		}
		return 0;
	}

	ProjectInfo(const int proiectId, string* persoane, int nrPersoane) : projectId(proiectId) {
		if (nrPersoane > 0) {
			this->members = new string[nrPersoane];
			for (int i = 0; i < nrPersoane; i++) {
				this->members[i] = persoane[i];
			}
			this->noMembers = nrPersoane;
		}
		else {
			this->members = nullptr;
			this->noMembers = 0;
		}
		this->type = TEAM;

		this->isComplex = true;

		this->noLinesOfCode = 0;


	}

	ProjectInfo(const ProjectInfo& p):projectId(p.projectId){
		this->noMembers = p.noMembers;
		this->noLinesOfCode = p.noLinesOfCode;
		this->type = p.type;
		this->isComplex = p.isComplex;
		if (p.noMembers > 0) {
			this->members = new string[this->noMembers];
			for (int i = 0; i < this->noMembers; i++) {
				this->members[i] = p.members[i];
			}
		}
		else
		{
			this->noMembers = 0;
			this->members = nullptr;
		}
	}

	void operator=(const ProjectInfo& p) {
		if (this != &p) {
			delete[] members;

			this->noMembers = p.noMembers;
			this->noLinesOfCode = p.noLinesOfCode;
			this->type = p.type;
			this->isComplex = p.isComplex;
			
			if (p.noMembers > 0 && p.members != nullptr) {
				this->members = new string[this->noMembers];
				for (int i = 0; i < this->noMembers; i++) {
					this->members[i] = p.members[i];
				}
			}
			else
			{
				this->noMembers = 0;
				this->members = nullptr;
			}
		}
		else
		{
			return ; 
		}
	}
	
	~ProjectInfo() {
		if (members != nullptr) {
			delete[] members;
			members = nullptr;
		}
	}
	bool operator>(ProjectInfo& p) {
		return (p.noLinesOfCode < this->noLinesOfCode);
	}

	explicit operator float() {
		return LINES_OF_CODE_PER_HOUR;
	}

	ProjectInfo& operator+=(const string& p) {
		//temp array pt membrii vechi
		string* tempMemb = new string[noMembers];
		//membrii vechi copiati aicea
		for (int i = 0; i < noMembers; i++)
		{
			tempMemb[i] = members[i];
		}
		//sterg vect vechi
		delete[] members;
		//aloc iar memorie cu plus 1 pt memru nou
		members = new string[noMembers + 1];

		//copiez ce era in vechi plus asta nou
		for (int i = 0; i < noMembers; i++) {
			members[i] = tempMemb[i];
		}

		//pe ultima pozitie il adaug pe asta nou
		members[noMembers] = p;
		//cresc numaru de membrii ca a mai venit unu
		++noMembers;
		// sterg ala temporar
		delete[] tempMemb;
		
		return *this;
	}
	
	friend ostream& operator<<(ostream& o, ProjectInfo p);
};


ostream& operator<<(ostream& o, ProjectInfo p) {
	o << "ID:";
	o << p.getId() << endl;
	o << "nr membrii:";
	o << p.noMembers << endl;
	o << "linii cod:";
	o << p.noLinesOfCode << endl;
	if (p.members != nullptr) {
		o << "membrii:";
		for (int i = 0; i < p.noMembers; i++) {
			o << p.members[i];
			o << " ";
		}
	}
	return o;
}


string typeToString(TYPE projectType) {
	return (projectType == INDIVIDUAL) ? "Individual" : "Team";
}




int main() {
	ProjectInfo prj1(101,"Alice");
		prj1.setNoLinesOfCode(800);
	cout << prj1.getNoLinesOfCode()<<endl;
	cout << prj1.getType()<<endl;
	string members[] = { "Alice", "Bob", "Charlie" };
	int noPersons = 3;
	ProjectInfo prj2(202, members, noPersons);

	cout << typeToString(prj2.getType())<<endl; 
	
	prj2.markAsEasy();

	if (!prj2.isEasy())
		cout << endl << "Is complex";

	cout << endl << prj2.getId()<<endl;

	prj1.writeCode(1200);
	// adds the lines of code to the existing ones
	cout << prj1.getNoLinesOfCode();  // prints 2000

	ProjectInfo prj3 = prj2; //dangling fara const copiere

	ProjectInfo prj4;
	prj4 = prj2;
	prj4 = prj4;
	cout << endl;

	cout << prj2;


	cout << endl << prj2.getNoLinesOfCode()<<" " << prj1.getNoLinesOfCode();
	if (prj2 > prj1)
		cout << "\n Project 2 has more than 1000 lines of code";
	else
		cout << "\n Project 2 has less than 1000 lines of code";

	cout<< endl<< (float)prj2;
	cout << "After marking as easy: " << prj2.markAsEasy() << endl;

	ProjectInfo prj5(303, "David");
	prj5 += "Emma";
	cout << prj5;

}
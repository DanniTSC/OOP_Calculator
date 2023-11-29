#include<iostream>
#include<string>
using namespace std;

enum TYPE{TEAM, INDIVIDUAL};

class CppProject {
	const int projectId;
	string* members;
	int noMembers;
	int noLinesOfCode;
	bool isComplex = false;
	TYPE type;
	const static int LIES_OF_CODE_PER_HOUR = 30;
public:
	
	TYPE getType() {
		if (this->type == INDIVIDUAL)
		{
			return INDIVIDUAL;
		}
		if (this->type == TEAM)
		{
			return TEAM;
		}
	}

	string getTypeString(TYPE tip) {
		if (tip == INDIVIDUAL)
		{
			return "INDIVIDUAL";
		}
		else
		{
			return "TEAM";
		}
	}

	CppProject(int projectid,string member) : projectId(projectid) {
		this->type = INDIVIDUAL;
		this->noLinesOfCode = 0;
			members = new string[1]; //corect ????
			members[0] = member;
			this->noMembers = 1;

	}

	CppProject(int projectID, string* member, int nrPers) : projectId(projectID) {
		noMembers = nrPers;

		if (nrPers > 1) {
			this->type = TEAM;
		}
		else
		{
			this->type = INDIVIDUAL;
		}
		this->isComplex = true;
		

		if (member != nullptr && nrPers > 0) {
			members = new string[nrPers];
			for (int i = 0; i < nrPers; i++) {
				this->members[i] = member[i];
			}
		}
		
		else {
			members = nullptr;
		}
	}
	
	
	
	const int getId() {
		return this->projectId;
	}

	int getNoLinesOfCode() {
		return this->noLinesOfCode;
	}

	void writeCode(int x) {
		this->noLinesOfCode += x;
	}

	int getLinesOfCode() {
		return this->noLinesOfCode;
	}

	void setNoLinesOfCode(int x) {
		this->noLinesOfCode = x;
	}
	
	bool isEasy() {
		return this->isComplex == 0;
	}
	
	bool markAsEasy() {
		if (this->isComplex) {
			this->isComplex = false;
		}
		return this->isComplex;
	}

	CppProject(const CppProject& p) : projectId(p.projectId) {
		if (p.members != nullptr && p.noMembers > 0)
		{
			this->noMembers = p.noMembers;
			members = new string[p.noMembers];
			for (int i = 0; i < p.noMembers; i++)
			{
				members[i] = p.members[i];
			}

		}
		else
		{
			this->members = nullptr;
			this->noMembers = 0;
		}
		this->isComplex = p.isComplex;
		this->noLinesOfCode = p.noLinesOfCode;
		this->type = p.type;
	}

	CppProject& operator=(const CppProject& p)
	{
		if (this == &p)
		{
			return *this;
		}
		
		if (members != nullptr)
		{
			delete[] members;
		}
		
		if (p.members != nullptr && p.noMembers > 0)
		{
			this->noMembers = p.noMembers;
			members = new string[p.noMembers];
			for (int i = 0; i < p.noMembers; i++)
			{
				members[i] = p.members[i];
			}

		}
		else
		{
			this->members = nullptr;
			this->noMembers = 0;
		}
		this->isComplex = p.isComplex;
		this->noLinesOfCode = p.noLinesOfCode;
		this->type = p.type;
	

		return *this;
	}
	

	CppProject& operator +=(string x) {
					string* temp;
			temp = new string[this->noMembers];
			for (int i = 0; i < this->noMembers; i++)
			{
				temp[i] = members[i];
			}
			delete[] members;

			members = new string[noMembers + 1];
			for (int i = 0; i < this->noMembers; i++)
			{
				members[i] = temp[i];
			}
			delete[] temp;

			members[noMembers] = x;

			++noMembers;

			return *this;
		
	}


	~CppProject(){
		if (this->members != nullptr) {
			delete[] members;
			members = nullptr;
		}
	}

	bool operator>(const CppProject& p) {
		return (this->noLinesOfCode > p.noLinesOfCode) == 0;
	}

	friend ostream& operator<<(ostream& o, const CppProject p);
	
	explicit operator float() {
		return float(LIES_OF_CODE_PER_HOUR);
	}
};
ostream& operator<<(ostream& o, const CppProject p) {
	if (p.members != nullptr && p.noMembers > 0 )
	{
		o << "memebrii:";
		for (int i = 0; i < p.noMembers; i++)
		{
			o << p.members[i] << " ";
		}
	}
	else
	{
		o << "nu sunt membrii";
	}
	o << "nr membrii:" << p.noMembers << endl;
	o << " complex: " << p.isComplex << endl;
	o << " id: " << p.projectId << endl;
	o << "nr lini cod:" << p.noLinesOfCode << endl;
	return o;
}


int main() {
	int pers = 1;
	string memberi[] = { "John"};
	CppProject prj1(1, memberi , pers);
	cout << prj1 << endl;
	prj1 += "EMMA";
	cout << prj1 << endl;

	prj1.setNoLinesOfCode(1000);
	cout << prj1.getNoLinesOfCode() << endl;;

	cout <<prj1.getTypeString(prj1.getType())<<endl;           // prints “Individual” or “Team” based on project type


	string members[] = { "John", "Alice", "Bob" };

	int noPersons = 3;

	CppProject prj2(2, members, noPersons);        //2 is the project id

	//the project type will be set to TEAM

	//the project is set to be a complex one

	cout << prj2.getType();                             // prints Team


		if (!prj2.isEasy())

			cout << endl << "Is complex";        //prints this message


		cout << endl << prj2.getId() << endl;;        //prints 2

	prj2.markAsEasy();

	prj1.writeCode(1500);                              //adds the lines of code to the existing ones

	cout << prj1.getNoLinesOfCode();          // prints 2500

	CppProject prj3 = prj2;

	prj1 = prj2;

	prj1 = prj1;

	if (prj2 > prj1)
		cout << " da" << endl;
	
	cout << prj2;

	float totalHours = (float)prj1;

	cout << "\n Total hours" << totalHours << endl;

	CppProject prj4(1, "John");
	cout << prj4;
}
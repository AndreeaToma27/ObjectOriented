#include<iostream>
#include<string>

using namespace std;

enum ProgramType {UNDERGRADUATE, MASTER, PHD};
//-----------------------------------------------------------------------CLASS STUDENT
class Student {
	string name = "";
	ProgramType program = UNDERGRADUATE;   

	int* grades = nullptr;
	int noGrades = 0;

	static int minAge;
	static int maxAge;

public:
	//---------------------------------------------------------------------------METHOD
	void printInfo() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Program type: " << this->getProgramName();
		if (this->grades != nullptr) {
			cout << endl << "Student grades: ";
			for (int i = 0; i < noGrades; i++) {
				cout << grades[i] << " ";
			}
		}
		cout << endl << "------------------";
	}

	string getProgramName() {
		switch (this->program)
		{
			case UNDERGRADUATE:
				return "Undergraduate ";
			case MASTER:
				return "Master";
			case PHD:
				return "Phd";
		}
	}

	ProgramType getProgramType() {
		return this->program;
	}

	void setGrades( int* someGrades, int noGrades) {
		if (someGrades == nullptr) {
			throw exception("No grades");
		}

		//deep copy
		//avoid memory leaks
		if (this->grades != nullptr) {
			delete[] this->grades;
		}
		this->grades = new int[noGrades];
		for (int i = 0; i < noGrades; i++) {
			this->grades[i] = someGrades[i];
		}

		this->noGrades = noGrades;
	}

	void retakeExam(int newGrade, int index) {
		if (index < 0 || index >= this->noGrades) {
			throw exception("Wrong index");
		}
		this->grades[index] = newGrade;
	}

	void setName(string name) {
		this->name = name;
	}

	Student(string name, ProgramType program, int* grades, int noGrades) {
		this->name = name;
		this->program = program;
		this->setGrades(grades, noGrades);
	}

	//class destructor 
	//release the space from heap where objects store data 
	
	~Student() {
		if (this->grades != nullptr) {
			delete this->grades;
		}
	}


	Student() {

	}
};

int Student::minAge = 10;
int Student::maxAge = 90;

//----------------------------------------------------------------------------MAIN
int main() {
	Student student;
	student.printInfo();

	int grades[] = { 10,10,9 };
	int noGrades = 3;

	student.setGrades(grades, noGrades);

	student.printInfo();

	Student alice("Alice", UNDERGRADUATE, grades, noGrades);
	alice.printInfo();
	student.setName("John");
	student.retakeExam(10, 2);
	student.printInfo();
	alice.printInfo();

	
}

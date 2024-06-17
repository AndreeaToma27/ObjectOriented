#include<iostream>
#include<string>
using namespace std;

//static attributes 
//constant attributes
//copy constructor
//overloading operators -  = operator and others

class Student {
public:
	const int registrationNo;
private:
	string name = "";
	int age;
	int* grades = nullptr;
	int noCourses = 0;
	const int birthYear;

	static int MIN_AGE;
	static int MAX_AGE;
	const static int DEFAULT_REG_NO;
	static int STUDENT_COUNTER;

public:
	void setAge(int value) {
		if (value > Student::MIN_AGE && value < Student::MAX_AGE) {
			this->age = value;
		}
		else {
			throw exception("Wrong value for age");
		}
	}

	void setName(const char* value) {
		this->name = string(value);
	}

	/*void changeRegNo(int value) {
		this->registrationNo = value;
	}*/
public:
	//the const is initialised with a default value from a static 
	Student():registrationNo(Student::DEFAULT_REG_NO), birthYear(0) {
		Student::STUDENT_COUNTER += 1;
	}

	//the constant is initialized with the value from a static attribute
	Student(string name):registrationNo(Student::STUDENT_COUNTER), birthYear(0) {
		this->name = name;
		Student::STUDENT_COUNTER += 1;
	}

	//the constant is initialised with a value received
	Student(string name, int id) :registrationNo(id), birthYear(0) {
		this->name = name;
		Student::STUDENT_COUNTER += 1;
	}

	Student( string name,int id, int age):registrationNo(id), name(name), age(age), birthYear(0) {
		Student::STUDENT_COUNTER += 1;
	}

	Student(int id, string name, int age) :registrationNo(id), birthYear(0) {
		Student::STUDENT_COUNTER += 1;
	}
	

	Student(int id, string name, int age, int birthYear) :registrationNo(id), birthYear(birthYear) {
		Student::STUDENT_COUNTER += 1;
	}
};



//init the static attributes
int Student::MIN_AGE = 14;
int Student::MAX_AGE = 100;
const int Student::DEFAULT_REG_NO= 0;
int Student::STUDENT_COUNTER = 1;

//--------------------------------------------------------------------class gradebook
class GradeBook {
	string courseName;
	int* grades;
	int noGrades;

public:
	GradeBook(string name) : courseName(name){}

	void addGrade(int grade) {
		int* newArray = new int[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++) {
			newArray[i] = this->grades[i];
		}
		newArray[this->noGrades] = grade;
		this->noGrades += 1;
		if (this->grades != nullptr) {
			delete[] this->grades;
		}
		this->grades = newArray;
	}

	void print() {
		cout << endl << "Grades for " << this->courseName << " ";
		for (int i = 0; i < this->noGrades; i++) {
			cout << this->grades[i] << "";

		}
	}

	~GradeBook() {
		delete[] this->grades;
	}

	//class copy constructor
	GradeBook(const GradeBook& object) {
		cout << endl << "calling cc";
		this->courseName = object.courseName;
		this->grades = new int[object.noGrades]; 
		for (int i = 0; i < object.noGrades; i++) {
			this->grades[i] = object.grades[i];
		}
		this->noGrades = object.noGrades;

			
	}
};

void doSomething(GradeBook gradeBook) {
	cout << endl << "Something";
}

//here the cc is not needed
void doSomethingWPointer(GradeBook* gradeBook) {
	cout << endl << "Something";
}

GradeBook initGradeBook(string name) {
	GradeBook gradeBook(name);
	return gradeBook;
}


int main() {
	Student student;
	Student alice(1, "Alice", 21);
	Student john(2, "John", 20, 2000);
	cout << endl << "John id is " << john.registrationNo;

	Student bob("Bob");
	cout << endl << "Bob id is " << bob.registrationNo;
	Student vader(4, "Bob", 21, 2000);
	
	GradeBook oop("OOP");
	oop.addGrade(10);
	oop.addGrade(10);
	oop.addGrade(9);
	oop.print();

	doSomething(oop);
	//initGradeBook("DSAD");

	//calling the copy constructor
	GradeBook oopCopy = oop;
}

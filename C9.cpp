#include<iostream>
#include<string>

using namespace std;


class GradeBook {
	string courseName = "";
	int* grades = nullptr;
	int noGrades = 0;

public:
	GradeBook(string name) : courseName(name) {}

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
		cout << endl << "Grades for " << this->courseName << ": ";
		for (int i = 0; i < this->noGrades; i++) {
			cout << this->grades[i] << " ";

		}
	}

	string getName() {Name;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	int* getGrades() {
		return this->course
		int* gradesCopy = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			gradesCopy[i] = this->grades[i];
		}
		return gradesCopy;
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

	//overloading operator= for the gradebook class
	void operator=(const GradeBook source) { //left = destination, right = source
		this->courseName = source.courseName;
		this->noGrades = source.noGrades;

		if (this->grades = source.grades) {
			//is the same object
		}
		else {
			delete[] this->grades;
			this->grades = new int[this->noGrades];
			for (int i = 0; i < this->noGrades; i++) {
				this->grades[i] = source.grades[i];
			}
		}
	}

	void operator +=(int grade) {
		this->addGrade(grade);
	}

	//we use the reference to avoid the copy constructor
	bool operator>=(GradeBook& gradeBook) {
		if (this->noGrades >= gradeBook.noGrades) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!() {
		if (this->noGrades == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	//no return type
	explicit operator float() {
		int sum = 0;
		for (int i = 0; i < this->noGrades; i++) {
			sum += this->grades[i];
		}
		if(this->noGrades == 0) {
			return 0;
		}
		else {
			return (float) sum / this->noGrades;
		}
	}

	//pre-incrementation
	GradeBook operator++() {
		this->addGrade(10);
		return *this;
	}

	//post-incrementation
	GradeBook operator++(int) {
		GradeBook copy = *this;
		this->addGrade(10);
		return copy;
	}


	//friend -> this method will have access to the private area of the class
	friend void operator>>(istream& console, GradeBook& gradebook);
};
//overloading operators
//1. overload in the class - they receive the this pointer as the first argument 
//2. overload them as  global methods

void operator<<(ostream& console, GradeBook& gradebook) {
	console <<endl<< "The gradebook data is: ";
	console <<endl<< "The name of the course is: " << gradebook.getName();
	if (gradebook.getNoGrades() > 0) {
		int* grades = gradebook.getGrades();
		console <<endl<< "Grades: ";
		for (int i = 0; i < gradebook.getNoGrades(); i++) {
			console << grades[i] << " ";
		}
	}
	else {
		console << endl << "No grades";
	}
}

void operator>>(istream& console, GradeBook& gradebook) {
	cout <<endl<< "The course name is: ";
	string courseName;
	console >> courseName;
	gradebook.courseName = courseName; //we have access because this method is friend of the class
	cout << endl << "The new number of grades: ";
	console >> gradebook.noGrades;

	delete[] gradebook.grades;
	gradebook.grades = new int[gradebook.noGrades];
	for (int i = 0; i < gradebook.noGrades; i++) {
		cout << endl << "Grade " << i + 1 << ": ";
		console >> gradebook.grades[i];
	}

	

}

int main() {
	GradeBook oopGradeBook("OOP");
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(9);
	oopGradeBook.print();


	//<< operator used to print
	// >> used to read
	cout << oopGradeBook;					//operator<<(std::ostream, GradeBook)
	
	
	GradeBook webGradeBook("Webtech");
	//cin >> webGradeBook;					//operator>>(std::istream, GradeBook)
	cout << webGradeBook;

	oopGradeBook += 10;						//oopGradeBook = oopGradeBook + 10
											//operator+=(GradeBook, int)

	if (oopGradeBook >= webGradeBook) {
		cout << endl << oopGradeBook.getName() << " has more grades or the same number of grades as " << webGradeBook.getName();
	}
	else {
		cout << endl << oopGradeBook.getName() << " has less grades or the same number of grades as " << webGradeBook.getName();
	}

	//!
	if (!oopGradeBook) {
		cout << endl << oopGradeBook.getName() << " has no grades";
	}
	else {
		cout << endl << oopGradeBook.getName() << " has grades";
	}


	//cast operator
	float averageGrade = (float)oopGradeBook; //operator float(GradeBook)
	cout << endl << "The average grade is " << averageGrade;

	//using the explicit cast
	int value = (float)oopGradeBook + 5;

	//++, --

	int vb1 = 10;
	int vb2 = ++vb1;
	int vb3 = vb1++;

	//add a default 10  grade
	//post incremetation
	webGradeBook = oopGradeBook++;			//operator++(GradeBook, int)
	
	//pre incrementation
	webGradeBook = ++oopGradeBook;			//operator++(int, GradeBook)

	cout << oopGradeBook;

	
}

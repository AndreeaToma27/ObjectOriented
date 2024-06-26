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

	string getName() {
		return this->courseName;
	}

	int getNoGrades() {
		return this->noGrades;
	}

	int* getGrades() {
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

	GradeBook operator+(int grade) {
		//this is a mistake
		//this->addGrade(grade);

		GradeBook copy = *this;
		copy.addGrade(grade);
		return copy;
	}
};

GradeBook operator+(int grade, GradeBook gradeBook) {
	return gradeBook + grade;

	//if you don't have the other version

	/*GradeBook copy = gradeBook;
	copy.addGrade(grade);
	return copy;*/
}

GradeBook createAGradeBook() {
	GradeBook newGradeBook("An empty gradebook");
	return newGradeBook;
}



int main() {
	GradeBook oopGradeBook("OOP");
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(10);
	oopGradeBook.addGrade(9);
	oopGradeBook.print();

	GradeBook oop2021("OOP for 2021");
	GradeBook oop2022("OOP for 2022");

	//explicit call of the copy constructor
	GradeBook oopGradeBookCopy = oopGradeBook;

	//operator = 
	oop2021 = oopGradeBook; // operator=(oop2021, oopGradeBook)

	oopGradeBook = oopGradeBook;

	//operator =
	//oop2021 = createAGradeBook();


	//here they are always executed from right to left
	//the first one executed:  oop2022 = oopGradeBook;
	//the second one executed: oop2021 = oop2022
	//oop2021 = oop2022 = oopGradeBook; //oop2021 = operator=(oop2022, oopGradeBook)

	oop2021 = oopGradeBook;  //oop2021.operator=(oopGradeBook)
	oop2022 = oopGradeBook;

	int vb = 10; //operator=(int left, int right)
	vb = vb + 20; //operator+(int a, int b)
	

	oop2021 = (oop2021 + 8); //oop2021.operator+(8) //operator+(GradeBook, int)

	oop2021 = 9 + oop2021; //operator+(int, GradeBook)
}

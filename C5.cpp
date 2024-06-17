#include<iostream>
#include<string>
#include<string.h>
using namespace std;

class Student {
private:

	//you can choose your own defaults
	char name[100]="";
	bool hasScholarship=false;
	int age=0;
	int noGrades=0;
	int* grades=nullptr;
public:
	

	//----------------------------------------------------------------------------------CONSTRUCTORS
	//public interface
	//class constructor
	Student(const char* name, int age, bool hasScholarship) {
		this->setAge(age);
		hasScholarship ? this->gainsScholarship() : this->losesScholarship();
		this->setName(name);
	}

	Student(const char* name, bool hasScholarship, int age) {
		this->setAge(age);
		hasScholarship ? this->gainsScholarship() : this->losesScholarship();
		this->setName(name);
	}

	Student(const char* name, int age) {
		this->setAge(age);
		this->hasScholarship = false;
		this->setName(name);
	}

	//we chose not to implement this because name and age should be mandatory
	/*Student(const char* name) {
		//this->setAge(0);
		this->age = 0;
		this->hasScholarship = false;
		this->setName(name);
	}
	*/

private:
	//private because allows inconsistent data 
	//default constructor
	Student() {
		this->setName("John Doe");
		this->age = 0;
		this->hasScholarship = false;
	}

public:
	//------------------------------------------------------------------------------GETTERS AND SETTERS
	int getAge() {
							//receives by default the adress of the calling object
							//the poiner name is this
							//Student* this
		return this->age;
	}

	bool getHasScholaship() {
		return this->hasScholarship;
	}

	string getNameValue() {
		return string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, name);
		return nameCopy;
	}

	//write access
	void setAge(int value) {
		//validate the input
		if (value >= 10 && value <= 100) {
			this->age = value;
		}
		else {
			//throw "Wrong value for age";
			throw exception("Wrong value for age");
		}
	}

	void gainsScholarship() {
		this->hasScholarship = true;
	}

	void losesScholarship() {
		this->hasScholarship = false;
	}

private:

	void setName(const char* value) {
		if (strlen(value) > 99) {
			throw exception("Value too long");
		}
		strcpy_s(this->name, 99, value);
	}
public:
	void printInfo() {
		cout << endl << "---------------------------------";
		cout << endl << "Name: " << this->getNameValue();
		cout << endl << "Age: " << this->age;
		cout << endl << "Has scholarship: " << (this->hasScholarship ? "true" : "false");
		if (this->noGrades != 0) {
			cout << endl << "Grades: ";
			for (int i = 0; i < noGrades; i++) {
				cout << this->grades[i] << " ";
			}
		}
	}
};
//--------------------------------------------------------------------------------------------CLASS FACUTLY

class Faculty {
	string name;
	string adress;
public:
	//Faculty(string name, string adress) :name(name), adress(adress) {}
	Faculty() {
		
	}
};

//--------------------------------------------------------------------------------------------ADDING FUNCTIONS
//overloading
//defining multiple methods with the same name, different arguments list : no of arguments, types, order of arg
int addNumbers(int a, int b) {
	return a + b;
}

int addNumbers(int a, int b, int c) {
	return a + b + c;
}

float addNumbers(float a, float b) {
	return a + b;
}

void incrementCounter(int value) {
	value++;
}

void incrementCounterWithPointer(int *pointerToCounter) {
	*pointerToCounter += 1;
}


//---------------------------------------------------------------------------------------------------MAIN
int main() {
	addNumbers(10, 20);
	addNumbers(10, 20, 30);

	//so the compiler knows which version i want to use  
	float realResult = addNumbers((float)1.2, (float)3.4);

	//testing the constructors

	Student alice("Alice", true, 21);
	Student john("John", 21, false);
	Student bob("Bob", 20);

	alice.printInfo();
	john.printInfo();
	bob.printInfo();


	//Student vader("Vader");
	//vader.printInfo();

	//Student vader;
	//Faculty csie;

	//vader.printInfo();

	int counter = 0;
	counter += 1;

	cout << endl << "-------------------Counter: " << counter;
	incrementCounter(counter);
	cout << endl << "-------------------Counter: " << counter;

	incrementCounterWithPointer(&counter);
	cout << endl << "-------------------Counter: " << counter;
}

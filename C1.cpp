//c++ can use c libraries
#include<stdio.h>
#include<iostream>

using namespace std;

int global;

namespace myVariables {
	int vb;
}

namespace yourVariables {
	int vb;
}

void doSomething() {
	int anIntegerValue;
	char aCharVariable;
	short int aShortIntVariable;
}



int main() {
	
	printf("\n ByeBye C");

	myVariables::vb = 10;
	yourVariables::vb = 20;
	//vb = 30;


	std::cout << "\n Hello C++";
	std::cout << std::endl << "Recap on pointers";
	cout << endl << "Recap on pointers";

	int anIntegerValue;
	char aCharVariable;
	short int aShortIntVariable;

	aCharVariable = 'a';

	//this is a char array of 2 elements because it contains the /0
	//aCharVariable = "a";
	aCharVariable = 10; 

	aCharVariable = 108; //aka = 'm'
	anIntegerValue = 'a';

	aCharVariable += 10; //aka 'v'


	cout << endl << "The number is " << anIntegerValue;


	// pointers
	//pointers are variables used to store numbers that represent adresses


	//a pointer to an adress of any type
	void* aPointerVariable = (void*)(108);

	int* aPointerToAnInteger = (int*)108;
	char* aPointerToAChar;

	//cout << endl << "The value from RAM at adress 108 is " << aPointerVariable; //you see the pointer value
	//cout << endl << "The value from RAM at adress 108 is " << *aPointerToAnInteger;

	aPointerToAnInteger = &anIntegerValue;

	cout << endl << "The adress of anIntegerVariable is " << aPointerVariable;



	//this is not necessary, the program will put it by default 
	//return 0;
}

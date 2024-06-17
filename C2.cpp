#include<iostream>
using namespace std;


void interchange(int vbX, int vbY) {
	int temp = vbX;
	vbX = vbY;
	vbY = temp;
}

void interchange2(int* pX, int* pY) {
	int temp = *pX;
	pX = pY;
	*pY = temp;

}

int main() {
	std::cout << std::endl << "Course 03";

	int valueA = 10;
	int valueB = 20;

	int values[] = { 1,2,3,4,5,6 };
	int noValues = 6;

	int* pointerA = nullptr;
	void* genericPointer = nullptr;

	cout << endl << "A value "<<valueA;

	//a mistake
	//pointerA = (int*)valueA;

	pointerA = &valueA;

	cout <<endl<< "The value (adress) of the pointer is " << pointerA;
	cout <<endl<< "The value at the pointer is adress is " << *pointerA;

	//go into memory at the adress and change the value to 90
	*pointerA = 90;
	cout << endl << "A value is " << valueA;

	cout << endl << "Adress of A is " << &valueA;
	cout << endl << "Adress of B is " << &valueB;

	int* pointerB = &valueB;

	int* (*pointerOfPointerA) = &pointerA;

	int vbX = 10;
	int vbY = 20;

	cout << endl << "x = " << vbX << " and y = " << vbY;

	int temp = vbX;
	vbX = vbY;
	vbY = temp;

	cout << endl << "x = " << vbX << " and y = " << vbY;
	interchange(vbX, vbY);
	cout << endl << "x = " << vbX << " and y = " << vbY;

	interchange2(&vbX, &vbY);
	cout << endl << "x = " << vbX << " and y = " << vbY;
	
}

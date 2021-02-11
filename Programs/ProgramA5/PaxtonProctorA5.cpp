//*****************************************************************************
//                 Assignment #5
//                 Name: Paxton Proctor
//                 Data Structures Date: Date of Submission (11/13/2020)
//*****************************************************************************
//                 This Program uses Recursion and has 2 functions that will
//                 call themselves and will give the summation and the result
//                 of a couple of powers.
//*****************************************************************************
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Function Prototypes
int Summation(int number, int total, bool firstcall );
int BaseExponent(int base, int exponent, bool secondcall);

//main
int main() {
	//declarations
	int num = 0;
	int total1 = 0;
	bool firstcall = true;
	//gets total of summation
	total1 = Summation(num, total1, firstcall);
	//prints total of summation
	cout << " total of Summation is " << total1 << '\n';
	//declarations
	int base1 = 0;
	int exponent1 = 0;
	bool secondcall = true;
	//prints result of baseexponent
	cout << "result of Base and Exponent is " << 
		BaseExponent(base1, exponent1, secondcall) << '\n';
}
/*****************************************************
 * Name: Summation                                   *
 * Input: int NUM1                                   *
 * Process: Ask user for number and then gets all    *
 * odds and adds them together                       *
 * output: Prints out the total for odd numbers      *
 *                                                   *
 ****************************************************/
int Summation(int number, int total, bool firstcall) {
	// calls recursion until bool becomes false
	if (firstcall) {
		// asking user for positive number
		cout << "Please enter a positive number.\n";
		cin >> total;
		// if the number is less than 0 then it will call itself
		if (total <= 0) {
			cout << "Sorry please enter a positive number.\n";
			return Summation(number, total, firstcall);
		}
		else {
			firstcall = false;
			return Summation(number, total, firstcall);
		}
	}
	// if all the conditions pass then it'll check to see if odd or even
	else {
		int sum = number;
		if (total <= 0) {
			return sum;
		}
		else if (total % 2 != 0) {
			sum += total;
			// when it is initially odd then it will subtract by 2 to stay odd
			// and will call itself until the number becomes negative
			return Summation(sum, total - 2, firstcall);
		}
		else {
			// when it is initially even then it will subtract by 1 to become odd
			// and will call itself again
			return Summation(sum, total -1, firstcall);
		}
	}
}

/*****************************************************
 * Name: BaseExponent                                *
 * Input: int base1 and exponent 1                   *
 * Process: Ask user for base and exponent gets the  *
 * total from them                                   *
 * output: Prints out the total for base and exponent*
 *                                                   *
 ****************************************************/
int BaseExponent(int base, int exponent, bool secondcall) {
	if (secondcall) {
		// ask user for base and exponent
		cout << "enter a base and then a exponent.\n";
		cin >> base;
		cin >> exponent;
		// checks to see if the exponent is less than 0 and will call itself
		// until a positive value is entered
		if (exponent == 0) {
			cout << "sorry you must enter a exponent\n";
			return BaseExponent(base, exponent, secondcall);
		}
		else {
			secondcall = false;
			return BaseExponent(base, exponent, secondcall);
		}
	}
	// after all conditions are met it will call itself until the exponents
	// are equal to zero and will multiply the result by the base.
	else {
		if (exponent == 0) {
			return 1;
		}
		else {
			return (base * BaseExponent(base, exponent - 1, secondcall));
		}
	}
}
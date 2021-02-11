//*******************************************************************************
//                 Assignment #1
//                 Name: Paxton Proctor
//                 Data Structures Date: Date of Submission (09/21/2020)
//*******************************************************************************
//                 This Program Creates and answers the Quadractic equation
//                 using 6 Functions and a Matrix it creates
//                 The Discriminant, Numerator, Denominator, and The root.
//                 It lastly displays the Matrix that your inputs were put in.
//*******************************************************************************
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>

using namespace std;

// Function Prototypes
void myMatrix(double(&myArray)[3][3]);
void showMatrix(double[3][3]);
void valueOfDiscriminant(double[3][3], int k);
void valueOfNumerator(double[3][3], int k);
void valueOfDenominator(double[3][3], int k);
void printRoots(double[3][3], int k);

// Main
int main() {
	double maTrix[3][3];
	myMatrix(maTrix);
	showMatrix(maTrix);
	return 0;
}
/**************************************
 * Name: myMatrix                     *
 * Input: double &myArray             *
 * Process: Creates a 2D array Matrix *
 * output: a, b, c. 3 times.          *
 *                                    *
 **************************************/
void myMatrix(double(&myArray)[3][3]) {
	double a, b, c = 0;
	for (int i = 0; i < 3; i++) {
		cin >> a >> b >> c;
		myArray[i][0] = a;
		myArray[i][1] = b;
		myArray[i][2] = c;
	}
	return;
}
/*****************************************************************
 * Name: showMatrix                                              *
 * Input: double myArray                                         *
 * Process: Calls all Functions and Matrix and Prints the results*
 * output: Num, Disc, Den, Roots, Matrix                         *
 *****************************************************************/
void showMatrix(double myArray[3][3]) {
	for (int k = 0; k < 3; k++) {
		cout << "Equation " << k + 1 << '\n';
		cout << "Discriminant: ";
		valueOfDiscriminant(myArray, k);
		cout << "The Numerator is: ";
		valueOfNumerator(myArray, k);
		cout << "The Denominator is: ";
		valueOfDenominator(myArray, k);
		printRoots(myArray, k);
		cout << "=======================\n";
	}
	cout << "Your Matrix\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << myArray[i][j] << " ";
		}
		cout << '\n';
	}
}
/*****************************************************************
 * Name: valueOfDiscriminant                                     *
 * Input: double myArray                                         *
 * Process: Creates the Answer to the Discriminant               *
 * output: Discriminant                                          *
 *****************************************************************/
void valueOfDiscriminant(double myArray[3][3], int k) {
	double disc = 0;
	disc = ((myArray[k][1]) * (myArray[k][1])
		- (4 * (myArray[k][0]) * (myArray[k][2])));
	cout << disc << endl;
	return;
}
/*****************************************************************
 * Name: valueOfNumerator                                        *
 * Input: double myArray                                         *
 * Process: Creates the Answer to the Numerator                  *
 * output: Nemerator                                             *
 *****************************************************************/
void valueOfNumerator(double myArray[3][3], int k) {
	double Num = 0;
	double Num2 = 0;
	double tempNum1 = (myArray[k][1]) * (myArray[k][1])
		- (4) * (myArray[k][0]) * (myArray[k][2]);
	Num = (-(myArray[k][1])) - sqrt(tempNum1);
	Num2 = (-(myArray[k][1])) + sqrt(tempNum1);
	if (Num == Num2) // 1 real
	{
		Num = (-(myArray[k][1])) - sqrt(tempNum1);
		cout << Num << endl;
	}
	else if (tempNum1 < 0) //complex
	{
		cout << -(myArray[k][1]) << " +- " << sqrt(-tempNum1) << 'i' << endl;
	}
	else // 2 real
	{
		cout << -(myArray[k][1]) << " +- " << sqrt(tempNum1) << endl;
	}
	return;
}
/*****************************************************************
 * Name: valueOfDenominator                                      *
 * Input: double myArray                                         *
 * Process: Creates the Answer to the Denominator                *
 * output: Denominator                                           *
 *****************************************************************/
void valueOfDenominator(double myArray[3][3], int k) {
	double Den = 0;
	Den = 2 * (myArray[k][0]);
	cout << Den << endl;
	return;
}
/*****************************************************************
 * Name: printsRoots                                            *
 * Input: double myArray                                         *
 * Process: Creates the Answer to the Roots                      *
 * output: Roots                                                 *
 *****************************************************************/
void printRoots(double myArray[3][3], int k) {
	double tempNum1 = (myArray[k][1]) * (myArray[k][1])
		- ((4) * (myArray[k][0]) * (myArray[k][2]));
	// quadractic1 is the - and quadractic2 is the +
	double quadratic1 = ((-(myArray[k][1])) - 
		sqrt(tempNum1)) / 2 * (myArray[k][0]);
	double quadratic2 = ((-(myArray[k][1])) +
		sqrt(tempNum1)) / 2 * (myArray[k][0]);
	if (quadratic1 == quadratic2)
	{
		cout << "This is one real root: " << quadratic1 << endl;
	}

	else if (tempNum1 < 0)
	{
		// quadractic3 is the - and quadractic4 is the +
		double quadratic3 = (((-myArray[k][1])) // check here
			- sqrt(tempNum1 * -1)) / (2 * (myArray[k][0]));
		double quadratic4 = (((-myArray[k][1])) // check Here
			+ sqrt(tempNum1 * -1)) / (2 * (myArray[k][0]));
		cout << "This is two complex roots: " << 
			quadratic3 << " +- " << quadratic4 << 'i' << endl;
	}
	else
	{
		cout << "This is two real roots: " << 
			quadratic2 << " and " << quadratic1 << endl;
	}
	return;
}
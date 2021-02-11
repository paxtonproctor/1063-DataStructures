//*****************************************************************************
//                 Assignment #4
//                 Name: Paxton Proctor
//                 Data Structures Date: Date of Submission (11/9/2020)
//*****************************************************************************
//                 This Program uses pointers as references into functions
//                 that create a dynamic allocated matrix and adds SSNs
//                 and prints them. The second function determines whether
//                 they are man or women.
//*****************************************************************************
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

//Function Prototypes
void socialSecuritynum(int **SSN, int SIZE);
void tinyvillepeeps(int** SSN, int SIZE);

// main
int main() {
	// creates a new random generated number every time
	srand(time(NULL));
	
	// creates dynamic allocated array
	int m;
	cout << "How big do you you want the 2d array?\n";
	cin >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = (rand()%5000)+1000;
		}
	}

	// Prints matrix and calls functions
	cout << "=======================================\n";
	cout << "The Matrix:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << "    ";
		}
		cout << '\n';
	}
	cout << "=======================================\n";
	socialSecuritynum(a, m);
	cout << "=======================================\n";
	tinyvillepeeps(a, m);
	cout << "=======================================\n";
}
/*****************************************************
 * Name: socialSecuritynum                           *
 * Input: int *SSN, int SIZE                         *
 * Process: Gets user matrix info                    *
 * output: prints out SSN and total amount of people *
 *                                                   *
 ****************************************************/
void socialSecuritynum(int **SSN, int SIZE) {
	
	//Declarations
	int socSecnum1 = 0;
	int socSecNum2 = 0;
	int SocSecNum3 = 0;
	int Socsecnum4 = 0;
	int socsecNum5 = 0;
	int total;
	//start of 2d array and compares and sorts SSNs into each group
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (SSN[i][j] >= 1000 && SSN[i][j] < 2000) {
				socSecnum1++;
			}
			else if (SSN[i][j] >= 2000 && SSN[i][j] < 3000) {
				socSecNum2++;
			}
			else if (SSN[i][j] >= 3000 && SSN[i][j] < 4000) {
				SocSecNum3++;
			}
			else if (SSN[i][j] >= 4000 && SSN[i][j] < 5000) {
				Socsecnum4++;
			}
			else {
				socsecNum5++;
			}
		}
	}
	// total number of social security numbers
	total = socSecnum1 + socSecNum2 + SocSecNum3 + Socsecnum4 + socsecNum5;
	cout << "The following summarizes the SSNs in Tiny Ville\n";
	cout << "SSN: 1000s = " << socSecnum1 << "\nSSN: 2000s = " <<
		socSecNum2 << "\nSSN: 3000s = " <<
		SocSecNum3 << "\nSSN: 4000s = " << Socsecnum4 
		<< "\nSSN: 5000s = " << socsecNum5 << '\n';
	cout << "The total # of habitants in Tiny Ville is = " << total << '\n';
	return;
}
/*****************************************************
 * Name: tinyvillepeeps                              *
 * Input: int *SSN, int SIZE                         *
 * Process: Gets user matrix and prints 2 genders    *
 * output: prints out 2 genders                      *
 *                                                   *
 ****************************************************/
void tinyvillepeeps(int** SSN, int SIZE) {
	// declarations
	int men = 0;
	int women = 0;
	int baby = 0;
	// start of 2d array
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// comparing to determine men or women
			if (SSN[i][j] % 2) {
				women++;
			}
			else {
				men++;
			}
		}
	}
	// total
	baby = men + women;
	// prints women and men
	cout << "The total # of habitants in Tiny Ville is = " << baby << '\n';
	cout << "Tiny Ville has = " << women << " women" << '\n';
	cout << "Tiny Ville has = " << men << " men" << '\n';
}
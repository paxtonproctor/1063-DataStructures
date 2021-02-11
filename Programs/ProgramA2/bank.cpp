//*****************************************************************************
//                 Assignment #2
//                 Name: Paxton Proctor
//				   Name: Daniel Stanley
//                 Data Structures Date: Date of Submission (10/21/2020)
//*****************************************************************************
//                 This program is creating a bank account and doing various
//                 things such as showing the bank info, withdraw, deposit,
//                 and doing a transfer. The code uses vector, classes,
//                 and functions The Menu will let you know which
//                 task you want to do.
//*****************************************************************************
#include <iostream>
#include <iomanip>
#include "account.h"
#include <vector>

using namespace std;

// Function Prototypes
void askingBankInfo(vector<account> &Accounts, int &totalAccounts);
void showUserType(vector<account> Accounts, int totalAccounts);
void UserDeposit(vector<account> &Accounts, int totalAccounts);
void UserWithdraw(vector<account>& Accounts, int totalAccounts);
void ChangeType(vector<account>& Accounts, int totalAccounts);
void Transfer(vector<account>& Accounts, int totalAccounts);


// Main
int main() {
    char Menu = 'z';
    int totalAccounts = 0;
    //vector declaration
    vector<account> Accounts;
    Accounts.resize(50);
    //Menu to choose a function of operation
    while (Menu != 'A' && Menu != 'a')
    {
        cout << "Type E to enter account information\n" <<
            "Type S to show account information\n" <<
            "Type D to deposit money\n" <<
            "Type W to withdraw money\n" <<
            "Type C to change account type\n" <<
            "Type T to transfer money from an account to another account\n"
            "Type A to exit the menu entirely\n";
        cin >> Menu;
        //enters account information
        if (Menu == 'E' || Menu == 'e')
        {
            askingBankInfo(Accounts, totalAccounts);
        }
        //Shows account information
        else if (Menu == 'S' || Menu == 's')
        {
            showUserType(Accounts, totalAccounts);
        }
        //Deposit money to a chosen account
        else if (Menu == 'D' || Menu == 'd')
        {
            UserDeposit(Accounts, totalAccounts);
        }
        //Withdraws money from a chosen account
        else if (Menu == 'W' || Menu == 'w')
        {
            UserWithdraw(Accounts, totalAccounts);
        }
        //Changes the type of account 
        else if (Menu == 'C' || Menu == 'c')
        {
            ChangeType(Accounts, totalAccounts);
        }
        //Transfers money from one account to another account
        else if (Menu == 'T' || Menu == 't')
        {
            Transfer(Accounts, totalAccounts);
        }
        else
        {
            cout << "This is not a valid character" << 
                "to input to access the bank\n";
        }
    }
}
/****************************************
 * Name: askingBankInfo                 *
 * Input: vector<account> &totalAccount *
 * Process: Gets info and stores it     *
 * output:  none                        *
 *                                      *
 ****************************************/
void askingBankInfo(vector<account> &Accounts,int &totalAccounts) {
    // declarations
	string UserName;
    int  AccountNumber;
	double Balance;
	char AccountType, decision;
	int year, month, day;
    //start of for loop
	for (int i = 0; i < 50; i++) {
		//getting Userinfo
		cout << "Enter your account number\n";
		cin >> AccountNumber;
		cout << "Enter your user name\n";
		cin >> UserName;
		cout << "Enter your Balance\n";
		cin >> Balance;
		cout << "Enter your account type\n";
		cin >> AccountType;
		cout << "Enter your access date\n";
		cin >> month >> day >> year;
		Accounts[i].setfullAccount(AccountNumber, UserName, 
			Balance, AccountType, year, month, day);// setfullaccount here
		cout << "Would you like to Enter another account? (y/n)\n";
		cin >> decision;
		if (decision != 'Y' && decision != 'y') {
			totalAccounts = i + 1;
			i = 50;
		}
    // End of for loop
	}
	return;
}
/*********************************************************
 * Name: showUserType                                    *
 * Input: vector<account> Accounts, totalAccount         *
 * Process: Takes User info and Prints it out            *
 * output:  Prints out user info                         *
 *                                                       *
 ********************************************************/
void showUserType(vector<account> Accounts, int totalAccounts) {
    //start of for loop
	for (int i = 0; i < totalAccounts; i++) {
        // shows the info the user put in
		cout << "=============================\n";
		cout << "Your Bank Account Number is: " <<
            Accounts[i].getAccountNum() << '\n';
		cout << "Your user name is: " << Accounts[i].getUserN() << '\n';
		cout << "Your Balance is: " << Accounts[i].getBal() << '\n';
		cout << "Your Account Type is: " << Accounts[i].getAType() << '\n';
		cout << "Your Last Payment: " << Accounts[i].getlastPayment() << '\n';
        cout << "=============================\n";
	}
    // end of for loop
	return;
}
/***************************************************************
 * Name: UserDeposit                                           *
 * Input: vector<account> &Accounts, totalAccount              *
 * Process: Gets User Account and Adds a depoosit into balance *
 * output:  Prints out user balance                            *
 *                                                             *
 **************************************************************/
void UserDeposit(vector<account> &Accounts, int totalAccounts) {
    int i = 0;
    char decision = 'y';
	int accountNumber;
	double deposit;
    double Balance_d;
    // Start of while loop
	while (decision == 'Y' || decision == 'y') {
        i = 0;
        cout << "What is your account number?\n";
        cin >> accountNumber;
        cout << "Type how much you wish to deposit\n";
        cin >> deposit;
        // checks to see if there is a account
        while (accountNumber != Accounts[i].getAccountNum()) {
            i++;
            if (i >= totalAccounts) {
                cout << "We do not have your Account" <<
                    "number on file please try again\n";
                cin >> accountNumber;
                i = 0;
            }
        }
        // deposit
        if (deposit > 0)
        {
            Balance_d = Accounts[i].getBal() + deposit;
            Accounts[i].setBal(Balance_d);
            cout << "Your current balance is: $" <<
                Accounts[i].getBal() << '\n';
        }
        //ensures that the user doesn't deposit 0 and below
        else
        {
            cout << "Not enough to deposit\n";
        }
        cout << "Would you like to Deposit more money? (y/n)\n";
        cin >> decision;
	}
    // end of while
}

/***************************************************************
 * Name: UserWithdraw                                          *
 * Input: vector<account> &Accounts, totalAccount              *
 * Process: Gets User Account and withdraws from balance       *
 * output:  Prints out user balance                            *
 *                                                             *
 **************************************************************/
void UserWithdraw(vector<account>& Accounts, int totalAccounts) {
    int i = 0;
    char decision = 'y';
    int accountNumber;
    double withDraw;
    double Balance_w;
    // start of the while loop
    while (decision == 'Y' || decision == 'y') {
        i = 0;
        cout << "What is your account number?\n";
        cin >> accountNumber;
        cout << "Type how much you wish to withdraw\n";
        cin >> withDraw;
        // checks to see if there is a account
        while (accountNumber != Accounts[i].getAccountNum()) {
            i++;
            if (i >= totalAccounts) {
                cout << "We do not have your Account" <<
                    "number on file please try again\n";
                cin >> accountNumber;
                i = 0;
            }
        }
        // withdraws
        if (withDraw <= Accounts[i].getBal())
        {
            Balance_w = Accounts[i].getBal() - withDraw;
            Accounts[i].setBal(Balance_w);
            cout << "Your current balance is: $" <<
                Accounts[i].getBal() << '\n';
        }
        //ensures that the user doesn't withdraw more money then the balance
        else
        {
            cout << "Not enough to withdraw\n";
        }
        cout << "Would you like to withdraw more money? (y/n)\n";
        cin >> decision;
    }
    // end of while loop
}
/***************************************************************
 * Name: ChangeType                                            *
 * Input: vector<account> &Accounts, totalAccount              *
 * Process: Gets User Account and change the account type      *
 * output:  Prints out new account type                        *
 *                                                             *
 **************************************************************/
void ChangeType(vector<account>& Accounts, int totalAccounts) {
    int i = 0;
    char decision = 'y';
    int accountNumber;
    // start of while loop
    while (decision == 'Y' || decision == 'y') {
        i = 0;
        cout << "What is your account number?\n";
        cin >> accountNumber;
        // checks to see if account is there
        while (accountNumber != Accounts[i].getAccountNum()) {
            i++;
            if (i >= totalAccounts) {
                cout << "We do not have your Account" <<
                    "number on file please try again\n";
                cin >> accountNumber;
                i = 0;
            }
        }
        // changes account type
        if (Accounts[i].getAType() == 'c' || Accounts[i].getAType() == 'C') {
            Accounts[i].setAType('s');
        }
        else {
            Accounts[i].setAType('c');
        }
        cout << "Your account type is now " << Accounts[i].getAType() << '\n';
        cout << "Would you like to change account type again? (y/n)\n";
        cin >> decision;
    }
    // end of while loop
}
/*****************************************************************************
 * Name: Transfer                                                            *
 * Input: vector<account> &Accounts, totalAccount                            *
 * Process: Gets User Account and transfers money between different accounts *
 * output:  none                                                             *
 *                                                                           *
 ****************************************************************************/
void Transfer(vector<account>& Accounts, int totalAccounts) {
    int i = 0;
    int o = 0;
    char decision = 'y';
    int accountNumber;
    int accountNumber2;
    double Transfer;
    double Balance_T;
    double Balance_T2;
    // start of while loop
    while (decision == 'Y' || decision == 'y') {
        i = 0;
        o = 0;
        cout << "What is your account number that you are transfering from?\n";
        cin >> accountNumber;
        // checks to see if there is a account
        while (accountNumber != Accounts[i].getAccountNum()) {
            i++;
            if (i >= totalAccounts) {
                cout << "We do not have your Account" <<
                    "number on file please try again\n";
                cin >> accountNumber;
                i = 0;
            }
        }
        cout << "What is your account number 2" <<
            "that you are transfering over to?\n";
        cin >> accountNumber2;
        // checks to see if there is a account
        while (accountNumber2 != Accounts[o].getAccountNum()) {
            o++;
            if (o >= totalAccounts) {
                cout << "We do not have your Account" <<
                    "number on file please try again\n";
                cin >> accountNumber2;
                o = 0;
            }
        }
        cout << "How much would you like to transfer\n";
        cin >> Transfer;
        // transfers money from one account to another
        if (Transfer <= Accounts[i].getBal())
        {
            // withdraw
            Balance_T = Accounts[i].getBal() - Transfer;
            Accounts[i].setBal(Balance_T);
            cout << "Your current balance is: $" <<
                Accounts[i].getBal() << '\n';
            // deposit
            Balance_T2 = Accounts[o].getBal() + Transfer;
            Accounts[o].setBal(Balance_T2);
            cout << "Your current balance is: $" <<
                Accounts[o].getBal() << '\n';
        }
        //ensures that the user doesn't withdraw more money then the balance
        else
        {
            cout << "Not enough to Transfer\n";
        }
        cout << "Would you like make another transfer? (y/n)\n";
        cin >> decision;
    }
    // End of while loop
}
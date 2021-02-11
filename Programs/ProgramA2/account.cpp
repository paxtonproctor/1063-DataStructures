#include <iostream>
#include <string>
#include <fstream>
#include "account.h"

using namespace std;

//Default constructors
account::account()
{
	AccountNumber = 0;
	UserName = "";
	Balance = 0.0;
	AccountType = 's';
	lastPayment.setDate(1, 1, 1);
}
// overloaded constructor
account::account(int AccountNum, string UserN, double Bal,
	char AType ,int year ,int month ,int day)
{
	AccountNumber = AccountNum;
	UserName = UserN;
	Balance = Bal;
	AccountType = AType;
	lastPayment.setDate(year, month, day);
}
//Getters
int account::getAccountNum()
{
	return AccountNumber;
}
string account::getUserN()
{
	return UserName;
}
double account::getBal()
{
	return Balance;
}
char account::getAType()
{
	return AccountType;
}
string account::getlastPayment()
{
	string last;
	last = to_string(lastPayment.getMonth()) + " " + 
		to_string(lastPayment.getDay()) + 
		", " + to_string(lastPayment.getYear());
	return last;
}
//setters
void account::setAccountNum(int AccountNum)
{
	AccountNumber = AccountNum;
	//AccountNum = AccountNumber
}
void account::setUserN(string UserN)
{
	UserName = UserN;
}
void account::setBal(double Bal)
{
	Balance = Bal;
}
void account::setAType(char AType)
{
	AccountType = AType;
}
void account::setlastPayment(int year, int month, int day) {
	lastPayment.setDate(year, month, day);
}
void account::setfullAccount(int AccountNum, string UserN, double Bal,
	char AType, int year, int month, int day)
{
	AccountNumber = AccountNum;
	UserName = UserN;
	Balance = Bal;
	AccountType = AType;
	lastPayment.setDate(year, month, day);
}
account::~account()
{}
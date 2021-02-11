#ifndef account_H
#define account_H
#endif // !Date
#include <string>
#include "bankDate.h"
using namespace std;
class account
{
private:
	string UserName;
	int AccountNumber;
	double Balance;
	char AccountType;
	Date lastPayment;
public:
	//constructors
	account();
	account(int AccountNum, string UserN, double Bal,
		char AType, int year, int month, int day);
	//getters
	int getAccountNum();
	string getUserN();
	double getBal();
	char getAType();
	string getlastPayment();
	//setters
	void setAccountNum(int AccountNum);
	void setUserN(string UserN);
	void setBal(double Bal);
	void setAType(char AType);
	void setlastPayment(int year, int month, int day);
	void setfullAccount(int AccountNum, string UserN, double Bal,
		char AType, int year, int month, int day);
	//deconstructor
	~account();
};

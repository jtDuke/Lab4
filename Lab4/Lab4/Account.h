//------------------------------ Account.h ------------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Account
{
	friend ostream& operator<<(ostream& os, Account *acct);

public:
	Account();
	Account(const int id, const string fname, const string lname);
	~Account();
	Account* createAccount(string &newLine);
	void displayAccount() const;
	bool validateData(string newLine);
	void setID(const int id);
	void setFirstName(const string name);
	void setLastName(const string name);
	int getID() const;
	string getFirstName() const;
	string getLastName() const;
	bool operator==(const Account &acct);
	bool operator<(const Account &acct);

private:
	string firstName;
	string lastName;
	int userID;
};
#endif
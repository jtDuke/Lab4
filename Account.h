//------------------------------ Account.h ------------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------B------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Account
{
public:
	Account() {}
	virtual ~Account() 
	{ 
		//cout << "Account Base Destructor" << endl; 
	}
	virtual Account* createAccount(string newLine) = 0;
	virtual void displayAccount() = 0;
protected:
	string firstName;
	string lastName;
	int userID;
};

class customerAccount : public Account
{
public:
	customerAccount()
	{
		//cout << "customerAccount Constructor" << endl;
	}
	~customerAccount() 
	{
		//cout << "customerAccount Destructor" << endl;
	}
	customerAccount* createAccount(string newLine)
	{
		customerAccount *nAcct = new customerAccount;
		istringstream testLine(newLine);		// allows splitting of a string
		string s;
		int id = 0;

		getline(testLine, s, ' ');		// userID		
		id = stoi(s);
		nAcct->userID = id;

		getline(testLine, s, ' ');		// firstName
		nAcct->firstName = s;

		getline(testLine, s, ' ');		// lastName
		nAcct->lastName = s;

		return nAcct;
	}

	int getUserID() const
	{
		return userID;
	}

	void displayAccount()
	{
		cout << "Account: " << userID << " " << firstName << " " << lastName << endl;
	}
};
//------------------------------ Account.h ------------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------B------------------------------------
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Account
{
public:
	Account();
	virtual ~Account();
	virtual void createAccount(string newLine) = 0;
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
		cout << "customerAccount Destructor" << endl;
	}
	void createAccount(string newLine)
	{
		istringstream testLine(newLine);		// allows splitting of a string
		string s;
		int id = 0;

		getline(testLine, s, ' ');		// userID		
		id = stoi(s);
		this->userID = id;
		getline(testLine, s, ' ');		// firstName
		this->firstName = s;
		getline(testLine, s, ' ');		// lastName
		this->lastName = s;
		
	}
	void displayAccount()
	{
		cout << "Account: " << userID << " " << firstName << " " << lastName << endl;
	}
};
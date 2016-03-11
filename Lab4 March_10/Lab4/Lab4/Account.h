//------------------------------ Account.h ------------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Account
{
public:
	Account();
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

private:
	string firstName;
	string lastName;
	int userID;
};
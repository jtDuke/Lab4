//------------------------------ Account.cpp ----------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include "Account.h"



Account::Account()
{
	//cout << "Base Account Constructor" << endl;
}


Account::~Account()
{
	//cout << "Base Account Destructor" << endl;
}

void Account::setID(const int id)
{
	userID = id;
}
void Account::setFirstName(const string name)
{
	firstName = name;
}
void Account::setLastName(const string name)
{
	lastName = name;
}
int Account::getID() const
{
	return userID;
}
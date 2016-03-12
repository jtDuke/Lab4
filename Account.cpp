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
Account::Account(const int id, const string fname, const string lname)
{
	userID = id;
	firstName = fname;
	lastName = lname;
}

Account::~Account()
{

}

ostream& operator<<(ostream& os, Account *acct)
{
	os << acct->userID << " " << acct->firstName << " " << acct->lastName << endl;
	return os;
}

bool Account::operator==(const Account &acct)
{
	if (this->userID == acct.userID)
		if (this->firstName == acct.firstName)
			if (this->lastName == acct.lastName)
				return true;
	
	return false;
}

bool Account::operator<(const Account &acct)
{
	if (this->userID < acct.userID)
		return true;
	else
		return false;
}

Account* Account::createAccount(string &newLine)
{
	istringstream testLine(newLine);		// allows splitting of a string
	string s;
	int id = 0;
	Account* newAcct = new Account;
	getline(testLine, s, ' ');		// userID	
	istringstream(s) >> id;
	//id = stoi(s);
	newAcct->setID(id);
	getline(testLine, s, ' ');		// firstName
	newAcct->setFirstName(s);
	getline(testLine, s, ' ');		// lastName
	newAcct->setLastName(s);

	return newAcct;
}

bool Account::validateData(string newLine)
{
	istringstream testLine(newLine);		// allows splitting of a string
	string s;
	int id;

	getline(testLine, s, ' ');		// userID		
	istringstream(s) >> id;
	if (id < 0 || id > 9999)		// Check valid range for ID (still need to check if the ID already exists)
		return false;				// If here, it's an invalid ID 		

	getline(testLine, s, ' ');		// first name
	if (s == "")					// making sure it's not blank
		return false;				// If here, it's an invalid name 

	getline(testLine, s, ' ');		// last name
	if (s == "")					// making sure it's not blank
		return false;				// If here, it's an invalid name

	return true;
}

void Account::displayAccount() const
{
	cout << "Account: " << userID << " " << firstName << " " << lastName << endl;
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

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

int Account::getID() const
{
	return userID;
}
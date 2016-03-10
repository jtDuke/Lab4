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
#include <fstream>
using namespace std;

class Account
{
public:
	Account();
	virtual ~Account();
	virtual Account* createAccount(string &newLine) = 0;
	virtual void displayAccount() = 0;
	//virtual Account* processAccounts(ifstream&) = 0;
	virtual void setID(const int id);
	virtual void setFirstName(const string name);
	virtual void setLastName(const string name);
	virtual int getID() const;
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
	Account* createAccount(string &newLine)
	{
		istringstream testLine(newLine);		// allows splitting of a string
		string s;
		int id = 0;
		Account* yoyo = new customerAccount;
		getline(testLine, s, ' ');		// userID		
		id = stoi(s);
		yoyo->setID(id);
		getline(testLine, s, ' ');		// firstName
		yoyo->setFirstName(s);
		getline(testLine, s, ' ');		// lastName
		yoyo->setLastName(s);

		return yoyo;
	}

	//Account* processAccounts(ifstream& file)
	//{




	//		return createAccount(newLine);
	//}

	bool validateData(string newLine)
	{
		istringstream testLine(newLine);		// allows splitting of a string
		string s;
		int id;

		getline(testLine, s, ' ');		// userID		
		id = stoi(s);
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

	void displayAccount()
	{
		cout << "Account: " << userID << " " << firstName << " " << lastName << endl;
	}
};
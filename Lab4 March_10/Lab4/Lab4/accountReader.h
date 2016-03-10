#include "Reader.h"
#include "Account.h"

class accountReader : public Reader
{
public:
	accountReader();
	~accountReader();
};

class customerReader : public accountReader
{
public:
	customerReader() {}
	~customerReader() {}

	void processAccounts(ifstream& file)
	{
		while (!file.eof())				// check for end of file
		{
			string newLine;				// placeholder for line of input
			getline(file, newLine);		// get line of input from Accounts file

			if (newLine == "")  // (backup eof check) If true, we're at the end of file
				break;			// exit loop

			if (!validateData(newLine))		// calling function to validate the line of data
			{
				cout << "INVALID ACCOUNT" << endl;
				continue;
			}

			Account *nAcct = new customerAccount;
			nAcct->createAccount(newLine);
			nAcct->displayAccount();
		}
	}

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
};




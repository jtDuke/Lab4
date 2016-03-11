#include "Store.h"



Store::Store() {}

Store::Store(string name, int id)
{
	this->name = name;
	this->storeID = id;

	ifstream accountFile("data4users.txt");
	ifstream movieFile("data4movies.txt");
	ifstream transactionFile("data4commands.txt");
	if (!accountFile || !movieFile || !transactionFile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

	processFileStreams(accountFile, 0);		 //start the add useAccount process
	processFileStreams(movieFile, 1);			 //addFile(productFile, 1);
	//processFileStreams(transactionFile, 2);     //addFile(transactionFile, 2);
}


void Store::processFileStreams(ifstream& file, int fileType)
{
		if (fileType == 0) //adduser
		{
			addAccount(file);
		}
		else if (fileType == 1)  //addMovie
		{
			addMovie(file);
		} 
		else
		{
			addTransaction(file); // addTransactions
		} 
}


void Store::addAccount(ifstream& file)
{
	while (!file.eof())				// check for end of file
	{
		Account yo;
		string newLine;				// placeholder for line of input
		getline(file, newLine);		// get line of input from Accounts file

		if (newLine == "")  // (backup eof check) If true, we're at the end of file
			break;			// exit loop //clear memory for account

		if (!yo.validateData(newLine))		// calling function to validate the line of data
		{
			cout << "INVALID ACCOUNT" << endl;
			continue; 
		}

		Account *newAccount = yo.createAccount(newLine);
		accountTable.insert(newAccount);
		accountTable.display(newAccount->getID()); //adds accounts to hashTable


		// !!!!!----- TESTING PURPOSES , DON'T DELETE ---------!!!!!!! //
		//userAccounts[newAccount->getID()] = newAccount;
		//cout << "ACCOUNT ID: " << newAccount->getID() << endl;
		//cout << "HASHED TO: " << accountTable.[newAccount->getID()] << endl;
	}
}

void Store::addMovie(ifstream& file)
{
	//make reader
	//give reader string
}

void Store::addTransaction(ifstream& file)
{
	//make reader
	//give reader string
}

Store::~Store()
{

}
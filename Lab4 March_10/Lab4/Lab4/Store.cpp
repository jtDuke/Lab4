#include "store.h"



Store::Store() {}
Store::Store(string name, int id, string accounts, string products, string transactions) 
{
	this->name = name;
	this->storeID = id;

	ifstream accountFile(accounts);
	ifstream productFile(products);
	ifstream transactionFile(transactions);
	if (!accountFile || !productFile || !transactionFile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

	processFile(accountFile, 0);   //start the add useAccount process
	//addFile(productFile, 1);
	//addFile(transactionFile, 2);
}

void Store::processFile(ifstream& file, int fileType)
{
		if (fileType == 0) //adduser
		{
			addAccount(file);
		}
		else if (fileType == 1)  //addMovie
		{
			addProduct(file);
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
			continue; //clear memory for account
		}

		Account *newAccount = yo.createAccount(newLine);
		accountTable.insert(newAccount);
		accountTable.display(newAccount->getID()); //adds accounts to hashTable

		//userAccounts[newAccount->getID()] = newAccount;
		//cout << "ACCOUNT ID: " << newAccount->getID() << endl;
		//cout << "HASHED TO: " << accountTable.[newAccount->getID()] << endl;
	}
}

void Store::addProduct(ifstream& file)
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
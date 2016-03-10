#include "store.h"


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
	//accountF.processAcctFile(accountFile);
	processFile(accountFile, 0);   //start the add useAccount process
	//addFile(productFile, 1);
	//addFile(transactionFile, 2);
}

void Store::processFile(ifstream& file, int fileType)
{

	/*Account * yo = new customerAccount;

	userAccounts[0] = yo;
	userAccounts[0]->displayAccount();*/

		if (fileType == 0) //adduser
		{
			//want to return account pointer here
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
		customerAccount yo;
		string newLine;				// placeholder for line of input
		getline(file, newLine);		// get line of input from Accounts file

		if (newLine == "")  // (backup eof check) If true, we're at the end of file
			break;			// exit loop

		if (!yo.validateData(newLine))		// calling function to validate the line of data
		{
			cout << "INVALID ACCOUNT" << endl;
			continue;
		}

		Account *newAccount = yo.createAccount(newLine);
		userAccounts[newAccount->getID()] = newAccount;
		cout << "ACCOUNT ID: " << newAccount->getID() << endl;
		cout << "HASHED TO: " << userAccounts[newAccount->getID()] << endl;		
		//userAccounts[newAccount->getID()]->displayAccount();
	}

	//customerReader custRead;     // create Reader
	//custRead.processAccounts(file);  // Start reader process
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

//void Store::storeAccount(Account * newAccount)
//{
//	userAccounts[0] = newAccount->
//} 
Store::~Store()
{

}
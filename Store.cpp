#include "Store.h"


Store::Store(string name, int id, string accounts, string products, string transactions) 
{
	userAccounts = new customerAccount*[MAX_ACCOUNTS];
	for (int i = 0; i < MAX_ACCOUNTS; i++)
	{
		userAccounts[i] = NULL;
	}
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
		customerReader custRead;     // create Reader
		string newLine = custRead.processAccounts(file); // Start reader process
		if (newLine == "")
			continue;

		customerAccount newAcct;
		customerAccount *yoyo = newAcct.createAccount(newLine);
		userAccounts[yoyo->getUserID()] = yoyo;
		userAccounts[yoyo->getUserID()]->displayAccount();
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
	for (int i = 0; i < MAX_ACCOUNTS; i++)
	{		
		if (userAccounts[i] == NULL)
			continue;
		else
		{
			delete userAccounts[i];
			userAccounts[i] = NULL;
		}		
	}
}
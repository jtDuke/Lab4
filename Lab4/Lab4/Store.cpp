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
	
	customerReader custRead;     // create Reader
	custRead.processAccounts(file);  // Start reader process
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
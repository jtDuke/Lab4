#include "store.h"

Store::Store(string name, int id, string accounts, string products, string transactions) 
{
	this->name = name;
	this->storeID = id;

	cout << name << " " << id << endl;
	ifstream infileAccounts(accounts);
	ifstream infileProducts(products);
	ifstream infileTransactions(transactions);
	if (!infileAccounts || !infileProducts || !infileTransactions)
	{
		cout << "File could not be opened." << endl;
		return;
	}

	addFile(infileAccounts, 0);
	addFile(infileProducts, 1);
	addFile(infileTransactions, 2);

}

void Store::addFile(ifstream& file, int fileType)
{
	for (;;)
	{
		if (file.eof())
			break;

		string s;
		getline(file, s);
		

		if (fileType == 0) //adduser();
		{
			addAccount(s);
		}
		else if (fileType == 1) 
		{
			addProduct(s);
		} //addMovie;
		else 
		{
			addTransaction(s);
		} //addTransactions
	}

}

void Store::addAccount(string account)
{
	//make reader
	//give reader string
}

void Store::addProduct(string product)
{
	//make reader
	//give reader string
}

void Store::addTransaction(string transaction)
{
	//make reader
	//give reader string
}
//addUser //calls the readers
Store::~Store()
{

}
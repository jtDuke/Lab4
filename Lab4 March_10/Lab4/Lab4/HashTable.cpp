#include "HashTable.h"

HashTable::HashTable()
{
}

//to do
HashTable::~HashTable()
{
}

void HashTable::insert(Account* account)
{
	userAccounts[getHashCode(account)] = account;
}

int HashTable::getHashCode(Account* account)
{
	return account->getID();
}

void HashTable::display(int index)
{
	cout << userAccounts[index]->getID() << endl;
}

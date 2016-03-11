#include "HashTable.h"

HashTable::HashTable()
{
	for (int i = 0; i < MAX_ACCOUNTS; i++)
		userAccounts[i] = NULL;
}

HashTable::~HashTable()
{
	for (int i = 9999; i >= 0; i--)
	{
		delete userAccounts[i];
		userAccounts[i] = NULL;
	}
}


// SET UP COLLISION PROTECTION // 
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

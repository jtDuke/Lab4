#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Account.h"

const int MAX_ACCOUNTS = 10000;       	 //Max Customer Accounts

class HashTable
{
public:
	HashTable();
	~HashTable(); //to do 
	void insert(Account*);
	int getHashCode(Account*);
	void display(int);

private:
	Account *userAccounts[MAX_ACCOUNTS];
};
#endif
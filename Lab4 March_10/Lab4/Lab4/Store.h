// file store.h
//-----------------------------------------------------------------------------------------------------
// Represents an individual store
// Store class can hold user accounts and hold collections of store products
//-----------------------------------------------------------------------------------------------------
// Implementation and Assumptions:
// No more than 10,000 unique user id’s
//-----------------------------------------------------------------------------------------------------


#include <fstream>
#include <iostream>
#include <string>
#include "Movie.h"
#include "HashTable.h"
using namespace std;

class Store
{

public:
	Store();
	Store(string, int, string, string, string); //takes strings of text file names as parameters
								   //store 
								   // loop through text file, for each line in text file (call addUser)
	void addAccount(ifstream& file); // handle adding users to system database
	void addProduct(ifstream& file);
	void addTransaction(ifstream& file);
	void processFile(ifstream&, int);
	//void storeAccount(Account* newAccount);
	~Store();

private:
	string name;
	int storeID;
	HashTable accountTable;
	//Account *userAccounts[10000];
	//AcctFactory accountF;
	//accountHashTable hashTable(MAX_ACCOUNTS);
	//productCollectionTable productCollectionTree*;

};

// file store.h
//-----------------------------------------------------------------------------
// Represents an individual store
// Store class can hold user accounts and hold collections of store products
//-----------------------------------------------------------------------------
// Implementation and Assumptions:
// No more than 10,000 unique user id’s
//-----------------------------------------------------------------------------
#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Movie.h"
#include "MovieFactory.h"
#include "BinTree.h"
using namespace std;

class Store
{

public:
	Store();			//store
	Store(string, int);							    
	
	
	void processFileStreams(ifstream&, int);  //Decides which file to read from

	void addAccount(ifstream& file);     // Add users to system 
	void addMovie(ifstream& file);       // Add movies to system
	void addTransaction(ifstream& file); // Perfrom transactions on the system
	
	//void storeAccount(Account* newAccount);
	~Store();

private:
	string name;
	int storeID;
	HashTable accountTable;
	BinTree funTree;
	BinTree dramaTree;
	BinTree classTree;
	//Account *userAccounts[10000];
	//AcctFactory accountF;
	//accountHashTable hashTable(MAX_ACCOUNTS);
	//productCollectionTable productCollectionTree*;

};
#endif
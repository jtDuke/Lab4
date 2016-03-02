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


using namespace std;

const int MAX_ACCOUNTS = 10000;       	 //Max Customer Accounts

class Store
{

public:
	Store();
	Store(string, int, string, string, string); //takes strings of text file names as parameters
								   //store 
								   // loop through text file, for each line in text file (call addUser)
	void addAccount(string); // handle adding users to system database
	void addProduct(string);
	void addTransaction(string);
	void addFile(ifstream&, int);
	~Store();

private:
	string name;
	int storeID;
	//accountHashTable hashTable(MAX_ACCOUNTS);
	//productCollectionTable productCollectionTree*;

};

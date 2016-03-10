#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <ios>
#include "Account.h"

using namespace std;

class AcctFactory
{
public:
	AcctFactory();
	~AcctFactory();

	void processAcctFile(ifstream& file);
	//bool validateData(string newLine);
	void processAccounts(ifstream& file, string id, string fname, string lname);
	bool validateData(string newLine);
};


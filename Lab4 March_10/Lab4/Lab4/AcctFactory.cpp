#include "AcctFactory.h"



AcctFactory::AcctFactory()
{
}

void AcctFactory::processAcctFile(ifstream& file)
{
	string id;
	string fname;
	string lname;

	// Get current position
	int len = file.tellg();

	// Read line
		file >> id;
		file >> fname;
		file >> lname;
		
		//TODO: --- HOW DO I CHECK IF THE ABOVE ARE CUSTOMER OR MANAGER OR ETC....
		
	// Return to position before "Read line".
	file.seekg(len, ios_base::beg);
	//Account *yoyo = processAccounts(file);
	//processAccounts(file, id, fname, lname);
}


AcctFactory::~AcctFactory()
{
}

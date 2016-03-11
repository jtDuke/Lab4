
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
class Reader
{
public:
	Reader();
	virtual bool validateData(string newLine) = 0;
	virtual void processAccounts(ifstream& file) = 0;
	~Reader();
};


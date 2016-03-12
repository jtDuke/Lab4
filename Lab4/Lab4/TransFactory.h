//------------------------------ TransFactory.h -------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H
#include "Transaction.h"
#include <string>
using namespace std;

class TransFactory
{
public:
	TransFactory();
	~TransFactory();

	static char getTransType(string newLine);
	static bool ValidateData(const char movieType, string newLine);
	//static bool validateHistory(string newLine);
	//static bool validateBorrow(string newLine);
	//static bool validateReturn(string newLine);
	//static Transaction* createHistory(string newLine);
	//static Transaction* createBorrow(string newLine);
	//static Transaction* createReturn(string newLine);
};

#endif
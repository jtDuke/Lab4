#include "Account.h"

class customerAccount : public Account
{
public:
	customerAccount();
	~customerAccount();
	void createAccount(const int ID, const string fname, const string lname);
};


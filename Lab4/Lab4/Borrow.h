//------------------------------ Borrow.h -------------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#ifndef BORROW_H
#define BORROW_H
#include "Transaction.h"
class Borrow : public Transaction
{
public:
	Borrow();
	~Borrow();

	// Comparison operators
	bool operator==(const Transaction&) const;
	bool operator!=(const Transaction&) const;
	bool operator<(const Transaction&) const;
	bool operator>(const Transaction&) const;

	// Getters n Setters
	char getTransType() const;
	void setTransType(const char &type);
	char getCustomerID() const;
	void setCustomerID(const int &id);
	char getMediaType() const;
	void setMediaType(const char &type);
	char getMovieType() const;
	void setMovieType(const char &type);
	int getMonth() const;
	void setMonth(const int &month);
	int getYear() const;
	void setYear(const int &year);
	string getDirector() const;
	void setDirector(const string &dir);
	string getTitle() const;
	void setTitle(const string &title);
};
#endif


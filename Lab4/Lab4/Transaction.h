//------------------------------ Transaction.h -------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

	virtual void display() const = 0;

	// Comparison Operators
	virtual bool operator==(const Transaction&) const = 0;
	virtual bool operator!=(const Transaction&) const = 0;
	virtual bool operator<(const Transaction&) const = 0;
	virtual bool operator>(const Transaction&) const = 0;

	// Getters n Setters
	virtual char getTransType() const = 0;
	virtual void setTransType(const char &type) = 0;
	virtual char getCustomerID() const = 0;
	virtual void setCustomerID(const int &id) = 0;
	virtual char getMediaType() const = 0;
	virtual void setMediaType(const char &type) = 0;
	virtual char getMovieType() const = 0;
	virtual void setMovieType(const char &type) = 0;
	virtual int getMonth() const = 0;
	virtual void setMonth(const int &month) = 0;
	virtual int getYear() const = 0;
	virtual void setYear(const int &year) = 0;
	virtual string getDirector() const = 0;
	virtual void setDirector(const string &dir) = 0;
	virtual string getTitle() const = 0;
	virtual void setTitle(const string &title) = 0;

protected:
	char transType;
	int customerID;
	char mediaType; 
	char movieType;
	int month;
	int year;
	string director;
	string title;
};

#endif
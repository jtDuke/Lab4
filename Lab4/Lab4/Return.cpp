//------------------------------ Return.cpp -----------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include "Return.h"

Return::Return()
{
}
Return::~Return()
{
}


// Comparison Operators
bool Return::operator==(const Transaction&) const
{
	return true;
}
bool Return::operator!=(const Transaction&) const
{
	return true;
}
bool Return::operator<(const Transaction&) const
{
	return true;
}
bool Return::operator>(const Transaction&) const
{
	return true;
}

// Getters n Setters
char Return::getCustomerID() const
{
	return customerID;
}
void Return::setCustomerID(const int &id)
{
	this->customerID = id;
}
char Return::getMediaType() const
{
	return mediaType;
}
void Return::setMediaType(const char &type)
{
	this->mediaType = type;
}
char Return::getMovieType() const
{
	return movieType;
}
void Return::setMovieType(const char &type)
{
	this->movieType = type;
}
int Return::getMonth() const
{
	return month;
}
char Return::getTransType() const
{
	return transType;
}
void Return::setTransType(const char &type)
{
	this->transType = type;
}
void Return::setMonth(const int &month)
{
	this->month = month;
}
int Return::getYear() const
{
	return year;
}
void Return::setYear(const int &year)
{
	this->year = year;
}
string Return::getDirector() const
{
	return director;
}
void Return::setDirector(const string &dir)
{
	this->director = dir;
}
string Return::getTitle() const
{
	return title;
}
void Return::setTitle(const string &title)
{
	this->title = title;
}
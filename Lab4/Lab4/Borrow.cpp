//------------------------------ Borrow.cpp -----------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include "Borrow.h"

Borrow::Borrow()
{
}
Borrow::~Borrow()
{
}

// comparison operators
bool Borrow::operator==(const Transaction&) const
{
	return true;
}
bool Borrow::operator!=(const Transaction&) const
{
	return true;
}
bool Borrow::operator<(const Transaction&) const
{
	return true;
}
bool Borrow::operator>(const Transaction&) const
{
	return true;
}

// Getters n Setters
char Borrow::getCustomerID() const
{
	return customerID;
}
void Borrow::setCustomerID(const int &id)
{
	this->customerID = id;
}
char Borrow::getMediaType() const
{
	return mediaType;
}
void Borrow::setMediaType(const char &type)
{
	this->mediaType = type;
}
char Borrow::getMovieType() const
{
	return movieType;
}
void Borrow::setMovieType(const char &type)
{
	this->movieType = type;
}
int Borrow::getMonth() const
{
	return month;
}
char Borrow::getTransType() const
{
	return transType;
}
void Borrow::setTransType(const char &type)
{
	this->transType = type;
}
void Borrow::setMonth(const int &month)
{
	this->month = month;
}
int Borrow::getYear() const
{
	return year;
}
void Borrow::setYear(const int &year)
{
	this->year = year;
}
string Borrow::getDirector() const
{
	return director;
}
void Borrow::setDirector(const string &dir)
{
	this->director = dir;
}
string Borrow::getTitle() const
{
	return title;
}
void Borrow::setTitle(const string &title)
{
	this->title = title;
}

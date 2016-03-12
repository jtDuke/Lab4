#include "Drama.h"

Drama::Drama()
{

}
Drama::~Drama()
{

}

bool Drama::operator==(const Movie& mov) const 
{
	if (this->director == mov.getDirector() && this->title == mov.getTitle())
		return true;
	else
		return false;
}
bool Drama::operator!=(const Movie& mov) const 
{
	if (*this == mov)
		return false;
	else
		return true;
}
bool Drama::operator<(const Movie& mov) const 
{
	if (this->director < mov.getDirector())
		return true;
	if (this->director > mov.getDirector())
		return false;

	 if (this->title < mov.getTitle())
		return true;
	else
		return false;
}
bool Drama::operator>(const Movie& mov) const 
{
	if (this->director > mov.getDirector())
		return true;
	if (this->director <  mov.getDirector())
		return false;
	
	if (this->title > mov.getTitle())
		return true;
	else
		return false;
}

void Drama::display() const
{
	cout << this->title << " " << this->director << " " << this->year << endl;
}

void Drama::setType(const char &type)
{
	this->movieType = type;
}
char Drama::getType() const
{
	return movieType;
}
void Drama::setTitle(const string &title) 
{
	this->title = title;
}
void Drama::setDirector(const string &dir)
{
	this->director = dir;
}
void Drama::setYear(const int &year)
{
	this->year = year;
}
string Drama::getTitle() const
{
	return this->title;
}
string Drama::getDirector() const
{
	return this->director;
}
int Drama::getYear() const
{
	return this->year;
}
void Drama::setStock(const int num)
{}
int Drama::getStock() const
{
	return this->stock;
}

void Drama::setMajorActor(const string &actor)
{
	this->majorActor = "";
}
string Drama::getMajorActor() const
{
	return "";
}
int Drama::getMonth() const
{
	return month;
}
void Drama::setMonth(const int &month)
{
	this->month = month;
}
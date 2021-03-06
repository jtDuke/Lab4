#include "Classic.h"

Classic::Classic()
{
}
Classic::~Classic()
{
	
}

bool Classic::operator==(const Movie& mov) const
{
	if (this->year == mov.getYear())
	{
		if (this->month == mov.getMonth())
			if (this->majorActor == mov.getMajorActor())
				return true;
	}
	else
		return false;	
}
bool Classic::operator!=(const Movie& mov) const 
{
	if (*this == mov)
		return false;
	else
		return true;
}
bool Classic::operator<(const Movie& mov) const 
{ 
	if (this->year == mov.getYear())
	{
		if (this->month == mov.getMonth())
		{
			if (this->majorActor < mov.getMajorActor())
				return true;
			else
				return false;
		}
		else if (this->month < mov.getMonth())
			return true;
		else
			return false;
	}
	else if (this->year < mov.getYear())
		return true;
	else
		return false;
}

bool Classic::operator>(const Movie& mov) const 
{ 
	if (this->year == mov.getYear())
	{
		if (this->month == mov.getMonth())
		{
			if (this->majorActor > mov.getMajorActor())
				return true;
			else
				return false;
		}
		else if (this->month > mov.getMonth())
			return true;
		else
			return false;

	}
	else if (this->year > mov.getYear())
		return true;
	else
		return false;
}

void Classic::display() const
{
	cout << this->director << " " << this->title << " " << this->majorActor << " " << this->month << " " << this->year << endl;
}

void Classic::setType(const char &type)
{
	this->movieType = type;
}
char Classic::getType() const
{
	return movieType;
}
void Classic::setReleaseDate(const int &date)
{
	this->releaseDate = date;
}
void Classic::setMajorActor(const string &actor)
{
	this->majorActor = actor;
}
void Classic::setTitle(const string &title)
{
	this->title = title;
}
void Classic::setDirector(const string &dir)
{
	this->director = dir;
}
void Classic::setYear(const int &year)
{
	this->year = year;
}
void Classic::setStock(const int num)
{
	this->stock += num;
}
int Classic::getStock() const
{
	return this->stock;
}
string Classic::getTitle() const
{
	return this->title;
}
string Classic::getDirector() const
{
	return this->director;
}
int Classic::getYear() const
{
	return this->year;
}
string Classic::getMajorActor() const
{
	return majorActor;
}
int Classic::getReleaseDate() const
{
	return releaseDate;
}
int Classic::getMonth() const
{
	return month;
}
void Classic::setMonth(const int &month)
{
	this->month = month;
}
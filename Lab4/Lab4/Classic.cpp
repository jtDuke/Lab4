#include "Classic.h"

Classic::Classic()
{
}
Classic::~Classic()
{
	
}

bool Classic::operator==(const Movie& mov) const
{
	if (this->releaseDate == mov.getReleaseDate() && this->majorActor == mov.getMajorActor())
		return true;
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
	if (this->releaseDate < mov.getReleaseDate())
		return true;
	if (this->releaseDate > mov.getReleaseDate())
		return false;

	if (this->majorActor < mov.getMajorActor())
		return true;
	else
		return false;
}
bool Classic::operator>(const Movie& mov) const 
{ 
	if (this->releaseDate > mov.getReleaseDate())
		return true;
	if (this->releaseDate <  mov.getReleaseDate())
		return false;

	if (this->majorActor > mov.getMajorActor())
		return true;
	else
		return false;
}

void Classic::display() const
{
	cout << this->director << " " << this->title << " " << this->majorActor << this->year << endl;
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

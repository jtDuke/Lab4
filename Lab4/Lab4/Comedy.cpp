#include "Comedy.h"

Comedy::Comedy()
{

}
Comedy::~Comedy()
{

}


bool Comedy::operator==(const Movie& mov) const 
{ 
	if (this->title == mov.getTitle() && this->year == mov.getYear())
		return true;
	else
		return false;
}
bool Comedy::operator!=(const Movie& mov) const
{
	if (*this == mov)
		return false;
	else
		return true;
}	
bool Comedy::operator<(const Movie& mov) const 
{ 
	if (this->title < mov.getTitle())
		return true;
	if (this->title > mov.getTitle())
		return false;

	if (this->year < mov.getYear())
		return true;
	else
		return false;
}
bool Comedy::operator>(const Movie& mov) const 
{
	if (this->title > mov.getTitle())
		return true;
	if (this->title <  mov.getTitle())
		return false;

	if (this->year > mov.getYear())
		return true;
	else
		return false;
}

void Comedy::display() const
{
	cout << this->title << " " << this->director << " " << this->year << endl;
}

void Comedy::setTitle(const string &title)
{
	this->title = title;
}
void Comedy::setDirector(const string &dir)
{
	this->director = dir;
}
void Comedy::setYear(const int &year)
{
	this->year = year;
}
void Comedy::setStock(const int num)
{
	this->stock += num;
}
int Comedy::getStock() const
{
	return this->stock;
}
string Comedy::getTitle() const
{
	return this->title;
}
string Comedy::getDirector() const
{
	return this->director;
}
int Comedy::getYear() const
{
	return this->year;
}



void Comedy::setReleaseDate(const int &date)
{
	this->releaseDate = 0;
}
int Comedy::getReleaseDate() const
{
	return 0;
}
void Comedy::setMajorActor(const string &actor)
{
	this->majorActor = "";
}
string Comedy::getMajorActor() const
{
	return "";
}
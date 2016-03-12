#ifndef MOVIE_H
#define MOVIE_H
#include <string>
//------------------------------ Movie.h --------------------------------------
// Movie class: 
// Includes Features:
//   -- 
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Movie
{

public:
	//Constructors and Destructor
	Movie();
	//Movie(Movie&);
	virtual ~Movie();

	//Functions
	virtual void display() const = 0;

	//Comparison Operators
	virtual bool operator==(const Movie&) const = 0;
	virtual bool operator!=(const Movie&) const = 0;
	virtual bool operator<(const Movie&) const = 0;
	virtual bool operator>(const Movie&) const = 0;

	virtual void setType(const char &type) = 0;
	virtual char getType() const = 0;
	virtual void setTitle(const string &title) = 0;
	virtual string getTitle() const = 0;
	virtual void setDirector(const string &dir) = 0;
	virtual string getDirector() const = 0;
	virtual void setYear(const int &year) = 0;
	virtual int getYear() const = 0;
	virtual int getMonth() const = 0;
	virtual void setMonth(const int &month) = 0;
	virtual void setMajorActor(const string &actor) = 0;
	virtual string getMajorActor() const = 0;
	virtual void setStock(const int num) = 0;
	virtual int getStock() const = 0;

protected:
	char movieType;
	string title;
	string director;
	string majorActor;
	int month;
	int year;
	int releaseDate;
	int stock;
};
#endif
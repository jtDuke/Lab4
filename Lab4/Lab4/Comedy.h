#ifndef COMEDY_H
#define COMEDY_H
#include "Movie.h"
class Comedy : public Movie
{
public:
	Comedy();
	~Comedy();

	bool operator==(const Movie& mov) const;
	bool operator!=(const Movie& mov) const;
	bool operator<(const Movie& mov) const;
	bool operator>(const Movie& mov) const;

	void display() const;

	char getType() const;
	void setType(const char &type);
	void setTitle(const string &title);
	void setDirector(const string &dir);
	void setYear(const int &year);
	string getTitle() const;
	string getDirector() const;
	int getYear() const;
	void setStock(const int num);
	virtual int getStock() const;

	int getMonth() const;
	void setMonth(const int &month);
	void setMajorActor(const string &actor);
	string getMajorActor() const;
};
#endif

#ifndef DRAMA_H
#define DRAMA_H

#include "Movie.h"
class Drama : public Movie
{
public:
	Drama();
	~Drama();

	bool operator==(const Movie& mov) const;
	bool operator!=(const Movie& mov) const;
	bool operator<(const Movie& mov) const;
	bool operator>(const Movie& mov) const;

	void display() const;

	void setTitle(const string &title);
	void setDirector(const string &dir);
	void setYear(const int &year);
	string getTitle() const;
	string getDirector() const;
	int getYear() const;
	void setStock(const int num);
	int getStock() const;

	virtual void setReleaseDate(const int &date);
	virtual int getReleaseDate() const;
	virtual void setMajorActor(const string &actor);
	virtual string getMajorActor() const;
};
#endif
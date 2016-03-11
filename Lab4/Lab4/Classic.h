
#ifndef CLASSIC_H
#define CLASSIC_H
#include "Movie.h"
class Classic : public Movie
{
public:
	Classic();
	~Classic();

	bool operator==(const Movie& mov) const;
	bool operator!=(const Movie& mov) const;
	bool operator<(const Movie& mov) const;
	bool operator>(const Movie& mov) const;

	void display() const;

	void setTitle(const string &title);
	void setDirector(const string &dir);
	void setYear(const int &year);
	void setReleaseDate(const int &date);
	void setMajorActor(const string &actor);
	string getTitle() const;
	string getDirector() const;
	string getMajorActor() const;
	int getReleaseDate() const;
	int getYear() const;
	void setStock(const int num);
	int getStock() const;
};
#endif

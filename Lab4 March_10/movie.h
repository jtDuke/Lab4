// file movie.h
//-----------------------------------------------------------------------------------------------------
//object that can be any item that is rented from the store
//-----------------------------------------------------------------------------------------------------
// Implementation and Assumptions:
//-----------------------------------------------------------------------------------------------------
#include <string>

using namespace std;

class Movie
{

public:

	//Constructors and Destructor
	Movie();
	Movie(Movie&);
	virtual ~Movie();

	//Functions
	virtual void display() const = 0;
	virtual void setData(string) = 0;

	//Comparison Operators
	virtual bool operator<=(const Movie&) const = 0;
	virtual bool operator>=(const Movie&) const = 0;
	virtual bool operator==(const Movie&) const = 0;
	virtual bool operator!=(const Movie&) const = 0;
	virtual bool operator<(const Movie&) const = 0;
	virtual bool operator>(const Movie&) const = 0;

protected:
	string name;
	string director;
	string year;
	int stock;
	bool setStock(int);
};

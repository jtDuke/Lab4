#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "Movie.h"
#include "Comedy.h"
#include "classic.h"
#include "Drama.h"
class MovieFactory
{
public:
	MovieFactory();
	static Movie* createMovie();
	~MovieFactory();
};
#endif

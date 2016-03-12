#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "Movie.h"
#include "Comedy.h"
#include "classic.h"
#include "Drama.h"
#include "BinTree.h"
#include <fstream>
#include <sstream>

class MovieFactory
{
public:
	MovieFactory();
	static Movie* createMovie(const char movieType, string newLine);
	static char getMovieType(string newLine);
	static bool ValidateData(const char movieType, string newLine);
	static bool validateComedy(string newLine);
	static bool validateClassic(string newLine);
	static bool validateDrama(string newLine);
	static Movie* createClassic(string newLine);
	/*static Movie* createComedy(string newLine);
	static Movie* createDrama(string newLine);*/
	~MovieFactory();
};
#endif

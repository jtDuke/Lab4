#include "MovieFactory.h"



MovieFactory::MovieFactory()
{
}

Movie* MovieFactory::createMovie()
{
	Movie *yo = new Comedy;
	return yo;
}

MovieFactory::~MovieFactory()
{
}

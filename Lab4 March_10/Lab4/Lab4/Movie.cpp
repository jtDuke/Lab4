#include "Movie.h"

Movie::Movie() : name(""), director(""), year(""), stock(0)
{
}

Movie::Movie(Movie& copyProduct)
{
	this->name = copyProduct.name;
	this->director = copyProduct.director;
	this->year = copyProduct.year;
	setStock(copyProduct.stock);
}

Movie::~Movie()
{
}

bool Movie::setStock(int stock)
{
	if (stock >= 0)
	{
		this->stock = stock;
		return true;
	}
	return false;
}
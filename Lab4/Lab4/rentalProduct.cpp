#include "rentalProduct.h"


rentalProduct::rentalProduct() : storeProduct()
{
}

rentalProduct::rentalProduct(rentalProduct& copyProduct)
{
	this->name = copyProduct.name;
	setStock(copyProduct.stock);
}

rentalProduct::~rentalProduct()
{
}

bool rentalProduct::setStock(int stock)
{
	if (stock >= 0)
	{
		this->stock = stock;
		return true;
	}
	return false;
}
#include "storeProduct.h"


storeProduct::storeProduct()
{
	this->name = "";
	setStock(0);
}

storeProduct::storeProduct(storeProduct& copyProduct)
{
	this->name = copyProduct.name;
	setStock(copyProduct.stock);
}

storeProduct::~storeProduct()
{
}

bool storeProduct::setStock(int stock)
{
	if(stock >= 0)
	{
		this->stock = stock;
		return true;
	}
	return false;
}
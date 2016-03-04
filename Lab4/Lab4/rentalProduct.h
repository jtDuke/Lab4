// file rentalProduct.h
//-----------------------------------------------------------------------------------------------------
//object that can be any item that is rented from the store
//-----------------------------------------------------------------------------------------------------
// Implementation and Assumptions:
//-----------------------------------------------------------------------------------------------------
#include "storeProduct.h"

using namespace std;

class rentalProduct: public storeProduct
{

public:

	//Constructors and Destructor
	rentalProduct();
	rentalProduct(rentalProduct&);
	virtual ~rentalProduct();

	//Functions
	virtual void display() const = 0;
	virtual void setData(string) = 0;

	//Comparison Operators
	virtual bool operator<=(const rentalProduct&) const = 0;
	virtual bool operator>=(const rentalProduct&) const = 0;
	virtual bool operator==(const rentalProduct&) const = 0;
	virtual bool operator!=(const rentalProduct&) const = 0;
	virtual bool operator<(const rentalProduct&) const = 0;
	virtual bool operator>(const rentalProduct&) const = 0;

private:
	bool setStock(int);

protected:
	string name;
	int stock;
};

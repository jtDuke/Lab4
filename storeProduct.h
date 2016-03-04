// file StoreProduct.h
//-----------------------------------------------------------------------------------------------------
//object that can be any item that is sold or rented from the store
//-----------------------------------------------------------------------------------------------------
// Implementation and Assumptions:
//-----------------------------------------------------------------------------------------------------
#include <string>

using namespace std;

class storeProduct
{

public:

	//Constructors and Destructor
	storeProduct();
	storeProduct(storeProduct&);
	virtual ~storeProduct();

	//Functions
	virtual void display() const = 0;
	virtual void setData(string) = 0;

	//Comparison Operators
	virtual bool operator<=(const storeProduct&) const = 0;
	virtual bool operator>=(const storeProduct&) const = 0;
	virtual bool operator==(const storeProduct&) const = 0;
	virtual bool operator!=(const storeProduct&) const = 0;
	virtual bool operator<(const storeProduct&) const = 0;
	virtual bool operator>(const storeProduct&) const = 0;

private:
	bool setStock(int);

protected:
	string name;
	int stock;
};

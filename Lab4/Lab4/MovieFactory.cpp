//------------------------------ MovieFactory.h -------------------------------
// Account class: 
// Includes Features:
//   -- Facilitates creation of user accounts
//
// Implementation and Assumptions:
//   --
//-----------------------------------------------------------------------------

#include "MovieFactory.h"



MovieFactory::MovieFactory()
{
}

// -------------------------- getMovieType ------------------------------------
// 
// 
// ----------------------------------------------------------------------------
char MovieFactory::getMovieType(string newLine)
{
	return newLine[0];
}

// -------------------------- ValidateData ------------------------------------
// 
// 
// ----------------------------------------------------------------------------
bool MovieFactory::ValidateData(const char movieType, string newLine)
{
	if (movieType == 'F')
	{
		return validateComedy(newLine);
	}
	else if (movieType == 'D')
	{
		return validateDrama(newLine);
	}
	else if (movieType == 'C')
	{
		return validateClassic(newLine);
	}
	else
		return false;
}

// -------------------------- createComedy ------------------------------------
// 
// 
// ----------------------------------------------------------------------------
Movie* MovieFactory::createComedy(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	char c;					// movieType
	int stock = 0;			// stock value
	int year = 0;			// release Year

	Movie *newMov = new Comedy;

	getline(text, s, ',');			// get first element of newLine
	c = s[0];
	newMov->setType(c);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	newMov->setStock(stock);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// Director first name
	newMov->setDirector(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	newMov->setTitle(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	newMov->setYear(year);

	return newMov;
}

// -------------------------- createDrama -------------------------------------
//
//
// ----------------------------------------------------------------------------
Movie* MovieFactory::createDrama(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	char c;					// movieType
	int stock = 0;			// stock value
	int year = 0;			// release Year

	Movie *newMov = new Drama;

	getline(text, s, ',');			// get first element of newLine
	c = s[0];
	newMov->setType(c);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	newMov->setStock(stock);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// Director first name
	newMov->setDirector(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	newMov->setTitle(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	newMov->setYear(year);

	return newMov;
}

// -------------------------- createClassic -----------------------------------
//
//
// ----------------------------------------------------------------------------
Movie* MovieFactory::createClassic(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	char c;					// movieType
	int stock = 0;			// stock value
	int year = 0;			// release Year
	int month = 0;			// release month
	string actorFirst;
	string actorLast;

	Movie *newMov = new Classic;

	getline(text, s, ',');			// get first element of newLine
	c = s[0];
	newMov->setType(c);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	newMov->setStock(stock);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// Director first name
	newMov->setDirector(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	newMov->setTitle(s);

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// Actor first name
	actorFirst = s;
	getline(text, s, ' ');			// Actor first name
	actorLast = s;
	newMov->setMajorActor(actorFirst + " " + actorLast);

	getline(text, s, ' ');			// release month		
	istringstream(s) >> month;
	newMov->setMonth(month);

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	newMov->setYear(year);

	return newMov;
}

// -------------------------- validateClassic ---------------------------------
//
//
// ----------------------------------------------------------------------------
bool MovieFactory::validateClassic(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	int stock = 0;			// stock value
	int year = 0;			// release Year
	int month = 0;			// release month

	getline(text, s, ',');			// get first element of newLine

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	if (stock < 0)					// stock error-checking
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// Director first name
	if (s == "")					// making sure it's not blank
		return false;

	getline(text, s, ',');			// Director last name
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// Actor first name
	if (s == "")					// making sure it's not blank
		return false;

	getline(text, s, ' ');			// Actor last name
	if (s == "")					// making sure it's not blank
		return false;

	getline(text, s, ' ');			// release month		
	istringstream(s) >> month;
	if (month < 0 || month > 12)	// month error-checking
		return false;

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	if (year <= 0 && year >= 2016)	// year error-checking
		return false;

	return true;
}

// -------------------------- validateComedy ----------------------------------
//
//
// ----------------------------------------------------------------------------
 bool MovieFactory::validateComedy(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	int stock = 0;			// stock value
	int year = 0;			// release Year
	int month = 0;			// release month

	getline(text, s, ',');			// get first element of newLine

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	if (stock < 0)					// stock error-checking
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// Director first name
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	if (year <= 0 && year >= 2016)	// year error-checking
		return false;

	return true;
}

 // -------------------------- validateDrama -----------------------------------
 //
 //
 // ----------------------------------------------------------------------------
bool MovieFactory::validateDrama(string newLine)
{
	istringstream text(newLine);		// allows splitting of a string

	string s;				// placeholder
	int stock = 0;			// stock value
	int year = 0;			// release Year
	int month = 0;			// release month

	getline(text, s, ',');			// get first element of newLine

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get amount of stock		
	istringstream(s) >> stock;
	if (stock < 0)					// stock error-checking
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// Director first name
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ',');			// get movie title
	if (s == "")					// making sure it's not blank
		return false;

	if (text.peek() == ' ') text.ignore();   //ignore a blank space

	getline(text, s, ' ');			// release year
	istringstream(s) >> year;
	if (year <= 0 && year >= 2016)	// year error-checking
		return false;

	return true;
}

MovieFactory::~MovieFactory()
{
}




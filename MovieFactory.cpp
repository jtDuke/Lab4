#include "MovieFactory.h"



MovieFactory::MovieFactory()
{
}

Movie* MovieFactory::createMovie(const char movieType, string newLine)
{	
	if (movieType == 'C')
	{
		Movie *tempMov = createClassic(newLine);
		return tempMov;
	}
}

//Movie* MovieFactory::createComedy(string newLine)
//{
//
//}
//Movie* MovieFactory::createDrama(string newLine)
//{
//
//}

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

char MovieFactory::getMovieType(string newLine)
{
	return newLine[0];
}

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

 bool MovieFactory::validateComedy(string newLine)
{
	//istringstream text(newLine);		// allows splitting of a string
	//string s;
	//char c;
	//int id;
	//
	//getline(text, s, ' ');
	//
	///*if (text.peek() == ',')
	//	text.ignore();*/
	//getline(text, s, ' ');		// userID		
	//istringstream(s) >> id;
	//if (id < 0 || id > 9999)		// Check valid range for ID (still need to check if the ID already exists)
	//	return false;				// If here, it's an invalid ID 		

	//getline(text, s, ' ');		// first name
	//if (s == "")					// making sure it's not blank
	//	return false;				// If here, it's an invalid name 

	//getline(text, s, ' ');		// last name
	//if (s == "")					// making sure it's not blank
	//	return false;				// If here, it's an invalid name

	return false;
}

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

bool MovieFactory::validateDrama(string newLine)
{
	return false;
}

MovieFactory::~MovieFactory()
{
}




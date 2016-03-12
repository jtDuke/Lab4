#include "Store.h"



Store::Store() {}
Store::Store(string name, int id)
{
	this->name = name;
	this->storeID = id;

	ifstream accountFile("data4users.txt");
	ifstream movieFile("data4movies.txt");
	ifstream transactionFile("data4commands.txt");
	if (!accountFile || !movieFile || !transactionFile)
	{
		cout << "File could not be opened." << endl;
		return;
	}

	processFileStreams(accountFile, 0);		 //start the add useAccount process
	processFileStreams(movieFile, 1);			 //addFile(productFile, 1);
	processFileStreams(transactionFile, 2);     //addFile(transactionFile, 2);
}

void Store::processFileStreams(ifstream& file, int fileType)
{
		if (fileType == 0) //adduser
		{
			addAccount(file);
		}
		else if (fileType == 1)  //addMovie
		{
			addMovie(file);
		} 
		else if (fileType == 2)
		{
			executeTransactions(file); // addTransactions
		} 
}

void Store::addAccount(ifstream& file)
{
	while (!file.eof())				// check for end of file
	{
		Account tempAcct;
		string newLine;				// placeholder for line of input
		getline(file, newLine);		// get line of input from Accounts file

		if (newLine == "")  // (backup eof check) If true, we're at the end of file
			break;			// exit loop //clear memory for account

		if (!tempAcct.validateData(newLine))		// calling function to validate the line of data
		{
			cout << "INVALID ACCOUNT" << endl;
			continue; 
		}

		Account *newAccount = tempAcct.createAccount(newLine);
		accountTable.insert(newAccount);
		accountTable.display(newAccount->getID()); //adds accounts to hashTable


		// !!!!!----- TESTING PURPOSES , DON'T DELETE ---------!!!!!!! //
		//userAccounts[newAccount->getID()] = newAccount;
		//cout << "ACCOUNT ID: " << newAccount->getID() << endl;
		//cout << "HASHED TO: " << accountTable.[newAccount->getID()] << endl;
	}
}

void Store::addMovie(ifstream& file)
{
	while (!file.eof())				// check for end of file
	{
		string newLine;				// placeholder for line of input
		getline(file, newLine);		// get line of input from Accounts file

		if (newLine == "")			// (backup eof check) If true, we're at the end of file
			break;					// exit loop //clear memory for account

		char movieType = MovieFactory::getMovieType(newLine);  //retrieves & stores movieType

		// error checks the current line of text representing a movie
		if (!MovieFactory::ValidateData(movieType, newLine))	
		{
			cout << "INVALID ACCOUNT: Entry denied" << endl;
			continue;
		}		

		if (movieType == 'C')		// create a Classic movie & insert into Tree
		{
			Movie *newMov = MovieFactory::createClassic(newLine);
			classTree.insert(newMov);
		}
		else if (movieType == 'F')	// create a Comedy movie & insert into Tree
		{
			Movie *newMov = MovieFactory::createComedy(newLine);
			funTree.insert(newMov);
		}
		else if (movieType == 'D')  // create a Drama movie & insert into Tree
		{
			Movie *newMov = MovieFactory::createDrama(newLine);
			dramaTree.insert(newMov);
		}
	}

}

void Store::executeTransactions(ifstream& file)
{

	while (!file.eof())				// check for end of file
	{
		string newLine;				// placeholder for line of input
		getline(file, newLine);		// get line of input from Accounts file

		if (newLine == "")			// (backup eof check) If true, we're at the end of file
			break;					// exit loop //clear memory for account

		char transType = TransFactory::getTransType(newLine);  //retrieves & stores movieType
															   
		// code below error checks the current line of text representing a movie
		// TODO - Uncomment these next few lines if you want to try to implement transaction factory methods
		/*	if (!TransFactory::ValidateData(transType, newLine))
		{
			cout << "INVALID ACCOUNT: Entry denied" << endl;
			continue;
		}*/

		if (transType == 'I')		// displays entire inventory of Movie's
		{
			cout << "--- Classic Movie Collection ---" << endl;
			classTree.DisplayInOrder(); 
			cout << endl;
			cout << "--- Comedy Movie Collection ---" << endl;
			funTree.DisplayInOrder();	
			cout << endl;
			cout << "--- Drama Movie Collection ---" << endl;
			dramaTree.DisplayInOrder();	
			cout << endl;
		}		

		// TODO - LL or Queue is not yet implementation so we can store Transactions
		//else if (transType == 'B')	// create a borrow transaction
		//{
		//	Transaction *newTrans = TransFactory::createBorrow(newLine);
		//	// INSERT INTO CUSTOMER LIST OR QUEUE
		//}
		//else if (transType == 'R')  // creates a Return transaction
		//{
		//	Transaction *newTrans = TransFactory::createReturn(newLine);
		//	// INSERT INTO CUSTOMER LIST OR QUEUE
		//}
		//else if (transType == 'H')  // displays the history of a customer's transactions
		//{
		//	//DISPLAY HISTORY
		//}
	}

}

Store::~Store()
{

}
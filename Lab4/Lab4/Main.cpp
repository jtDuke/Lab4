using namespace std;
#include "Store.h"

int main()
{
	string movies = "data4movies.txt";
	string users = "data4users.txt";
	string commands = "data4commands.txt";


	Store s1("Odegaard the Phenom", 11, movies, users, commands);
	system("Pause");
	return 0;
}
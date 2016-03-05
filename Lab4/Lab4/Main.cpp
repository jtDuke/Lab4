using namespace std;
#include "Store.h"

int main()
{
	string users = "data4users.txt";
	string movies = "data4movies.txt";
	string commands = "data4commands.txt";


	Store s1("Odegaard the Phenom", 11, users, movies, commands);
	system("Pause");
	return 0;
}
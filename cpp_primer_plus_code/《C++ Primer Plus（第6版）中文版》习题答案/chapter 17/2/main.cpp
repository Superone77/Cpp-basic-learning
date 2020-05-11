#include <iostream>
#include <fstream>

using namespace std;

int
main (int argc, char* argv[])
{
	if (argc != 2) {
		cerr << "格式：command file_name" << endl;
		return (EXIT_FAILURE);
	}

	ofstream	file_out(argv[1]);
	string	line;
	while (getline(cin, line)) {
		file_out << line << endl;
	}


	return (EXIT_SUCCESS);
}

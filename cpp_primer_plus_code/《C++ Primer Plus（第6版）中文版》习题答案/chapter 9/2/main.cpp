#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string	input;
	unsigned	total = 0;
	cout << "Enter a line:\n";
	getline(cin, input);
	while (cin && "" != input)
	{
		cout << "\"" << input <<"\" contains ";
		cout << input.size() << " characters\n";
		total += input.size();
		cout << total << " characters total\n";

		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input);
	}
	cout << "Bye\n";
	return 0;
}

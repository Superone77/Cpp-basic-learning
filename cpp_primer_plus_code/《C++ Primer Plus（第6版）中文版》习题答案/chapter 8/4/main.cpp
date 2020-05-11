#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char * str;
	int ct;
};

void
set (stringy& stry, const char* szTxt)
{
	stry.ct = (int)strlen(szTxt);
	stry.str = new char [stry.ct + 1];
	strcpy(stry.str, szTxt);
}

void
show (const char* szTxt, unsigned times = 1)
{
	for (unsigned i = 0; i < times; ++i) {
		cout << szTxt << endl;
	}
}

void
show (const stringy& stry, unsigned times = 1)
{
	for (unsigned i = 0; i < times; ++i) {
		cout << stry.str << endl;
	}
}

void
destroy (stringy& stry)
{
	delete [] stry.str;
	stry.str = NULL;
}

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);

	show(beany);
	show(beany, 2);
	destroy(beany);

	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");

	return 0;
	// prints member string once
	// prints member string twice
	// prints testing string once
	// prints testing string thrice
}

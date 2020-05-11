#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
	static const unsigned LIMIT = 25;
	string lname;
	// Person’s last name
	char fname[LIMIT]; // Person’s first name
public:
	Person() {lname = ""; fname[0] = '\0'; } // #1
	Person(const string & ln, const char * fn = "Heyyou");
	// the following methods display lname and fname
	void Show() const; // firstname lastname format
	void FormalShow() const; // lastname, firstname format
};

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void
Person::Show() const
{
	cout << fname << ' ' << lname;
}

void
Person::FormalShow() const
{
	cout << lname << ", " << fname;
}

int
main (void) 
{     
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	three.Show();
	cout << endl;
	three.FormalShow();

	cout << endl;
	return (0);
} 

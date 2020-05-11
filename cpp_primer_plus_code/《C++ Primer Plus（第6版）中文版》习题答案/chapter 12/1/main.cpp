#include <iostream>
#include <cstring>

using namespace std;

class Cow
{
	public:
		//Cow();
		explicit Cow(const char * nm = "", const char * ho = "", double wt = 0);
		Cow(const Cow & c);
		~Cow();
		Cow & operator=(const Cow & c);
		void ShowCow() const; // display all cow data

	private:
		char	name[20];
		char*	hobby;
		double	weight;
};

Cow::Cow (const char * nm, const char * ho, double wt)
	: weight(wt)
{
	unsigned	str_len = strlen(nm) < 20-1 ? strlen(nm) : 20-1;
	strncpy(name, nm, str_len);
	name[str_len] = '\0';

	hobby = new char [strlen(ho)+1];
	strcpy(hobby, ho);
}

Cow::Cow (const Cow& c)
	: weight(c.weight)
{
	strcpy(name, c.name);

	hobby = new char [strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);
}

Cow::~Cow ()
{
	delete [] hobby;
}

void
Cow::ShowCow () const
{
	cout << name << '\t' << hobby << '\t' << weight;
}

Cow&
Cow::operator= (const Cow & c)
{
	if (&c == this) {
		return (*this);
	}

	strcpy(name, c.name);

	delete [] hobby;
	hobby = new char [strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);

	weight = c.weight;

	return (*this);
}

int
main (void) 
{     
	Cow	cow1("cow1", "eat", 405.5);
	cout << "cow1: ";
	cow1.ShowCow();
	cout << endl;

	Cow cow2;
	cout << "cow2: ";
	cow2.ShowCow();
	cout << endl;

	Cow cow3(cow1);
	cout << "cow3: ";
	cow3.ShowCow();
	cout << endl;

	Cow cow4;
	cow4 = cow1;
	cout << "cow4: ";
	cow4.ShowCow();
	cout << endl;


	cout << endl;
	return (0);
} 

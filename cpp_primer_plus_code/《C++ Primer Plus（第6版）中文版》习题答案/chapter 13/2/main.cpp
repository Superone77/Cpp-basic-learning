#include <iostream>
#include <cstring>

using namespace std;

// base class
class Cd
{
	private:
		char* performers;
		char* label;
		int selections; // number of selections
		double playtime; // playing time in minutes

	public:
		explicit Cd(const char * s1 = "", const char * s2 = "", int n = 0, double x = 0.0);
		Cd(const Cd & d);
		virtual ~Cd(); 
		virtual void Report() const; // reports all CD data
		Cd & operator=(const Cd & d);
};

static char*
cpNewStr (const char* p_src_txt)
{
	unsigned	str_len = strlen(p_src_txt);
	char*	p_des_txt = new char [str_len + 1];
	strcpy(p_des_txt, p_src_txt);

	return (p_des_txt);
}

Cd::Cd (const char * s1, const char * s2, int n, double x)
	: selections(n), playtime(x)
{
	performers = cpNewStr(s1);
	label = cpNewStr(s2);
}

Cd::~Cd ()
{
	delete [] performers;
	delete [] label;
}

Cd::Cd(const Cd & d)
	: selections(d.selections), playtime(d.playtime)
{
	performers = cpNewStr(d.performers);
	label = cpNewStr(d.label);
}

Cd & 
Cd::operator=(const Cd & d)
{
	if (&d == this) {
		return (*this);
	}

	delete [] performers;
	performers = cpNewStr(d.performers);

	delete [] label;
	label = cpNewStr(d.label);

	selections = d.selections;

	playtime = d.playtime;

	return (*this);
}

void
Cd::Report() const
{
	cout << performers << ", " << label << ", " << selections << ", " << playtime << flush;
}


// derive
class Classic : public Cd
{
	private:
		char*	songs;

	public:
		explicit Classic (const char* songs_list = "", const char * s1 = "", const char * s2 = "", int n = 0, double x = 0.0);
		Classic (const Classic& classic);
		virtual ~Classic ();
		Classic& operator= (const Classic& classic);
		virtual void Report() const; // reports all CD data
};

Classic::Classic (const char* songs_list, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	songs = cpNewStr(songs_list);
}

Classic::Classic (const Classic& classic)
	: Cd(classic)
{
	songs = cpNewStr(classic.songs);
}

Classic::~Classic ()
{
	delete [] songs;
}

Classic&
Classic::operator= (const Classic& classic)
{
	if (&classic == this) {
		return (*this);
	}

	Cd::operator=(classic);

	delete [] songs;
	songs = cpNewStr(classic.songs);

	return (*this);
}

void
Classic::Report () const
{
	Cd::Report();
	cout << ", " << songs << endl;
}

void
Bravo(const Cd & disk)
{
	disk.Report();
}

int
main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report(); // use Cd method
	cout << endl;
	c2.Report(); // use Classic method
	cout << endl;
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); // use Cd method for cd object
	cout << endl;
	pcd = &c2;
	pcd->Report(); // use Classic method for classic object
	cout << endl;
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	cout << endl;
	Bravo(c2);
	cout << endl;
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	cout << endl;

	return 0;
}

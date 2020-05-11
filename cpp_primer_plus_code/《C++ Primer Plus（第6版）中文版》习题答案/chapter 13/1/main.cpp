#include <iostream>
#include <cstring>

using namespace std;

// base class
class Cd
{
	private:
		char performers[50];
		char label[20];
		int selections; // number of selections
		double playtime; // playing time in minutes

	public:
		explicit Cd(const char * s1 = "", const char * s2 = "", int n = 0, double x = 0.0);
		virtual ~Cd() {}
		virtual void Report() const; // reports all CD data
		//Cd & operator=(const Cd & d);
		//Cd(const Cd & d);
};

static void
cpStr (char* p_des_txt, const char* p_src_txt, unsigned des_arr_size)
{
	unsigned	str_len = strlen(p_src_txt) < des_arr_size-1 ? strlen(p_src_txt) : des_arr_size-1;
	strncpy(p_des_txt, p_src_txt, str_len);
	p_des_txt[str_len] = '\0';
}

Cd::Cd (const char * s1, const char * s2, int n, double x)
	: selections(n), playtime(x)
{
	cpStr(performers, s1, 50);
	cpStr(label, s2, 20);
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
		static const unsigned	mk_size = 64;

	private:
		char	m_songs[mk_size];

	public:
		Classic (const char* songs_list = "", const char * s1 = "", const char * s2 = "", int n = 0, double x = 0.0);
		virtual void Report() const; // reports all CD data
};

Classic::Classic (const char* songs_list, const char * s1, const char * s2, int n, double x)
	: Cd(s1, s2, n, x)
{
	cpStr(m_songs, songs_list, mk_size);
}

void
Classic::Report () const
{
	Cd::Report();
	cout << ", " << m_songs << endl;
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

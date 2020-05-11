#include <iostream>
#include <limits>
#include <string>

using namespace std;

// ========================================
class abstr_emp
{
	private:
		std::string fname;	// abstr_emp's first name
		std::string lname;	// abstr_emp's last name
		std::string job;
		
	public:
		//abstr_emp();
		explicit abstr_emp(const std::string & fn = "", const std::string & ln = "", const std::string & j = "");
		virtual void ShowAll() const;	// labels and shows all data
		virtual void SetAll();		// prompts user for values
		friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);	// just displays first and last name
		virtual ~abstr_emp() = 0;	// virtual base class
};

abstr_emp::abstr_emp (const std::string & fn, const std::string & ln, const std::string & j)
	: fname(fn), lname(ln), job(j)
{
	;
}

abstr_emp::~abstr_emp ()
{
	;
}

void
abstr_emp::ShowAll () const
{
	cout	<< "name: " << fname << ' ' << lname << '\n'
			<< "job: " << job << endl;
}

void
abstr_emp::SetAll ()
{
	cout << "enter first name: ";
	cin >> fname;
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

	cout << "enter second name: ";
	cin >> lname;
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

	cout << "enter job: ";
	cin >> job;
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容
}
	
std::ostream &
operator<< (std::ostream & os, const abstr_emp & e)
{
	e.ShowAll();
	return (os);
}


// ========================================
class employee : public abstr_emp
{
	public:
		//employee();
		explicit employee(const std::string & fn = "", const std::string & ln = "", const std::string & j = "");
		virtual void ShowAll() const;
		virtual void SetAll();
};

employee::employee (const std::string & fn, const std::string & ln, const std::string & j)
	: abstr_emp(fn, ln, j)
{
	;
}

void
employee::ShowAll () const
{
	abstr_emp::ShowAll();
}

void
employee::SetAll ()
{
	abstr_emp::SetAll();
}
	
// ========================================
class manager: virtual public abstr_emp
{
	private:
		int inchargeof;	// number of abstr_emps managed

	protected:
		int InChargeOf() const { return inchargeof; } // output
		int & InChargeOf(){ return inchargeof; }	// input

	public:
		//manager();
		explicit manager(const std::string & fn = "", const std::string & ln = "", const std::string & j = "", int ico = 0);
		manager(const abstr_emp & e, int ico);
		//manager(const manager & m);
		virtual void ShowAll() const;
		virtual void SetAll();
};

manager::manager (const std::string & fn, const std::string & ln, const std::string & j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{
	;
}

manager::manager (const abstr_emp & e, int ico)
	: abstr_emp(e), inchargeof(ico)
{
	;
}

void
manager::ShowAll () const
{
	abstr_emp::ShowAll();
	cout << "incharge of " << inchargeof << " employees" << endl;
}

void
manager::SetAll ()
{
	abstr_emp::SetAll();

	cout << "enter the number of managed: ";
	cin >> inchargeof;
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容
}

// ========================================
class fink: virtual public abstr_emp
{
	private:
		std::string reportsto;	// to whom fink reports
	protected:
		const std::string ReportsTo() const { return reportsto; }
		std::string & ReportsTo(){ return reportsto; }
	public:
		//fink();
		fink(const std::string & fn = "", const std::string & ln = "", const std::string & j = "", const std::string & rpo = "");
		fink(const abstr_emp & e, const std::string & rpo);
		//fink(const fink & e);
		virtual void ShowAll() const;
		virtual void SetAll();
};

fink::fink (const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo)
{
	;
}

fink::fink (const abstr_emp & e, const std::string & rpo)
	: abstr_emp(e), reportsto(rpo)
{
	;
}

void
fink::ShowAll () const
{
	abstr_emp::ShowAll();
	cout << "report to " << reportsto << endl;
}

void
fink::SetAll ()
{
	abstr_emp::SetAll();

	cout << "enter to whom fink reports: ";
	cin >> reportsto;
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容
}

// ========================================
class highfink: public manager, public fink // management fink
{
	public:
		//highfink();
		explicit highfink(const std::string & fn = "", const std::string & ln = "", const std::string & j = "", const std::string & rpo = "", int ico = 0);
		//highfink(const abstr_emp & e, const std::string & rpo, int ico);
		highfink(const fink & f, int ico);
		highfink(const manager & m, const std::string & rpo);
		//highfink(const highfink & h);
		virtual void ShowAll() const;
		virtual void SetAll();
};

highfink::highfink (const std::string & fn, const std::string & ln, const std::string & j, const std::string & rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
	;
}

highfink::highfink(const fink & f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f)
{
	;
}

highfink::highfink (const manager & m, const std::string & rpo)
	: abstr_emp(m), manager(m), fink(m, rpo)
{
	;
}

void
highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "report to " << ReportsTo() << endl;
}

void
highfink::SetAll()
{
	manager::SetAll();

	cout << "enter to whom fink reports: ";
	cin >> ReportsTo();
	cin.clear();	// 清空输入缓冲区错误标志位
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容
}

// ========================================
int main(void)
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	//em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	//ma.ShowAll();
	
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	//fi.ShowAll();

	highfink hf(ma, "Curly Kew"); // recruitment?
	cout << hf << endl;
	//hf.ShowAll();
	cout << endl;
	
	cout << "Press a key for next phase:\n";
	cin.get();
	highfink hf2;
	hf2.SetAll();
	cout << endl;

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
	
	return 0;
}

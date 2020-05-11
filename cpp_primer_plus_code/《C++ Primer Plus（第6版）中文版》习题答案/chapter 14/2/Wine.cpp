#include "Wine.h"


namespace n_wine
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::cerr;

	// ====================================
	// 公有成员函数
	// ====================================

	Wine::Wine (const string& name, unsigned years_total, unsigned vintage_years[], unsigned bottles_total[])
		:	string(name),
			pair<UnsignedArray, UnsignedArray>(UnsignedArray(vintage_years, years_total), UnsignedArray(bottles_total, years_total)),
			years_total_(years_total) 
	{
		;
	}
	
	Wine::Wine (const string& name, unsigned years_total)
		:	string(name),
			pair<UnsignedArray, UnsignedArray>(UnsignedArray(years_total), UnsignedArray(years_total)),
			years_total_(years_total) 
	{
		;
	}

	const string&
	Wine::getLabel (void) const
	{
		return ((const string&)*this);
	}

	void
	Wine::getBottles (void)
	{
		cout << "Enter "<< getLabel() << " data for " << years_total_ << " year(s) ---- \n";

		auto&	vintage_year_and_bottles_total = (pair<UnsignedArray, UnsignedArray>&)*this;
		for (unsigned i = 0; i < years_total_; ++i) {
			unsigned	vintage_year;
			cout << "Enter year: ";
			cin >> vintage_year;
			if (!cin) {
				cerr << "ERREOR! " << __FILE__ << ", " << __LINE__ << endl;
				exit(EXIT_FAILURE);
			}
			vintage_year_and_bottles_total.first[i] = vintage_year;

			unsigned	bottles_total;
			cout << "Enter bottles for that year: ";
			cin >> bottles_total;
			if (!cin) {
				cerr << "ERREOR! " << __FILE__ << ", " << __LINE__ << endl;
				exit(EXIT_FAILURE);
			}
			vintage_year_and_bottles_total.second[i] = bottles_total;
		}
	}

	void
	Wine::show (void) const
	{
		cout << "Wine: " << getLabel() << '\n';

		cout << '\t' << "Year" << '\t' << "Bottles" << '\n';
		const auto&	vintage_year_and_bottles_total = (pair<UnsignedArray, UnsignedArray>)*this;
		for (unsigned i = 0; i < years_total_; ++i) {
			cout << '\t' << vintage_year_and_bottles_total.first[i] << '\t' << vintage_year_and_bottles_total.second[i] << endl;
		}
	}

	unsigned
	Wine::sum (void) const
	{
		const auto&	vintage_year_and_bottles_total = (pair<UnsignedArray, UnsignedArray>)*this;
		return (vintage_year_and_bottles_total.second.sum());
	}
}

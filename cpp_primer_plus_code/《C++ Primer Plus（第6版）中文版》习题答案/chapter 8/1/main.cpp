#include <iostream>

using namespace std;

unsigned	k_times = 0;
void
print_times (const char* szTmp, int flag = 0)
{
	++k_times;
	unsigned	uPrintfTimes = (0 == flag) ? 1 : k_times;
	cout << ">>>>" << endl;
	for (unsigned i = 0; i < uPrintfTimes; ++i) {
		cout << szTmp << endl;
	}
	cout << "<<<<" << endl;
	cout << "-----------------" << endl;
}

int
main (void) 
{     
	const char*	szTxt = "hi, yangyang.gnu";
	print_times(szTxt, 8);
	print_times(szTxt);
	print_times(szTxt, -1);
	print_times(szTxt);
	print_times(szTxt, 256);

	cout << endl;
	return (0);
} 

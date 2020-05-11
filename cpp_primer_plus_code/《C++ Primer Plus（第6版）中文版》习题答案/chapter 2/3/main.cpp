#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void
print_mice (void)
{
	cout << "Three blind mice" << endl;
}

void
print_how (void)
{
	cout << "See how they run" << endl;
}

int
main (void) 
{     

	print_mice();
	print_mice();
	print_how();
	print_how();
	
	cout << endl;
	return (0);
} 

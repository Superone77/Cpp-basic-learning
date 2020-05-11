#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	const unsigned	k_nameMaxLen = 64;

	char	szFirstname[k_nameMaxLen];
	cout << "Enter your first name: ";
	cin.getline(szFirstname, k_nameMaxLen);

	char	szLastname[k_nameMaxLen];
	cout << "Enter your last name: ";
	cin.getline(szLastname, k_nameMaxLen);

	char* const	psz = new char [strlen(szFirstname) + strlen(szLastname) + 1];
	strcpy(psz, szLastname);
	strcat(psz, ", ");
	strcat(psz, szFirstname);
	cout << "Here’s the information in a single string: " << psz;
	delete [] psz;

	
	cout << endl;
	return (0);
} 

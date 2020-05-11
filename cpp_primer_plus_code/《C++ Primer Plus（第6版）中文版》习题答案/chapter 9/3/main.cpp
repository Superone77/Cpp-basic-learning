#include <iostream>
#include <cstring>

using namespace std;

struct TChaff
{
	char	szDross[20];
	int		slag;
};

char	g_buffer[1024];

int
main (void) 
{     
	TChaff*	pChaff = new (g_buffer) TChaff [2];

	strcpy(pChaff[0].szDross, "foo");
	pChaff[0].slag = 2;

	strcpy(pChaff[1].szDross, "bar");
	pChaff[1].slag = 8;

	for (unsigned i = 0; i < 2; ++i) {
		cout << pChaff[i].szDross << '\t' << pChaff[i].slag << endl;
	}


	cout << endl;
	return (0);
} 

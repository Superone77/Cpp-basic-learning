#include<iostream>
#include<stdio.h>

using namespace std;

unsigned int funny = 0;


void fuck(const char* sb, int x=1);

void fuck(const char* sb, int x)
{
	funny++;
	if (x != 0)
	{
		for (int i = 0; i < funny; i++)
		{
			cout << sb << endl;
		}
	}
	else
		cout << "None!" << endl;

	
}

int main(void)
{
	const char* sdiao = "Hello World!";
	fuck(sdiao);
    fuck(sdiao, 7);
	fuck(sdiao, -1);

	cout << endl;
	system("pause");
	return 0;

}
#include<iostream>
#include<stdio.h>
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void build_box(box fuck);
void V_box(box* pfuck);

using namespace std;

int main()
{
	box fuck = { "FUCKBOX",8,12,10 };

	build_box(fuck);

	V_box(&fuck);

	cout << endl;
	cout << "Volume of the box is " << fuck.volume << endl;

	system("pause");
	return 0;
}

void build_box(box fuck)
{
	cout << fuck.maker << " have the factors: " << endl;
	cout << fuck.height << ", " << fuck.width << ", " << fuck.length << endl;
	
}
void V_box(box* pfuck)
{
	pfuck->volume = pfuck->height*pfuck->length*pfuck->width;
}
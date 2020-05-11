#include <iostream>

using namespace std;

struct TBox
{
	char	szMaker[40];
	float	height;
	float	width;
	float	length;
	float	volume;
};

void
display_box (TBox box) {
	cout << box.szMaker << '\t' << box.height << '\t' << box.width << '\t' << box.length;
}

float
calc_box_volume (TBox* pBox)
{
	return (pBox->volume = pBox->height * pBox->width * pBox->length);
}

int
main (void) 
{     
	TBox	box = {"BigBro", 12, 8, 6, 0};

	display_box(box);
	cout << endl;
	cout << "体积为：" << calc_box_volume(&box);

	cout << endl;
	return (0);
} 

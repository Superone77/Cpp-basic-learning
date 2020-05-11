#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

struct TCandyBar
{
	string Brand;
	double weight;
	unsigned heat;
};

void fuck(TCandyBar &sb, const char* Tbrand = "Millennium Munch", const double Tweight = 2.85, const unsigned Theat = 350);
void shownm(TCandyBar &sb);



void fuck(TCandyBar &sb, const char* Tbrand, const double Tweight, const unsigned Theat)
{
	sb.Brand = Tbrand;
	sb.weight = Tweight;
	sb.heat = Theat;
}

void shownm(TCandyBar &sb)
{
	cout << sb.Brand << " " << sb.weight << " "<< sb.heat << endl;
}

int main()
{

	TCandyBar bar;
	fuck(bar);
    shownm(bar);
	fuck(bar, "panpan", 3.8, 300);
	shownm(bar);

	system("pause");
	return 0;

}
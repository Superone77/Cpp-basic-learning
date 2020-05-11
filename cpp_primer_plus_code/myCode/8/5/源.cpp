#include<iostream>
#include<stdio.h>


using namespace std;

template <typename T>
void maximal(T arr[], unsigned n,T &k);

template<typename T>
void maximal(T arr[], unsigned n,T &k)
{
	unsigned max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[max])
			max = i;
	}
	k = arr[max];
}

int main()
{
	int arr1[6] = { 1,2,3,4,5,6 };
	double arr2[4] = { 1,2,3,4 };
	int x = 0;
	double y = 0;
	maximal(arr1, 6,x);
	maximal(arr2, 4,y);

	cout << x << endl << y << endl;

	system( "pause" );
	return 0;
	
}
#include <iostream>
#include <string>

// constant data
const int Seasons = 4;
const char* Snames[] = {"Spring", "Summer", "Fall", "Winter"};

struct TData
{
	double	arr[Seasons];
};


void fill(TData* pData)
{
	using namespace std;
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pData->arr[i];
	}
}

void show(TData data)
{
	using namespace std;
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << data.arr[i] << endl;
		total += data.arr[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

int main()
{
	TData	expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

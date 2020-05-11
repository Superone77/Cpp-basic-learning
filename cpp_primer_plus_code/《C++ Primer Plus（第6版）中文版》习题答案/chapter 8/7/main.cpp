#include <iostream>

struct debts
{
	char name[50];
	double amount;
};

template <typename T>
double SumArray(T arr[], int n)
{
	using namespace std;
	cout << "template A\n";
	double	sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	return (sum);
}

template <typename T>
double SumArray(T * arr[], int n)
{
	using namespace std;
	cout << "template B\n";
	double	sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];

	return (sum);
}

int main()
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] = {	{"Ima Wolfe", 2400.0},
								{"Ura Foxe", 1300.0},
								{"Iby Stout", 1800.0}	};
	double * pd[3];
	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;
	cout << "the total number of Mr. E's things:\n" << SumArray(things, 6) << endl;
	cout << "the sum of Mr. E's all debts:\n" << SumArray(pd, 3);

	return 0;
}

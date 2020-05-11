#include <iostream>

using namespace std;

unsigned
input_golfscores (double arrGolfScores[], unsigned uSize)
{
	double	tmp;
	unsigned	numGolfscores = 0;
	while (numGolfscores < uSize && cin >> tmp && -1 != tmp) {
		arrGolfScores[numGolfscores++] = tmp;
	}

	return (numGolfscores);
}

void
display_golfscores (double arrGolfScores[], unsigned uSize) 
{
	for (unsigned i = 0; i < uSize; ++i) {
		cout << arrGolfScores[i] << ' ';
	}
}

double
calc_average (double arrGolfScores[], unsigned uSize)
{
	double	sum = 0;
	for (unsigned i = 0; i < uSize; ++i) {
		sum += arrGolfScores[i];
	}

	return (sum / uSize);
}

int
main (void) 
{     
	const unsigned	k_size = 10;
	double	arrGolfScores[k_size];

	cout << "输入" << k_size << "个高尔夫成绩，-1可提前结束：";
	unsigned	numGolfscores = input_golfscores(arrGolfScores, k_size);
	cout << "高尔夫成绩明细如下：";
	display_golfscores(arrGolfScores, numGolfscores);
	cout << endl;
	cout << "高尔夫成绩均值为：" << calc_average(arrGolfScores, numGolfscores) << endl;

	cout << endl;
	return (0);
} 

#include <iostream>
#include <limits>
#include "TVector.h"

using namespace std;
using namespace n_vector;


int
main (void) 
{     
	srand((unsigned)time(nullptr));
	while (true) {
		double		setp;
		double		distance;
		unsigned	times;
		unsigned	max_setps = 0, min_setps = numeric_limits<unsigned>::max(), sum_setps = 0;

		cout << "输入步长：";
		cin >> setp;
		if (!cin || setp <= 0) {
			break;
		}
		cin.clear();	// 清空输入缓冲区错误标志位
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

		cout << "输入距离：";
		cin >> distance;
		if (!cin || distance <= 0) {
			break;
		}
		cin.clear();	// 清空输入缓冲区错误标志位
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

		cout << "输入测试次数：";
		cin >> times;
		if (!cin) {
			break;
		}
		cin.clear();	// 清空输入缓冲区错误标志位
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

		for (unsigned i = 0; i < times; ++i) {
			unsigned	cnt_steps = 0;
			TVector		vec(0, 0, TVector::POL);

			cout << i << "：";
			while (vec.getLength() < distance) {
				vec += TVector(setp, rand()%360, TVector::POL);
				++cnt_steps;
			}
			cout << cnt_steps << "步走到" << vec << endl;

			if (cnt_steps > max_setps) {
				max_setps = cnt_steps;
			}
			if (cnt_steps < min_setps) {
				min_setps = cnt_steps;
			}
			sum_setps += cnt_steps;
		}
		cout << "距离" << distance << "，步长" << setp << "，测试" << times << "次，最多走" 
			 << max_setps << "步，最少走" << min_setps << "步，平均走" << sum_setps / times << "步" << endl;
		cout << "==========" << endl;
	}


	cout << endl;
	return (0);
} 

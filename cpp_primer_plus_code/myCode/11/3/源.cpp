#include<iostream>
#include<fstream>
#include<limits>
#include<stdio.h>
#include<time.h>
#include"vect.h"

using namespace std;
using namespace n_vector;

int
main(void)
{
	ofstream of;
	of.open("output.txt");

	while (true) {
		double step;
		double distance;
		
		double max = 0.0;
		double min = numeric_limits<unsigned>::max();
		double sum = 0.0;
		double average = 0.0;
		unsigned times;

		cout << "输入步长： ";
		cin >> step;

		if (!cin || step <= 0)
		{
			break;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容

		cout << "输入距离： ";
		cin >> distance;
		if (!cin || distance <= 0)
		{
			break;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "输入测试次数：";
		cin >> times;
		if (!cin) {
			break;
		}
		cin.clear();	// 清空输入缓冲区错误标志位
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// 清空输入缓冲区内容
		of << "开始" << endl;

		for (unsigned i = 0; i < times; ++i) {

			unsigned cnt_steps = 0;
			TVector vec(0, 0, TVector::POL);
			srand((unsigned)time(NULL));//从系统时钟获取随机数
			while (vec.getLength() < distance)
			{
				vec += TVector(step, rand() % 361, TVector::POL);
				of << cnt_steps++ << "：" << vec << endl;

			}

			cout << cnt_steps << "步走到" << vec << endl;

			if (cnt_steps > max) {
				max = cnt_steps;
			}
			if (cnt_steps < min) {
				min = cnt_steps;
			}

			sum = sum + cnt_steps;
		}

		cout << "结束<<<<<<<<<<" << endl;
		cout << "距离" << distance << "，步长" << step << "，历经" << step << endl;
		cout << max << endl;
		cout << min << endl;
		cout << sum / times << endl;
		of << "==========\n" << endl;
		
	}
	of.close();

	cout << endl;

	system("pause");
	return 0;
		
	

}
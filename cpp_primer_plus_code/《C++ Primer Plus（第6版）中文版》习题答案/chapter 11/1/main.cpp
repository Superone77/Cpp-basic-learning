#include <iostream>
#include <fstream>
#include <limits>
#include "TVector.h"

using namespace std;
using namespace n_vector;


int
main (void) 
{     
	ofstream	of;
	of.open("output.txt");

	while (true) {
		double		setp;
		double		distance;
		unsigned	cnt_steps = 0;

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

		of << "开始>>>>>>>>>>" << endl;
		TVector	vec(0, 0, TVector::POL);
		srand((unsigned)time(nullptr));
		while (vec.getLength() < distance) {
			vec += TVector(setp, rand()%361, TVector::POL);
			of << cnt_steps++ << "：" << vec << endl;
		}
		of << "结束<<<<<<<<<<" << endl;
		of << "距离" << distance << "，步长" << setp << "，历经" << cnt_steps << "步走完，终点坐标" << vec << endl;
		of << "==========\n" << endl;
	}

	of.close();


	cout << endl;
	return (0);
} 

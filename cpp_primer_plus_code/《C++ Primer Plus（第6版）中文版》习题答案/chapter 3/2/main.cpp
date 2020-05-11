#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	double	height, weight, bmi;

	// 输入身高以英尺和英寸为单位
	int	feet, inches;
	cout << "输入身高，__英尺又__英寸：";
	cin >> feet >> inches;

	// 获得以英寸为单位的身高
	const int	k_factorFeetToInches = 12; 	// 1英尺 = 12英寸
	height = feet * k_factorFeetToInches + inches;	

	// 获得以米为单位的身高
	const double	k_factorInchesToMeters = 0.0254; 	// 1英寸 = 0.0254米
	height = height * k_factorInchesToMeters;

	// 输入体重以磅为单位
	int	pounds;
	cout << "输入以磅为单位的体重：";
	cin >> pounds;

	// 获得以千克为单位的体重
	const double	k_factorPoundsToKilograms = 1/2.2; 	// 1磅 = 1/2.2千克 
	weight = pounds * k_factorPoundsToKilograms;

	// 计算BMI
	bmi = weight / (height * height);

	// 显示BMI
	cout << "BMI：" << bmi << endl;

	cout << endl;
	return (0);
} 

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int
main (void) 
{     
	cout << "输入欧洲标准的油耗（升/100公里）：";
	double	gasConsumptionInEuropean;
	cin >> gasConsumptionInEuropean;

	const double	k_factorKmToMile = 0.6214;
	const double	k_factorLiterToGallon = 1/3.875;
	cout << gasConsumptionInEuropean << "（升/100公里）=" << 100 * k_factorKmToMile / (gasConsumptionInEuropean * k_factorLiterToGallon) << "（英里/加仑）";

	
	cout << endl;
	return (0);
} 

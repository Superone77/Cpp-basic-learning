#include <iostream>

using namespace std;

typedef double (*TPfun) (double x, double y);

void
calculate (double x, double y, TPfun fun[], unsigned num_of_funs)
{
	for (unsigned i = 0; i < num_of_funs; ++i) {
		cout << fun[i](x, y) << endl;
	}
}

double
add (double x, double y)
{
	cout << "加法操作结果：";
	return (x + y);
}

double
sub (double x, double y)
{
	cout << "减法操作结果：";
	return (x - y);
}

int
main (void) 
{     
	TPfun	fun[] = {add, sub};
	while (true) {
		cout << "输入两个数：";
		double	x, y;
		cin >> x >> y;
		if (!cin) {
			break;
		}
		calculate(x, y, fun, sizeof(fun)/sizeof(fun[0]));
	}

	cout << endl;
	return (0);
} 

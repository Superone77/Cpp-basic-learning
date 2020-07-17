#include <iostream>
#include <cstring>

using namespace std;

// 模板函数
template <typename T>
T maxn (T arr[], unsigned n)
{
	unsigned	idxMax = 0;
	for (unsigned i = 0; i < n; ++i) {
		if (arr[i] > arr[idxMax]) {
			idxMax = i;
		}
	}

	return (arr[idxMax]);
}


// 模板具体化  （要使用模板具体化的需要把模板函数和具体化函数的声明一致。否则编译报错：没有与指定类型匹配的模板函数。
// 这里修改了模板函数声明【原始声明为 template <typename T> const T& maxn (const T arr[], unsigned n)）】
// 这里猜测不匹配的原因是：模板具体化函数中的const char * 整个被认为是模板函数中的T，所以当在模板函数中再对T进行const限定时，就会认为非模板函数中为非const类型，进而出现不匹配。
// 即使在模板具体化maxn后的<>中指明类型T仅为char *【template <> const char *maxn<char*>】,仍是会报不匹配错误。 
// 所以，目前这种写法是将const char *整体作为T，编译通过，运行结果也正确。暂时只理解到这种程度，欢迎大家指正。Thanks♪(･ω･)ﾉ  20200717
template <> const char* maxn<const char*>(const char *arr[], unsigned n)
{
	unsigned idxMax = 0;
	if ( n > 0 ) {
		for ( unsigned i=0; i<n; ++i ) {
			if ( strlen(arr[i]) > strlen(arr[idxMax]) ) {
				idxMax = i;
			}
		}
	}
	return arr[idxMax];
 }


int
main (void)
{
	int	iArray[] = {32, -1, 99, 0, 256, 9};
	for (const auto& e : iArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << maxn(iArray, sizeof(iArray)/sizeof(iArray[0])) << endl;

	double	dArray[] = {-3.2, 221.22, 9.9, 0, 1};
	for (const auto& e : dArray) {
		cout << e << ' ';
	}
	cout << " ----max: " << maxn(dArray, sizeof(dArray)/sizeof(dArray[0])) << endl;

	const char*	szArray[] = {	"aa aa",
					"dddddddddddd",
					"",
					"fffffff ffff",
					"kk kk",
				    };
	for (const auto& e : szArray) {
		cout << '\"' << e << '\"' << ' ';
	}
	cout << " ----max: " << '\"' << maxn(szArray, sizeof(szArray)/sizeof(szArray[0])) << '\"' << endl;


	cout << endl;
	return 0;
}

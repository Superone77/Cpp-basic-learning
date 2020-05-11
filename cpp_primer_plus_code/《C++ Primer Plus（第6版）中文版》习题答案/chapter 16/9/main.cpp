#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <ctime>

using namespace std;

int
main (void)
{
	unsigned	elem_size;
	cout << "输入元素数量：";
	cin >> elem_size;
	if (!cin) {
		cerr << "元素数量必须为正数！" << endl;
		return (EXIT_FAILURE);
	}
	cout << endl;

	cout << "vi0 产生" << elem_size << "个随机数" << flush;
	vector<int>	vi0;
	srand((unsigned)time(nullptr));
	for (unsigned i = 0; i < elem_size; ++i) {
		vi0.push_back(rand());
	}
	cout << endl;

	cout << "vi1 使用 sort() 泛型算法排序耗时：" << flush;
	vector<int>	vi1(vi0);
	clock_t	start = clock();
	sort(vi1.begin(), vi1.end());
	clock_t	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

	cout << "li1 使用 sort() 容器类成员函数排序耗时：" << flush;
	list<int>	li1(vi0.cbegin(), vi0.cend());
	start = clock();
	li1.sort();
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;

	cout << "li2 先将其元素拷贝至 vi2 中，vi2 再使用 sort() 泛型算法排序，最后 vi2 将其元素拷贝至 li2 中，总计耗时：" << flush;
	list<int>	li2(vi0.cbegin(), vi0.cend());
	start = clock();
	vector<int>	vi2(li2.cbegin(), li2.cend());
	sort(vi2.begin(), vi2.end());
	li2.assign(vi2.cbegin(), vi2.cend());
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;


	return (EXIT_SUCCESS);
}

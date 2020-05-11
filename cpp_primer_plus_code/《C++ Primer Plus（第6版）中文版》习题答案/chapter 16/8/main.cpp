#include <iostream>
#include <iterator>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

int
main (void)
{
	string	full_name;

	cout << "输入Mat的所有朋友：" << endl;
	unordered_set<string>	mat_friends;
	while (getline(cin, full_name)) {
		mat_friends.insert(full_name);
	}
	cin.clear();	// 清空输入缓冲区错误标志位
	
	cout << "输入Pat的所有朋友：" << endl;
	unordered_set<string>	pat_friends;
	while (getline(cin, full_name)) {
		pat_friends.insert(full_name);
	}

	set<string>	all_friends;
	insert_iterator<set<string>>	insert_iter(all_friends, all_friends.cbegin());
	set_union(mat_friends.cbegin(), mat_friends.cend(), pat_friends.cbegin(), pat_friends.cend(), insert_iter);
	cout << "所有朋友如下：" << endl;
	copy(all_friends.cbegin(), all_friends.cend(), ostream_iterator<string>(cout, "\n"));
	cout << endl;

	return (EXIT_SUCCESS);
}

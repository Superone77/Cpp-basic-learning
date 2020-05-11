#include <iostream>
#include <iterator>
#include <fstream>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

int
main (int argc, char* argv[])
{
	if (argc != 4) {
		cerr << "错误！命令格式：command mats_friends pats_friends all_friends" << endl;
		return (EXIT_FAILURE);
	}

	const string	mats_friends_filename = argv[1];
	const string	pats_friends_filename = argv[2];
	const string	all_friends_filename = argv[3];

	ifstream	mats_friends_ifs(mats_friends_filename);
	if (!mats_friends_ifs) {
		cerr << "错误！" << mats_friends_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	ifstream	pats_friends_ifs(pats_friends_filename);
	if (!pats_friends_ifs) {
		cerr << "错误！" << pats_friends_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	ofstream	all_friends_ofs(all_friends_filename);
	if (!all_friends_ofs) {
		cerr << "错误！" << all_friends_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	string	full_name;

	cout << "从文件 " << mats_friends_filename << " 中读取 Mat 的所有朋友：" << endl;
	unordered_set<string>	mat_friends;
	while (getline(mats_friends_ifs, full_name)) {
		mat_friends.insert(full_name);
		cout << full_name << endl;
	}
	cout << "完成。共计 " << mat_friends.size() << " 个" << endl << endl;

	cout << "从文件 " << pats_friends_filename << " 中读取 Pat 的所有朋友：" << endl;
	unordered_set<string>	pat_friends;
	while (getline(pats_friends_ifs, full_name)) {
		pat_friends.insert(full_name);
		cout << full_name << endl;
	}
	cout << "完成。共计 " << pat_friends.size() << " 个" << endl << endl;
	
	unordered_set<string>	all_friends(mat_friends.cbegin(), mat_friends.cend());
	all_friends.insert(pat_friends.cbegin(), pat_friends.cend());
	cout << "所有朋友如下：" << endl;
	copy(all_friends.cbegin(), all_friends.cend(), ostream_iterator<string>(cout, "\n"));
	copy(all_friends.cbegin(), all_friends.cend(), ostream_iterator<string>(all_friends_ofs, "\n"));
	cout << "已保存至文件 " << all_friends_filename << endl;
	cout << endl;



	return (EXIT_SUCCESS);
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int
main (int argc, char* argv[])
{
	if (argc != 4) {
		cerr << "错误！命令格式：command src_filename_left src_filename_right dest_filename" << endl;
		return (EXIT_FAILURE);
	}

	const string	src_filename_left = argv[1];
	const string	src_filename_right = argv[2];
	const string	dest_filename = argv[3];
	if (src_filename_left == dest_filename || src_filename_right == dest_filename) {
		cerr << "错误！源文件和目的文件不能重名" << endl;
		return (EXIT_FAILURE);
	}

	ifstream	src_ifstream_left(src_filename_left);
	if (!src_ifstream_left) {
		cerr << "错误！" << src_filename_left << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	ifstream	src_ifstream_right(src_filename_right);
	if (!src_ifstream_right) {
		cerr << "错误！" << src_filename_right << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	ofstream	dest_ofstream(dest_filename);
	if (!dest_ofstream) {
		cerr << "错误！" << dest_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	cout << "将 " << src_filename_left << " 与 " << src_filename_right << " 按行合并至 " << dest_filename << " ... " << endl;
	while (true) {
		string	left_line, right_line;
		bool	left_state = getline(src_ifstream_left, left_line);
		bool	right_state = getline(src_ifstream_right, right_line);
		if (!left_state && !right_state) {
			break;
		}
		
		dest_ofstream << left_line + ' ' + right_line << endl;
	}
	cout << "完成" << endl;


	return (EXIT_SUCCESS);
}

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int
main (int argc, char* argv[])
{
	if (argc != 3) {
		cerr << "错误！命令格式：command src_file_name dest_file_name" << endl;
		return (EXIT_FAILURE);
	}

	const string	src_filename = argv[1];
	const string	dest_filename = argv[2];
	if (src_filename == dest_filename) {
		cerr << "错误！源文件和目的文件不能重名" << endl;
		return (EXIT_FAILURE);
	}

	ifstream	src_ifstream(src_filename);
	if (!src_ifstream) {
		cerr << "错误！" << src_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	ofstream	dest_ofstream(dest_filename);
	if (!dest_ofstream) {
		cerr << "错误！" << dest_filename << " 打开失败" << endl;
		return (EXIT_FAILURE);
	}

	cout << "将 " << src_filename << " 拷贝至 " << dest_filename << " ... " << endl;
	string	line;
	while (getline(src_ifstream, line)) {
		dest_ofstream << line << endl;
	}
	cout << "完成" << endl;


	return (EXIT_SUCCESS);
}

#include <iostream>
#include <cstring>

using namespace std;

int
main (void)
{
	const unsigned	k_size = 64;
	const char		key_char = '$';
	unsigned		char_cnt = 0;

	char	line_txt[k_size];
	while (cin.get(line_txt, k_size, key_char)) {
		char_cnt += strlen(line_txt);
	}
	cin.clear();

	char	ch;
	cin >> ch;
	cout << "第一个 " << ch << " 前出现了 " << char_cnt << " 个字符 （注，含换行符）" << endl;


	return (EXIT_SUCCESS);
}

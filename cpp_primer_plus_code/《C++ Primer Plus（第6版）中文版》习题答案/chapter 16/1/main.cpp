#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static bool
isPalindrome (const string& word)
{
	string	word_reverse(word.crbegin(), word.crend());
	return (word == word_reverse);
}

int
main (void)
{
	cout << "输入单词：" << endl;
	string	word;
	while (cin >> word) {
		cout << word << (isPalindrome(word) ? "是" : "不是") << "回文" << endl;
	}
	cout << endl;

	return (EXIT_SUCCESS);
}

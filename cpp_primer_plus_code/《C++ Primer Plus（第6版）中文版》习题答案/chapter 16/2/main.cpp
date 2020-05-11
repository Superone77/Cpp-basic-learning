#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

static bool
isPalindrome (const string& word)
{
	string	word_pure;
	for (auto& e : word) {
		if (isalpha(e)) {
			word_pure.push_back(static_cast<char>(tolower(e)));
		}
	}
	string	word_reverse(word_pure.crbegin(), word_pure.crend());
	return (word_pure == word_reverse);
}

int
main (void)
{
	cout << "输入单词：" << endl;
	string	word;
	while (getline(cin, word)) {
		cout << word << (isPalindrome(word) ? "是" : "不是") << "回文" << endl;
	}
	cout << endl;

	return (EXIT_SUCCESS);
}

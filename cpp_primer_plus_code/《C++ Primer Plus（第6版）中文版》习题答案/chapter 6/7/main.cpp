#include <iostream>


int
main (void) 
{     
	using namespace std;

	unsigned	cntVowels = 0, cntConsonants = 0, cntOthers = 0;
	
	cout << "输入单词，字母q结束：";
	string	word;
	while (cin >> word && "q" != word) {
		char&	first_char = word[0];
		if (!isalpha(first_char)) {
			++cntOthers;
		} else if (	'a' == first_char || 'A' == first_char || 
					'e' == first_char || 'E' == first_char || 
					'i' == first_char || 'I' == first_char || 
					'o' == first_char || 'O' == first_char || 
					'u' == first_char || 'U' == first_char	) {
			++cntVowels;
		} else {
			++cntConsonants;
		}
	}

	cout << "元音开头的单词" << cntVowels << "个、辅音单词" << cntConsonants << "个、其他" << cntOthers << "个" << endl;

	cout << endl;
	return (0);
} 

#include <iostream>


const unsigned	gk_size = 64;
enum TPreference {FULLNAME, TITLE, BOPNAME};
struct TBop {
	char		szFullname[gk_size];	// real name
	char		szTitle[gk_size];	// job title
	char		szBopname[gk_size];	// secret BOP name
	TPreference	preference;
};

int
main (void) 
{     
	using namespace std;

	TBop	lstBops[] = {	{"Yang Yang", "chinamobile", "yangyang.gnu", TITLE},
							{"xiao wang", "microsoft", "xiaowang", BOPNAME},
							{"xiao liu", "IBM", "xiaoliu", FULLNAME},
							{"xiao zhang", "Huawei", "xiaozhang", TITLE}	};

	bool	bDisplay = true;
	while (bDisplay) {
		cout << "Benevolent Order of Programmers Report" << endl;
		cout << "a. display by name" << "\t" << "b. display by title" << endl;
		cout << "c. display by bopname" << "\t" << "d. display by preference" << endl;
		cout << "q. quit" << endl;

		char	chAction;
		if (!(cin >> chAction)) {
			bDisplay = false;
			break;
		}

		switch (chAction) {
			case 'a': {
				for (const auto& e : lstBops) {
					cout << e.szFullname << endl;
				};
			}
			break;
		
			case 'b': {
				for (const auto& e : lstBops) {
					cout << e.szTitle << endl;
				};
			}
			break;
		
			case 'c': {
				for (const auto& e : lstBops) {
					cout << e.szBopname << endl;
				};
			}
			break;
		
			case 'd': {
				for (const auto& e : lstBops) {
					if (FULLNAME == e.preference) {
						cout << e.szFullname << endl;
					} else if (TITLE == e.preference) {
						cout << e.szTitle<< endl;
					} else if (BOPNAME == e.preference) {
						cout << e.szBopname<< endl;
					} else {
						;
					}
				}
			}
			break;
		
			case 'q': {
				cout << "Bye! " << endl;
				bDisplay = false;
			}
			break;
		
			default: {
				cout << "Error! " << endl;
			}
			break;
		}
	}


	cout << endl;
	return (0);
} 

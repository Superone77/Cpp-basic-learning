#include <iostream>

int
main (void) 
{     
	using namespace std;

	cout << "Please enter one of the following choices: " << endl;
	cout << "c) carnivore\t" << "p) pianist" << endl;
	cout << "t) tree\t\t" << "g) game" << endl;
	char	ch;
	while (cin >> ch) {
		switch (ch) {
			case 'c': {
					cout << "A dog is a carnivore. " << endl;
				}
				break;
		
			case 'p': {
					cout << "Lang Lang is a pianist. " << endl;
				}
				break;
		
			case 't': {
					cout << "A maple is a tree." << endl;
				}
				break;
		
			case 'g': {
					cout << "Red alert is a game. " << endl;
				}
				break;
		
			default:
				cout << "Please enter a c, p, t, or g: ";
				break;
		}
	}


	cout << endl;
	return (0);
} 

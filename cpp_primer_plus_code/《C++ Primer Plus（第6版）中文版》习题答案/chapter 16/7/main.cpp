#include <iostream>
#include <iterator>
#include <unordered_set>

using namespace std;

static unordered_set<unsigned>
getLotto (unsigned rang, unsigned total)
{
	unordered_set<unsigned>	winners;

	if (rang < total) {
		return (winners);
	}

	srand((unsigned)time(nullptr));
	while (winners.size() < total) {
		winners.insert((unsigned)rand() % rang);
	}

	return (winners);
}

int
main (void)
{
	unordered_set<unsigned>	winners = getLotto(51, 6);
	for (const auto& e : winners) {
		cout << e << ' ';
	}
	cout << endl;

	return (EXIT_SUCCESS);
}

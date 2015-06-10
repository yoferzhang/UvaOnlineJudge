#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int  chance;
char puzzle[100], guesses[200];
int win, lose;
int position;

void guess(char ch) {
	int bad = 1;
	for (int i = 0; i < strlen(puzzle); i++) {
		if (puzzle[i] == ch) {
			position--;
			puzzle[i] = ' ';
			bad = 0;
		}
	}
	if (bad) {
		--chance;
	}
	if (!chance) {
		lose = 1;
	}
	if (!position) {
		win = 1;
	}
}

int main()
{
	int number;
	while (cin >> number) {
		// -1ÍË³ö
		if (number == -1) {
			break;
		}
		scanf("%s%s", puzzle, guesses);
		win = lose = 0;
		chance = 7;
		position = strlen(puzzle);
		for (int i = 0; i < strlen(guesses); i++) {
			guess(guesses[i]);
			if (win || lose) {
				break;
			}
		}
		cout << "Round " << number << endl;
		if (win) {
			cout << "You win.\n";
		}
		else if (lose) {
			cout << "You lose.\n";
		}
		else {
			cout << "You chickened out.\n";
		}
	}

	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

set<string> dict;

int main()
{
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s) {
		dict.insert(s);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
		string t = *it;
		for (int i = 1; i < t.length(); i++) {
			if (dict.find(t.substr(0, i)) != dict.end() &&
				dict.find(t.substr(i, t.length() - i)) != dict.end()) {
				cout << t << endl;
				break;
			}
		}

	}

	return 0;
}
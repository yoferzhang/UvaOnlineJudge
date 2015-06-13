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

typedef pair<int, int> point;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		set<point> data;
		int n;
		point p;
		int sum = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p.first >> p.second;
			sum += p.first;
			data.insert(point(p.first * n, p.second));
		}
		bool flag = true;
		for (set<point>::iterator it = data.begin(); it != data.end(); it++) {
			point p = *it;
			if (data.find(point(2 * sum - p.first, p.second)) == data.end()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
	return 0;
}
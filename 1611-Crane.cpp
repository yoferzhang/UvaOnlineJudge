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
#include <bitset> 
#include <cassert> 
#include <cmath>
#include <functional>

using namespace std;

const int maxn = 10005;
int numbers[maxn];

void exchange(int L, int R)
{
	for (int i = L, j = L + (R - L + 1) / 2;
		j <= R; j++, i++) {
		swap(numbers[i], numbers[j]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> numbers[i];
		}

		vector<pair<int, int> > ans;
		for (int i = 1; i <= n; i++) {
			int pos;
			for (int j = i; j <= n; j++) {
				if (numbers[j] == i) { // 找到i的位置
					pos = j;
					break;
				}
			}
			if (pos == i) {
				continue;
			}
			if (i + 2 * (pos - i) - 1 <= n) { // 满足这个条件可直接
				ans.push_back(make_pair(i, i + 2 * (pos - i) - 1));
				exchange(i, i + 2 * (pos - i) - 1);
			}
			else {
				if ((pos - i) % 2) {
					ans.push_back(make_pair(i, pos));
					exchange(i, pos);
				}
				else {
					ans.push_back(make_pair(i + 1, pos));
					exchange(i + 1, pos);
				}
				i--;
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
	}

	return 0;
}
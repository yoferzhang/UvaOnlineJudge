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

const int maxn = 55;

int n, t, p, ans;
int len[maxn];
int d[2][180 * maxn + 678];

void init()
{
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> len[i];
	}

	for (int i = 0; i < t; i++) {
		d[0][i] = -1;
	}
	d[0][0] = 0;
}

void solve()
{
	p = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < t; j++) {
			d[p][j] = d[p ^ 1][j];
			if (j >= len[i] && d[p ^ 1][j - len[i]] >= 0) {
				d[p][j] = max(d[p][j], d[p ^ 1][j - len[i]] + 1);
			}
			ans = max(ans, d[p][j]);
		}
		p ^= 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		init();
		solve();
		for (int i = t - 1; i >= 0; i--) {
			if (d[p ^ 1][i] == ans) {
				cout << "Case " << ++kase << ": " << ans + 1 << ' ' << i + 678 << endl;
				break;
			}
		}
	}

	return 0;
}
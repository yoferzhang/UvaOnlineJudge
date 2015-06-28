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

const int maxn = 1000005;
int n, m, A[maxn], ans[maxn], full[maxn];

void init()
{
	memset(ans, 0, sizeof(ans));
	memset(full, 0, sizeof(ans));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> A[i];
	}
}

void solve()
{
	set<int> E;
	bool err = false;
	for (int i = 1; i <= m && !err; i++) {
		if (A[i] > 0) {
			// 查找当前湖最后灌满的日子之后有没有不下雨的日子
			set<int>::iterator it = E.lower_bound(full[A[i]]);
			if (it != E.end() && *it > full[A[i]]) {
				ans[*it] = A[i];
				E.erase(it);
				full[A[i]] = i; // 湖满水的日子
			}
			else {
				err = true;
			}
		}
		else {
			E.insert(i);
		}
	}
	if (err) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		bool flag = false;
		for (int i = 1; i <= m; i++) {
			if (A[i] == 0) {
				if (flag) {
					cout << ' ';
				}
				flag = true;
				cout << ans[i];
			}
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		init();
		solve();
	}

	return 0;
}
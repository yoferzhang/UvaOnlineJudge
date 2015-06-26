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
int X[maxn], vis[maxn];
int n, m, k;

void init()
{
	memset(vis, 0, sizeof(vis)); // 记得重置状态矩阵
	X[1] = 1;
	X[2] = 2;
	X[3] = 3;
	for (int i = 4; i <= n; i++) {
		X[i] = (X[i - 1] + X[i - 2] + X[i - 3]) % m + 1;
	}
}

void solve()
{
	int l = 1, r = 1, cnt = 0;
	int ans = n + 1;
	while (r <= n) {
		int t = X[r++];
		vis[t]++;
		if (t <= k && vis[t] == 1) {
			cnt++;
		}

		while (l < r && cnt == k) { // 当够了k个之后往右移动
			ans = min(ans, r - l); // 记录下当前最优解再往右移
			t = X[l++];
			vis[t]--;
			if (t <= k && vis[t] == 0) {
				cnt--;
			}
		}
	}

	if (ans <= n) {
		cout << ans << endl;
	}
	else {
		cout << "sequence nai\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		cin >> n >> m >> k;
		init();
		cout << "Case " << ++kase << ": ";
		solve();
	}

	return 0;
}
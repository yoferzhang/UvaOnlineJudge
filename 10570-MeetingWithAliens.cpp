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

const int maxn = 505;
int a[1005], b[1005];
int n;

int solve() {
	int ret = 0xfffffff;
	for (int i = 0, j = n; i < n; i++, j++) {
		a[j] = a[i];
	}
	for (int i = 0; i < n; i++) {
		int mark[maxn], cnt = 0;
		for (int j = 0; j < n; j++) {
			mark[a[i + j]] = i + j;
			b[i + j] = a[i + j];
		}
		for (int j = 0; j < n; j++) {
			if (b[i + j] != j) {
				cnt++;
				int idx = mark[j];
				swap(b[i + j], b[idx]);
				mark[b[idx]] = idx;
			}
		}
		ret = min(ret, cnt);
	}
	return ret;
}

int main() 
{
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--; // 方便处理
		}
		int ret;
		ret = solve();
		reverse(a, a + n); // 反转再算一次求最小
		ret = min(ret, solve());
		cout << ret << endl;
	}
	return 0;
}
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

const int maxn = 100005;
int p[maxn], q[maxn];
int n;

int run(int s)
{
	int fuel = p[s] - q[s];
	for (int i = (s + 1) % n; i != s; i = (i + 1) % n) {
		if (fuel < 0) { // 在上一站加油，车上的总油量不足以走到此站
			return i;
		}
		fuel += p[i] - q[i]; // 加满油，往下一站走
	}
	if (fuel < 0) {
		return -1; //  走了一圈，sum[p] < sum[q]，所以这种情况肯定是不可能的，直接返回-1
	}
	return s; // 成功返回起点
}

// 枚举起点
int solve()
{
	int start = 0;
	while (1) {
		int finish = run(start);
		if (finish < start) {
			return -1; // 失败
		}
		if (finish == start) { // 成功了
			return start;
		}
		start = finish; // 从断开的地方继续
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}

		int ans = solve();
		cout << "Case " << ++kase << ": ";
		if (ans >= 0) {
			cout << "Possible from station " << ans + 1 << endl;
		}
		else {
			cout << "Not possible\n";
		}
	}

	return 0;
}
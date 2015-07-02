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

const int maxn = 1005;

struct Lamp
{
	int v, k, c, l;
	bool operator < (const Lamp& rhs) const {
		return v < rhs.v;
	}
}lamp[maxn];

int n, s[maxn]; // s[i]为前i种灯泡的总数量
int d[maxn]; // d[i]为灯泡1~i的最小开销

void init()
{
	for (int i = 1; i <= n; i++) {
		cin >> lamp[i].v >> lamp[i].k >> lamp[i].c >> lamp[i].l;
	}
	sort(lamp + 1, lamp + n + 1); // 注意排序范围

	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + lamp[i].l;
	}
}

void solve()
{
	d[0] = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = s[i] * lamp[i].c + lamp[i].k; // 前i灯泡全买类型i
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], d[j] + (s[i] - s[j]) * lamp[i].c + lamp[i].k);
		}
	}
	cout << d[n] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		init();
		solve();
	}

	return 0;
}
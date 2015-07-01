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

const int maxn = 35;

int n;
int blocks[maxn][3];
int d[maxn][3];
// 状态数组，d[idx][k]当顶面为立方体idx，其中第k条边（排序后）为高

void init()
{
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> blocks[i][j];
		}
		sort(blocks[i], blocks[i] + 3);
	}
}

void getDimensions(int* v, int b, int dim)
{
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		if (i != dim) {
			v[idx++] = blocks[b][i];
		}
	}
}

int dp(int i, int j)
{
	int& ans = d[i][j];
	if (ans > 0) {
		return ans;
	}
	ans = 0;
	int v[2], v2[2];
	getDimensions(v, i, j);
	for (int a = 0; a < n; a++) {
		for (int b = 0; b < 3; b++) {
			getDimensions(v2, a, b);
			if (v2[0] < v[0] && v2[1] < v[1]) {
				ans = max(ans, dp(a, b));
			}
		}
	}
	ans += blocks[i][j];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n && n) {
		init();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				ans = max(ans, dp(i, j));
			}
		}
		cout << "Case " << ++kase << ": maximum height = " << ans << endl;
	}

	return 0;
}
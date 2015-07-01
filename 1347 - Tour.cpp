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
#include <iomanip>

using namespace std;

const int maxn = 55;
int n;
double x[maxn], y[maxn], dist[maxn][maxn];
double d[maxn][maxn];
// d(i, j)表示1~max(i, j)全都走过，并且两个人的当前位置是i和j还需要走多长的距离

// 动态规划求解
void solve()
{
	for (int i = n - 1; i >= 2; i--) {
		for (int j = 1; j < i; j++) {
			if (i == n - 1) { // 边界
				d[i][j] = dist[i][n] + dist[j][n];
			}
			else {
				d[i][j] = min(dist[i][i + 1] + d[i + 1][j], dist[j][i + 1] + d[i + 1][i]);
			}
		}
	}
	double ans = dist[1][2] + d[2][1];
	cout.setf(ios::fixed);
	cout << setprecision(2) << ans << endl; // 输出格式注意
}

int main()
{
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			}
		}
		solve();
	}

	return 0;
}
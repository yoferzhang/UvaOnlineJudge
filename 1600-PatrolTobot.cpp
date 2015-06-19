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

using namespace std;

const int maxn = 30;
int m, n, k;
int grid[maxn][maxn];
int state[21][21][21];
int ans;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

// dfs递归，从(x,y)出发，当前走了cnt步，已经连续穿越了haveCross层墙
void dfs(int x, int y, int cnt, int haveCross)
{
	if (x == m - 1 && y == n - 1) {
		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x1 = x + dr[i];
		int y1 = y + dc[i];
		int c = haveCross;
		if (grid[x1][y1] == 1) {
			c++;
		}
		else {
			c = 0;
		}
		if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n) {
			if ((state[x1][y1][c] < 0 ||
				state[x1][y1][c] > cnt + 1) &&
				c <= k) { // 走到下一步的时候，之前走到这里的步数必须小于之后走到这里的步数。
				state[x1][y1][c] = cnt + 1;
				dfs(x1, y1, cnt + 1, c);
			}
		}
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		memset(state, -1, sizeof(state));
		ans = 1 << 30;
		//cout << ans;
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		dfs(0, 0, 0, 0);
		if (ans != 1 << 30) {
			cout << ans << endl;
		}
		else {
			cout << "-1\n";
		}
	}

	return 0;
}
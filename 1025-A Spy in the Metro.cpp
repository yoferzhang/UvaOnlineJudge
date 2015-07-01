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

const int maxt = 75;
const int maxm = 55;
const int maxT = 205;
const int maxn = 55;
const int inf = 0x3f3f3f3f;

int n, T, M1, M2;
int t[maxt], d;
int dp[maxT][maxn]; // dp(i,j)表示时刻i，在车站j，最少还需要等待多长时间
int hasTrain[maxT][maxn][2];
// hasTrain[t][i][0]表示时刻t，在车站i是否有往右开的火车

void init()
{
	memset(t, 0, sizeof(t));
	memset(dp, 0, sizeof(dp));
	memset(hasTrain, 0, sizeof(hasTrain));
	cin >> T;
	for (int i = 1; i <= n - 1; i++) {
		cin >> t[i];
	}

	cin >> M1;
	for (int i = 1; i <= M1; i++) {
		cin >> d;
		for (int j = 1; j <= n - 1; j++) {
			if (d <= T) {
				hasTrain[d][j][0] = 1;
			}
			d += t[j];
		}
	}

	cin >> M2;
	for (int i = 1; i <= M2; i++) {
		cin >> d;
		for (int j = n - 1; j >= 1; j--) {
			if (d <= T) {
				hasTrain[d][j + 1][1] = 1;
			}
			d += t[j];
		}
	}
}

// 动态规划求解
void solve()
{
	for (int i = 1; i <= n - 1; i++) {
		dp[T][i] = inf;
	}
	dp[T][n] = 0;

	for (int i = T - 1; i >= 0; i--) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i + 1][j] + 1;
			if (j < n && hasTrain[i][j][0] && i + t[j] <= T) {
				dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
			}
			if (j > 1 && hasTrain[i][j][1] && i + t[j - 1] <= T) {
				dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n && n) {
		init();
		solve();
		cout << "Case Number " << ++kase << ": ";
		if (dp[0][1] >= inf) {
			cout << "impossible\n";
		}
		else {
			cout << dp[0][1] << "\n";
		}
	}

	return 0;
}
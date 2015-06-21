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

const int maxm = 505;
int k, m;
int p[maxm];

// 在maxp的限制下最多需要多少scribers
int solve(long long maxp)
{
	long long done = 0;
	int ans = 1;
	for (int i = 0; i < m; i++) {
		if (done + p[i] <= maxp) {
			done += p[i];
		}
		else {
			ans++;
			done = p[i];
		}
	}
	return ans;
}

int last[maxm];
// 贪心输出结果
void print(long long ans)
{
	long long done = 0;
	memset(last, 0, sizeof(last));
	int remain = k;
	for (int i = m - 1; i >= 0; i--) {
		if (done + p[i] > ans || i + 1 < remain) {
			last[i] = 1;
			remain--;
			done = p[i];
		}
		else {
			done += p[i];
		}
	}
	for (int i = 0; i < m - 1; i++) {
		cout << p[i] << " ";
		if (last[i]) {
			cout << "/ ";
		}
	}
	cout << p[m - 1] << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--) {
		cin >> m >> k;
		long long tot = 0; // 总和
		int maxp = -1; // 最大值
		for (int i = 0; i < m; i++) {
			cin >> p[i];
			tot += p[i];
			maxp = max(maxp, p[i]);
		}
		long long L = maxp, R = tot;
		// 二分最小值
		while (L < R) {
			long long M = L + (R - L) / 2;
			if (solve(M) <= k) {
				R = M;
			}
			else {
				L = M + 1;
			}
		}
		print(L);
	}

	return 0;
}
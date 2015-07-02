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

const int maxn = 3;
int bottles[maxn][maxn];
int ans, ri, rj, rk;

void init()
{
	// 输入的时候注意，为了按字母顺序输出，所以这里的存储顺序有所改变
	cin >> bottles[0][2] >> bottles[0][1];
	cin >> bottles[1][0] >> bottles[1][2] >> bottles[1][1];
	cin >> bottles[2][0] >> bottles[2][2] >> bottles[2][1];
}

void solve()
{
	ans = 1 << 31 - 1;
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			if (i != j) {
				int k = 3 - i - j;
				int total = 0;
				for (int m = 0; m < maxn; m++) {
					if (i != m) {
						total += bottles[0][m];
					}
					if (j != m) {
						total += bottles[1][m];
					}
					if (k != m) {
						total += bottles[2][m];
					}
				}
				if (total < ans) {
					ans = total;
					ri = i;
					rj = j;
					rk = k;
				}
			}
		}
	}
	cout << (ri == 0 ? 'B' : ((ri == 1) ? 'C' : 'G'));
	cout << (rj == 0 ? 'B' : ((rj == 1) ? 'C' : 'G'));
	cout << (rk == 0 ? 'B' : ((rk == 1) ? 'C' : 'G'));
	cout << ' ' << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> bottles[0][0]) {
		init();
		solve();
	}

	return 0;
}
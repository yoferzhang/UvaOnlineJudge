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

const int maxn = 20;
int n;
int ans[maxn], vis[maxn];
// 小于50的素数：2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
// 如果i是素数，则ips[i]等于1，否则等于0，这里直接打表搞定。
int isp[50] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
				0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 
				0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
				0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 
				0, 1, 0, 1, 0, 0, 0, 1, 0, 0 };

void dfs(int cur)
{
	// 递归边界，别忘了测试第一个数和最后一个数的和是否是素数
	if (cur == n && isp[ans[0] + ans[n - 1]]) {
		cout << ans[0];
		for (int i = 1; i < n; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	else for (int i = 2; i <= n; i++) {
		if (!vis[i] && isp[i + ans[cur - 1]]) { // i没有用过，且与前一个数的和是素数
			ans[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0; // 记得出口处改回来
		}
	}

}

int main()
{
	int kase = 0;
	while (cin >> n) {
		if (kase) {
			cout << endl;
		}
		cout << "Case " << ++kase << ":\n";
		memset(vis, 0, sizeof(vis));
		ans[0] = 1;
		dfs(1);
	}

	return 0;
}
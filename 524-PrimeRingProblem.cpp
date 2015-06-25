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
// С��50��������2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 
// ���i����������ips[i]����1���������0������ֱ�Ӵ��㶨��
int isp[50] = { 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
				0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 
				0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 
				0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 
				0, 1, 0, 1, 0, 0, 0, 1, 0, 0 };

void dfs(int cur)
{
	// �ݹ�߽磬�����˲��Ե�һ���������һ�����ĺ��Ƿ�������
	if (cur == n && isp[ans[0] + ans[n - 1]]) {
		cout << ans[0];
		for (int i = 1; i < n; i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	else for (int i = 2; i <= n; i++) {
		if (!vis[i] && isp[i + ans[cur - 1]]) { // iû���ù�������ǰһ�����ĺ�������
			ans[cur] = i;
			vis[i] = 1;
			dfs(cur + 1);
			vis[i] = 0; // �ǵó��ڴ��Ļ���
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
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

int n, L, cnt;
int s[85];

bool dfs(int cur) // 返回false表示已经得到解，不用继续搜索
{
	if (cnt++ == n) {
		for (int i = 0; i < cur; i++) {
			if (i % 64 == 0 && i > 0) { // 每行64个
				cout << endl;
			}
			else if (i % 4 == 0 && i > 0) { // 每4个一个空格
				cout << ' ';
			}
			cout << (char)('A' + s[i]);
		}
		cout << endl << cur << endl;
		return false;
	}

	for (int i = 0; i < L; i++) {
		s[cur] = i;
		bool ok = true;
		for (int j = 1; j * 2 <= cur + 1; j++) { // 长度为j*2的后缀是否满足
			bool equal = true;
			for (int k = 0; k < j; k++) {
				if (s[cur - k] != s[cur - k - j]) { // 检查后一半是否等于前一半
					equal = false;
					break;
				}
			}
			if (equal) { // 前后相等了，不合法
				ok = false;
				break;
			}
		}
		if (ok) {
			if (!dfs(cur + 1)) {
				return false; // 递归搜索，如果已经找到，则退出
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> L && n) {
		cnt = 0;
		dfs(0);
	}

	return 0;
}
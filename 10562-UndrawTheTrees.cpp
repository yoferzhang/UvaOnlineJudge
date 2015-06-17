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

using namespace std;

const int maxn = 205;
int n;
char buf[maxn][maxn];

// 递归遍历输出以buf[r][c]为根的树
void dfs(int r, int c)
{
	printf("%c(", buf[r][c]);
	if (r + 1 < n && buf[r + 1][c] == '|') { // r不是最后一行，并别下面有子树
		int i = c;
		// 找到“---"的左边界
		while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') {
			i--;
		}
		while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0') {
			if (!isspace(buf[r + 3][i])) {
				dfs(r + 3, i);
			}
			i++;
		}
	}
	printf(")");
}

// 输入数据并从根开始dfs求解
void solve()
{
	n = 0;
	while (1) {
		fgets(buf[n], maxn, stdin);
		if (buf[n][0] == '#') {
			break;
		}
		else {
			n++;
		}
	}
	printf("(");
	if (n) {
		for (int i = 0; i < strlen(buf[0]); i++) {
			if (buf[0][i] != ' ') {
				dfs(0, i);
				break;
			}
		}
	}
	printf(")\n");
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &T);
	while (T--) {
		solve();
	}

	return 0;
}
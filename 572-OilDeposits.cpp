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

const int maxn = 105;
int m, n;
char pic[maxn][maxn];
int idx[maxn][maxn];

void dfs(int r, int c, int id) {
	if (r < 0 || r >= m || c < 0 || c >= n) { // 非法位置
		return;
	}
	if (idx[r][c] > 0 || pic[r][c] != '@') { // 已经标记过或者不是油田
		return;
	}
	idx[r][c] = id; // 一块油田编号
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) { // 用两个循环遍历周围的八个油田
			if (dr != 0 || dc != 0) { // dr == 0 和dc == 0是中间自身，跳过不执行
				dfs(r + dr, c + dc, id);
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &m, &n) == 2 && m && n) {
		for (int i = 0; i < m; i++) {
			scanf("%s", pic[i]);
		}
		memset(idx, 0, sizeof(idx));
		int cnt = 0; // 油田块的个数
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (idx[i][j] == 0 && pic[i][j] == '@') { // 是油田，并且没有并编号过
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
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
	if (r < 0 || r >= m || c < 0 || c >= n) { // �Ƿ�λ��
		return;
	}
	if (idx[r][c] > 0 || pic[r][c] != '@') { // �Ѿ���ǹ����߲�������
		return;
	}
	idx[r][c] = id; // һ��������
	for (int dr = -1; dr <= 1; dr++) {
		for (int dc = -1; dc <= 1; dc++) { // ������ѭ��������Χ�İ˸�����
			if (dr != 0 || dc != 0) { // dr == 0 ��dc == 0���м�����������ִ��
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
		int cnt = 0; // �����ĸ���
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (idx[i][j] == 0 && pic[i][j] == '@') { // ���������û�в���Ź�
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
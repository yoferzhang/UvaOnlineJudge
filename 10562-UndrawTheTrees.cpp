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

// �ݹ���������buf[r][c]Ϊ������
void dfs(int r, int c)
{
	printf("%c(", buf[r][c]);
	if (r + 1 < n && buf[r + 1][c] == '|') { // r�������һ�У���������������
		int i = c;
		// �ҵ���---"����߽�
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

// �������ݲ��Ӹ���ʼdfs���
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
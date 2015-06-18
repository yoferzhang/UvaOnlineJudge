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

const int maxn = 52;

int G[maxn][maxn];

// ��52���ַ�A+~Z+,A-~Z-,ת��������
int ID(char a1, char a2)
{
	return (a1 - 'A') * 2 + ((a2 == '+') ? 0 : 1);
}

void connect(char a1, char a2, char b1, char b2)
{
	if (a1 == '0' || b1 == '0') { // ��00�߲�������
		return;
	}
	int u = ID(a1, a2) ^ 1;
	int v = ID(b1, b2);
	G[u][v] = 1;
}

int c[maxn]; // ��ʾ����״̬

// �ж��Ƿ��u������������
bool dfs(int u)
{
	c[u] = -1; // ��ʾ���ڷ���
	for (int v = 0; v < maxn; v++) {
		if (G[u][v]) {
			if (c[v] < 0) { //�ߵ������
				return true;
			}
			else if (!c[v] && dfs(v)) {
				return true;
			}
		}
	}
	c[u] = 1;
	return false;
}

// �Ƿ��������
bool findCycle()
{
	memset(c, 0, sizeof(c));
	for (int i = 0; i < maxn; i++) {
		if (!c[i]) {
			if (dfs(i)) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	//while (scanf("%d", &n) == 1 && n) {
	while (cin >> n && n) {
		memset(G, 0, sizeof(G));
		while (n--) {
			char s[10];
			//scanf("%s", s);
			cin >> s;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i != j) {
						connect(s[i * 2], s[i * 2 + 1], s[j * 2], s[j * 2 + 1]);
					}
				}
			}
		}
		if (findCycle()) {
			printf("unbounded\n");
		}
		else {
			printf("bounded\n");
		}
	}

	return 0;
}
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

const int maxv = 26;
const int maxn = 1005;

int G[maxv][maxv];
int inDeg[maxv]; // 每个点的入度数
int outDeg[maxv]; // 每个点的出度数
int vis[maxv];

void dfs(int u)
{
	vis[u] = true;
	for (int i = 0; i < maxv; i++) {
		if (G[u][i] > 0) {
			G[u][i]--;
			G[i][u]--;
			dfs(i);
		}
	}
}

// 判断度数是否满足
bool okDeg()
{
	bool star = false;
	bool end = false;

	for (int i = 0; i < maxv; i++) {
		if (inDeg[i] != outDeg[i]) {
			if (!end && inDeg[i] == outDeg[i] + 1) { // 终点
				end = true;
			}
			else if (!star && inDeg[i] + 1 == outDeg[i]) { // 起点
				star = true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

bool okDfs()
{
	for (int u = 0; u < maxv; u++) {
		if (inDeg[u] + outDeg[u]) {
			if (vis[u] == false) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		memset(G, 0, sizeof(G));
		memset(inDeg, 0, sizeof(inDeg));
		memset(outDeg, 0, sizeof(outDeg));
		memset(vis, 0, sizeof(vis));

		int edge, star;
		cin >> edge;
		while (edge--) {
			char ch[maxn];
			cin >> ch;
			int u = ch[0] - 'a';
			int v = ch[strlen(ch) - 1] - 'a';
			inDeg[u]++;
			outDeg[v]++;
			G[u][v]++;
			G[v][u]++;
			star = u;
		}

		dfs(star);
		if (okDfs() && okDeg()) {
			cout << "Ordering is possible.\n";
		}
		else {
			cout << "The door cannot be opened.\n";
		}
	}

	return 0;
}
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

const int maxn = 100005;
const int maxc = 1000000000;

struct Edge {
	int u, v, c;
	Edge(int u = 0, int v = 0, int c = 0) : u(u), v(v), c(c) {}
};

vector<Edge> edges;
vector<int> G[maxn];

void addEdge(int u, int v, int c)
{
	edges.push_back(Edge(u, v, c));
	int idx = edges.size() - 1;
	G[u].push_back(idx);
}

int n, vis[maxn];
int d[maxn]; // 每个结点i到重点的最短距离d[i]

// 从终点倒着BFS，找到到达n-1的最短路
void revBfs()
{
	memset(vis, 0, sizeof(vis));
	d[n - 1] = 0;
	vis[n - 1] = true; // 访问状态

	queue<int> q;
	q.push(n - 1);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < G[v].size(); i++) {
			int e = G[v][i];
			int u = edges[e].v;
			if (!vis[u]) { // 还没有杯访问过
				vis[u] = true;
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}

vector<int> ans;

// 从起点开始BFS，如果有多种走法，选颜色字典序最小的走
void bfs()
{
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	ans.clear();

	vector<int> next;
	next.push_back(0);
	for (int i = 0; i < d[0]; i++) {
		int minColor = maxc;
		for (int j = 0; j < next.size(); j++) {
			int u = next[j];
			for (int k = 0; k < G[u].size(); k++) {
				int e = G[u][k];
				int v = edges[e].v;
				if (d[u] == d[v] + 1) {
					minColor = min(minColor, edges[e].c);
				}
			}
		}
		ans.push_back(minColor);
		
		// 再一次BFS
		vector<int> next2;
		for (int j = 0; j < next.size(); j++) {
			int u = next[j];
			for (int k = 0; k < G[u].size(); k++) {
				int e = G[u][k];
				int v = edges[e].v;
				if (d[u] == d[v] + 1 &&
					!vis[v] &&
					edges[e].c == minColor) {
					vis[v] = true;
					next2.push_back(v);
				}
			}
		}
		next = next2;
	}

	printf("%d\n", ans.size());
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
}

int main()
{
	int u, v, c, m;
	while (scanf("%d%d", &n, &m) == 2) {
		edges.size();
		for (int i = 0; i < n; i++) {
			G[i].clear();
		}
		while (m--) {
			scanf("%d%d%d", &u, &v, &c);
			addEdge(u - 1, v - 1, c);
			addEdge(v - 1, u - 1, c);
		}
		revBfs();
		bfs();
	}

	return 0;
}
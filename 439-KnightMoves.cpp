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

using namespace std;

const int maxn = 8;
int r1, c1, r2, c2;
int vis[maxn][maxn]; // 记录访问状态

const int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dc[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

struct State
{
	int r, c, cnt;
	State(int r = 0, int c = 0, int cnt = 0) : r(r), c(c), cnt(cnt) {}
	bool operator==(const State& rhs) // 重载==操作符
	{
		return r == rhs.r && c == rhs.c;
	}
};

// 把列也转化成数字来维护
void tr(char* p, int &r, int &c)
{
	r = p[0] - 'a';
	c = p[1] - '1';
}

// bfs求最短路，并维护cnt
int bfs()
{
	State f(r1, c1, 0), t(r2, c2);
	if (f == t) {
		return 0;
	}
	queue<State> q;
	q.push(f);
	vis[r1][c1] = 1;

	while (!q.empty()) {
		State s = q.front();
		q.pop();
		if (s == t) {
			return s.cnt;
		}
		for (int i = 0; i < maxn; i++) {
			int nr, nc;
			nr = s.r + dr[i];
			nc = s.c + dc[i];
			if (nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && !vis[nr][nc]) {
				q.push(State(nr, nc, s.cnt+1));
				vis[nr][nc] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	char p1[3];
	char p2[3];
	while (scanf("%s%s", p1, p2) != EOF) {
		tr(p1, r1, c1);
		tr(p2, r2, c2);
		memset(vis, 0, sizeof(vis));
		int cnt = bfs();
		printf("To get from %s to %s takes %d knight moves.\n", p1, p2, cnt);
	}

	return 0;
}
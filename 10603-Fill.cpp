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

const int maxn = 205;
int a, b, c, d;
int vis[maxn][maxn], cap[3], ans[maxn];
int dist[maxn][maxn];

struct Node {
	int v[3], dist;
	// 为了作为优先队列的基本元素，所以要定义小于号
	bool operator<(const Node& rhs) const {
		return dist > rhs.dist;
	}
};

void updateAns(const Node& u) {
	for (int i = 0; i < 3; i++) {
		int d = u.v[i];
		if (ans[d] < 0 || u.dist < ans[d]) {
			ans[d] = u.dist;
		}
	}
}

void solve()
{
	cap[0] = a;
	cap[1] = b;
	cap[2] = c;
	memset(vis, 0, sizeof(vis));
	memset(ans, -1, sizeof(ans));
	memset(dist, -1, sizeof(dist));
	priority_queue<Node> q;

	Node start;
	start.dist = 0;
	start.v[0] = 0;
	start.v[1] = 0;
	start.v[2] = c;
	q.push(start);

	dist[0][0] = 0;
	// bfs
	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		if (vis[u.v[0]][u.v[1]]) {
			continue;
		}
		vis[u.v[0]][u.v[1]] = 1;

		updateAns(u);
		if (ans[d] >= 0) {
			break;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i != j) {
					if (u.v[i] == 0 || u.v[j] == cap[j]) {
						continue;
					}
					int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];
					Node u2;
					memcpy(&u2, &u, sizeof(u));
					u2.dist = u.dist + amount;
					u2.v[i] -= amount;
					u2.v[j] += amount;
					int& D = dist[u2.v[0]][u2.v[1]];
					if (D < 0 || u2.dist < D) {
						D = u2.dist;
						q.push(u2);
					}
				}
			}
		}
	}
	while (d >= 0) {
		if (ans[d] >= 0) {
			cout << ans[d] << ' ' << d << endl;
			return;
		}
		d--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		solve();
	}

	return 0;
}
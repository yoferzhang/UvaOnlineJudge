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

const int maxn = 1005;

struct Seg {
	int lef, rig;
	Seg(int lef, int rig) : lef(lef), rig(rig) {}
};

queue<Seg> q;
vector<int> v[maxn];

int bfs[maxn], dfs[maxn];
int n;

void solve()
{
	// 整个数先入队
	q.push(Seg(0, n));
	int p = 1;
	int root;
	while (!q.empty()) {
		Seg s = q.front();
		q.pop();
		if (s.rig - s.lef <= 1 || p == n) {
			continue;
		}

		root = dfs[s.lef];
		int pre = s.lef + 1; // 分离根结点
		// 在dfs中往下找子树
		for (int i = pre; i < s.rig; i++) {
			if (dfs[i] == bfs[p]) {
				q.push(Seg(pre, i));
				v[root].push_back(dfs[i]);
				p++;
				pre = i;
			}
		}
		if (pre < s.rig) {
			q.push(Seg(pre, s.rig));
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> bfs[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> dfs[i];
		}
		solve();
		for (int i = 1; i <= n; i++) {
			cout << i << ":";
			for (int j = 0; j < v[i].size(); j++) {
				cout << " " << v[i][j];
			}
			cout << endl;
			v[i].clear();
		}

	}

	return 0;
}
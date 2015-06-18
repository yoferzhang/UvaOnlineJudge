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
const double W = 1000.0;

int n, vis[maxn];
double x[maxn], y[maxn], r[maxn], leftP, rightP;
bool flag;

// 判断c1和c2是否相交
bool intersect(int c1, int c2)
{
	return sqrt((x[c1] - x[c2]) * (x[c1] - x[c2]) + (y[c1] - y[c2]) * (y[c1] - y[c2])) < r[c1] + r[c2];
}

void checkCircle(int u)
{
	if (x[u] - r[u] < 0) {
		leftP = min(leftP, y[u] - sqrt(r[u] * r[u] - x[u] * x[u]));
	}
	if (x[u] + r[u] > W) {
		rightP = min(rightP, y[u] - sqrt(r[u] * r[u] - (W - x[u]) * (W - x[u])));
	}
}

// 能不能到达底部
bool dfs(int u)
{
	if (vis[u]) {
		return false;
	}
	vis[u] = 1;
	if (y[u] - r[u] < 0) {
		return true;
	}
	for (int v = 0; v < n; v++) {
		if (intersect(u, v) && dfs(v)) {
			return true;
		}
	}
	checkCircle(u);
	return false;
}

int main()
{
	while (scanf("%d", &n) == 1) {
		flag = true;
		leftP = rightP = W; 
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		}
		for (int i = 0; i < n; i++) {
			if (y[i] + r[i] >= W && dfs(i)) { // 从上面开始dfs
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("0.00 %.2lf %.2lf %.2lf\n", leftP, W, rightP);
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
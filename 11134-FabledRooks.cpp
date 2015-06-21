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

const int maxn = 5005;

struct Edge
{
	int l, r, id;
}edgeX[maxn], edgeY[maxn];

int ansX[maxn], ansY[maxn];
set<int> setX, setY;

bool camp(Edge a, Edge b)
{
	return a.r < b.r;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int xl, yl, xr, yr;
	while (cin >> n && n) {
		setX.clear();
		setY.clear();
		for (int i = 1; i <= n; i++) {
			cin >> xl >> yl >> xr >> yr;
			edgeX[i].l = xl;
			edgeX[i].r = xr;
			edgeY[i].l = yl;
			edgeY[i].r = yr;
			edgeX[i].id = edgeY[i].id = i;
			setX.insert(i);
			setY.insert(i);
		}
		setX.insert(10000000);
		setY.insert(10000000);
		// 把区间按照又边界排序
		sort(edgeX + 1, edgeX + n + 1, camp);
		sort(edgeY + 1, edgeY + n + 1, camp);

		bool flag = false;
		for (int i = 1; i <= n && !flag; i++) {
			int tmpX = *setX.lower_bound(edgeX[i].l);
			if (tmpX > edgeX[i].r) { // 越界，标记退出
				flag = true;
			}
			ansX[edgeX[i].id] = tmpX;
			setX.erase(tmpX);

			int tmpY = *setY.lower_bound(edgeY[i].l);
			if (tmpY > edgeY[i].r) { // 越界，标记退出
				flag = true;
			}
			ansY[edgeY[i].id] = tmpY;
			setY.erase(tmpY);
		}
		if (flag) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for (int i = 1; i <= n; i++) {
			cout << ansX[i] << " " << ansY[i] << endl;
		}
	}

	return 0;
}
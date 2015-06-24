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

double L, D;
int n;

struct interval
{
	double l, r;
	interval(const double &x, const double &y) {
		double R = sqrt(D * D - y * y);
		l = max(x - R, 0.0);
		r = min(x + R, L);

	}
	// 为了使用sort，所以这里重载定义了操作符<
	bool operator<(const interval &x) const {
		return r == x.r ? l > x.l : r < x.r;
	}
};

vector<interval> inter;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> L) {
		cin >> D >> n;
		inter.clear();
		double x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			inter.push_back(interval(x, y));
		}

		sort(inter.begin(), inter.end());
		int cnt = 1;
		double pos = inter[0].r;
		for (int i = 0; i < inter.size(); i++) {
			if (pos <= inter[i].r && pos >= inter[i].l) {
				continue;
			}
			// 当出现不相交的区间时，点数就要增加了
			pos = inter[i].r;
			cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}
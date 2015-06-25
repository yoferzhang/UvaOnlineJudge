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

const int maxn = 100005;
const double eps = 1e-10;

typedef pair<int, int>  Pair;
vector<Pair> interval;
int n;

double ret;
void cal()
{
	double l = 0, r = 1000000, mid;
	ret = 0;
	for (int it = 0; it < 100; it++) {
		mid = (l + r) / 2; // 二分
		double left = 0;
		bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			if (interval[i].first > left) {
				left = interval[i].first;
			}
			if (left + mid > interval[i].second) {
				ok = false;
			}
			left += mid;
		}
		if (ok) {
			l = mid;
			ret = mid;
		}
		else {
			r = mid;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		interval.clear();
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			interval.push_back(make_pair(x, y));
		}
		sort(interval.begin(), interval.end()); // 按照左端点排序，从小到大

		cal(); // 计算最优方案

		// 计算分数形式
		int rp = 0, rq = 1;
		for (int p, q = 1; q <= n; q++) {
			p = round(ret * q);
			if (fabs((double)p / q - ret) < fabs((double)rp / rq - ret)) {
				rp = p;
				rq = q;
			}
		}

		cout << rp << "/" << rq << endl;
	}

	return 0;
}
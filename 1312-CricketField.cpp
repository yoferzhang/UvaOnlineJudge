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

struct Pt
{
	int x, y;
	Pt(int a = 0, int b = 0) : x(a), y(b) {}
}tree[110];

int n, w, h;
int P, Q, L;

// 按横坐标排序用
bool cmpx(Pt a, Pt b)
{
	if (a.x != b.x) {
		return a.x < b.x;
	}
	return a.y < b.y;
}

// 按纵坐标排序用
bool cmpy(Pt a, Pt b)
{
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

void solve()
{
	P = Q = L = 0;
	// 横向枚举
	sort(tree, tree + n, cmpx);
	for (int i = 0; i < n; i++) {
		int mny = 0, mxy = h;
		for (int j = i + 1; j < n; j++) {
			int l = min(tree[j].x - tree[i].x, mxy - mny); // 可以构成的最大正方形变长
			if (l > L) { 
				P = tree[i].x;
				Q = mny;
				L = l;
			}
			if (tree[j].x == tree[i].x) { // 在同一列失败
				continue;
			}
			if (tree[j].y > tree[i].y) {
				mxy = min(mxy, tree[j].y);
			}
			else {
				mny = max(mny, tree[i].y);
			}
		}
	}

	// 纵向枚举
	sort(tree, tree + n, cmpy);
	for (int i = 0; i < n; i++) {
		int mnx = 0, mxx = w;
		for (int j = i + 1; j < n; j++) {
			int l = min(tree[j].y - tree[i].y, mxx - mnx);
			if (l > L) {
				P = mnx;
				Q = tree[i].y;
				L = l;
			}
			if (tree[j].y == tree[i].y) {
				continue;
			}
			if (tree[j].x > tree[i].x) {
				mxx = min(mxx, tree[j].x);
			}
			else {
				mnx = max(mnx, tree[j].x);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		cin >> n >> w >> h;
		for (int i = 0; i < n; i++) {
			cin >> tree[i].x >> tree[i].y;
		}
		// 四个边界也加上树
		tree[n++] = Pt(0, 0);
		tree[n++] = Pt(w, 0);
		tree[n++] = Pt(0, h);
		tree[n++] = Pt(w, h);
		solve();
		if (kase++) {
			cout << endl;
		}
		cout << P << ' ' << Q << ' ' << L << endl;
	}
	

	return 0;
}
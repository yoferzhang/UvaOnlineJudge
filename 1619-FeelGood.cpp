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
typedef long long LL;
const int maxn = 100005;

int n, a[maxn], L[maxn], R[maxn];
// L[i]表示i左边小于第i个元素的第一个元素的位置
// R[i]表示i右边小于第i个元素的第一个元素的位置
LL sum[maxn]; // sum[i]表示前i项和
stack<int> q;

void init()
{
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	a[0] = a[n + 1] = -0x3f3f3f3f;
	while (!q.empty()) {
		q.pop();
	}
	q.push(0);
	for (int i = 1; i <= n; i++) {
		while (a[q.top()] >= a[i]) {
			q.pop();
		}
		L[i] = q.top();
		q.push(i);
	}
	while (!q.empty()) {
		q.pop();
	}
	q.push(n + 1);
	for (int i = n; i; i--) {
		while (a[q.top()] >= a[i]) {
			q.pop();
		}
		R[i] = q.top();
		q.push(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n) {
		if (kase++) {
			cout << endl;
		}
		init();
		LL ans = 0;
		int l, r;
		for (int i = 1; i <= n; i++) {
			LL t = a[i] * (sum[R[i] - 1] - sum[L[i]]);
			if (t > ans) {
				ans = t;
				l = L[i] + 1;
				r = R[i] - 1;
			}
			else if (t == ans && R[i] - L[i] - 1 < r - l + 1) {
				l = L[i] + 1;
				r = R[i] - 1;
			}
		}
		if (ans == 0) { // 特殊情况
			cout << "0\n1 1\n";
		}
		else {
			cout << ans << endl << l << ' ' << r << endl;
		}
	}

	return 0;
}
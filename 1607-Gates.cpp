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

const int maxm = 200005;
int n, m;

struct Gates
{
	int a, b, o;
}gates[maxm];

// k个0输入，即000..0111...1这种情况的输出
int output(int k)
{
	for (int i = 1; i <= m; i++) {
		int a = gates[i].a;
		int b = gates[i].b;
		int va = a < 0 ? -a > k : gates[a].o;
		int vb = b < 0 ? -b > k : gates[b].o;
		gates[i].o = !(va && vb);
	}
	return gates[m].o;
}

int solve(int vn)
{
	int L = 1, R = n;
	while (L < R) {
		int mid = L + (R - L) / 2; // 二分1的个数
		if (output(mid) == vn) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}
	return L;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> gates[i].a >> gates[i].b;
		}
		int v0 = output(0);
		int vn = output(n);
		if (v0 == vn) { // 相同，那么整个电路就是常数
			for (int i = 1; i <= n; i++) {
				cout << "0";
			}
		}
		else {
			int x = solve(vn);
			for (int i = 1; i < x; i++) {
				cout << "0";
			}
			cout << "x";
			for (int i = x + 1; i <= n; i++) {
				cout << "1";
			}
		}
		cout << endl;
	}

	return 0;
}
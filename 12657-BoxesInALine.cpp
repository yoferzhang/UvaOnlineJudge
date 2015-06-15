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

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
const int maxn = 100005;
int n;
int rightP[maxn], leftP[maxn];

void link(int L, int R)
{
	rightP[L] = R;
	leftP[R] = L;
}

int main()
{
	int m, kase = 0;
	while (scanf("%d%d", &n, &m) == 2 && kase < 10) {
		for (int i = 1; i <= n; i++) { // 初始化n个盒子
			leftP[i] = i - 1;
			rightP[i] = (i + 1) % (n + 1);
		}
		rightP[0] = 1;
		leftP[0] = n;
		int op, x, y, inv = 0;

		
		while (m--) {
			scanf("%d", &op);
			if (op == 4) { // 4不需要再读取了
				inv = !inv;
			}
			else {
				scanf("%d%d", &x, &y);
				if (op == 3 && rightP[y] == x) {
					swap(x, y);
				}
				if (op != 3 && inv) {
					op = 3 - op;
				}
				if (op == 1 && x == leftP[y]) {
					continue;
				}
				if (op == 2 && x == rightP[y]) {
					continue;
				}

				int lx = leftP[x], rx = rightP[x], ly = leftP[y], ry = rightP[y];
				if (op == 1) {
					link(lx, rx);
					link(ly, x);
					link(x, y);
				}
				else if (op == 2) {
					link(lx, rx);
					link(y, x);
					link(x, ry);
				}
				else if (op == 3) {
					if (rightP[x] == y) {
						link(lx, y);
						link(y, x);
						link(x, ry);
					}
					else {
						link(lx, y);
						link(y, rx);
						link(ly, x);
						link(x, ry);
					}
				}
			}
		
		}
		int b = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++) { // 从左到右求出奇数和
			b = rightP[b];
			if (i % 2 == 1) {
				ans += b;
			}
		}
		// 如果长度为偶数，并处于反转状态，则用总和减去ans
		if (inv && n % 2 == 0) {
			ans = (long long)n * (n + 1) / 2 - ans;
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}

	return 0;
}
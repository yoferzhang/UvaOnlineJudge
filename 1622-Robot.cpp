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

int main()
{
	ios::sync_with_stdio(false);
	LL n, m, t = 0;
	while (cin >> n >> m && m){
		LL cn, cs, cw, ce, ans = 0;
		cin >> cn >> cs >> cw >> ce;
		if (cn < cs) {
			swap(cs, cn); // s.t. cw>=ce
		}
		if (cw < ce) {
			swap(ce, cw); // s.t. cn >= cs
		}
		LL t1 = n + (m - 1) * n * ce * 2 + (m - 1) + (m - 1) * (n - 1) * cs * 2;
		LL t2 = m + m * (n - 1) * cs * 2 + (n - 1) + (m - 1) * (n - 1) * ce * 2;//判断是否需要交换。
		if (cw - ce) {
			t1 += (m - 1) * n;
			t2 += (m - 1) * (n - 1);
		}
		if (cn - cs) {
			t1 += (m - 1) * (n - 1);
			t2 += m * (n - 1);
		}
		if (t1 < t2) {
			swap(m, n);
			swap(cn, cw);
			swap(cs, ce);
		}
		if (ce) { // 先东西来回
			ans += n + (m - 1) * n * ce * 2;
			cw -= ce;
			ce = 0;
			m--;
		}
		if (cw) {
			ans += m * n;
			cw--;
		}
		cw = min(m, cw);
		while (cw || cn){
			if (cs){ // 判断是否开始进行南北移动。
				LL t1 = m * n + (n - 1) * m * 2 * cs;
				LL t2 = m * n + (m - 1) * n + (m - 1) * (n - 1) * (2 * cs - 1);
				if (cn - cs) {
					t1 = m * n + (n - 1) * m * (2 * cs + 1);
					t2 = m * n + (m - 1) * n + (m - 1) * (n - 1) * 2 * cs;
				}
				if (t1 > t2 || !cw){ // cw为0时也要执行南北移动。
					ans += m + m * (n - 1) * cs * 2;
					cn -= cs;
					cs = 0;
					n--;
					if (cn) {
						ans += m * n;
						cn--;
					}
					cn = min(n, cn);
				}
				else {
					ans += m * n;
					m--;
					cw--;
				}
			}
			else if (!cw) {
				ans += m * cn * (2 * n - cn + 1) / 2;
				cn = 0;
			}
			else if (!cn) {
				ans += n * cw * (2 * m - cw + 1) / 2;
				cw = 0;
			}
			else{
				ans += m * n;
				if (m > n) {
					m--;
					cw--;
				}
				else {
					n--, cn--;
				}
			}
		}
		cout << "Case " << ++t << ": " << ans << endl;
	}
	return 0;
}
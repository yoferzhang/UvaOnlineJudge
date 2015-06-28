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

const int maxn = 1005;

int H[maxn];

int main() {
	ios::sync_with_stdio(false);
	int LX, RX, N;
	while (cin >> LX >> RX && LX) {
		N = (RX - LX) / 2 + 1; // 挡板的个数
		int LH = 0, RH = 0, LHpos = -1, RHpos = -1;
		int l = (-1 - LX) / 2, r = (-1 - LX) / 2 + 1;
		int ret = 0;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
			if (i <= l && LH <= H[i]) { // 求左边最高的挡板中最靠近中间的
				LH = H[i];
				LHpos = i;
			}
			if (i >= r && RH < H[i]) { // 求右边最高的挡板中最靠近中间的
				RH = H[i];
				RHpos = i;
			}
		}
		if (LH == RH) {
			int lcost = 0, rcost = 0;
			for (int i = 0, j = 0; i < LHpos; i++) {
				j = max(j, H[i]);
				lcost += j;
			}
			for (int i = N - 1, j = 0; i > RHpos; i--) {
				j = max(j, H[i]);
				rcost += j;
			}
			ret = (RHpos - LHpos) * RH * 2 + min(lcost, rcost) * 2 * 2;
			cout << ret << endl;
		}
		else {
			int v = min(LH, RH);
			int lcost = 0, rcost = 0;
			while (H[l] < v)    l--;
			while (H[r] < v)    r++;
			if (RH > LH) {
				for (int i = r, j = H[i]; H[i] <= LH; i++) {
					rcost += j;
					j = max(j, H[i + 1]);
				}
				for (int i = 0, j = H[0]; i < l; i++) {
					lcost += j;
					j = max(j, H[i + 1]);
				}
			}
			else {
				for (int i = l, j = H[i]; H[i] <= RH; i--) {
					rcost += j;
					j = max(j, H[i - 1]);
				}
				for (int i = N - 1, j = H[N - 1]; i > r; i--) {
					lcost += j;
					j = max(j, H[i - 1]);
				}
			}
			ret = (lcost > rcost ? lcost + rcost : 2 * lcost) * 2;
			ret += (r - l) * v * 2;
			cout << ret << endl;
		}
	}
	return 0;
}
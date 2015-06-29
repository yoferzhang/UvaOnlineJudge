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

int g[305][305], gt[305];
int invg[305][305], invgt[305], to[305];
int n, m;

bool check() {
	int j, k;
	for (int i = n - 1; i >= 0; i--) {
		for (j = 0; j < n; j++)  to[j] = 0;
		for (j = invgt[i] - 1; j >= 0; j--) {
			for (k = gt[invg[i][j]] - 1; k >= 0; k--) {
				to[g[invg[i][j]][k]]++;
			}
		}
		for (j = 0; j < n; j++) {
			if (to[j] == 0 || to[j] == invgt[i]) {
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	int kase= 0;
	int T;
	cin >> T;
	while (T--) {
		memset(gt, 0, sizeof(gt));
		memset(invgt, 0, sizeof(gt));
		cin >> n >> m;
		int x, y;
		while (m--) {
			cin >> x >> y;
			g[x][gt[x]++] = y;
			invg[y][invgt[y]++] = x;
		}
		bool flag = check();
		cout << "Case #" << ++kase << ": " << (flag ? "Yes\n" : "No\n");
	}
	return 0;
}
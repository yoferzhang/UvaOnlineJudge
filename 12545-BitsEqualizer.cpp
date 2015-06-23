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

const int maxn = 105;
int oneVzero, zeroVone, qVone, qVzero;
int ans;
string S, T;

void solve()
{
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '1' && T[i] == '0') {
			oneVzero++;
		}
		else if (S[i] == '0' && T[i] == '1') {
			zeroVone++;
		}
		else if (S[i] == '?' && T[i] == '0') {
			qVzero++;
		}
		else if (S[i] == '?' && T[i] == '1') {
			qVone++;
		}
	}

	while (oneVzero && zeroVone) { // 交换1-0和0-1
		oneVzero--;
		zeroVone--;
		ans++;
	}
	while (oneVzero && qVone) { // 交换1-0和？-1
		oneVzero--;
		qVone--;
		ans += 2;
	}
	if (oneVzero) {
		ans = -1;
	}
	else {
		ans += zeroVone + qVone + qVzero;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int C;
	cin >> C;
	int kase = 0;
	while (C--) {
		cin >> S >> T;

		// 初始化
		ans = 0;
		oneVzero = zeroVone = qVzero = qVone = 0;
		solve();
		cout << "Case " << ++kase << ": " << ans << endl;
	}

	return 0;
}
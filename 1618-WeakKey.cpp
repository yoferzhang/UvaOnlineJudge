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

const int maxn = 5005;
int num[maxn], l[maxn][maxn], r[maxn][maxn];
// l[i][j]表示下标小于j且值比Ni大的数中最小值的位置
// r[i][j]表示下标大于j且值比Ni小的数中最大值的位置
int k;

bool solve()
{
	for (int i = 1; i <= k; i++) {
		l[i][0] = 0;
		for (int j = 1; j < i; j++) { // 枚举Nq和Nr,找Np
			if (num[i] >= num[j]) {
				l[i][j] = l[i][j - 1];
			}
			else if (!l[i][j - 1] || num[j] < num[l[i][j - 1]]) {
				l[i][j] = j;
			}
			else {
				l[i][j] = l[i][j - 1];
			}
		}
			
	}

	for (int i = 1; i <= k; i++) {
		r[i][k + 1] = 0;
		for (int j = k; j > i; j--) {// 枚举Nq和Nr,找Ns
			if (num[i] <= num[j]) {
				r[i][j] = r[i][j + 1];
			}
			else if (!r[i][j + 1] || num[j] > num[r[i][j + 1]]) {
				r[i][j] = j;
			}
			else {
				r[i][j] = r[i][j + 1];
			}
		}
	}

	//i是q,j是r
	for (int i = 1; i <= k; i++) {
		for (int j = i + 1; j <= k; j++) {
			if (!l[j][i - 1] || !r[i][j + 1] || num[i] <= num[j]) {
				continue;
			}
			int p = l[j][i - 1], s = r[i][j + 1];
			if (num[j] < num[p] && num[p] < num[s] && num[s] < num[i]) {
				return true;
			}
		}
	}		
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> num[i];
		}

		if (solve()) {
			cout << "YES\n";
		}
		else {
			reverse(num + 1, num + k + 1);
			if (solve()) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}
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

using namespace std;

const int maxn = 4005;
int n, c, A[maxn], B[maxn], C[maxn], D[maxn], sums[maxn * maxn];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> A[i] >> B[i] >> C[i] >> D[i];
		}
		c = 0;
		// ö��a��b
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sums[c++] = A[i] + B[j];
			}
		}
		// ����sums����Ҫһ����������
		sort(sums, sums + c);
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cnt += upper_bound(sums, sums + c, -C[i] - D[j]) 
					- lower_bound(sums, sums + c, -C[i] - D[j]);
			}
		}
		cout << cnt << endl;
		if (T) {
			cout << endl;
		}
	}

	return 0;
}
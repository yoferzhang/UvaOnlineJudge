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

const int maxn = 100005;
pair<int, int> A[maxn];
int n;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> A[i].first;
			A[i].second = i;
			sum += A[i].first;
		}

		int ans[maxn];
		if (sum % 2) { // 如果和是奇数，无解
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
			sum /= 2;
			sort(A, A + n);
			for (int i = n - 1; i >= 0; i--) { // 从大到小贪心求解
				if (sum >= A[i].first) {
					sum -= A[i].first;
					ans[A[i].second] = 1;
				}
				else {
					ans[A[i].second] = -1;
				}
			}
			cout << ans[0];
			for (int i = 1; i < n; i++) {
				cout << ' ' << ans[i];
			}
			cout << endl;
		}
	}

	return 0;
}
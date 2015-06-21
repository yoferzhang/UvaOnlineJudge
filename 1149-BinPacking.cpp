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
int lengthOfItems[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		if (kase++) {
			cout << endl;
		}
		int n, l;
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> lengthOfItems[i];
		}

		sort(lengthOfItems, lengthOfItems + n);
		int p1 = 0, p2 = n - 1, cnt = 0;
		// 贪心算法
		while (p1 <= p2) {
			if (p1 == p2) { // 剩下一个了
				cnt++;
				break;
			}
			else if (lengthOfItems[p1] + lengthOfItems[p2] <= l) { // 大加小，小于容量限制，可以放到同一个背包中
				cnt++;
				p1++;
				p2--;
			}
			else { // 只把大的放到一个背包中
				cnt++;
				p2--;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
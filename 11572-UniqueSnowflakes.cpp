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

const int maxn = 1000005;
int snowflakes[maxn];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> snowflakes[i];
		}
		// 存放当前序列的所有元素
		set<int> s;
		int letfP = 0, rightP = 0, ans = 0;
		while (rightP < n) {
			while (rightP < n && !s.count(snowflakes[rightP])) {
				s.insert(snowflakes[rightP++]);
			}
			ans = max(ans, rightP - letfP);
			s.erase(snowflakes[letfP++]); // 增大左边界
		}
		cout << ans << endl;
	}

	return 0;
}
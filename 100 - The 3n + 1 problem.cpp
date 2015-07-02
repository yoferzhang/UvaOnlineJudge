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

int n, m;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n)
	{
		cin >> m;
		cout << n << ' ' << m << ' ';
		int ans = 1;
		if (n > m) { // ×¢ÒâÊäÈëµÄÏİÚå
			swap(n, m);
		}
		for (n; n <= m; n++) {
			int t = 1;
			int i = n;
			while (i != 1) {
				i = (i % 2 ? 3 * i + 1 : i / 2);
				t++;
			}
			ans = max(ans, t);
		}
		cout << ans << endl;
	}

	return 0;
}
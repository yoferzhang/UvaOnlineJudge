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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n) {
		long long ans = 0, a, last = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			ans += abs(last);
			last += a;
		}
		cout << ans << endl;
	}

	return 0;
}
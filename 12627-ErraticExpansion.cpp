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

long long c(int k)
{
	return k == 0 ? 1 : c(k - 1) * 3;
}

long long f(int k, int i)
{
	if (i == 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}

	int k2 = 1 << (k - 1); // 2的k-1次方
	if (i >= k2) {
		return f(k - 1, i - k2) + c(k - 1) * 2;
	}
	else {
		return f(k - 1, i) * 2;
	}
}

long long g(int k, int i)
{
	if (i == 0) {
		return 0;
	}
	if (k == 0) {
		return 1;
	}

	int k2 = 1 << (k - 1); // 2的k-1次方
	if (i >= k2) {
		return 2 * g(k - 1, i - k2) + c(k - 1);
	}
	else {
		return g(k - 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		int k, a, b;
		cin >> k >> a >> b;
		cout << "Case " << ++kase << ": ";
		//cout << f(k, b) - f(k, a - 1) << endl;
		cout << g(k, (1 << k) - a + 1) - g(k, (1 << k) - b) << endl;
	}

	return 0;
}
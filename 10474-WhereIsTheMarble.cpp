#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int main()
{
	int n, q, x, a[maxn], kase = 0;
	while (scanf("%d%d", &n, &q) == 2 && n) {
		
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n); // ÅÅÐò
		printf("CASE# %d:\n", ++kase);
		while (q--) {
			scanf("%d", &x);
			int p = lower_bound(a, a + n, x) - a;
			if (a[p] == x) {
				printf("%d found at %d\n", x, p + 1);
			}
			else {
				printf("%d not found\n", x);
			}
		}
	}

	return 0;
}
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
int s[maxn];

int main()
{
	int n, d;
	while (scanf("%d%d%*c", &n, &d) && n) {
		int t = 0;
		int a;
		d = n - d;
		for (int i = 0; i < n; i++) {
			a = getchar() - '0';
			while (t && t + n - i > d && a > s[t - 1]) {
				t--;
			}
			if (t < d) {
				s[t++] = a;
			}
		}
		for (int i = 0; i < t; i++) {
			printf("%d", s[i]);
		}
		printf("\n");
	}

	return 0;
}
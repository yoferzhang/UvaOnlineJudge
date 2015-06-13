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

using namespace std;

int a[500005];
int b[500005];

int main()
{
	int n;
	while (cin >> n && n) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		sort(a, a + n);
		sort(b, b + n);
		int flag = 0;
		// 排序之后比较是否相等
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}
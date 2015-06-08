#include <stdio.h>
#include <string.h>
const int MAXN = 100005;
int ans[MAXN]; // 数组比较大的情况下，就将数组放在堆中

int main()
{
	int T, n;
	memset(ans, 0, sizeof(ans));
	// 先用循环遍历，枚举出100000以内的所有正整数的最小生成元
	for (int m = 1; m < MAXN; m++) {
		int x = m, y = m;
		while (x) {
			y += x % 10;
			x /= 10;
		}
		if ((ans[y] == 0) || m < ans[y]) {
			ans[y] = m;
		}
	}
	scanf("%d", &T);
	// 最后这里直接查表即可
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;
}
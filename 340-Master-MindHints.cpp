#include <stdio.h>
const int MAXN = 1010;

int main()
{
	int n, a[MAXN], b[MAXN];
	while (scanf("%d", &n) == 1 && n) { // n等于0的时候结束
		int aNumberCount[10] = { 0 }; // 记录输入中的每个数字出现的次数
		for (int i = 0; i < n; i++) {
			scanf("%d", a[i]);
			aNumberCount[a[i]]++;
		}
		while (1) {
			int A = 0, B = 0; // A记录
		}
	}
}
#include <stdio.h>
const int MAXN = 1010;

int main()
{
	int n, a[MAXN], b[MAXN];
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) { // n等于0的时候结束
		printf("Game %d:\n", ++kase);
		int aNumberCount[10] = { 0 }; // 记录输入中的每个数字出现的次数
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			aNumberCount[a[i]]++;
		}
		while (1) {
			// A记录位置正确，B记录位置不对的情况，不过B要减去A才是真正的结果
			int A = 0, B = 0; 
			int bNumberCount[10] = { 0 };
			for (int i = 0; i < n; i++) {
				scanf("%d", &b[i]);
				if (b[i] == a[i]) {
					A++;
				}
				bNumberCount[b[i]]++;
			}
			if (b[0] == 0) {
				break;
			}
			for (int i = 1; i < 10; i++) {
				aNumberCount[i] < bNumberCount[i] ? B += aNumberCount[i] : B += bNumberCount[i];
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
}
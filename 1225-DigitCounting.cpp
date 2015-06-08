#include <cstdio>
#include <cstring>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)	{
		int count[10] = { 0 }; // 记录每个数字出现的次数
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int m = i;
			while (m) {
				count[m % 10]++;
				m /= 10;
			}
		}
		for (int i = 0; i < 9; i++) {
			printf("%d ", count[i]);
		}
		printf("%d\n", count[9]);
	}

	return 0;
}
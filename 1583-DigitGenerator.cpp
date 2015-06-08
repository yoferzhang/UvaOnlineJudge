#include <stdio.h>
#include <string.h>
const int MAXN = 100005;
int ans[MAXN]; // ����Ƚϴ������£��ͽ�������ڶ���

int main()
{
	int T, n;
	memset(ans, 0, sizeof(ans));
	// ����ѭ��������ö�ٳ�100000���ڵ���������������С����Ԫ
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
	// �������ֱ�Ӳ����
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}

	return 0;
}
#include <stdio.h>
const int MAXN = 1010;

int main()
{
	int n, a[MAXN], b[MAXN];
	while (scanf("%d", &n) == 1 && n) { // n����0��ʱ�����
		int aNumberCount[10] = { 0 }; // ��¼�����е�ÿ�����ֳ��ֵĴ���
		for (int i = 0; i < n; i++) {
			scanf("%d", a[i]);
			aNumberCount[a[i]]++;
		}
		while (1) {
			int A = 0, B = 0; // A��¼
		}
	}
}
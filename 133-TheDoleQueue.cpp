#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, m;
int a[25];

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) && n) {
		// �ǵ���գ���Ȼ�����Ŀ�����û��ʲôӰ��
		memset(a, 0, sizeof(a));
		// ����ղ���Ӱ����������Ϊ���ｫ��Ҫ�õ��Ķ����¸�ֵ��
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		// ʣ�µ�����
		int leftPeople = n;
		int pa = n, pb = 1;
		while (leftPeople) {
			// �������µı�������Ҫ�ı�k��m
			int ka = k;
			int mb = m;
			while (ka--) {
				pa = (pa + n) % n + 1;
				while (a[pa] == 0) {
					pa = (pa + n) % n + 1;
				}
			}
			while (mb--) {
				pb = (pb - 2 + n) % n + 1;
				while (a[pb] == 0) {
					pb = (pb - 2 + n) % n + 1;
				}
			}
			printf("%3d", pa);
			leftPeople--;
			if (pa != pb) {
				printf("%3d", pb);
				leftPeople--;
			}
			a[pa] = a[pb] = 0;
			if (leftPeople) {
				printf(",");
			}
		}
		printf("\n");
	}

	return 0;
}
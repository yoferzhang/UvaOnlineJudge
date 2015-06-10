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
		// 记得清空，虽然这道题目不清空没有什么影响
		memset(a, 0, sizeof(a));
		// 不清空不会影响结果，是因为这里将需要用到的都重新赋值了
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		// 剩下的人数
		int leftPeople = n;
		int pa = n, pb = 1;
		while (leftPeople) {
			// 用两个新的变量，不要改变k和m
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
#include <cstdio>
#include <cstring>
#include <ctype.h>
#define M 55
#define N 1005

char dna[M][N];
int cnt[M];
int main()
{
	int T;
	scanf("%d", &T);
	int m, n;
	while (T--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			scanf("%s", dna[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int Max = 0, id;
			memset(cnt, 0, sizeof(cnt));
			for (int j = 0; j < m; j++) {
				int tmp = dna[j][i] - 'A';
				cnt[tmp]++;
				if (cnt[tmp] > Max) {
					Max = cnt[tmp];
					id = tmp;
				}
				else if (cnt[tmp] == Max && tmp < id)
					id = tmp;
			}
			ans += m - Max;
			printf("%c", 'A' + id);
		}
		printf("\n%d\n", ans);
	}

	return 0;
}
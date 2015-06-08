#include <stdio.h>
#include <string.h>
#define MAXN 85

int main()
{
	int T;
	char s[MAXN];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		// p=0表示上个字符是x
		int score = 0, p = 0, q = 1;
		for (int i = 0; i < n; i++) {
			// 不是很明确字母o是大写还是小写，两种情况都考虑
			if (s[i] == 'o' || s[i] == 'O') {
				if (p == 0) {
					score += q++;
					p = 1;
				}
				else {
					score += q++;
				}
			}
			else {
				p = 0;
				q = 1;
			}
		}
		printf("%d\n", score);
	}

	return 0;
}
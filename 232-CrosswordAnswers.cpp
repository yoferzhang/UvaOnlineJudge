#include <cstdio>
#include <cstring>
#include <ctype.h>

char s[15][15];
int eligible[15][15] = { 0 };

int main()
{
	int r, c;
	int cases = 0;
	while (~scanf("%d", &r) && (r != 0)) {
		// 一定要注意清空
		memset(eligible, 0, sizeof(eligible));
		scanf("%d", &c);
		for (int i = 0; i < r; i++) {
			scanf("%s", s[i]);
		}
		int m = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (isalpha(s[i][j])) {
					if ((i == 0) || (j == 0) || (s[i - 1][j] == '*') || (s[i][j - 1] == '*')) {
						eligible[i][j] = m++;
					}
				}
			}
		}
		if (cases++) printf("\n");
		printf("puzzle #%d:\n", cases);
		printf("Across\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (eligible[i][j] != 0 && ((s[i][j - 1] == '*') || j == 0)) {
					printf("%3d.%c", eligible[i][j], s[i][j]);
					for (int k = j + 1; k < c; k++) {
						if (isalpha(s[i][k])) {
							printf("%c", s[i][k]);
						}
						else {
							break;
						}
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((eligible[i][j] != 0) && ((s[i - 1][j] == '*') || i == 0)) {
					printf("%3d.%c", eligible[i][j], s[i][j]);
					for (int k = i + 1; k < r; k++) {
						if (isalpha(s[k][j])) {
							printf("%c", s[k][j]);
						}
						else {
							break;
						}
					}
					printf("\n");
				}
			}
		}
		
	}

	return 0;
}
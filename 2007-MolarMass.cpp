#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 100

// 判断字符ch是哪一个元素符号
double mass(char ch) {
	switch (ch)
	{
	case 'C':
		return 12.01;
	case 'H':
		return 1.008;
	case 'O':
		return 16.00;
	case 'N':
		return 14.01;
	}
}

int main()
{
	int T;
	char s[MAXN];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		double molarMass = 0.0;
		int i = 0;
		while (i < n) {
			// 分三种情况处理
			if (isalpha(s[i + 1]) || i == n - 1) {
				molarMass += mass(s[i]);
				i++;
			}
			else if (isdigit(s[i + 1]) && isalpha(s[i + 2])) {
				molarMass += mass(s[i]) * (s[i + 1] - '0');
				i += 2;
			}
			else {
				molarMass += mass(s[i]) * ((s[i + 1] - '0') * 10 + (s[i + 2] - '0'));
				i += 3;
			}
		}
		printf("%.3lf\n", molarMass); // 注意只需要保留小数点后3位
	}
	return 0;
}
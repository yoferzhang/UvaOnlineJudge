#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXN 100

// �ж��ַ�ch����һ��Ԫ�ط���
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
			// �������������
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
		printf("%.3lf\n", molarMass); // ע��ֻ��Ҫ����С�����3λ
	}
	return 0;
}
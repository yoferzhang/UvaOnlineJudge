#include <stdio.h>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
	int i, c;
	while ((c = getchar()) != EOF) {
		for (i = 1; s[i] && (s[i] != c); i++); // �Ҵ�λ֮����ַ��ڳ������е�λ��
		if (s[i]) {
			putchar(s[i - 1]); // ����ҵ������������ǰһ���ַ�
		}
		else {
			putchar(c);
		}
	}

	return 0;
}
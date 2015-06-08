#include <stdio.h>
#include <string.h>
#define MAXN 105

//��״��s�ı�ʾ��p�ȱ�ʾ��q���ֵ���С
int less(const char* s, int p, int q)
{
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		// ѭ���������Խṹ�ǣ��öԳ���ȡ��ķ�ʽ
		if (s[(p + i) % n] != s[(q + i) % n]) {
			return s[(p + i) % n] < s[(q + i) % n];
		}
	}
	return 0; // ���
}

int main()
{
	int T;
	char s[MAXN];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int ans = 0;
		int n = strlen(s);
		for (int i = 1; i < n; i++) {
			if (less(s, i, ans)) {
				ans = i;
			}
		}
		for (int i = 0; i < n; i++) {
			putchar(s[(i + ans) % n]);
		}
		printf("\n");
	}

	return 0;
}
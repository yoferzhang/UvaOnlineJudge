#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdio>

int main()
{
	int n;
	char str[104];
	while (~scanf("%d", &n)) {
		while (n--) {
			scanf("%s", str);
			int len = strlen(str);
			for (int k, i = 1; i <= len; ++i)
				if (len % i == 0) { // �ж�i�Ƿ�����Ϊ������
					for (k = i; k < len; ++k) // �жϺ�����Ƿ�����������
						if (str[k] != str[k % i])
							break;
					if (k == len) {
						printf("%d\n", i);
						break;
					}
				}
			if (n) printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 存放镜像串
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
// 存放输出的文字
const char* msg[] = { "not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome" };

// 判断镜像串的时候需要用到这个函数，找出对应的镜像字符
char r(char ch) {
	if (isalpha(ch)) {
		return rev[ch - 'A'];
	}
	return rev[ch - '0' + 25];
}

int main()
{
	char s[30];
	while (scanf("%s", s) == 1) {
		int len = strlen(s);
		int m = 1, p = 1;
		for (int i = 0; i < (len + 1) / 2; i++) {
			if (r(s[i]) != s[len - 1 - i]) {
				m = 0; // 不是镜像串
			}
			if (s[i] != s[len - 1 - i]) {
				p = 0; // 不是回文串
			}
		}
		printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
	}
	return 0;
}
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
char s[100005], t[100005];
int main()
{
	// 这里不能用scanf，提交会出现RE或者TLE
	while (cin >> s >> t) {
		int bingo = 0;
		int nS = strlen(s);
		int nT = strlen(t);
		int i = 0;
		if (nS <= nT) {
			for (int j = 0; j < nT; j++) {
				if (t[j] == s[i]) {
					bingo++;
					i++;
				}
			}
			if (bingo == nS) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
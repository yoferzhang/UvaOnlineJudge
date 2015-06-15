#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <bitset> 
#include <cassert> 

using namespace std;

const int maxn = 1000;

int leftSide[] = { 4, 0, 2, 3, 5, 1 };
int up[] = { 2, 1, 5, 0, 4, 3 };

char s1[maxn], s2[maxn], s[maxn];

// °´ÕÕTÐý×ªstr
void rot(int *T, char *str) 
{
	char t[maxn];
	strcpy(t, str);
	for (int i = 0; i < 6; i++) {
		str[i] = t[T[i]];
	}
}

bool check()
{
	char t[maxn];
	for (int i = 0; i < 6; i++) {
		strcpy(t, s1);
		if (i == 0) {
			rot(up, t);
		}
		else if (i == 1) {
			rot(leftSide, t);
			rot(up, t);
		}
		else if (i == 3) {
			rot(up, t);
			rot(up, t);
		}
		else if (i == 4) {
			rot(leftSide, t);
			rot(leftSide, t);
			rot(up, t);
		}
		else if (i == 5) {
			rot(leftSide, t);
			rot(leftSide, t);
			rot(leftSide, t);
			rot(up, t);
		}
		for (int i = 0; i < 4; i++) {
			rot(leftSide, t);
			if (strcmp(s2, t) == 0) {
				return 1;
			}
		}
	}
	return 0;
}


int main()
{
	while (gets(s)) {
		for (int i = 0; i < 6; i++) {
			s1[i] = s[i];
		}
		s1[6] = '\0';
		for (int i = 6; i < 12; i++) {
			s2[i - 6] = s[i];
		}
		s2[6] = '\0';

		if (check()) {
			printf("TRUE\n");
		}
		else {
			printf("FALSE\n");
		}
	}

	return 0;
}
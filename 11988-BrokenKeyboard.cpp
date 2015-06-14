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

const int maxn = 100005;
int last, cur, nextP[maxn]; // 光标在cur号字符后面
char s[maxn];

int main()
{
	while (scanf("%s", s + 1) == 1) {
		int n = strlen(s + 1);
		last = cur = 0;
		nextP[0] = 0;

		for (int i = 1; i <= n; i++) {
			char ch = s[i];
			if (ch == '[') {
				cur = 0;
			}
			else if (ch == ']') {
				cur = last;
			}
			else {
				nextP[i] = nextP[cur];
				nextP[cur] = i;
				if (cur == last) { // 更新最后一个字符编号
					last = i;
				}
				cur = i; // 移动光标
			}
		}
		
		for (int i = nextP[0]; i != 0; i = nextP[i]) {
			printf("%c", s[i]);
		}
		cout << endl;
	}

	return 0;
}
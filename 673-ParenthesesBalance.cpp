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
#include <cmath>

using namespace std;

const int maxn = 256;

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) {
		char str[maxn];
		fgets(str, sizeof(str), stdin);
		bool flag = true;
		stack<char> stc;
		for (int i = 0; str[i] != '\0'; i++) {
			switch (str[i])
			{
			case '(':
				stc.push(str[i]);
				break;
			case '[':
				stc.push(str[i]);
				break;
			case ')':
				// 刚开始忘了加！stc.empty()，RE了好几次，太伤心了
				if (!stc.empty() && stc.top() == '(') {
					stc.pop();
				}
				else {
					flag = false;
				}
				break;
			case ']':
				if (!stc.empty() && stc.top() == '[') {
					stc.pop();
				}
				else {
					flag = false;
				}
				break;
			}
			if (!flag) {
				break;
			}
		}
		if (flag && stc.empty()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}
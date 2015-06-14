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

const int maxn = 1010;

int bRail[maxn];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n) {
		stack<int> s;
		memset(bRail, 0, sizeof(bRail));
		
		while (scanf("%d", &bRail[1]) == 1 && bRail[1]) {
			for (int i = 2; i <= n; i++) {
				scanf("%d", &bRail[i]);
			}
			int A = 1, B = 1;
			int ok = 1;
			while (B <= n) {
				if (A == bRail[B]) { // 先看A中第一个是否满足B
					A++;
					B++;
				}
				else if (!s.empty() && s.top() == bRail[B]) { // 再看栈顶车厢是否满足
					s.pop();
					B++;
				}
				else if (A <= n) { // 都不满足就让A的车厢入栈
					s.push(A++);
				}
				else  { // B没有满，但是没有满足的情况了，失败
					ok = 0;
					break;
				}
			}
			printf("%s\n", ok ? "Yes" : "No");
		}
		printf("\n");
	}

	return 0;
}
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
				if (A == bRail[B]) { // �ȿ�A�е�һ���Ƿ�����B
					A++;
					B++;
				}
				else if (!s.empty() && s.top() == bRail[B]) { // �ٿ�ջ�������Ƿ�����
					s.pop();
					B++;
				}
				else if (A <= n) { // �����������A�ĳ�����ջ
					s.push(A++);
				}
				else  { // Bû����������û�����������ˣ�ʧ��
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
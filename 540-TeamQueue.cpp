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

using namespace std;

const int maxt = 1010;

int main()
{
	int t, kase = 0;
	while (scanf("%d", &t) == 1 && t) {
		printf("Scenario #%d\n", ++kase);

		map<int, int> team;
		// team[x]��ʾ���Ϊx�������ڵ��Ŷӱ��
		for (int i = 0; i < t; i++) {
			int n, x;
			scanf("%d", &n);
			while (n--) {
				scanf("%d", &x);
				team[x] = i;
			}
		}
		queue<int> qt, qp[maxt];
		// qt���ŶӵĶ��У�qp[i]���Ŷ�i��Ա����
		while (1) {
			char cmd[10];
			scanf("%s", cmd);
			if (cmd[0] == 'S') {
				break;
			}
			else if (cmd[0] == 'E') {
				int x;
				scanf("%d", &x);
				int t = team[x];
				if (qp[t].empty()) {
					// ���x���ڵ��Ŷ�û�������ŶӶ����У��Ŷ�t����
					qt.push(t);
				}
				qp[t].push(x);
			}
			else {
				int t = qt.front();
				printf("%d\n", qp[t].front());
				qp[t].pop();
				if (qp[t].empty()) {
					qt.pop();
					// ���ĳ���˳��Ӻ󣬶������
					// �ǾͰѶ���Ӷ�������г���
				}
			}
		}
		printf("\n");
	}

	return 0;
}
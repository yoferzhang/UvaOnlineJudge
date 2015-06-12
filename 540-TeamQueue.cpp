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
		// team[x]表示编号为x的人所在的团队编号
		for (int i = 0; i < t; i++) {
			int n, x;
			scanf("%d", &n);
			while (n--) {
				scanf("%d", &x);
				team[x] = i;
			}
		}
		queue<int> qt, qp[maxt];
		// qt是团队的队列，qp[i]是团队i成员队列
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
					// 如果x所在的团队没有人在团队队列中，团队t入列
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
					// 如果某个人出队后，队伍空了
					// 那就把队伍从队伍队列中出列
				}
			}
		}
		printf("\n");
	}

	return 0;
}
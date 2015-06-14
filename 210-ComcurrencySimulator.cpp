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

int c[5];
int n, quantum, var[26], ip[maxn];
// ip[pid]是程序pid的当前行号
bool locked;
char prog[maxn][10];

deque<int> readyQ; // 因为阻止队列的程序是插入到等待队列的首部，所以不能用queue，要用deque
queue<int> blockQ;

void run(int pid)
{
	int q = quantum;
	// 每次最多运行quantum时间
	while (q > 0) {
		char *p = prog[ip[pid]];
		switch (p[2]) {
		case '=': // 赋值语句
			// 赋值要考虑两位数和一位数的情况
			var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
			q -= c[0];
			break;
		case 'i': // 打印语句
			printf("%d: %d\n", pid + 1, var[p[6] - 'a']);
			q -= c[1];
			break;
		case 'c': // lock
			if (locked) {
				blockQ.push(pid);
				return;
			}
			locked = true;
			q -= c[2];
			break;
		case 'l': // unlock
			locked = false;
			if (!blockQ.empty()) {
				int pid2 = blockQ.front();
				blockQ.pop();
				readyQ.push_front(pid2);
				// deque的操作push_front，插入到队首
			}
			q -= c[3];
			break;
		case 'd':
			return;
		}
		ip[pid]++;
	}
	readyQ.push_back(pid);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d %d %d %d\n", &n, &c[0], &c[1], &c[2], &c[3], &c[4], &quantum);
		memset(var, 0, sizeof(var));

		int line = 0;
		for (int i = 0; i < n; i++) {
			fgets(prog[line++], maxn, stdin);
			ip[i] = line - 1;
			while (prog[line - 1][2] != 'd') { // 判断是否是end
				fgets(prog[line++], maxn, stdin);
			}
			readyQ.push_back(i);
		}

		locked = false;
		while (!readyQ.empty()) {
			// 取出队首元素执行
			int pid = readyQ.front();
			readyQ.pop_front(); // 别忘了把队首出队
			run(pid);
		}
		if (T) {
			printf("\n");
		}
	}

	return 0;
}
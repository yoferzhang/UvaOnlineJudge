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

const int maxn = 65536;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct State {
	int x, y, top, front;
	State *prev;
} states[maxn];

int statesIdx;
int n, m, sx, sy, dtop, dfront;
int g[32][32];

State* getNewState(int x, int y, int dtop, int dfront, State *prev = NULL) {
	State *p = &states[statesIdx++];
	assert(statesIdx < maxn);
	p->x = x, p->y = y, p->top = dtop, p->front = dfront, p->prev = prev;
	return p;
}

int diceTable[7][7]; // [front][top] = right

void rotateDice(int dir, int dtop, int dfront, int &rtop, int &rfront) {
	rtop = rfront = 1;
	if (dir == 0) { // 向上滚动
		rtop = dfront, rfront = 7 - dtop;
	}
	else if (dir == 1) { // 向下滚动
		rtop = 7 - dfront, rfront = dtop;
	}
	else if (dir == 2) { // 向左滚动
		rfront = dfront;
		rtop = diceTable[dfront][dtop];
	}
	else if (dir == 3) { // 向右滚动
		rfront = dfront;
		rtop = 7 - diceTable[dfront][dtop];
	}
}

void bfs(int sx, int sy, int dtop, int dfront) {
	statesIdx = 0;
	int used[32][32][7][7] = {}; // used[x][y][dtop][dfront]
	int tx, ty, tdtop, tdfront;
	queue<State*> Q;
	State *u, *v;
	Q.push(getNewState(sx, sy, dtop, dfront));
	used[sx][sy][dtop][dfront] = 1;

	while (!Q.empty()) {
		u = Q.front(), Q.pop();
		for (int i = 0; i < 4; i++) {
			tx = u->x + dx[i], ty = u->y + dy[i];
			if (tx <= 0 || ty <= 0 || tx > n || ty > m) {
				continue;
			}
			if (g[tx][ty] != -1 && g[tx][ty] != u->top) {
				continue;
			}
			if (tx == sx && ty == sy) { 
				vector< pair<int, int> > ret;
				State *p = u;
				ret.push_back(make_pair(sx, sy));
				while (p != NULL) {
					ret.push_back(make_pair(p->x, p->y));
					p = p->prev;
				}
				for (int i = ret.size() - 1, j = 0; i >= 0; i--, j++) {
					if (j % 9 == 0)	printf("  ");
					if (j % 9 != 0)	printf(",");
					printf("(%d,%d)", ret[i].first, ret[i].second);	
					if (j % 9 == 8 || i == 0) {
						if (i) {
							printf(",\n");
						}
						else {
							puts("");
						}
					}
				}
				return;
			}
			rotateDice(i, u->top, u->front, tdtop, tdfront);
			if (used[tx][ty][tdtop][tdfront]) {
				continue;
			}
			used[tx][ty][tdtop][tdfront] = 1;
			v = getNewState(tx, ty, tdtop, tdfront, u);
			Q.push(v);
		}
	}
	printf("  No Solution Possible\n");
}

int main() {
	// 手动打表维护骰子滚动
	// diceface[front][top] = right
	diceTable[1][2] = 4, diceTable[1][3] = 2, diceTable[1][4] = 5, diceTable[1][5] = 3;
	diceTable[2][1] = 3, diceTable[2][3] = 6, diceTable[2][4] = 1, diceTable[2][6] = 4;
	diceTable[3][1] = 5, diceTable[3][2] = 1, diceTable[3][5] = 6, diceTable[3][6] = 2;
	diceTable[4][1] = 2, diceTable[4][2] = 6, diceTable[4][5] = 1, diceTable[4][6] = 5;
	diceTable[5][1] = 4, diceTable[5][3] = 1, diceTable[5][4] = 6, diceTable[5][6] = 3;
	diceTable[6][2] = 3, diceTable[6][3] = 5, diceTable[6][4] = 2, diceTable[6][5] = 4;

	char testcase[1024];
	while (scanf("%s", testcase) == 1) {
		if (!strcmp("END", testcase))
			break;
		scanf("%d %d %d %d %d %d", &n, &m, &sx, &sy, &dtop, &dfront);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &g[i][j]);
			}
		}		
		printf("%s\n", testcase);
		bfs(sx, sy, dtop, dfront);
	}
	return 0;
}
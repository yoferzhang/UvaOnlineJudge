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
#include <functional>

using namespace std;

const int maxn = 20000;
int n;
int rankOfPlayer[maxn];

void calcScores(vector<int>& v, int* a, int d, int maxd, int sum) { // 得到所有8种可能
	if (d == maxd)
		v.push_back(sum);
	else {
		calcScores(v, a, d + 1, maxd, sum + a[d]);
		calcScores(v, a, d + 1, maxd, sum);
	}
}

struct Player{
	vector<int> scores;
	int ID;
	Player(){}
	Player(int* a, int id) :ID(id){
		calcScores(scores, a, 0, 3, 0);
		sort(scores.begin(), scores.end());
	}
};

int main() {
	int kase = 1;
	while (scanf("%d", &n) && n) {
		memset(rankOfPlayer, -1, sizeof(rankOfPlayer));
		Player q[maxn];
		float data_fl[3];
		int data_int[3];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%f", &data_fl[j]);
				data_int[j] = (int)(round((data_fl[j] * 100.0)));
			}
			Player& p = q[i];
			p = Player(data_int, i);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &rankOfPlayer[i]);
		}
		int recd = 1000000;
		int recdID = -1;
		for (int i = 0; i < n; i++) {
			Player& u = q[rankOfPlayer[i] - 1];
			bool ok = false;
			for (int j = 7; j >= 0; j--) { // 从大到小
				if (u.scores[j] == recd && u.ID > recdID) { // 小分数ID比较大
					recdID = u.ID;
					ok = true;
					break;
				}
				else if (u.scores[j] < recd) { // 最小的分数
					recd = u.scores[j];
					recdID = u.ID;
					ok = true;
					break;
				}
			}
			if (!ok) {
				recd = -1;
				break;
			}
		}
		if (recd == -1) {
			printf("Case %d: No solution\n", kase++);
		}
		else {
			printf("Case %d: %.2f\n", kase++, recd / 100.0);
		}
	}
	return 0;
}
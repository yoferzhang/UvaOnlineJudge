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

const int maxn = 105;

struct SNode
{
	SNode(int pri = 0, bool tar = false) {
		priority = pri;
		target = tar;
	}
	int priority;
	bool target;
};

int cmp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	while (T--) {
		int jobs[maxn];
		queue<SNode> que;
		int n, target;
		memset(jobs, 0, sizeof(jobs));
		while (!que.empty()) {
			que.pop();
		}
		cin >> n >> target;
		for (int i = 0; i < n; i++) {
			int priority;
			cin >> priority;

			if (i == target) {
				que.push(SNode(priority, true));
			}
			else {
				que.push(SNode(priority, false));
			}
			jobs[i] = priority;
		}

		sort(jobs, jobs + maxn, cmp);

		bool ok = false;
		int count = 0;
		int *p = jobs;
		while (!ok) {
			SNode front = que.front();
			que.pop();
			if (front.priority == *p) {
				count++;
				p++;
				if (front.target) {
					ok = true;
				}
			}
			else {
				que.push(front);
			}
		}

		cout << count << endl;
	}

	return 0;
}
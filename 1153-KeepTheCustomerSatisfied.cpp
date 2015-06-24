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

typedef pair<int, int> Pair;
vector<Pair> state;
int n, ans, tmp;

// 默认Pair的排序是first，但是这里排序需要用d，就是second，所以要写一个比较函数
bool cmp(const Pair &a, const Pair &b)
{
	return a.second < b.second;
}

void solve()
{
	priority_queue<Pair> q; // 用优先队列，其中是按first比较大小的
	ans = tmp = 0; // 记得初始化。。。
	for (int i = 0; i < n; i++) { // 贪心求解
		tmp += state[i].first;
		q.push(state[i]);
		ans++;

		if (tmp > state[i].second) { // 如果超了当前的等待时间
			Pair t = q.top(); // 最大的是q最大的元素
			q.pop();
			ans--;
			tmp -= t.first;
		}
	}
	cout << ans << endl;
	
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		state.clear();
		cin >> n;
		int q, d;
		for (int i = 0; i < n; i++) {
			cin >> q >> d;
			state.push_back(make_pair(q, d));
		}
		sort(state.begin(), state.end(), cmp); // 按照d的大小排序
		solve();
		if (T) {
			cout << endl;
		}
	}

	return 0;
}
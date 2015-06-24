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

// Ĭ��Pair��������first����������������Ҫ��d������second������Ҫдһ���ȽϺ���
bool cmp(const Pair &a, const Pair &b)
{
	return a.second < b.second;
}

void solve()
{
	priority_queue<Pair> q; // �����ȶ��У������ǰ�first�Ƚϴ�С��
	ans = tmp = 0; // �ǵó�ʼ��������
	for (int i = 0; i < n; i++) { // ̰�����
		tmp += state[i].first;
		q.push(state[i]);
		ans++;

		if (tmp > state[i].second) { // ������˵�ǰ�ĵȴ�ʱ��
			Pair t = q.top(); // ������q����Ԫ��
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
		sort(state.begin(), state.end(), cmp); // ����d�Ĵ�С����
		solve();
		if (T) {
			cout << endl;
		}
	}

	return 0;
}
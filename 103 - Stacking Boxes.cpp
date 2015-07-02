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

const int maxk = 35;
int k, n, ans, target;
int dp[maxk];
bool first;

struct Box
{
	int dimension[12];
	bool operator < (const Box& rhs) const { // ·½±ãÅÐ¶ÏÊÇ·ñÇ¶Ì×
		for (int i = 0; i < n; i++) {
			if (dimension[i] >= rhs.dimension[i]) {
				return false;
			}
		}
		return true;
	}
}box[maxk];

void init()
{
	memset(dp, -1, sizeof(dp));
	first = true;
	ans = -1;
	cin >> n;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			cin >> box[i].dimension[j];
		}
		sort(box[i].dimension, box[i].dimension + n);
	}
}

int dfs(int i, const vector<int> *mp)
{
	int &ans = dp[i], temp;
	if (ans != -1) {
		return ans;
	}
	ans = 1;
	for (int j = 0; j < mp[i].size(); j++) {
		temp = dfs(mp[i][j], mp) + 1;
		ans = max(temp, ans);
	}
	return ans;
}

void printAns(int i, const vector<int> *mp)
{
	if (first) {
		cout << i + 1;
		first = false;
	}
	else {
		cout << ' ' << i + 1;
	}
	for (int j = 0; j < mp[i].size(); j++) {
		if (dp[mp[i][j]] == dp[i] - 1) {
			printAns(mp[i][j], mp);
			break;
		}
	}
}

void solve()
{
	vector<int> mp[maxk];
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (box[i] < box[j]) {
				mp[i].push_back(j);
			}
			else if (box[j] < box[i]) {
				mp[j].push_back(i);
			}
		}
	}

	for (int i = 0; i < k; i++) {
		int temp = dfs(i, mp);
		if (temp > ans) {
			ans = temp;
			target = i;
		}
	}
	cout << ans << endl;
	printAns(target, mp);
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> k) {
		init();
		solve();
	}

	return 0;
}
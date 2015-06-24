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

vector<int> permu, ans;
int  n;

void operate()
{
	while (1) {
		if (permu[0] == 1) { // 判断是否完成了
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (permu[i] != i + 1) {
					ok = false;
				}
			}
			if (ok) {
				return;
			}
		}

		// 注意当第一个大于第二个的时候换，但是如果第一个等于n第二个等于1是不能换的
		if (permu[0] > permu[1] && !(permu[0] == n && permu[1] == 1)) {
			ans.push_back(1);
			swap(permu[0], permu[1]);
		}
		else {
			ans.push_back(2);
			permu.insert(permu.begin(), permu[n - 1]);
			permu.erase(permu.end() - 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n && n) {
		int t;
		permu.clear();
		ans.clear();
		for (int i = 0; i < n; i++) {
			cin >> t;
			permu.push_back(t);
		}
		operate();
		// 逆着输出ans
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}
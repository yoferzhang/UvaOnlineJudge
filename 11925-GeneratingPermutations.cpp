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
		if (permu[0] == 1) { // �ж��Ƿ������
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

		// ע�⵱��һ�����ڵڶ�����ʱ�򻻣����������һ������n�ڶ�������1�ǲ��ܻ���
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
		// �������ans
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}
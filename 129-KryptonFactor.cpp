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

int n, L, cnt;
int s[85];

bool dfs(int cur) // ����false��ʾ�Ѿ��õ��⣬���ü�������
{
	if (cnt++ == n) {
		for (int i = 0; i < cur; i++) {
			if (i % 64 == 0 && i > 0) { // ÿ��64��
				cout << endl;
			}
			else if (i % 4 == 0 && i > 0) { // ÿ4��һ���ո�
				cout << ' ';
			}
			cout << (char)('A' + s[i]);
		}
		cout << endl << cur << endl;
		return false;
	}

	for (int i = 0; i < L; i++) {
		s[cur] = i;
		bool ok = true;
		for (int j = 1; j * 2 <= cur + 1; j++) { // ����Ϊj*2�ĺ�׺�Ƿ�����
			bool equal = true;
			for (int k = 0; k < j; k++) {
				if (s[cur - k] != s[cur - k - j]) { // ����һ���Ƿ����ǰһ��
					equal = false;
					break;
				}
			}
			if (equal) { // ǰ������ˣ����Ϸ�
				ok = false;
				break;
			}
		}
		if (ok) {
			if (!dfs(cur + 1)) {
				return false; // �ݹ�����������Ѿ��ҵ������˳�
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> L && n) {
		cnt = 0;
		dfs(0);
	}

	return 0;
}
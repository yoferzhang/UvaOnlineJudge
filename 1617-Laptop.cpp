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

int n;

// �Ȱ����Ҷ˵��С���������Ҷ˵���ͬ������°���˵�����
bool cmp(Pair A, Pair B)
{
	if (A.second != B.second) {
		return A.second < B.second;
	}
	return A.first < B.first;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<Pair> A;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			A.push_back(Pair(x, y));
		}
		sort(A.begin(), A.end(), cmp);

		// ̰�����
		int ret = 1, right = A[0].second;
		for (int i = 1; i < n; i++) {
			if (right != A[i].second) {
				if (right < A[i].first) {
					ret++;
					right = A[i].second;
				}
				else {
					right++; // �������̰�Ĵ���
				}
			}
		}
		cout << ret - 1 << endl;
	}

	return 0;
}
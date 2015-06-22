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

const int maxn = 100005;
int p[maxn], q[maxn];
int n;

int run(int s)
{
	int fuel = p[s] - q[s];
	for (int i = (s + 1) % n; i != s; i = (i + 1) % n) {
		if (fuel < 0) { // ����һվ���ͣ����ϵ��������������ߵ���վ
			return i;
		}
		fuel += p[i] - q[i]; // �����ͣ�����һվ��
	}
	if (fuel < 0) {
		return -1; //  ����һȦ��sum[p] < sum[q]��������������϶��ǲ����ܵģ�ֱ�ӷ���-1
	}
	return s; // �ɹ��������
}

// ö�����
int solve()
{
	int start = 0;
	while (1) {
		int finish = run(start);
		if (finish < start) {
			return -1; // ʧ��
		}
		if (finish == start) { // �ɹ���
			return start;
		}
		start = finish; // �ӶϿ��ĵط�����
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int kase = 0;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> q[i];
		}

		int ans = solve();
		cout << "Case " << ++kase << ": ";
		if (ans >= 0) {
			cout << "Possible from station " << ans + 1 << endl;
		}
		else {
			cout << "Not possible\n";
		}
	}

	return 0;
}
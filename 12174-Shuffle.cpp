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
int s, n, tot;
int x[maxn * 3], cnt[maxn], ok[maxn * 2];

void solve()
{
	for (int i = 0; i < n + s + 1; i++) {
		if (tot == s) { // �����Ĵ���
			ok[i] = 1;
		}
		if (i < s && tot == i) { // �տ�ʼ��ര�ڲ�����
			ok[i] = 1;
		}
		if (i > n && tot == n + s - i) { // ������ʱ���Ҳ�Ĵ��ڲ�����
			ok[i] = 1;
		}

		// Ϊ��һ�λ������ڸ���cnt��tot
		if (i == n + s) { // ����ͷ��
			break;
		}
		if (x[i] != -1 && --cnt[x[i]] == 0) { // ɾ����һ��
			tot--;
		}
		if (x[i + s] != -1 && cnt[x[i + s]]++ == 0) { // ����һ��
			tot++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> s >> n;

		// ��ÿ���������Ҷ���һ��-1
		fill(x, x + n + 2 * s, -1);
		for (int i = 0; i < n; i++) {
			cin >> x[i + s];
		}

		tot = 0; // ��ǰ���������ж��ٸ���ͬ������
		fill(cnt + 1, cnt + s + 1, 0);
		// cnt[i]��i�ڵ�ǰ�������ڵ�����
		fill(ok, ok + n + s + 1, 0);
		// �����i����������û��һ����������ok[i] = 1

		solve();

		int ans = 0;
		// ���ÿ�����ܵĽ��
		for (int i = 0; i < s; i++) {
			int valid = 1;
			// ���д�������Ҫ�����������ǿ��е�
			for (int j = i; j < n + s + 1; j += s) {
				if (!ok[j]) {
					valid = 0;
				}
			}
			if (valid) {
				ans++;
			}
		}
		if (ans == n + 1) {
			ans = s;
		}
		cout << ans << endl;

	}

	return 0;
}
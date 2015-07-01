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

const int maxm = 12;
const int maxn = 105;
const int inf = 0x3f3f3f3f;

int matrix[maxm][maxn], nextLine[maxm][maxn];
int d[maxm][maxn]; // d[i][j]��ʾ�Ӹ���(i, j)���������һ�е���С����
int m, n;

void init()
{
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
}

// ��̬�滮������
void solve()
{
	int ans = inf, first = 0;
	for (int j = n - 1; j >= 0; j--) { // ����
		for (int i = 0; i < m; i++) {
			if (j == n - 1) { // �߽�
				d[i][j] = matrix[i][j];
			}
			else {
				int row[3] = { i, i - 1, i + 1 };
				if (i == 0) {
					row[1] = m - 1; // ��0�������ǵ�m-1��
				}
				if (i == m - 1) {
					row[2] = 0; // ��m-1�������ǵ�0��
				}
				sort(row, row + 3); // ��������Ϊ�˵õ��ֵ�����С��
				d[i][j] = inf;
				for (int k = 0; k < 3; k++) { // �����ߣ��ж��Ǹ��Ƚ�С
					int v = d[row[k]][j + 1] + matrix[i][j];
					if (v < d[i][j]) {
						d[i][j] = v;
						nextLine[i][j] = row[k];
					}
				}
			}
			if (j == 0 && d[i][j] < ans) {
				ans = d[i][j];
				first = i;
			}
		}
	}
	// ���
	cout << first + 1;
	for (int i = nextLine[first][0], j = 1; j < n; i = nextLine[i][j], j++) {
		cout << ' ' << i + 1;
	}
	cout << endl << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> m) {
		init();
		solve();
	}

	return 0;
}
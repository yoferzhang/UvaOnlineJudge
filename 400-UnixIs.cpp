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

using namespace std;

const int maxcol = 60;
const int maxn = 105;
string filenames[maxn];

// 输出函数，s长度不足len时补字符extra
void print(const string s, int len, char extra)
{
	cout << s;
	for (int i = 0; i < len - s.length(); i++) {
		cout << extra;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n) {
		int M = 0; // 输出的列数
		for (int i = 0; i < n; i++) {
			cin >> filenames[i];
			M = max(M, (int)filenames[i].length());
		}
		//计算列数cols和行数rows
		int cols = (maxcol - M) / (M + 2) + 1;
		int rows = (n - 1) / cols + 1;
		print("", 60, '-');
		cout << endl;
		sort(filenames, filenames + n);
		for (int r = 0; r < rows; r++) {
			for (int c = 0; c < cols; c++) {
				int idx = c * rows + r;
				if (idx < n) {
					print(filenames[idx], c == cols - 1 ? M : M + 2, ' ');
				}
			}
			cout << endl;
		}
	}

	return 0;
}
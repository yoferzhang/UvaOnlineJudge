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

using namespace std;

const int maxn = 1000;
int n, m, sum;
string str[10], mstr[maxn]; // mstr存储操作的步骤
char num[maxn]; // 结点的值

int main()
{
	ios::sync_with_stdio(false);
	int kase = 0;
	while (cin >> n && n) {
		sum = pow(2, n);
		// 输入结点
		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}
		cin >> num;

		cin >> m;
		int temp;
		for (int i = 0; i < m; i++) {
			cin >> mstr[i];
		}
		cout << "S-Tree #" << ++kase << ":\n";
		//printf("S-Tree #%d:\n", ++kase);
		for (int i = 0; i < m; i++) {
			temp = 0;
			for (int j = 0; j < n; j++) {
				temp += (mstr[i][j] - '0') * pow(2, n - j - 1);
			}
			cout << num[temp];
		}
		cout << endl << endl;
	}

	return 0;
}
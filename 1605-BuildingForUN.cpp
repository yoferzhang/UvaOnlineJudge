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

int n;

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n) {
		cout << "2 " << n << " " << n << endl;
		if (n <= 26) { // 大写字母够用
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'A'); // 第i行全是国家i
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(j + 'A'); // 第j列全是国家j
				}
				cout << endl;
			}
			cout << endl;
		}
		else { // n大于26，大写字母不够用的情况
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'A'); // 第i行全是国家i
				}
				cout << endl;
			}
			for (int i = 0; i < n - 26; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'a'); // 大写字母用完用小写字母
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 26; j++) {
					cout << char(j + 'A');
				}
				for (int j = 26; j < n; j++) {
					cout << char(j - 26 + 'a');
				}
				cout << endl;
			}
		}
	}

	return 0;
}
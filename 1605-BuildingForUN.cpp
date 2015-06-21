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
		if (n <= 26) { // ��д��ĸ����
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'A'); // ��i��ȫ�ǹ���i
				}
				cout << endl;
			}
			cout << endl;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(j + 'A'); // ��j��ȫ�ǹ���j
				}
				cout << endl;
			}
			cout << endl;
		}
		else { // n����26����д��ĸ�����õ����
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'A'); // ��i��ȫ�ǹ���i
				}
				cout << endl;
			}
			for (int i = 0; i < n - 26; i++) {
				for (int j = 0; j < n; j++) {
					cout << char(i + 'a'); // ��д��ĸ������Сд��ĸ
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
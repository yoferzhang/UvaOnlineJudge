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

const int maxn = 1 << 15;
int A[maxn];

// 0,1,2,3�ֱ�����������
int trans[] = { 2, 3, 1, 0 };

map<int, set< pair<int, int> > > P;

void build(int n)
{
	int m = 1;
	A[0] = 3;
	for (int i = 1; i <= n; i++) {
		for (int j = m - 1, k = m; j >= 0; j--, k++) { // �����һ��չ����λ��
			A[k] = trans[A[j]];
		}
		m <<= 1;
	}
	int x = -1, y = 0, px = 0, py = 0;
	P.clear();
	// ��ÿ�����ߵ�λ�ü��������������P��
	for (int i = 0; i < m; i++) {
		if (A[i] == 0) {
			x = px << 1;
			y = py;
			P[y].insert(make_pair(x, 0));
			py++;
		}
		else if (A[i] == 1) {
			x = px << 1;
			y = py - 1;
			P[y].insert(make_pair(x, 1));
			py--;
		}
		else if (A[i] == 2) {
			x = (px << 1) - 1;
			y = py;
			P[y].insert(make_pair(x, 2));
			px--;
		}
		else {
			x = (px << 1) + 1;
			y = py;
			P[y].insert(make_pair(x, 3));
			px++;
		}
	}
}

void draw()
{
	// ��������������С������Ϊʲô����ƪ���ǰһƪ������˵��
	int mxy = -0x3f3f3f3f, mnx = 0x3f3f3f3f;
	for (map<int, set< pair<int, int> > >::iterator it = P.begin();
		it != P.end(); it++) {
		mxy = max(mxy, it->first);
		for (set< pair<int, int> >::iterator jt = it->second.begin();
			jt != it->second.end(); jt++) {
			mnx = min(mnx, jt->first);
		}
	}
	// ��������һ�л���������Ҫ�������
	for (map<int, set< pair<int, int> > >::reverse_iterator it = P.rbegin();
		it != P.rend(); it++) {
		int i = mnx;
		for (set<pair<int, int> >::iterator jt = it->second.begin();
			jt != it->second.end(); jt++) {
			while (i < jt->first) {
				cout << ' ';
				i++;
			}
			i++;
			if (jt->second == 0 || jt->second == 1) {
				cout << '|';
			}
			else {
				cout << '_';
			}
		}
		cout << endl;
	}
	cout << '^' << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n) {
		build(n);
		draw();
	}

	return 0;
}
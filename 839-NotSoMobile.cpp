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

using namespace std;

// �ݹ�����벢�ж��Ƿ�ƽ�⡣
bool solve(int& W)
{
	int Wl, Dl, Wr, Dr;
	cin >> Wl >> Dl >> Wr >> Dr;
	bool b1 = true, b2 = true;
	if (!Wl) { // ����Ǹ�����ƽ���ݹ��������
		b1 = solve(Wl);
	}
	if (!Wr) { // �ұ��Ǹ�����ƽ���ݹ��������
		b2 = solve(Wr);
	}
	W = Wl + Wr; // ���Ҷ�������ϣ��޸�WΪ����ƽ��������
	return b1 && b2 && (Wl * Dl == Wr * Dr);
}

int main()
{
	ios::sync_with_stdio(false);
	int T, W;
	cin >> T;
	while (T--) {
		if (solve(W)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		if (T) {
			cout << endl;
		}
	}

	return 0;
}
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

// 递归的输入并判断是否平衡。
bool solve(int& W)
{
	int Wl, Dl, Wr, Dr;
	cin >> Wl >> Dl >> Wr >> Dr;
	bool b1 = true, b2 = true;
	if (!Wl) { // 左边是个子天平，递归输入求解
		b1 = solve(Wl);
	}
	if (!Wr) { // 右边是个子天平，递归输入求解
		b2 = solve(Wr);
	}
	W = Wl + Wr; // 左右都计算完毕，修改W为子天平的总重量
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
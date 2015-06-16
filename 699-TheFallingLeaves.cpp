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

const int maxn = 200;
int sum[maxn];

// 递归构造二叉树，并且同时把相应位置的和计算出来
void build(int p)
{
	int v;
	cin >> v;
	if (v == -1) {
		return;
	}
	sum[p] += v;
	build(p - 1);
	build(p + 1);
}

int main()
{
	int v;
	int kase = 0;
	while (cin >> v) {
		if (v == -1) {
			break;
		}
		memset(sum, 0, sizeof(sum));
		int pos = maxn / 2; // 树根在中间
		sum[pos] = v; // 先序遍历，所以第一个就是树根
		build(pos - 1);
		build(pos + 1);

		int p = 0;
		while (sum[p] == 0) { // 找到最左边的起始叶子结点
			p++;
		}
		// 先输出一个，后面在循环输出空格加sum[p++]
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while (sum[p]) {
			cout << " " << sum[p++];
		}
		cout << "\n\n";
	}

	return 0;
}
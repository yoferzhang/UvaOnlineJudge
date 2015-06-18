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

const int maxv = 30;
// 因为各个结点的字母都不相同，所以把字母的ASCII码减去A的ASCII码，再加1作为编号
// 不能直接用ASCII码减去A的ASCII码作为编号是因为A的编号为0，对于访问会认为失败
int firstOrder[maxv], inOrder[maxv], postOrder[maxv], lch[maxv], rch[maxv];
int n;

// 给出先序L1..R1和前序L2..R2递归建成一颗二叉树，返回树根
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1) { // 空树
		return 0;
	}
	int root = firstOrder[L2]; // 先序遍历的第一个结点就是根
	int p = L1;
	while (inOrder[p] != root) {
		p++;
	}
	int cnt = p - L1; // 左子树的结点个数
	lch[root] = build(L1, p - 1, L2 + 1, L2 + cnt);
	rch[root] = build(p + 1, R1, L2 + cnt + 1, R2);
	return root;
}

// 从树根开始递归打印后序遍历
void printPostOrder(int root)
{
	if (lch[root]) {
		printPostOrder(lch[root]);
	}
	if (rch[root]) {
		printPostOrder(rch[root]);
	}
	cout << (char)(root + 'A' - 1);
	
}

int main()
{
	string line;
	while (cin >> line) {
		for (int i = 0; i < line.length(); i++) {
			firstOrder[i] = line[i] - 'A' + 1; // 这里加1的用意要好好体会
		}
		cin >> line;
		for (int i = 0; i < line.length(); i++) {
			inOrder[i] = line[i] - 'A' + 1;
		}
		int root = build(0, line.length() - 1, 0, line.length() - 1);
		printPostOrder(root);
		cout << endl;
	}

	return 0;
}
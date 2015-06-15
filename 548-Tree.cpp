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

const int maxv = 10005;
// 各个结点的权值各不相同且都是正整数，可以直接用权值作为结点编号
int inOrder[maxv], postOrder[maxv], lch[maxv], rch[maxv];
int n;

// 因为不知道每次测试数据的输入量，所以读取一行，然后再填入数组中
bool readList(int* a)
{
	string line;
	if (!getline(cin, line)) { // 非法输入，结束
		return false;
	}
	n = 0;
	int x;
	stringstream ss(line);
	while (ss >> x) { // 将数字取出存入数组
		a[n++] = x;
	}
	return n > 0;
}

// 递归构造二叉树，返回树根
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1) {
		return 0; // 空树
	}
	int root = postOrder[R2]; // 后序遍历的最后一个结点是根节点
	int p = L1;
	while (inOrder[p] != root) { // 在中序遍历中找到根节点
		p++;
	}
	int cnt = p - L1; // 找到后计算出左结点的个数
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1); // 递归左子树构造二叉树
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1); // 递归右子树构造二叉树
	return root;
}

int best, bestSum;

// DFS深度优先遍历
void dfs(int u, int sum) {
	sum += u;
	if (!lch[u] && !rch[u]) {
		if (sum < bestSum || (sum == bestSum && u < best)) {
			best = u;
			bestSum = sum;
		}
	}
	if (lch[u]) {
		dfs(lch[u], sum);
	}
	if (rch[u]) {
		dfs(rch[u], sum);
	}
}

int main()
{
	while (readList(inOrder)) { // EOF停止
		readList(postOrder);
		build(0, n - 1, 0, n - 1);
		bestSum = 1000000000;
		dfs(postOrder[n - 1], 0);
		cout << best << endl;
	}

	return 0;
}
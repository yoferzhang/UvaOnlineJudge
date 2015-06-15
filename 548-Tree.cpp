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
// ��������Ȩֵ������ͬ�Ҷ���������������ֱ����Ȩֵ��Ϊ�����
int inOrder[maxv], postOrder[maxv], lch[maxv], rch[maxv];
int n;

// ��Ϊ��֪��ÿ�β������ݵ������������Զ�ȡһ�У�Ȼ��������������
bool readList(int* a)
{
	string line;
	if (!getline(cin, line)) { // �Ƿ����룬����
		return false;
	}
	n = 0;
	int x;
	stringstream ss(line);
	while (ss >> x) { // ������ȡ����������
		a[n++] = x;
	}
	return n > 0;
}

// �ݹ鹹�����������������
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1) {
		return 0; // ����
	}
	int root = postOrder[R2]; // ������������һ������Ǹ��ڵ�
	int p = L1;
	while (inOrder[p] != root) { // ������������ҵ����ڵ�
		p++;
	}
	int cnt = p - L1; // �ҵ�����������ĸ���
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1); // �ݹ����������������
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1); // �ݹ����������������
	return root;
}

int best, bestSum;

// DFS������ȱ���
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
	while (readList(inOrder)) { // EOFֹͣ
		readList(postOrder);
		build(0, n - 1, 0, n - 1);
		bestSum = 1000000000;
		dfs(postOrder[n - 1], 0);
		cout << best << endl;
	}

	return 0;
}
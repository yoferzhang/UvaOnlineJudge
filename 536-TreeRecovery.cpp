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
// ��Ϊ����������ĸ������ͬ�����԰���ĸ��ASCII���ȥA��ASCII�룬�ټ�1��Ϊ���
// ����ֱ����ASCII���ȥA��ASCII����Ϊ�������ΪA�ı��Ϊ0�����ڷ��ʻ���Ϊʧ��
int firstOrder[maxv], inOrder[maxv], postOrder[maxv], lch[maxv], rch[maxv];
int n;

// ��������L1..R1��ǰ��L2..R2�ݹ齨��һ�Ŷ���������������
int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1) { // ����
		return 0;
	}
	int root = firstOrder[L2]; // ��������ĵ�һ�������Ǹ�
	int p = L1;
	while (inOrder[p] != root) {
		p++;
	}
	int cnt = p - L1; // �������Ľ�����
	lch[root] = build(L1, p - 1, L2 + 1, L2 + cnt);
	rch[root] = build(p + 1, R1, L2 + cnt + 1, R2);
	return root;
}

// ��������ʼ�ݹ��ӡ�������
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
			firstOrder[i] = line[i] - 'A' + 1; // �����1������Ҫ�ú����
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
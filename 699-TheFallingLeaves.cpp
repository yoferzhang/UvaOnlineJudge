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

// �ݹ鹹�������������ͬʱ����Ӧλ�õĺͼ������
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
		int pos = maxn / 2; // �������м�
		sum[pos] = v; // ������������Ե�һ����������
		build(pos - 1);
		build(pos + 1);

		int p = 0;
		while (sum[p] == 0) { // �ҵ�����ߵ���ʼҶ�ӽ��
			p++;
		}
		// �����һ����������ѭ������ո��sum[p++]
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while (sum[p]) {
			cout << " " << sum[p++];
		}
		cout << "\n\n";
	}

	return 0;
}
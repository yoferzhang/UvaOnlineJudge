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

const int maxn = 10;
int id[256], letter[maxn];
char input[1000];
int n;

void init() // ������ĸ���������ĸ���
{
	n = 0;
	for (char ch = 'A'; ch <= 'Z'; ch++) {
		if (strchr(input, ch) != NULL) {
			id[ch] = n++;
			letter[id[ch]] = ch;
		}
	}
}

// ��������
vector <int> u, v;
void readInput()
{
	int len = strlen(input);
	int p = 0, q = 0;
	u.clear();
	v.clear();
	while (1) {
		while (p < len && input[p] != ':') {
			p++;
		}
		if (p == len) {
			break;
		}
		while (q < len && input[q] != ';') {
			q++;
		}
		for (int i = p + 1; i < q; i++) {
			u.push_back(id[input[p - 1]]);
			v.push_back(id[input[i]]);
		}
		p++;
		q++;
	}
}

// ö��ȫ����
void solve()
{
	int P[maxn], bestP[maxn], pos[maxn], ans = n;
	for (int i = 0; i < n; i++) {
		P[i] = i;
	}
	do {
		for (int i = 0; i < n; i++) {
			pos[P[i]] = i; // ÿ����ĸ��λ��
		}
		int bandwidth = 0;
		for (int i = 0; i < u.size(); i++) {
			bandwidth = max(bandwidth, abs(pos[u[i]] - pos[v[i]])); // �������
		}
		if (bandwidth < ans) {
			ans = bandwidth;
			memcpy(bestP, P, sizeof(P));
		}
	} while (next_permutation(P, P + n));

	// ���
	for (int i = 0; i < n; i++) {
		cout << (char)letter[bestP[i]] << ' ';
	}
	cout << "-> " << ans << endl;
}

int main()
{
	while (cin >> input && input[0] != '#') {
		init();
		readInput();
		solve();
	}

	return 0;
}
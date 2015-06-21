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

const int maxn = 35;
int n, pancakes[maxn];

void filp(int p)
{
	for (int i = 0; i < p - i; i++) {
		swap(pancakes[i], pancakes[p - i]);
	}
	cout << n - p << " ";
}


int main()
{
	ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s)) { // ��֪��һ���ж��ٸ���ֱ�Ӷ�ȡһ��
		cout << s << endl;
		stringstream ss(s);
		n = 0;
		while (ss >> pancakes[n]) {
			n++;
		}

		for (int i = n - 1; i > 0; i--) {
			int maxP = max_element(pancakes, pancakes + i + 1) - pancakes;
			if (maxP == i) { // ������Ԫ�Ѿ�����ײ������÷�ת��
				continue;
			}
			if (maxP > 0) {
				filp(maxP); // �����Ԫ�ȷ���������
			}
			filp(i); // Ȼ�󷭵���ȷ��λ��
		}
		cout << "0\n";
	}
	

	return 0;
}
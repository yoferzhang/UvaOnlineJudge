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

const int maxn = 20;

int s[1 << maxn]; // 2��20�η�

int main()
{
	int D, I;
	int T;
	cin >> T;
	while (T--) {
		cin >> D;
		if (D == -1) {
			break;
		}
		cin >> I;
		memset(s, 0, sizeof(s));
		int k, n = (1 << D) - 1; // n�����ڵ���2��D�η���һ
		for (int i = 0; i < I; i++) {
			k = 1;
			while (1) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n) {
					break;
				}
			}
		}
		printf("%d\n", k / 2);
	}
	cout << -1 << endl;

	return 0;
}
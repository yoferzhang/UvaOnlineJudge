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

using namespace std;

int ducci[20];

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		// 记得清0
		memset(ducci, 0, sizeof(ducci));
		for (int i = 0; i < n; i++) {
			cin >> ducci[i];
		}
		int zero = 0, q = 0;
		// 循环1000次
		for (int i = 0; i < 1000; i++) {
			zero = 0;
			// 最后一个减去第一个的时候第一个已经改变了，所以先存储下来
			int t = ducci[0];
			for (int j = 0; j < n - 1; j++) {
				ducci[j] = abs(ducci[j] - ducci[j + 1]);
			}
			ducci[n - 1] = abs(ducci[n - 1] - t);
			// 判断是否全0
			for (int j = 0; j < n; j++) {
				if (ducci[j] == 0) {
					zero++;
				}
			}
			if (zero == n) {
				printf("ZERO\n");
				break;
			}
			if (i == 999) {
				printf("LOOP\n");
			}
		}
		
	}

	return 0;
}
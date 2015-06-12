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
		// �ǵ���0
		memset(ducci, 0, sizeof(ducci));
		for (int i = 0; i < n; i++) {
			cin >> ducci[i];
		}
		int zero = 0, q = 0;
		// ѭ��1000��
		for (int i = 0; i < 1000; i++) {
			zero = 0;
			// ���һ����ȥ��һ����ʱ���һ���Ѿ��ı��ˣ������ȴ洢����
			int t = ducci[0];
			for (int j = 0; j < n - 1; j++) {
				ducci[j] = abs(ducci[j] - ducci[j + 1]);
			}
			ducci[n - 1] = abs(ducci[n - 1] - t);
			// �ж��Ƿ�ȫ0
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
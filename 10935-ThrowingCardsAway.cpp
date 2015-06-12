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

int main()
{
	int n;
	while (cin >> n && n) {
		queue<int> cards;
		// ��ʼ������
		for (int i = 1; i <= n; i++) {
			cards.push(i);
		}
		printf("Discarded cards:");
		int first = 1;

		while (cards.size() != 1) {
			if (first) {
				printf(" %d", cards.front());
				first = 0;
			}
			else {
				printf(", %d", cards.front());
			}
			cards.pop();
			// �µĵ�һ�����ȳ�����������У��ǵ��ȴ���
			int t = cards.front();
			cards.pop();
			cards.push(t);
		}
		printf("\nRemaining card: %d\n", cards.front());
	}

	return 0;
}
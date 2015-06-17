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

queue<pair<int, int> > ans;

int main()
{
	int k;
	while (cin >> k && k) {
		int cnt = 0;
		for (int i = k + 1; i <= 2 * k; i++) {
			long long pro = (long long)i * k;
			int minus = i - k;
			if (pro % minus == 0) { // 是否能约分成分子是1的分数
				ans.push(pair<int, int>(pro / minus, i));
				cnt++;
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i++) {
			printf("1/%d = 1/%d + 1/%d\n", k, ans.front().first, ans.front().second);
			ans.pop(); // 全部输入就刚好清空了
		}
	}

	return 0;
}
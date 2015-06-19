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

string line;
map<long long, int> base;
int sum;

// 从深度depth开始，从line的第s个开始，重点为第e个
void dfs(int depth, int s, int e)
{
	if (line[s] == '[') {
		int p = 0;
		for (int i = s + 1; i != e; i++) {
			// 下面两个if是为了找到左子树
			if (line[i] == '[') {
				p++;
			}
			if (line[i] == ']') {
				p--;
			}
			if (p == 0 && line[i] == ',') {
				dfs(depth + 1, s + 1, i - 1); // dfs左子树
				dfs(depth + 1, i + 1, e - 1); // dfs右子树
			}
		}
	}
	else {
		long long w = 0;
		for (int i = s; i <= e; i++) {
			w = w * 10 + line[i] - '0';
		}
		sum++;
		// 重量为w的秤砣为基准，整个天平的重量就是w * pow(2,depth)，也就是w << depth
		base[w << depth]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		cin >> line; 
		base.clear();
		sum = 0;
		dfs(0, 0, line.size() - 1);

		int maxn = 0;
		
		for (map<long long, int>::iterator it = base.begin(); it != base.end(); it++) {
			maxn = max(maxn, it->second);
		}
		cout << sum - maxn << endl;
	}

	return 0;
}
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
#include <functional> // 为了使用greater

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n) {
		priority_queue<int, vector<int>, greater<int> > q;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			q.push(x);
		}
		int total = 0;
		int first, second, sum;
		for (int i = 0; i < n - 1; i++) {
			first = q.top();
			q.pop();
			second = q.top();
			q.pop();
			sum = first + second;
			total += sum;
			q.push(sum);
		}
		cout << total << endl;
	}

	return 0;
}
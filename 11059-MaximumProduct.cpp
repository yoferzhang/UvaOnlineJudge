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

int s[20];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int kase = 0;
	while (cin >> n && n) {
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		long long pro = 0;
		for (int star = 0; star < n; star++) {
			long long proTem = 1;
			for (int end = star; end < n; end++) {
				proTem = proTem * (long long)s[end];
				if (proTem > pro) {
					pro = proTem;
				}
			}
		}
		//printf("Case #%d: The maximum product is %d.\n\n", ++kase, pro);
		cout << "Case #" << ++kase << ": The maximum product is " << pro << ".\n\n";
	}

	return 0;
}
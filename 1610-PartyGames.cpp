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


const int maxn = 1010;
string s[maxn];

void solve(int a1, int a2)
{
	char ans[100];
	int len1 = s[a1].size();
	int len2 = s[a2].size();
	if (len1 < len2) {
		int t = 0;
		for (int i = 0; i < len1; i++) {
			if (i == len1 - 1) {
				ans[t++] = s[a1][i]; break; 
			}//刚开始忽略  
			if (s[a1][i] == s[a2][i]) {
				ans[t++] = s[a1][i];
			}
			if (s[a1][i] != s[a2][i]) {
				ans[t++] = s[a1][i] + 1;
				break;
			}
		}
		for (int i = 0; i < t; i++) {
			cout << ans[i];
		}
	}
	else {
		int t = 0;
		for (int i = 0; i < len2; i++) {
			if (s[a1][i] == s[a2][i]) {
				ans[t++] = s[a1][i];
			}
			if (s[a1][i] != s[a2][i]) {
				if (i != len2 - 1) {
					ans[t++] = s[a1][i] + 1;
					break;
				}
				else {
					if (i == len1 - 1) { //刚开始忽略
						ans[t++] = s[a1][i];
						break;
					}
					char ch1 = s[a1][i] + 1;
					if (s[a2][i] != ch1) {
						ans[t++] = ch1;
						break;
					}
					else {
						ans[t++] = s[a1][i];
						for (int j = i + 1; j < len1; j++) {
							if (j == len1 - 1) {
								ans[t++] = s[a1][j];
								break;
							}
							if (s[a1][j] != 'Z') {
								ans[t++] = s[a1][j] + 1;
								break;
							}
							else {
								ans[t++] = s[a1][j];
							}
						}
						for (int k = 0; k < t; k++) {
							cout << ans[k];
						}
						return;
					}
				}
			}
		}
		for (int i = 0; i < t; i++) {
			cout << ans[i];

		}
		return;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		sort(s, s + n);
		int a1 = (n - 1) / 2;
		int a2 = a1 + 1;
		solve(a1, a2);
		cout << endl;
	}
	return 0;
}
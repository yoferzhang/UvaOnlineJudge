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
#include <iomanip> 

using namespace std;

vector<string> s[1005];
int len[185];

int main()
{
	string line, buf;
	int i = 0, j = 0;
	while (getline(cin, line)) {
		istringstream stream(line);
		while (stream >> buf) {
			len[j] = max(len[j], (int)buf.length());
			j++;
			s[i].push_back(buf);
		}
		i++;
		j = 0;
	}
	// 设置左对齐
	cout << setiosflags(ios::left);
	for (int k = 0; k < i; k++) {
		int l = 0;
		for (l; l < s[k].size() - 1; l++) {
			// setw设置宽度
			cout << setw(len[l] + 1) << s[k][l];
		}
		cout << s[k][l] << endl;
	}

	return 0;
}
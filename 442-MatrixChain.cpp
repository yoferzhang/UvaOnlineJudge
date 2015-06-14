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

typedef pair<int, int> mn;
map<string, mn> matrix; // 存放矩阵

int main()
{
	int n;
	scanf("%d", &n);
	// 矩阵输入并存放
	for (int i = 0; i < n; i++) {
		string s;
		int m, n;
		cin >> s >> m >> n;
		matrix[s] = mn(m, n);
	}

	string expr;
	while (cin >> expr) {
		if (expr.length() == 1) { // 只有一个的时候直接输出0
			printf("0\n");
			continue;
		}
		
		long long countOfM = 0; // 乘法次数，怕溢出用了long long
		stack<mn> exprStack; // 用来存放表达式的栈
		bool ok = true;
		for (int i = 0; i < expr.length(); i++) {
			string s = expr.substr(i, 1);
			if (isalpha(expr[i])) { // 如果是字母，就入栈
				exprStack.push(mn(matrix[s].first, matrix[s].second));
			}
			else if (s == ")") { // 如果是右括号，就出栈两个矩阵做计算
				// 注意先出栈的是B，后出栈的是A，然后AB相乘
				int Bm = exprStack.top().first;
				int Bn = exprStack.top().second;
				exprStack.pop();
				int Am = exprStack.top().first;
				int An = exprStack.top().second;
				exprStack.pop();
				if (An == Bm) {
					countOfM += (long)Am * (long)An * (long)Bn;
					exprStack.push(mn(Am, Bn));
				}
				else {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			cout << countOfM << endl;
		}
		else {
			cout << "error\n";
		}
	}
	
	return 0;
}
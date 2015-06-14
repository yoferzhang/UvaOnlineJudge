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
map<string, mn> matrix; // ��ž���

int main()
{
	int n;
	scanf("%d", &n);
	// �������벢���
	for (int i = 0; i < n; i++) {
		string s;
		int m, n;
		cin >> s >> m >> n;
		matrix[s] = mn(m, n);
	}

	string expr;
	while (cin >> expr) {
		if (expr.length() == 1) { // ֻ��һ����ʱ��ֱ�����0
			printf("0\n");
			continue;
		}
		
		long long countOfM = 0; // �˷����������������long long
		stack<mn> exprStack; // ������ű��ʽ��ջ
		bool ok = true;
		for (int i = 0; i < expr.length(); i++) {
			string s = expr.substr(i, 1);
			if (isalpha(expr[i])) { // �������ĸ������ջ
				exprStack.push(mn(matrix[s].first, matrix[s].second));
			}
			else if (s == ")") { // ����������ţ��ͳ�ջ��������������
				// ע���ȳ�ջ����B�����ջ����A��Ȼ��AB���
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
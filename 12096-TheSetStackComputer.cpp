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

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache; // ÿ�����϶���Ӧһ��ID
vector<Set> Setcache; // ����ID�ҵ�����
// ��������ļ���s��IDcache[s]��������ID,��Setcache[IDcache[s]]����s����

int ID(Set x) {
	// ����Ҳ�������x��ID�������һ����ID
	if (IDcache.count(x)) {
		return IDcache[x];
	}
	Setcache.push_back(x); // ����¼���
	return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(),x.end() // ���е�����
#define INS(x) inserter(x,x.begin()) // ���������

int main()
{
	int T, n;
	cin >> T;
	while (T--) {
		// ��ĿҪ���ջ
		stack<int> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string op;
			cin >> op;
			if (op[0] == 'P') { // ֻ��Ҫ�жϵ�һ����ĸ�͹���
				s.push(ID(Set()));
			}
			else if (op[0] == 'D') {
				s.push(s.top());
			}
			else {
				// ʣ�����ֲ�������Ҫ��ջ����Ԫ��
				Set x1 = Setcache[s.top()];
				s.pop();
				Set x2 = Setcache[s.top()];
				s.pop();
				Set x;
				if (op[0] == 'U') {
					// STL������set_union
					set_union(ALL(x1), ALL(x2), INS(x));
				}
				else if (op[0] == 'I') {
					// STL������set_intersection
					set_intersection(ALL(x1), ALL(x2), INS(x));
				}
				else if (op[0] == 'A') {
					x = x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			cout << Setcache[s.top()].size() << endl;
		}
		cout << "***\n";
	}

	return 0;
}
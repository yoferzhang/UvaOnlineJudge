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
map<Set, int> IDcache; // 每个集合都对应一个ID
vector<Set> Setcache; // 根据ID找到集合
// 对于任意的集合s，IDcache[s]就是它的ID,而Setcache[IDcache[s]]就是s本身。

int ID(Set x) {
	// 如果找不到集合x的ID，则分配一个新ID
	if (IDcache.count(x)) {
		return IDcache[x];
	}
	Setcache.push_back(x); // 添加新集合
	return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(),x.end() // 所有的内容
#define INS(x) inserter(x,x.begin()) // 插入迭代器

int main()
{
	int T, n;
	cin >> T;
	while (T--) {
		// 题目要求的栈
		stack<int> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string op;
			cin >> op;
			if (op[0] == 'P') { // 只需要判断第一个字母就够了
				s.push(ID(Set()));
			}
			else if (op[0] == 'D') {
				s.push(s.top());
			}
			else {
				// 剩下三种操作都需要出栈两个元素
				Set x1 = Setcache[s.top()];
				s.pop();
				Set x2 = Setcache[s.top()];
				s.pop();
				Set x;
				if (op[0] == 'U') {
					// STL内置有set_union
					set_union(ALL(x1), ALL(x2), INS(x));
				}
				else if (op[0] == 'I') {
					// STL内置有set_intersection
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
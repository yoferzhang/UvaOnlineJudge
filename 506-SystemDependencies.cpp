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

const int maxn = 10000;
int cnt = 0;
map<string, int> name2id; // 把名字转化为整数，方便处理
string name[maxn];

vector<int> depend[maxn]; // 组件x所以来的组件列表
vector<int> depended[maxn]; // 依赖于x的组件列表

int status[maxn]; // 0表示组件x未安装，1表示显示安装，2表示隐式安装
vector<int> installed; // 存放安装过的组件，安装过的就不要再安装了

// 把名字转化为整数维护
int ID(const string& item)
{
	if (!name2id.count(item)) {
		name[++cnt] = item;
		name2id[item] = cnt;
	}
	return name2id[item];
}

// 是否有组件依赖于item
bool needed(int item)
{
	for (int i = 0; i < depended[item].size(); i++) {
		if (status[depended[item][i]]) {
			return true;
		}
	}
	return false;
}

// 安装item，如果有依赖项，递归的继续安装
void install(int item, bool toplevel)
{
	if (!status[item]) {
		for (int i = 0; i < depend[item].size(); i++) {
			install(depend[item][i], false);
		}
		cout << "   Installing " << name[item] << endl;
		status[item] = toplevel ? 1 : 2;
		installed.push_back(item);
	}
}

// 判断是否能删除，如果能，删除之后递归的删除其他所依赖的组件
void remove(int item, bool toplevel)
{
	if ((toplevel || status[item] == 2) && !needed(item)) {
		status[item] = 0;
		installed.erase(remove(installed.begin(), installed.end(), item), installed.end());
		cout << "   Removing " << name[item] << endl;
		for (int i = 0; i < depend[item].size(); i++) {
			remove(depend[item][i], false);
		}
	}
}

// 按照安装顺序输出
void list()
{
	for (int i = 0; i < installed.size(); i++) {
		cout << "   " << name[installed[i]] << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	string line, cmd;
	memset(status, 0, sizeof(status));
	while (getline(cin, line)) {
		cout << line << endl;
		stringstream ss(line);
		ss >> cmd;
		if (cmd[0] == 'E') {
			break;
		}
		string item1, item2;
		if (cmd[0] == 'L') {
			list();
		}
		else {
			ss >> item1;
			int i1 = ID(item1);
			if (cmd[0] == 'D') {
				while (ss >> item2) {
					int i2 = ID(item2);
					depend[i1].push_back(i2);
					depended[i2].push_back(i1);
				}
			}
			else if (cmd[0] == 'I') {
				if (status[i1]) {
					cout << "   " << item1 << " is already installed.\n";
				}
				else {
					install(i1, true);
				}
			}
			else {
				if (!status[i1]) {
					cout << "   " << item1 << " is not installed.\n";
				}
				else if (needed(i1)) {
					cout << "   " << item1 << " is still needed.\n";
				}
				else {
					remove(i1, true);
				}
			}
		}
	}

	return 0;
}
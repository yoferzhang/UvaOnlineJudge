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
map<string, int> name2id; // ������ת��Ϊ���������㴦��
string name[maxn];

vector<int> depend[maxn]; // ���x������������б�
vector<int> depended[maxn]; // ������x������б�

int status[maxn]; // 0��ʾ���xδ��װ��1��ʾ��ʾ��װ��2��ʾ��ʽ��װ
vector<int> installed; // ��Ű�װ�����������װ���ľͲ�Ҫ�ٰ�װ��

// ������ת��Ϊ����ά��
int ID(const string& item)
{
	if (!name2id.count(item)) {
		name[++cnt] = item;
		name2id[item] = cnt;
	}
	return name2id[item];
}

// �Ƿ������������item
bool needed(int item)
{
	for (int i = 0; i < depended[item].size(); i++) {
		if (status[depended[item][i]]) {
			return true;
		}
	}
	return false;
}

// ��װitem�������������ݹ�ļ�����װ
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

// �ж��Ƿ���ɾ��������ܣ�ɾ��֮��ݹ��ɾ�����������������
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

// ���հ�װ˳�����
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
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

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		map<string, string> ma;
		string dictOld, dictNew;
		string ad[102], del[102], cha[102];
		// 分别存储增加的，减少的，变化的关键字
		cin >> dictOld >> dictNew;
		int addCount = 0;
		int deleteCount = 0;
		int changeCount = 0;

		int a = 0;
		while (dictOld.find(',', a + 1) < dictOld.size()) {
			// 这里截取方法比较重要
			string s(dictOld, a + 1, dictOld.find(',', a + 1) - a - 1);
			string kay(s, 0, s.find(':', 0));
			string value(s, s.find(':', 0) + 1, s.size() - s.find(':', 0));
			ma.insert(pair<string, string>(kay, value));
			a = dictOld.find(',', a + 1);
		}
		string s(dictOld, a + 1, dictOld.find('}', a + 1) - a - 1);

		string kay(s, 0, s.find(':', 0));
		string value(s, s.find(':', 0) + 1, s.size() - s.find(':', 0));

		if (kay.size()) {
			ma.insert(pair<string, string>(kay, value));
		}

		a = 0;
		while (dictNew.find(',', a + 1) < dictNew.size()) {
			string s(dictNew, a + 1, dictNew.find(',', a + 1) - a - 1);
			string key(s, 0, s.find(':', 0));
			string value(s, s.find(':', 0) + 1, s.size() - s.find(':', 0));

			if (ma.find(key) == ma.end()) {
				ad[addCount++] = key;
			}
			else {
				string temp = ma.find(key)->second;
				if (temp != value) {
					cha[changeCount++] = key;
				}
				ma.erase(key);
			}
			a = dictNew.find(',', a + 1);
		}

		string s1(dictNew, a + 1, dictNew.find('}', a + 1) - a - 1);
		string key1(s1, 0, s1.find(':', 0));
		string value1(s1, s1.find(':', 0) + 1, s1.size() - s1.find(':', 0));

		if (key1.size()) {
			if (ma.find(key1) == ma.end()) {
				ad[addCount++] = key1;
			}
			else {
				string temp = ma.find(key1)->second;
				if (temp != value1) {
					cha[changeCount++] = key1;
				}
				ma.erase(key1);
			}
		}

		while (ma.begin() != ma.end()) {
			string temp = ma.begin()->first;
			del[deleteCount++] = temp;
			ma.erase(temp);
		}

		if (addCount == 0 &&
			deleteCount == 0 &&
			changeCount == 0) {
			cout << "No changes\n";
		}
		else {
			if (addCount) {
				sort(ad, ad + addCount);
				cout << "+";
				for (int i = 0; i < addCount; i++) {
					if (i) {
						cout << ",";
					}
					cout << ad[i];
				}
				cout << endl;
			}
			if (deleteCount) {
				sort(del, del + deleteCount);
				cout << "-";
				for (int i = 0; i < deleteCount; i++) {
					if (i) {
						cout << ",";
					}
					cout << del[i];
				}
				cout << endl;
			}
			if (changeCount) {
				sort(cha, cha + changeCount);
				cout << "*";
				for (int i = 0; i < changeCount; i++) {
					if (i) {
						cout << ",";
					}
					cout << cha[i];
				}
				cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
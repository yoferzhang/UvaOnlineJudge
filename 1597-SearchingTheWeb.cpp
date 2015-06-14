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

#define rep(i, b) for(int i = 0; i < (b); i++)
#define FOR for(int j = limitLine[i]; j < limitLine[i + 1]; j++)
typedef bool Bit[1505];

int n, lines, m; // n�ĵ�����lines������m������
int limitLine[105]; // limit[i]:��iƪ�ĵ��ӵڼ��п�ʼ

string doc[1505]; // ��������
map<string, Bit> Index; // Index[����]:Bit�������Щ�г��ֹ�

// ��s������Index
void upDate(string s, int p)
{
	string word;
	for (string::iterator it = s.begin(); it != s.end(); it++) {
		if (isalpha(*it)) {
			*it = tolower(*it); // ������ĸ��ת����Сд
		}
		else {
			*it = ' '; // ���ַ���հ�
		}
	}

	stringstream ss(s);
	while (ss >> word) {
		Index[word][p] = true;
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin >> n;
	scanf("%d ", &n);
	rep(i, n) {
		limitLine[i] = lines;
		while (getline(cin, doc[lines]), doc[lines] != "**********") {
			upDate(doc[lines], lines);
			lines++;
		}
	}
	limitLine[n] = lines;

	string s;
	Bit mark;
	bool *A, *B;

	scanf("%d ", &m);
	for (int iii = 0; iii < m; iii++) {
		getline(cin, s);
		if (s[0] == 'N') {
			A = Index[s.substr(4)];
			rep(i, n) {
				bool logo = true;
				FOR if (A[j]) {
					logo = false;
					break;
				}
				FOR mark[j] = logo;
			}
		}
		else if (s.find("AND") != string::npos) {
			int p = s.find(" AND ");
			A = Index[s.substr(0, p)];
			B = Index[s.substr(p + 5)];
			memset(mark, 0, sizeof(mark));
			bool hasA, hasB; // ��ͬһ�����У��������Ƿ񶼳���
			rep(i, n) {
				hasA = hasB = false;
				FOR if (A[j]) {
					hasA = true;
					break;
				}
				FOR if (B[j]) {
					hasB = true;
					break;
				}
				if (!(hasA && hasB)) {
					continue;
				}
				FOR mark[j] = (A[j] || B[j]);
			}
		}
		else if (s.find("OR") != string::npos) {
			int p = s.find(" OR ");
			A = Index[s.substr(0, p)];
			B = Index[s.substr(p + 4)];
			rep(i, lines) mark[i] = (A[i] || B[i]);
		}
		else {
			memcpy(mark, Index[s], sizeof(mark));
		}

		// ���mark
		bool hasOut = false, needOut = false;
		rep(i, n) {
			if (hasOut) needOut = true;
			hasOut = false;
			FOR if (mark[j]) {
				if (needOut) {
					cout << "----------\n";
					needOut = false;
				}
				cout << doc[j] << endl;
				hasOut = true;
			}
		}
		if (!(needOut || hasOut)) {
			cout << "Sorry, I found nothing.\n";
		}
		cout << "==========\n";
	}


	return 0;
}
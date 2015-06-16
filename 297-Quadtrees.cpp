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

const int len = 32;
const int maxn = 1034;
char s[maxn];
int buf[len][len], cnt;

// ��buf�л���
void draw(const char* s, int& p, int r, int c, int w) {
	char ch = s[p++];
	if (ch == 'p') {
		draw(s, p, r, c + w / 2, w / 2); // ��1����
		draw(s, p, r, c, w / 2); // ��2����
		draw(s, p, r + w / 2, c, w / 2); // ��3����
		draw(s, p, r + w / 2, c + w / 2, w / 2); // ��4����
	}
	else if (ch == 'f'){
		for (int i = r; i < r + w; i++) {
			for (int j = c; j < c + w; j++) {
				if (buf[i][j] == 0) { // ������˺����أ��Ͳ�Ҫ�ٻ��ˣ��������ͼ��һ��ֽbuf�ϻ�
					buf[i][j] = 1;
					cnt++; // ��������ص�ĸ���
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		memset(buf, 0, sizeof(buf)); // ��ջ�ͼ����
		cnt = 0; // �ǵðѺ����ص�ĸ������
		for (int i = 0; i < 2; i++) {
			cin >> s;
			int p = 0;
			// ������ͼ����ͬһ��buf�У��������൱���Ѿ���������
			draw(s, p, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}

	return 0;
}
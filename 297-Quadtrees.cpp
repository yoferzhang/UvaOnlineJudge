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

// 在buf中绘制
void draw(const char* s, int& p, int r, int c, int w) {
	char ch = s[p++];
	if (ch == 'p') {
		draw(s, p, r, c + w / 2, w / 2); // 画1区域
		draw(s, p, r, c, w / 2); // 画2区域
		draw(s, p, r + w / 2, c, w / 2); // 画3区域
		draw(s, p, r + w / 2, c + w / 2, w / 2); // 画4区域
	}
	else if (ch == 'f'){
		for (int i = r; i < r + w; i++) {
			for (int j = c; j < c + w; j++) {
				if (buf[i][j] == 0) { // 如果画了黑像素，就不要再画了，这个两个图在一张纸buf上画
					buf[i][j] = 1;
					cnt++; // 计算黑像素点的个数
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
		memset(buf, 0, sizeof(buf)); // 清空画图区域
		cnt = 0; // 记得把黑像素点的个数清空
		for (int i = 0; i < 2; i++) {
			cin >> s;
			int p = 0;
			// 把两个图画到同一个buf中，这样就相当于已经加起来了
			draw(s, p, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}

	return 0;
}
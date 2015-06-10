#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

struct One{
	int r, c;
	char type;
};

One Red[10];

int N, r0, c0, G_NO;
char tab[12][12]; // 棋盘
// 黑将能走的四个方向
const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

// 马的行走方向
const int Hdir[8][4] = {
	{ -1, 2, 0, 2 }, { 1, 2, 0, 2 },
	{ -2, -1, -2, 0 }, { -2, 1, -2, 0 },
	{ -1, -2, 0, -2 }, { 1, -2, 0, -2 },
	{ 2, -1, 2, 0 }, { 2, 1, 2, 0 }
};

inline bool in_black_palace(const int r, const int c)
{
	return r >= 1 && r <= 3 && c >= 4 && c <= 6;
}

int get_range_block(int r1, int c1, int r2, int c2)
{
	int cnt = 0;
	if (r1 != r2 && c1 != c2) return -1;
	if (r1 == r2){
		if (c1 > c2) swap(c1, c2);
		for (int i = c1 + 1; i <= c2 - 1; ++i) {
			if (tab[r1][i] != '\0')
				cnt++;
		}
	}
	else if (c1 == c2){
		if (r1 > r2) swap(r1, r2);
		for (int i = r1 + 1; i <= r2 - 1; ++i) {
			if (tab[i][c1] != '\0') {
				cnt++;
			}
		}
	}
	return cnt;
}

// 四种棋子的将军判别方法
bool G(const int r, const int c, const int x, const int y)
{
	if (c != y) return false;
	return get_range_block(r, c, x, y) == 0;
}

bool R(const int r, const int c, const int x, const int y) 
{
	int res = get_range_block(r, c, x, y);
	if (res == -1) return false;
	return res == 0;
}

bool H(const int r, const int c, const int x, const int y) 
{
	for (int i = 0; i < 8; ++i) {
		int x1 = x + Hdir[i][0], y1 = y + Hdir[i][1];
		if (x1 == r && y1 == c && get_range_block(x, y, x + Hdir[i][2], y + Hdir[i][3]) == 0)
			return true;
	}
	return false;
}

bool C(const int r, const int c, const int x, const int y){
	int res = get_range_block(r, c, x, y);
	if (res == -1) {
		return false;
	}
	return res == 1;
}

bool check_red_win(const int r, const int c) {
	for (int i = 0; i < N; ++i) if (!(Red[i].r == r && Red[i].c == c)) {
		One & t = Red[i];
		if (t.type == 'G' && G(r, c, t.r, t.c)) return true;
		if (t.type == 'R' && R(r, c, t.r, t.c)) return true;
		if (t.type == 'H' && H(r, c, t.r, t.c)) return true;
		if (t.type == 'C' && C(r, c, t.r, t.c)) return true;
	}
	return false;
}

int main()
{
	//ios::sync_with_stdio(false);
	while ( cin >> N >> r0 >> c0 && (N != 0)) {
		// 记得清空红方棋子和棋盘
		memset(Red, 0, sizeof(Red)), memset(tab, 0, sizeof(tab));
		for (int i = 0; i < N; i++) {
			One t;
			cin >> t.type >> t.r >> t.c;
			if (t.type == 'G') {
				G_NO = i; // 标记黑将
			}
			tab[t.r][t.c] = t.type; 
			Red[i] = t;
		}
		// 判断黑将能否直接吃掉红将
		if (G(r0, c0, Red[G_NO].r, Red[G_NO].r)) { 
			printf("NO\n"); 
			continue;
		}
		bool red_win = true;
		// 红将向上下左右分别移动，看是否能逃脱
		for (int i = 0; i < 4; ++i) {
			int r1 = r0 + dir[i][0], c1 = c0 + dir[i][1];
			if (in_black_palace(r1, c1) && !check_red_win(r1, c1)) {
				red_win = false;
				break; 
			}
		}
		if (red_win) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
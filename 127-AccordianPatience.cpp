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
#include <cmath>  

using namespace std;

// 每个牌堆可能有52张牌，用结构体存放牌堆  
struct Pile
{
	char cards[53][3];
	int x; // 牌堆最上面牌的位置  
}pile[53];

// 从i开始往左移动s个距离  
void move(int n, int s)
{
	int left = pile[n - s].x;
	int right = pile[n].x;
	for (int i = 0; i < 3; i++) {
		pile[n - s].cards[left + 1][i] = pile[n].cards[right][i];
	}

	pile[n - s].x++;
	pile[n].x--;

	if (pile[n].x >= 0) {
		return;
	}
	for (int i = n; i < 52; i++) { // 如果空了，就要把后面的往前移动  
		pile[i] = pile[i + 1];
	}
}

int main()
{
	while (1) {
		scanf("%s", pile[0].cards[0]);
		if ('#' == pile[0].cards[0][0]) {
			break;
		}
		pile[0].x = 0;
		pile[52].x = -1;
		// 读入数据  
		for (int i = 1; i < 52; i++) {
			scanf("%s", pile[i].cards[0]);
			pile[i].x = 0;
		}

		bool flag = true;
		int cnt = 0;
		while (flag) {
			int i;
			for (i = 1; pile[i].x != -1; i++) {
				int left = pile[i - 3].x; // 牌堆顶部的位置  
				int right = pile[i].x; // 牌堆顶部的位置  
				// 先和左边第3张牌match  
				if (i > 0 &&
					(pile[i].cards[right][0] == pile[i - 3].cards[left][0] ||
					pile[i].cards[right][1] == pile[i - 3].cards[left][1])) {
					move(i, 3);
					flag = false;
					break;
				}

				left = pile[i - 1].x;
				right = pile[i].x;
				// 如果左边第3长match失败，再和左边那张match  
				if (pile[i].cards[right][0] == pile[i - 1].cards[left][0] ||
					pile[i].cards[right][1] == pile[i - 1].cards[left][1]) {
					move(i, 1);
					flag = false;
					break;
				}
			}
			cnt = i;
			// 判断是否交换，没有交换就跳出while  
			if (true == flag) {
				flag = false;
			}
			else {
				flag = true;
			}
		}
		if (cnt > 1) {
			printf("%d piles remaining:", cnt);
		}
		else {
			printf("%d pile remaining:", cnt);
		}
		for (int i = 0; pile[i].x != -1; i++) {
			printf(" %d", pile[i].x + 1);
		}
		printf("\n");
	}

	return 0;
}
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

//双端队列比较好处理
vector<deque<int> > piles;
// 用一个set存放状态，每次检查
set<vector<deque<int> > > vis;
int n, zero[8]; // zero记录每个牌堆是否为空
int first, second, third, sum;

void init()
{
	piles.clear();
	vis.clear();
	memset(zero, 0, sizeof(zero));
	// 初始化数组
	for (int i = 0; i < 8; i++) {
		piles.push_back(deque<int>());
	}
	// 前7张牌放入7个牌堆中
	piles[1].push_back(n);
	for (int i = 2; i <= 7; i++) {
	scanf("%d", &n);
	piles[i].push_back(n);
	}
	// 读取剩下的45张牌，放到手牌中
	for (int i = 0; i < 45; i++) {
	scanf("%d", &n);
	piles[0].push_back(n);
	}
}

// 最上面两张和最下面一张
bool checkSum1(int i)
{
	first = piles[i].front();
	piles[i].pop_front();
	second = piles[i].front();
	third = piles[i].back();
	sum = first + second + third;
	if (10 == sum || 20 == sum || 30 == sum) {
		piles[0].push_back(first);
		piles[0].push_back(second);
		piles[0].push_back(third);
		piles[i].pop_front();
		piles[i].pop_back();
		return true;
	}
	piles[i].push_front(first);
	return false;
}

// 最上面一张和最下面两张
bool checkSum2(int i)
{
	first = piles[i].front();
	third = piles[i].back();
	piles[i].pop_back();
	second = piles[i].back();
	sum = first + second + third;
	if (10 == sum || 20 == sum || 30 == sum) {
		piles[0].push_back(first);	
		piles[0].push_back(second);
		piles[0].push_back(third);
		piles[i].pop_front();
		piles[i].pop_back();
		return true;
	}
	piles[i].push_back(third);
	return false;
}

// 最下面三张
bool checkSum3(int i)
{
	third = piles[i].back();
	piles[i].pop_back();
	second = piles[i].back();
	piles[i].pop_back();
	first = piles[i].back();
	sum = first + second + third;
	if (10 == sum || 20 == sum || 30 == sum) {
		piles[0].push_back(first);
		piles[0].push_back(second);
		piles[0].push_back(third);
		piles[i].pop_back();
		return true;
	}
	piles[i].push_back(second);
	piles[i].push_back(third);
	return false;
}

bool checkSum(int i)
{
	if (piles[i].size() < 3) {
		return false;
	}
	if (checkSum1(i)) {
		return true;
	}
	if (checkSum2(i)) {
		return true;
	}
	if (checkSum3(i)) {
		return true;
	}
	return false;
}

void solve()
{
	int i = 1;
	for (int cnt = 8;; cnt++) {
		int newCard = piles[0].front();
		piles[0].pop_front();
		piles[i].push_back(newCard);
		while (checkSum(i));
		if (piles[i].size() == 0) {
			zero[i] = 1;
		}
		if (vis.find(piles) != vis.end()) { // 如果找到了
			printf("Draw: %d\n", cnt);
			return;
		}
		vis.insert(piles);
		if (piles[0].size() == 0) {
			printf("Loss: %d\n", cnt);
			return;
		}
		if (piles[0].size() == 52) {
			printf("Win : %d\n", cnt);
			return;
		}
		
		i = i % 7 + 1;
		while (zero[i]) {
			i = i % 7 + 1;
		}
	}
}

int main()
{
	while (scanf("%d", &n) && n) {
		init();
		solve();
	}

	return 0;
}
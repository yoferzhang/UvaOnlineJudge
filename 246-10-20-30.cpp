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

//˫�˶��бȽϺô���
vector<deque<int> > piles;
// ��һ��set���״̬��ÿ�μ��
set<vector<deque<int> > > vis;
int n, zero[8]; // zero��¼ÿ���ƶ��Ƿ�Ϊ��
int first, second, third, sum;

void init()
{
	piles.clear();
	vis.clear();
	memset(zero, 0, sizeof(zero));
	// ��ʼ������
	for (int i = 0; i < 8; i++) {
		piles.push_back(deque<int>());
	}
	// ǰ7���Ʒ���7���ƶ���
	piles[1].push_back(n);
	for (int i = 2; i <= 7; i++) {
	scanf("%d", &n);
	piles[i].push_back(n);
	}
	// ��ȡʣ�µ�45���ƣ��ŵ�������
	for (int i = 0; i < 45; i++) {
	scanf("%d", &n);
	piles[0].push_back(n);
	}
}

// ���������ź�������һ��
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

// ������һ�ź�����������
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

// ����������
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
		if (vis.find(piles) != vis.end()) { // ����ҵ���
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
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


const int maxn = 105;

int p, t, np[maxn], lim;

struct petri{
	int ip, op, i[maxn], o[maxn], in[maxn], out[maxn];
} pet[maxn];
// ip��op�ǲ����Ǩ��place�ı��  

int main(){
	int kase = 0;
	while (scanf("%d", &p) && p){
		memset(pet, 0, sizeof(pet));
		for (int i = 1; i <= p; ++i) {
			scanf("%d", &np[i]);
		}
		scanf("%d", &t);
		for (int i = 1; i <= t; ++i){
			int k;
			while (scanf("%d", &k), k){
				if (k < 0) {
					++pet[i].in[-k];
				}
				else {
					++pet[i].out[k];
				}
			}
			for (int j = 1; j <= p; ++j){
				if (pet[i].in[j]) {
					pet[i].i[++pet[i].ip] = j;
				}
				if (pet[i].out[j]) {
					pet[i].o[++pet[i].op] = j;
				}
			}
		}
		scanf("%d", &lim);
		int cnt = 0;
		for (int i = 1; i <= t; ++i){
			bool flag = true;
			petri &k = pet[i];
			for (int j = 1; j <= k.ip; ++j) {
				if (np[k.i[j]] < k.in[k.i[j]]){
					flag = false; break;
				}
			}
			if (!flag) continue;
			for (int j = 1; j <= k.ip; ++j) {
				np[k.i[j]] -= k.in[k.i[j]];
			}
			for (int j = 1; j <= k.op; ++j) {
				np[k.o[j]] += k.out[k.o[j]];
			}
			i = 0;
			if (++cnt >= lim) break;
		}
		if (cnt >= lim) {
			printf("Case %d: still live after %d transitions\n", ++kase, lim);
		}
		else {
			printf("Case %d: dead after %d transitions\n", ++kase, cnt);
		}
		printf("Places with tokens:");
		for (int i = 1; i <= p; ++i) {
			if (np[i]) {
				printf(" %d (%d)", i, np[i]);
			}
		}
		printf("\n\n");
	}
	return 0;
}
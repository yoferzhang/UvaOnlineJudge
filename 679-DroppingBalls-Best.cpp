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

int main()
{
	int D, I;
	int T;
	cin >> T;
	while (1) {
		scanf("%d", &D);
		if (D == -1) {
			break;
		}
		scanf("%d", &I);
		int k = 1;
		for (int i = 0; i < D - 1; i++) {
			if (I % 2) {
				k = k * 2;
				I = (I + 1) / 2;
			}
			else {
				k = k * 2 + 1;
				I /= 2;
			}
		}
		printf("%d\n", k);
	}
	
	return 0;
}
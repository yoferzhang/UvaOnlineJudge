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
	int n;
	int kase = 0;
	while (cin >> n && n) {
		int cnt = 0;
		char buf[99];
		if (kase++) {
			cout << endl;
		}
		for (int fghij = 1234;; fghij++) { // 从1234开始遍历
			int abcde = fghij * n;
			// 把数字合成字符串
			sprintf(buf, "%05d%05d", abcde, fghij);
			if (strlen(buf) > 10) { // 如果长度超过10，终止循环
				break;
			}
			sort(buf, buf + 10); 
			// 排序之后应该和0123456789一一对应，才算成功
			bool flag = true;
			for (int i = 0; i < 10; i++) {
				if (buf[i] - '0' != i) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
				printf("%05d / %05d = %d\n", abcde, fghij, n);
			}
		}
		if (!cnt) {
			printf("There are no solutions for %d.\n", n);
		}
	}

	return 0;
}
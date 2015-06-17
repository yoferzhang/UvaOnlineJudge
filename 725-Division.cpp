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
		for (int fghij = 1234;; fghij++) { // ��1234��ʼ����
			int abcde = fghij * n;
			// �����ֺϳ��ַ���
			sprintf(buf, "%05d%05d", abcde, fghij);
			if (strlen(buf) > 10) { // ������ȳ���10����ֹѭ��
				break;
			}
			sort(buf, buf + 10); 
			// ����֮��Ӧ�ú�0123456789һһ��Ӧ������ɹ�
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
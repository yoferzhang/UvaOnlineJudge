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

using namespace std;

int d[1505];

int main()
{
	int p2 = 1, p3 = 1, p5 = 1, save = 2;
	d[1] = 1;
	while (save <= 1500) {
		if (d[p2] * 2 <= d[p3] * 3 && d[p2] * 2 <= d[p5] * 5) {
			if (d[save - 1] < d[p2] * 2)
				d[save++] = d[p2++] * 2;
			else p2++;
		}
		else if (d[p3] * 3 <= d[p2] * 2 && d[p3] * 3 <= d[p5] * 5) {
			if (d[save - 1] < d[p3] * 3)
				d[save++] = d[p3++] * 3;
			else p3++;
		}
		else if (d[p5] * 5 <= d[p2] * 2 && d[p5] * 5 <= d[p3] * 3) {
			if (d[save - 1] < d[p5] * 5)
				d[save++] = d[p5++] * 5;
			else p5++;
		}
	}
	printf("The 1500'th ugly number is %d.\n", d[1500]);

	return 0;
}
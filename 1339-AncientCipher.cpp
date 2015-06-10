#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

char a[110], b[110];
int pa[26], pb[26];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	while (cin >> a >> b) {
		memset(pa, 0, sizeof(pa));
		memset(pb, 0, sizeof(pb));
		int al = strlen(a);
		int bl = strlen(b);
		if (al != bl) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i < al; i++) {
			pa[a[i] - 'A']++;
			pb[b[i] - 'A']++;
		}
		qsort(pa, 26, sizeof(pa[0]), cmp);
		qsort(pb, 26, sizeof(pb[0]), cmp);
		if (!memcmp(pa, pb, sizeof(pa))) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
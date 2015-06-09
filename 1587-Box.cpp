#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 6;

struct rec{ int l, w; } r[N];
bool cmp(rec a, rec b)
{
	return a.w < b.w || (a.w == b.w && a.l < b.l);
}

int main()
{
	int a, b, ok;
	while (~scanf("%d%d", &r[0].w, &r[0].l))
	{
		ok = 1;
		if (r[0].w > r[0].l) swap(r[0].w, r[0].l);
		for (int i = 1; i < 6; ++i)
		{
			scanf("%d%d", &r[i].w, &r[i].l);
			if (r[i].w > r[i].l) swap(r[i].w, r[i].l);
		}

		sort(r, r + N, cmp);
		for (int i = 0; i < N; i += 2)
			if (r[i].w != r[i + 1].w || r[i].l != r[i + 1].l) ok = 0;
		if (r[0].w != r[2].w || r[0].l != r[4].w || r[2].l != r[4].l) ok = 0;

		puts(ok ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (b)
		exgcd(b, a % b, d, y, x), y -= x * (a / b);
	else
		d = a, x = 1, y = 0;
}
int main()
{
	LL x, y, m, n, L, d, t, s;
	int flg = 0;
	cin >> x >> y >> m >> n >> L;
	if (m < n)
		swap(m, n), swap(x, y);
	exgcd(m - n, L, d, t, s);
	LL mod = L / d;
	if ((y - x) % d)
		puts("Impossible");
	else
		t = (y - x) / d * t, printf("%lld", (t % mod + mod) % mod);
	return 0;
}

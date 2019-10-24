#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,a[110],uup[110],ddown[110];
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a[i];
	}
	uup[1] = 1;
	int maxn = 1;
	for (int j = 2; j <= N; ++j)
	{
		maxn = 1;
		for (int i = j-1; i > 0; --i)
		{
			if(a[i] < a[j])
				maxn = max(uup[i] + 1,maxn);
		}
		uup[j] = maxn;
	}
	ddown[N] = 1;
	for (int l = N-1; l > 0; --l)
	{
		maxn = 1;
		for (int i = l + 1; i <= N; ++i)
		{
			if(a[l] > a[i])
				maxn = max(maxn,ddown[i] + 1);
		}
		ddown[l] = maxn;
	}
	maxn = 1;
	for (int m = 1; m <= N; ++m)
	{
		maxn = max(maxn,uup[m] + ddown[m]);
	}
	cout << N - maxn + 1 << endl;
	return 0;
}

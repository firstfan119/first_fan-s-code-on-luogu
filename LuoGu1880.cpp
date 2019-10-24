#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;

int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}

const int maxn=1125;
int f_min[maxn][maxn];
int f_max[maxn][maxn];
int pre[maxn];
int v[maxn];
int main()
{
	int n=read();
	for(ri i=1; i<=n; i++)
	{
		v[n+i]=v[i]=read();
	}
	for(ri i=1; i<=2*n; i++)
	{
		pre[i]=pre[i-1]+v[i];
	}
	for(ri len=2; len<=n; len++)
	{
		for(ri i=1; i<=2*n-len+1; i++)
		{
			int mn=20031125;
			int mx=0;
			int lim=i+len-1;
			for(ri k=i; k<lim; k++)
			{
				mn=min(mn,f_min[i][k]+f_min[k+1][lim]+pre[lim]-pre[i-1]);
				mx=max(mx,f_max[i][k]+f_max[k+1][lim]+pre[lim]-pre[i-1]);
			}
			f_min[i][lim]=mn;
			f_max[i][lim]=mx;
		}
	}
	int mx=0;
	int mn=2003115;
	for(ri i=1; i<=n; i++)
	{
		mx=max(mx,f_max[i][i+n-1]);
		mn=min(mn,f_min[i][i+n-1]);
	}
	return 0&printf("%d\n%d",mn,mx);
}

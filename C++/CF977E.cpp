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

const int maxn=1e6+7;
int f[maxn];

int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

int u[maxn];
int v[maxn];
int ind[maxn];

int main()
{
	int n;
	int m;
	while(scanf("%d%d",&n,&m))
	{
		int ans=0;
		for(ri i=1;i<=n;i++)
		{
			f[i]=i;
			ind[i]=0;
		}
		for(ri i=1; i<=m; i++)
		{
			u[i]=read();
			v[i]=read();
			ind[u[i]]++;
			ind[v[i]]++;
		}
		for(ri i=1;i<=m;i++)
		{
			if(ind[u[i]]==2&&ind[v[i]]==2)
			{
				int fu=find(u[i]);
				int fv=find(v[i]);
				if(fu!=fv)
				{
					f[fu]=fv;
				}
				else
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}

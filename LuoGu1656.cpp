#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=20031125;
int tot;
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return num*flg;
}
struct edge
{
	int u;
	int v;//val=1;
} e[maxn];
int f[maxn];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}
bool cmp(edge a,edge b)
{
	return a.u==b.u?a.v<b.v:a.u<b.u;
}
int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=m; i++)
	{
		e[i].u=read();
		e[i].v=read();
		if(e[i].u>e[i].v)
		{
			swap(e[i].u,e[i].v);
		}
	}
	sort(e+1,e+m+1,cmp);
	for(ri i=1; i<=m; i++)
	{
		tot=0;
		for(ri j=1; j<=n; j++)
		{
			f[j]=j;
		}
		for(ri j=1; j<=m; j++)
		{
			if(i!=j)
			{
				int fu=find(e[j].u);
				int fv=find(e[j].v);
				if(fu!=fv)
				{
					f[fu]=fv;
					tot++;
				}
			}
			if(tot==n-1)
			{
				break;
			}
		}
		if(tot!=n-1)
		{
			printf("%d %d\n",e[i].u,e[i].v);
		}
	}
}

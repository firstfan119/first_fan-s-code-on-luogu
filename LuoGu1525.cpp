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

struct edge
{
	int u;
	int v;
	int val;
	friend bool operator <(edge one,edge two)
	{
		return one.val>two.val;
	}
} e[maxn];

int enm[maxn];//enemy

int main()
{
	int n=read();
	int m=read();
	for(ri i=1; i<=m; i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].val=read();
	}
	sort(e+1,e+m+1);
	for(ri i=1;i<=n;i++)
	{
		f[i]=i;
	}
	for(ri i=1;i<=m+1;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv)
		{
			return 0&printf("%d",e[i].val);
		}
		else
		{
			if(!enm[u])
			{
				enm[u]=v;
			}
			else
			{
				f[find(v)]=find(enm[u]);
			}
			if(!enm[v])
			{
				enm[v]=u;
			}
			else
			{
				f[find(u)]=find(enm[v]);
			}
		}
	}
}
/*
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
out:
3512
*/

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

struct edge
{
	int u;
	int v;
	int val;
	int id;
	friend bool operator<(edge one,edge two)
	{
		return one.val<two.val;
	}
} e[6005];

int cnt=0;
void add(int u,int v,int val)
{
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].val=val;
}

int f[6005];
int find(int x)
{
	return x==f[x]?x:(f[x]=find(f[x]));
}

int n,m;
int kru(int p)
{
	int cnt=0;
	int res=0;
	for(ri i=1; i<=n; i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=m; i++)
	{
		int fu=find(e[i].u);
		int fv=find(e[i].v);
		if(fu!=fv)
		{
			if(e[i].id<=p)
			{
				cnt++;
				res+=e[i].val;
				f[fu]=fv;
			}
		}
	}
	if(cnt!=n-1)
	{
		res=-1;
	}
	return res;
}
int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=m; i++)
	{
		int u=read();
		int v=read();
		int val=read();
		add(u,v,val);
		e[i].id=i;
	}
	sort(e+1,e+m+1);
	for(ri i=1; i<=m; i++)
	{
		printf("%d\n",kru(i));
	}
}

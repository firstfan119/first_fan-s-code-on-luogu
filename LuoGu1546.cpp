#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,val;
} e[200002];
int f[200002];
int read()
{
	int num=0;
	int flg=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			flg=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return flg*num;
}
bool cmp(edge a,edge b)
{
	return a.val<b.val;
}
int find(int x)
{
	return x==f[x]?x:(f[f[x]]=find(f[x]));
}
int main()
{
	int n=read(),cnt=0;
	for(int i=1; i<=n; i++)
	{
		f[i]=i;
		for(int j=1; j<=n; j++)
		{
			int val=read();
			e[++cnt].u=i;
			e[cnt].v=j;
			e[cnt].val=val;
		}
	}
	sort(e+1,e+cnt+1,cmp);
	int ans=0,p=0;
	for(int i=1; i<=cnt; i++)
	{
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy)
		{
			ans+=e[i].val;
			f[find(e[i].u)]=e[i].v;
			p++;
			if(p==n-1)
			{
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}

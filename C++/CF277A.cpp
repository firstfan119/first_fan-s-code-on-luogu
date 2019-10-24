#include <bits/stdc++.h>
#define ll long long
#define ri register int
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
int a[maxn];

int k,g,nex,n,m,cnt,ans;

int f[maxn];
inline int find(ri x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main()
{
	n=read();
	m=read();
	for(ri i=1; i<=max(n,m); i++)
	{
		f[i]=i;
	}
	for(ri i=1; i<=n; i++)
	{
		k=read();
		if(k==0)
		{
			ans++;
			continue;
		}
		g=read();
		a[g]++;
		for(ri i=1; i<k; i++)
		{
			nex=read();
			a[nex]++;
			int x=find(g),y=find(nex);
			if(x!=y)
			{
				f[x]=y;
			}
		}
	}
	for(ri i=1; i<=m; i++)
	{
		if(a[i]==0)cnt++;
		if(f[i]==i)
		{
			ans++;
		}
	}
	printf("%d\n",cnt==m?n:ans-cnt-1);
}
/*
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
out:
2
*/

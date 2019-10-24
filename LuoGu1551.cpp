#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1e7+7;
int f[maxn];
int n,m,q;
int find(int x)
{
	return f[x]==x?x:(f[x]=find(f[x]));
}
int read()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		num=num*10+c-48;
		c=getchar();
	}
	return num;
}
int main()
{
	int n,m,p;
	n=read();
	m=read();
	p=read();
	for(int i=1; i<=n; i++)
		f[i]=i;
	int x,y;
	for(int i=1; i<=m; i++)
	{
		x=read();
		y=read();
		f[find(x)]=find(y);
	}
	for(int i=1; i<=p; i++)
	{
		x=read();
		y=read();
		if(find(x)==find(y))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

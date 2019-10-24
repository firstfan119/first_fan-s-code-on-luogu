#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int maxn=1125;
int len[maxn][maxn],dis[maxn];
bool vis[maxn];
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
int main()
{
	int n=read();
	int l=20031125;
	memset(dis,0x3f3f,sizeof(dis));
	for (ri i=1; i<n; i++)
	{
		for (ri j=i+1; j<=n; j++)
		{
			len[i][j]=read();
		}
	}
	dis[1]=0;
	int a;
	for (ri k=1; k<=n; k++)
	{
		l=20031125;
		for (ri i=1; i<=n; i++)
		{
			if ((!vis[i])&&(l>dis[i]))
			{
				l=dis[i];
				a=i;
			}
		}
		vis[a]=1;
		for (ri i=a+1; i<=n; i++)
		{
			if (dis[i]>l+len[a][i])
			{
				dis[i]=l+len[a][i];
			}
		}
	}
	cout<<dis[n];
	return 0;
}
